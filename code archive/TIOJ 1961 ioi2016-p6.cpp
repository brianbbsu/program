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

vector<ii> d,tmpd;
ll dp[2][MAXn];
deque<int> dq;
ll a[MAXn],b[MAXn];


ll take_photos(int n, int m, int k, vector<int> r, vector<int> c)
{
  d.clear();
  tmpd.clear();
  FILL(dp,0);

  REP(i,n)tmpd.pb(ii(min(r[i],c[i]),-max(r[i],c[i])));
  sort(ALL(tmpd));
  ll lt=-1;
  d.pb(ii(-1,-1));
  for(ii &tmp:tmpd)if(-tmp.Y>lt)lt=-tmp.Y,d.pb(ii(tmp.X,-tmp.Y));
  debug(d);
  n=SZ(d)-1;
  k=min(k,n);

  bool fg=0;
  REP1(i,n)dp[0][i]=INF;
  REP(t,k)
  {
    REP(i,n+1)debug(t,i,dp[fg][i]);
    fg=!fg;
    while(SZ(dq))dq.pop_front();
    REP1(i,n)
    {
      a[i-1]=-2*d[i].X;b[i-1]=dp[!fg][i-1]+d[i].X*d[i].X-2*d[i].X-max(0LL,(d[i-1].Y-d[i].X+1))*max(0LL,(d[i-1].Y-d[i].X+1));
      while(SZ(dq)>=2&&(b[i-1]-b[dq[SZ(dq)-2]])*(a[dq[SZ(dq)-2]]-a[dq[SZ(dq)-1]])<=
                       (b[dq[SZ(dq)-1]]-b[dq[SZ(dq)-2]])*(a[dq[SZ(dq)-2]]-a[i-1]))dq.pop_back();
      dq.pb(i-1);
      ll x=d[i].Y;
      while(SZ(dq)>=2&&a[dq[1]]*x+b[dq[1]]<=a[dq[0]]*x+b[dq[0]])dq.pop_front();

      dp[fg][i]=a[dq[0]]*x+b[dq[0]]+(x+1)*(x+1);
    }
  }
  REP(i,n+1)debug(k,i,dp[fg][i]);
  return dp[fg][n];
}

#ifdef brian
int main()
{
    IOS();
    vector<int> _r={0,4,4,4,4};
    vector<int> _c={3,4,6,5,6};
    int _n=5,_m=7,_k=2;
    ll _rs=take_photos(_n,_m,_k,_r,_c);
    debug(_rs);
}
#endif
