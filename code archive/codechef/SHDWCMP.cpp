//{
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(ll i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define FILL(i,n) memset(i,n,sizeof i)
#define X first
#define Y second
#define SZ(_a) (int)_a.size()
#define ALL(_a) _a.begin(),_a.end()
#define pb push_back
#ifdef brian
#define debug(...) do{\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0)
template<typename T>void _do(T &&_x){cerr<<_x<<endl;}
template<typename T,typename ...S> void _do(T &&_x,S &&..._t){cerr<<_x<<" ,";_do(_t...);}
template<typename _a,typename _b> ostream& operator << (ostream &_s,const pair<_a,_b> &_p){return _s<<"("<<_p.X<<","<<_p.Y<<")";}
template<typename It> ostream& _OUTC(ostream &_s,It _ita,It _itb)
{
    _s<<"{";
    for(It _it=_ita;_it!=_itb;_it++)
    {
        _s<<(_it==_ita?"":",")<<*_it;
    }
    _s<<"}";
    return _s;
}
template<typename _a> ostream &operator << (ostream &_s,vector<_a> &_c){return _OUTC(_s,ALL(_c));}
template<typename _a> ostream &operator << (ostream &_s,set<_a> &_c){return _OUTC(_s,ALL(_c));}
template<typename _a,typename _b> ostream &operator << (ostream &_s,map<_a,_b> &_c){return _OUTC(_s,ALL(_c));}
template<typename _t> void pary(_t _a,_t _b){_OUTC(cerr,_a,_b);cerr<<endl;}
#define IOS()
#else
#define debug(...)
#define pary(...)
#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#endif // brian
//}


const ll MAXn=5e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

struct node;

ll gd(node *a,ll t);


struct node{
  int l,r;
  node *lc,*rc;
  ll d[2],tg[2],h;
  node(int li,int ri,node *lci=0,node *rci=0):l(li),r(ri),lc(lci),rc(rci){d[0]=d[1]=tg[0]=tg[1]=0;h=(l+r)/2;}
  void ins(int li,int ri,int k,int t)
  {
    if(li>=r||ri<=l)return;
    if(li<=l&&ri>=r)tg[t]+=k;
    else
    {
      if(t==0)
      {
        if(li<h)
        {
          if(!lc)lc=new node(l,h);
          lc->ins(li,ri,k,t);
        }
        else
        {
          if(!rc)rc=new node(h,r);
          rc->ins(li,ri,k,t);
        }
        d[0]=gd(lc,0)+gd(rc,0);
        d[1]=gd(lc,1)+gd(rc,1);
      }
      else
      {
        if(li<h)
        {
          if(!lc)lc=new node(l,h);
          lc->ins(li,ri,k,t);
        }
        if(ri>h)
        {
          if(!rc)rc=new node(h,r);
          rc->ins(li,ri,k,t);
        }

        d[1]=gd(lc,1)+gd(rc,1);
      }



    }
  }
  ii qr(int li,int ri)
  {
    debug(this,l,r,d[0],d[1],tg[0],tg[1]);
    if(li>=r||ri<=l)return ii(0,0);
    if(li<=l&&ri>=r)return ii(d[0]+tg[0],d[1]+(d[0]+tg[0])*tg[1]);
    else
    {

      ii a,b;
      a=lc?lc->qr(li,ri):ii(0,0);
      b=rc?rc->qr(li,ri):ii(0,0);

      return ii(a.X+b.X,(a.X+b.X)*tg[1]+a.Y+b.Y);
    }
  }
  int qr2(int li,int ri)
  {
    //debug(this,l,r,d[0],d[1],tg[0],tg[1]);
    if(li>=r||ri<=l)return 0;
    if(li<=l&&ri>=r)return d[0]+tg[0];
    else
    {

      int a,b;
      a=lc?lc->qr2(li,ri):0;
      b=rc?rc->qr2(li,ri):0;

      return a+b;
    }
  }
};
ll gd(node *a,ll t)
{
  if(t==0)return a?(a->tg[t]+a->d[t]):0;
  else return a?(a->d[t]+(a->d[0]+a->tg[0])*a->tg[t]):0;
}
node *rt[MAXn];

vector<int> v[MAXn];
ll d[MAXn];
ll ans=0;

int sz[MAXn],mx[MAXn],p[MAXn],cp[MAXn],tl[MAXn],tr[MAXn];
ll tit=-1;

void szdfs(int now)
{
  sz[now]=1;
  mx[now]=-1;
  for(int k:v[now])
  {
    szdfs(k);
    sz[now]+=sz[k];
    if(mx[now]==-1||sz[k]>sz[mx[now]])mx[now]=k;
  }
}
void decomp(int now)
{
  tl[now]=++tit;
  if(mx[now]!=-1)
  {
    cp[mx[now]]=cp[now];
    decomp(mx[now]);
  }
  for(int k:v[now])
  {
    if(k==mx[now])continue;
    cp[k]=k;
    decomp(k);
  }
  tr[now]=tit;
}

ll add(int x,int k)//node x, color k
{
  //rt[k]->ins(tl[x],tl[x]+1,1,0);
  int now=p[x];
  while(now!=-1)
  {
    //rt[k]->ins(tl[cp[now]],tl[now]+1,1,1);
    now=p[cp[now]];
  }
  ll r=0,s=0;
  now=p[x];
  while(now!=-1)
  {
    s+=rt[k]->qr2(tl[cp[now]],tl[now]+1);
    now=p[cp[now]];
  }
  debug(x,k,s);
  r=s*(s-1)/2;
  ii tmp=rt[k]->qr(tl[x]+1,tr[x]+1);
  r+=s*tmp.X;
  r+=tmp.Y;
  debug(x,k,r);
  return r;
}

ll rm(int x,int k)
{
  //rt[k]->ins(tl[x],tl[x]+1,-1,0);
  int now=p[x];
  while(now!=-1)
  {
    //rt[k]->ins(tl[cp[now]],tl[now]+1,-1,1);
    now=p[cp[now]];
  }
  ll r=0,s=0;
  now=p[x];
  while(now!=-1)
  {
    s+=rt[k]->qr2(tl[cp[now]],tl[now]+1);
    now=p[cp[now]];
  }
  debug(x,k,s);
  r=s*(s-1)/2;
  ii tmp=rt[k]->qr(tl[x]+1,tr[x]+1);
  r+=s*tmp.X;
  r+=tmp.Y;
  debug(x,k,r,tmp);
  return -r;
}

int main()
{
    IOS();
    ll n,q;
    cin>>n>>q;

    REP1(i,n-1)
    {
      ll t;
      cin>>t;
      v[t].pb(i);
      p[i]=t;
    }
    p[0]=-1;

    REP(i,n)cin>>d[i];

    szdfs(0);
    decomp(0);
    pary(tl,tl+n);
    pary(tr,tr+n);

    REP(i,n)rt[i]=new node(0,n);

    REP(i,n)
    {
      ans+=add(i,d[i]);
      debug(i,ans);
    }

    cout<<ans<<endl;


    REP1(i,q)
    {
      ll x;
      cin>>x;
      x=(x+ans)%n;
      ll t=(i-1)%n;
      debug("Q:",t,x);
      if(d[t]!=x)
      {
        ans+=rm(t,d[t]);
        ans+=add(t,x);
        d[t]=x;
      }

      cout<<ans<<endl;
    }


}
