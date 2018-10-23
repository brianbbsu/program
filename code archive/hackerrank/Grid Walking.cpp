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


const ll MAXn=1e1+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

const ll MAXm=3e2+5,MAXd=1e2+5;

ll dp[MAXn][MAXm][MAXd],s[MAXn][MAXm];
ll a[MAXn][MAXm];
ll d[MAXn];

ll c[MAXm][MAXm];


int main()
{
    IOS();
    ll T;
    cin>>T;
    ll n,m;
    REP(i,MAXm)
    {
      c[i][0]=c[i][i]=1;
      REP1(j,i-1)c[i][j]=(c[i-1][j]+c[i-1][j-1])%MOD;
    }
    while(T--&&cin>>n>>m)
    {
      FILL(dp,0);
      FILL(a,0);
      FILL(s,0);
      REP(i,n)
      {
        ll t;
        cin>>t;
        dp[i][0][t]=1;
        s[i][0]=1;
      }
      REP(i,n)cin>>d[i];
      REP(i,n)
      {
        REP1(j,m)
        {
          REP1(k,d[i])
          {
            if(k!=1)dp[i][j][k]=dp[i][j-1][k-1];
            if(k!=d[i])dp[i][j][k]=(dp[i][j][k]+dp[i][j-1][k+1])%MOD;
            s[i][j]=(s[i][j]+dp[i][j][k])%MOD;
          }
          debug(i,j,s[i][j]);
        }
      }

      REP(i,n+1)a[i][0]=1;
      REP1(i,n)REP1(j,m)
      {
        REP(k,j+1)
        {
          //debug(j,k,c[j][k]);
          a[i][j]=(a[i][j]+((s[i-1][j-k]*c[j][k])%MOD)*a[i-1][k])%MOD;
          debug(i,j,k,a[i][j]);
        }

      }
      cout<<a[n][m]<<endl;
    }
}
