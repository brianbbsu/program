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


ll n,q;
ll bit[MAXn];
void add(int x,int k)
{
  while(x<=n)bit[x]+=k,x+=x&-x;
}
ll qr(ll x)
{
  ll rt=0;
  while(x>0)rt+=bit[x],x-=x&-x;
  return rt;
}
vector<ii> dt;
struct tg{
  ll  l,r,id,x,t;
  tg(ll li,ll ri,ll idi,ll xi,ll ti):l(li),r(ri),id(idi),x(xi),t(ti){};
};
vector<tg> qrs;
vector<ll> qrid;
ll ans[MAXn*10];

int main()
{
    IOS();
    cin>>n>>q;
    REP(i,n)
    {
      ll t;
      cin>>t;
      dt.pb(ii(t,i+1));
    }
    sort(ALL(dt));
    REP(i,q)
    {
      ll l,r,a,b;
      cin>>l>>r>>a>>b;
      qrs.pb(tg(l-1,r,i,a-1,-1));
      qrs.pb(tg(l-1,r,i,b,1));
      qrid.pb(2*i);
      qrid.pb(2*i+1);
    }
    sort(ALL(qrid),[](int a,int b){return qrs[a].x<qrs[b].x;});
    ll dit=0,qrit=0;
    REP(i,n+1)
    {
      while(dit<n&&dt[dit].X<=i)add(dt[dit++].Y,1);
      while(qrit<SZ(qrs)&&qrs[qrid[qrit]].x<=i)
      {
        ans[qrs[qrid[qrit]].id]+=qrs[qrid[qrit]].t*(qr(qrs[qrid[qrit]].r)-qr(qrs[qrid[qrit]].l));
        qrit++;
      }
      debug(123);
    }
    REP(i,q)cout<<ans[i]<<endl;

}
