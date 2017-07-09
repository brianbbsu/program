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


const ll MAXn=3e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

struct node{
  ll l,r;
  node *lc,*rc;
  ll d,tt;
  node(ll li,ll ri,node *lci=0,node *rci=0):l(li),r(ri),lc(lci),rc(rci),d(0),tt(0){}
  void ins(ll li,ll ri,ll k)
  {
    if(li>=r||ri<=l)return;
    if(li<=l&&ri>=r)d+=k;
    else
    {
      lc->ins(li,ri,k),rc->ins(li,ri,k);
      tt=lc->tt+rc->tt+lc->d*(lc->r-lc->l)+rc->d*(rc->r-rc->l);
    }
  }
  ll qr(ll li,ll ri)
  {
    if(li>=r||ri<=l)return 0;
    else
    {
      ll rt=(min(ri,r)-max(li,l))*d;
      if(li<=l&&ri>=r)return rt+tt;
      else return rt+lc->qr(li,ri)+rc->qr(li,ri);
    }
  }
};
node *build(ll l,ll r)
{
  if(l==r-1)return new node(l,r);
  else return new node(l,r,build(l,(l+r)/2),build((l+r)/2,r));
}
node *rt=0;
struct tg{
  ll l,r,d,tp,id;
  tg(ll li,ll ri,ll di,ll tpi,ll idi):l(li),r(ri),d(di),tp(tpi),id(idi){}
  bool operator < (const tg &t){return d<t.d;}
};

ll ans[MAXn];
vector<tg> dt;
ll l[MAXn],r[MAXn],v[MAXn],d[MAXn];

int main()
{
    IOS();
    ll n,m;
    cin>>n>>m;
    REP(i,n)cin>>d[i+1];
    REP(i,m)cin>>l[i]>>r[i]>>v[i],l[i]--;
    ll q;
    cin>>q;
    REP(i,q)
    {
      ll l,r,L,R;
      cin>>l>>r>>L>>R;
      l--;L--;R--;
      if(L!=0)dt.pb(tg(l,r,L-1,-1,i));
      dt.pb(tg(l,r,R,1,i));
    }
    sort(ALL(dt));
    rt=build(0,n);
    partial_sum(d,d+n+1,d);
    //REP(i,n)rt->ins(i,i+1,d[i]);
    //debug(rt->qr(0,n));

    ll it=0;
    for(auto k:dt)debug(k.id);
    REP(i,m)
    {
      rt->ins(l[i],r[i],v[i]);
      while(it<SZ(dt)&&dt[it].d==i)ans[dt[it].id]+=dt[it].tp*rt->qr(dt[it].l,dt[it].r),it++;
      //REP(i,q)cout<<ans[i]<<endl;
    }
    for(auto k:dt)if(k.tp==1)ans[k.id]+=d[k.r]-d[k.l];
    REP(i,q)cout<<ans[i]<<endl;
}
