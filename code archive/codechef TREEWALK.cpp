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


const ll MAXn=3e3+5,MAXlg=__lg(MAXn)+2;
const ll MOD=998244353;
const ll INF=ll(1e15);

vector<ll> v[MAXn];

int main()
{
    IOS();
    ll n,rt,k;
    cin>>n;
    REP(i,n-1)
    {
      ll a,b;
      cin>>a>>b;
      v[a].pb(b);
      v[b].pb(a);
    }
    cin>>rt>>k;
    if(k <= 3000)
    {
      ll dp[MAXn][MAXn];
      FILL(dp,0);
      dp[rt][0] = 1;
      REP1(i,k)REP1(j,n)
      {
        for(ll t:v[j])dp[j][i] += dp[t][i-1];
        dp[j][i] %= MOD;
      }
      REP1(i,n)cout<<dp[i][k]<<" ";
      cout<<endl;
    }
    else
    {
      ll dp[2][MAXn],mat[2][MAXn][MAXn];
      ll dpfg = 0,matfg = 0;
      FILL(dp,0);
      FILL(mat,0);
      dp[0][rt] = 1;
      REP1(i,n)for(ll t:v[i])mat[0][i][t] = 1;
      while(k)
      {
        if(k & 1)
        {
          dpfg = !dpfg;
          FILL(dp[dpfg],0);
          REP1(i,n)REP1(j,n)dp[dpfg][i] += dp[!dpfg][j] * mat[matfg][j][i] % MOD;
          REP1(i,n)dp[dpfg][i] %= MOD;
        }
        matfg = !matfg;
        FILL(mat[matfg],0);
        REP1(i,n)REP1(j,n)REP1(t,n)mat[matfg][i][j] += mat[!matfg][i][t] * mat[!matfg][t][j] % MOD;
        REP1(i,n)REP1(j,n)mat[matfg][i][j] %= MOD;
        k /= 2;
      }
      REP1(i,n)cout<<dp[dpfg][i]<<" ";
    }
}
