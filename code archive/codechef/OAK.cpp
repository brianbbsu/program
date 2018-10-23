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


const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e18);


bool swt;

struct node;

node *nds,*ndptr;

struct node{
  int l,r;
  node *lc,*rc;
  ll id,org_mxw,mxw,wtg;
  bool emptg;
  void clr(){
    id=0,org_mxw=INF,mxw=INF;
    emptg=0;wtg=0;
  }
  node(ll li=0,ll ri=0,node *lci=0,node *rci=0):l(li),r(ri),lc(lci),rc(rci){clr();}
  node(node *t):l(t->l),r(t->r),lc(t->lc),rc(t->rc),id(t->id),org_mxw(t->org_mxw),mxw(t->mxw),wtg(t->wtg),emptg(t->emptg){}

  void mak_clr()
  {
    mxw=org_mxw;
    wtg=0;
    emptg=1;
  }

  void clrdfs(ll *mxwi,vector<ll> &dt,ll n)
  {
    if(l>n)return;
    clr();
    if(l!=r-1)lc->clrdfs(mxwi,dt,n),rc->clrdfs(mxwi,dt,n);
    if(l==r-1)id=dt[l],org_mxw=mxw=mxwi[id];
    else org_mxw=mxw=min(lc->mxw,rc->mxw);
  }

  void push()
  {
    lc=new(ndptr++) node(lc);
    rc=new(ndptr++) node(rc);
    //assert(ndptr<nds+285*MAXn);
    if(emptg){lc->mak_clr();rc->mak_clr();emptg=0;}
    lc->wtg+=wtg;
    rc->wtg+=wtg;
    mxw-=wtg;
    wtg=0;
  }
  void pull()
  {
    mxw=min(lc->mxw-lc->wtg,rc->mxw-rc->wtg);
  }

  void add(ll li,ll ri,ll k)
  {
    if(li>=r||ri<=l)return;
    if(li<=l&&ri>=r)wtg+=k;
    else
    {
      push();
      lc->add(li,ri,k);
      rc->add(li,ri,k);
      pull();
    }
  }

  ll qrbrk(ll li,ll ri,ll tw)
  {
    if(li>=r||ri<=l||mxw-tw-wtg>=0)return -1;
    else if(l==r-1)return id;
    else if(li<=l&&ri>=r)
    {
      push();
      //pull();
      tw+=wtg;
      if(rc->mxw-rc->wtg-tw<0)return rc->qrbrk(li,ri,tw);
      else return lc->qrbrk(li,ri,tw);
    }
    else
    {
      push();
      //pull();
      tw+=wtg;
      ll t=rc->qrbrk(li,ri,tw);
      if(t!=-1)return t;
      t=lc->qrbrk(li,ri,tw);
      return t;
    }
  }

  ll qrs(ll x,ll tw)
  {
    tw+=wtg;
    //debug(x,tw,l,r,emptg,wtg);
    if(l==r-1||emptg)return tw;
    else if(x<(l+r)/2)return lc->qrs(x,tw);
    else return rc->qrs(x,tw);
  }

  void rem(ll li,ll ri)
  {
    if(li>=r||ri<=l)return;
    else if(li<=l&&ri>=r)mak_clr();
    else
    {
      push();
      lc->rem(li,ri);
      rc->rem(li,ri);
      pull();
    }
  }
  void dbg()
  {
    debug(l,r,id,wtg,mxw);
    if(l!=r-1)lc->dbg(),rc->dbg();
  }
};

node* build(ll l,ll r)
{
  if(l==r-1)return new(ndptr++) node(l,r);
  else return new(ndptr++) node(l,r,build(l,(l+r)/2),build((l+r)/2,r));
}

ll n,q,rtid;
vector<ll> v[MAXn];
ll mxw[MAXn],p[MAXn];
node *rt[MAXn];

ll sz[MAXn],mxs[MAXn],cp[MAXn],tin[MAXn],tout[MAXn];
void szdfs(ll now)
{
  sz[now]=1;mxs[now]=-1;
  for(ll k:v[now]){
    szdfs(k);
    sz[now]+=sz[k];
    if(mxs[now]==-1||sz[k]>sz[mxs[now]])mxs[now]=k;
  }
}
ll dfsit;
vector<ll> dt;
void make_chain(ll now)
{
  tin[now]=++dfsit;
  dt.pb(now);
  if(mxs[now]!=-1)
  {
    ll t=mxs[now];
    cp[t]=cp[now];
    make_chain(t);
  }
  for(ll k:v[now])
  {
    if(k==mxs[now])continue;
    cp[k]=k;
    make_chain(k);
  }
  tout[now]=dfsit;
}


ll tsk2(ll x,ll i)
{
  assert(x>0);
  ll t=rt[i]->qrs(tin[x],0);
  rt[i]->rem(tin[x],tout[x]+1);
  x=p[x];
  while(x!=-1)
  {
    rt[i]->add(tin[cp[x]],tin[x]+1,-t);
    x=p[cp[x]];
  }
  return t;
}

int main()
{
    IOS();

    nds=new node[280*MAXn];

    ll T;
    cin>>T;
    while(T--&&cin>>n>>q)
    {
        //if(n>100)swt=0;
        //else swt=1;
        swt=1;


        ndptr=nds;
        rt[0]=build(0,MAXn);

        REP(i,n+1)v[i].clear();
        FILL(mxw,0);
        FILL(p,0);


        p[0]=-1;
        mxw[0]=INF;
        REP1(i,n)
        {
          ll f,w;
          cin>>f>>w;
          v[f].pb(i),p[i]=f;
          mxw[i]=w;
        }
        n++;
        szdfs(0);
        dfsit=-1;
        dt.clear();
        make_chain(0);

        rt[0]->clrdfs(mxw,dt,n);

        REP1(i,q)
        {
          ll st,tp;
          cin>>st>>tp;
          rt[i]=new node(rt[st]);
          if(tp==1)// grow
          {
            ll x,k;
            cin>>x>>k;
            ll tmpx=x;
            while(x!=-1)
            {
              rt[i]->add(tin[cp[x]],tin[x]+1,k);
              x=p[cp[x]];
            }
            //debug(i,rt[i]->mxw,rt[i]->wtg);
            x=tmpx;
            while(x!=-1)
            {
              ll t=rt[i]->qrbrk(tin[cp[x]],tin[x]+1,0);
              if(t!=-1){cout<<t<<endl;tsk2(t,i);break;}
              x=p[cp[x]];
              if(x==-1)cout<<0<<endl;
            }

          }
          else
          {
            ll x;
            cin>>x;
            cout<<tsk2(x,i)<<endl;
          }
        }


    }
}
