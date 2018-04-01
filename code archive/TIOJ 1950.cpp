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
const ll INF=ll(1e15);

struct node{
  int d,pri;
  node *lc,*rc,*p;
  int sz;
};

inline int gsz(node *a){return a?a->sz:0;}
void pull(node *a)
{
  if(!a)return;
  a->sz=gsz(a->lc)+gsz(a->rc)+1;
  //debug(a->d,gsz(a));
  a->p = 0;
  if(a->lc)a->lc->p = a;
  if(a->rc)a->rc->p = a;
}

node *mg(node *a,node *b)
{
  //debug(gsz(a),gsz(b),(a?a->d:0),(b?b->d:0));
  if(!a||!b)return a?a:b;
  if(a->pri>b->pri){
    a->rc=mg(a->rc,b);
    pull(a);
    //debug(gsz(a));
    return a;
  }
  b->lc=mg(a,b->lc);
  pull(b);
  //debug(gsz(b));
  return b;
}

void split(node *a,node *&b,node *&c,ll k)//k to left, k+1... to right
{
  if(!a)b=c=0;
  else if(gsz(a->lc)>=k)
  {
    c=a;
    split(a->lc,b,c->lc,k);
    pull(c);
  }
  else
  {
    b=a;
    split(a->rc,b->rc,c,k-1-gsz(a->lc));
    pull(b);
  }
}

pair<node*,int> gst(node *a)
{
  ll tt=0;
  tt+=gsz(a->lc);
  while(a->p)
  {
    //debug(a->d);
    if(a->p->rc == a)tt+=gsz(a->p->lc)+1;
    a=a->p;
  }
  return {a,tt};
}

node *nd[MAXn];
ll d[MAXn],vis[MAXn];

int main()
{
    IOS();
    srand(880301);
    ll n,m;
    cin>>n>>m;
    REP1(i,n)
    {
      cin>>d[i];
      nd[i] = new node{i,rand(),0,0,0,1};
    }
    ll ans=n;
    REP1(i,n)if(!vis[i])
    {
      vis[i]=1;
      node *ptr = nd[i];
      ll now = d[i];
      while(!vis[now])
      {
        //debug(i,now);
        vis[now] = 1;
        //debug(gsz(ptr),gsz(nd[now]));
        ptr = mg(ptr,nd[now]);
        now = d[now];
      }
      ans--;
    }
    cout<<ans<<endl;

    while(m--)
    {
      ll a,b;
      cin>>a>>b;
      auto dta = gst(nd[a]),dtb = gst(nd[b]);
      if(dta.X == dtb.X)
      {
        if(dta.Y> dtb.Y)swap(a,b),swap(dta,dtb);
        ans--;
        node *x,*y,*z,*tmp;
        split(dta.X,x,tmp,dta.Y);
        //debug("spl");
        split(tmp,y,z,dtb.Y-dta.Y);
        //debug("spr");
        mg(x,z);
        //debug("mg");
      }
      else
      {
        node *x,*y,*xx,*yy;
        split(dta.X,x,y,dta.Y);
        //debug("spa");
        split(dtb.X,xx,yy,dtb.Y);
        //debug("spb");
        //debug(gsz(x),gsz(y),gsz(xx),gsz(yy));
        x = mg(mg(x,yy),mg(xx,y));
        //debug("mg");
        //debug(gsz(x));
        ans++;
      }
      //REP1(i,n)debug(i,nd[i]->p ? 1: 0);
      cout<<ans<<endl;
    }
}
