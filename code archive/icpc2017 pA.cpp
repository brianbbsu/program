//{
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
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


const ll MAXn=2e2+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

struct frac{
  ll a, b;
  frac(ll ai,ll bi):a(ai), b(bi){}
  frac(ll ai):a(ai), b(1){}
  frac():a(0), b(1){}
};
ii operator - (ii a, ii b){return ii(a.X - b.X, a.Y - b.Y);}
ll cros(ii a, ii b){return a.X * b.Y - b.X * a.Y;}
ll sign(ll x){return x < 0 ? -1 : (x > 0);}
bool operator < (frac a, frac b){
  if(a.b < 0)a.a = -a.a, a.b = -a.b;
  if(b.b < 0)b.a = -b.a, b.b = -b.b;
  return __int128(a.a) * __int128(b.b) < __int128(b.a) * __int128(a.b);
}
bool operator <= (frac a, frac b){
  if(a.b < 0)a.a = -a.a, a.b = -a.b;
  if(b.b < 0)b.a = -b.a, b.b = -b.b;
  return __int128(a.a) * __int128(b.b) <= __int128(b.a) * __int128(a.b);
}
bool operator > (frac a, frac b){return b < a;}
bool operator >= (frac a, frac b){return b <= a;}

#ifdef brian
  ostream & operator << (ostream &_s, frac _p){return _s<<make_pair(_p.a, _p.b);}
#endif

ii d[MAXn];
ll n;

ld chk(ii a, ii b)
{
  frac mxneg = -INF, mnpos = INF;
  REP1(i,n)
  {
    if(cros(b - a, d[i + 1] - d[i]) == 0)continue;
    ll a1 = (b.X - a.X), b1 = -(d[i + 1].X - d[i].X), c1 = (d[i].X - a.X);
    ll a2 = (b.Y - a.Y), b2 = -(d[i + 1].Y - d[i].Y), c2 = (d[i].Y - a.Y);
    frac p = frac(c1 * b2 - c2 * b1, a1 * b2 - a2 * b1), q = frac(c2 * a1 - c1 * a2, a1 * b2 - a2 * b1);
    if(!(q > 0 && q < 1))continue;
    if(p > 0 && p < 1)return 0;
    else if(p <= 0 && p > mxneg)mxneg = p;
    else if(p >= 1 && p < mnpos)mnpos = p;
    debug(i, d[i], d[i + 1], p, q);
  }
  REP1(i, n)
  {
    if(cros(b - a, d[i] - a) != 0)continue;
    if(sign(cros(b - a, d[i-1] - d[i])) * sign(cros(b-a, d[i+1] - d[i])) < 0 || cros(d[i] - d[i - 1], d[i + 1] - d[i]) >= 0)
    {
      frac t;
      if(b.X != a.X)t = frac(d[i].X - a.X,b.X - a.X);
      else t = frac(d[i].Y - a.Y,b.Y - a.Y);
      if(t > 0 && t < 1)return 0;
      else if(t <= 0 && t > mxneg)mxneg = t;
      else if(t >= 1 && t < mnpos)mnpos = t;
    }
  }
  ld x1 = a.X + ld(b.X - a.X) / ld(mxneg.b) * ld(mxneg.a);
  ld x2 = a.X + ld(b.X - a.X) / ld(mnpos.b) * ld(mnpos.a);
  ld y1 = a.Y + ld(b.Y - a.Y) / ld(mxneg.b) * ld(mxneg.a);
  ld y2 = a.Y + ld(b.Y - a.Y) / ld(mnpos.b) * ld(mnpos.a);

  ld ans = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
  debug(a, b, x1, y1, x2, y2, ans);
  return ans;
}

int main()
{
  IOS();
  cin>>n;
  REP1(i, n)cin>>d[i].X>>d[i].Y;
  d[n + 1] = d[1];
  d[0] = d[n];
  ld ans = 0;
  for(int i = 1;i <= n;i ++)for(int j = 1;j < i;j ++)
  {
    if(cros(d[i] - d[i-1], d[i + 1] - d[i]) >= 0 && (cros(d[i] - d[i-1], d[j] - d[i]) < 0 || cros(d[i + 1] - d[i], d[j] - d[i]) < 0))continue;
    else if(cros(d[i] - d[i-1], d[i + 1] - d[i]) < 0 && !(cros(d[i] - d[i-1], d[j] - d[i]) >= 0 || cros(d[i + 1] - d[i], d[j] - d[i]) >= 0))continue;
    ans = max(ans, chk(d[i], d[j]));
  }
  cout<<fixed<<setprecision(12)<<ans<<endl;
}
