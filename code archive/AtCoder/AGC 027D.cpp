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


const ll MAXn=5e2+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll ispm[10000];
vector<ll> pm;
ll d[MAXn][MAXn];


ll lcm(vector<ll> v)
{
  ll res = 1;
  for(ll x:v)
  {
    ll g = __gcd(x,res);
    res = (res / g) * x;
  }
  return res;
}

int main()
{
    IOS();
    for(int i = 2;SZ(pm) < 1010;i++)
    {
      if(!ispm[i])pm.pb(i);
      for(int j = 0;pm[j] * i < 10000;j++)
      {
        ispm[pm[j] * i] = 1;
        if(i % pm[j] == 0)break;
      }
    }
    debug(pm.back());
    ll n;
    cin>>n;
    REP(i,n + 2)REP(j,n + 2)
    {
      if((i + j) % 2 != 0)continue;
      ll a = (i + j) / 2 ,b = (i + n + 1 - j) / 2 + n + 2 + 1;
      d[i][j] = pm[a] * pm[b];
      debug(i,j,a,b);
    }
    REP1(i,n)REP1(j,n)
    {
      if((i + j) % 2 == 0)continue;
      vector<ll> tmp;
      tmp.pb(d[i-1][j]);
      tmp.pb(d[i][j - 1]);
      tmp.pb(d[i+1][j]);
      tmp.pb(d[i][j + 1]);
      d[i][j] = lcm(tmp) + 1;
    }

    REP1(i,n)
    {
      REP1(j,n)cout<<d[i][j]<<" \n"[j==n];
    }

}
