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

struct tg{
  ll a,b,sz,tt,id;
  tg(ll ai,ll bi,ll szi,ll tti,ll idi):a(ai),b(bi),sz(szi),tt(tti),id(idi){}
};

struct DSU
{
  ll g[MAXn],sz[MAXn];
  ll n,tt;
  vector<tg> his;
  void init(ll ni)
  {
    n=ni;
    tt=0;
    REP1(i,n)g[i]=i,sz[i]=1;
    his.clear();
  }
  ll fd(ll a){return (g[a]==a?a:fd(g[a]));}
  void mg(ll a,ll b,ll id)
  {
    a=fd(a),b=fd(b);
    if(a==b)return;
    if(sz[a]>sz[b])swap(a,b);
    his.pb(tg(a,b,sz[b],tt,id));
    tt+=2*sz[a]*sz[b];
    sz[b]+=sz[a];
    g[a]=b;
  }
  void rev(ll id)
  {
    while(SZ(his)&&his.back().id==id)
    {
      tg tmp=his.back();
      his.pop_back();
      tt=tmp.tt;
      g[tmp.a]=tmp.a;
      sz[tmp.b]=tmp.sz;
    }
  }
}dsu;

struct node{
  ll l,r;
  node *lc,*rc;
  vector<ii> dt;
  ll id;
  node(ll li,ll ri,ll idi,node *lci=0,node *rci=0):l(li),r(ri),lc(lci),rc(rci),dt(vector<ii>(0)),id(idi){}
  void ins(ll li,ll ri,ii di)
  {
    if(li>=r||ri<=l)return;
    else if(li<=l&&ri>=r)dt.pb(di);
    else lc->ins(li,ri,di),rc->ins(li,ri,di);
  }
  void go()
  {
    for(auto &tmp:dt)
    {
      dsu.mg(tmp.X,tmp.Y,id);
    }
    if(l==r-1)cout<<dsu.tt<<endl;
    else lc->go(),rc->go();
    dsu.rev(id);
  }
  void dbg()
  {
    debug(l,r,dt);
    if(l!=r-1)lc->dbg(),rc->dbg();
  }
};
ll nit=-1;
node *build(ll l,ll r)
{
  if(l==r-1)return new node(l,r,++nit);
  else return new node(l,r,++nit,build(l,(l+r)/2),build((l+r)/2,r));
}
node *rt=0;

map<ii,ll> mp;

int main()
{
    IOS();
    ll n,m;
    cin>>n>>m;
    rt=build(0,m);
    REP(i,m)
    {
      ll a,b;
      cin>>a>>b;
      if(a>b)swap(a,b);
      auto it=mp.insert(make_pair(ii(a,b),i));
      if(!it.Y)
      {
        rt->ins(it.X->Y,i,ii(a,b));
        mp.erase(it.X);
      }
    }
    for(auto it:mp)rt->ins(it.Y,m,it.X);
    rt->dbg();
    dsu.init(n);
    rt->go();
}
