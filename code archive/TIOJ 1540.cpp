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


const ll MAXn=2e3+5,MAXg=1e2+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

void add(ll &a,ll b)
{
  a+=b%MOD;
  if(a>=MOD)a-=MOD;
}

ll dt[MAXn];

void cal(ll n,ll k,ll g)
{
  ll bs[g+1][g+1],mat[2][g+1][g+1];
  FILL(bs,0);
  REP1(i,g)
  {
    bs[i][i]=2*i;
    if(i>1)bs[i][i-1]=i-1;
    if(i<g)bs[i][i+1]=i+1;
  }
  FILL(mat,0);
  REP1(i,g)mat[0][i][i]=1;
  bool fg=0;
  k--;
  for(int t = __lg(k);t>=0;t--)
  {
    fg=!fg;
    FILL(mat[fg],0);
    REP1(i,g)REP1(j,g)REP1(p,g)add(mat[fg][i][j],mat[!fg][i][p]*mat[!fg][p][j]);
    if((1<<t)&k)
    {
      fg=!fg;
      FILL(mat[fg],0);
      REP1(i,g)REP1(j,g)REP1(p,g)add(mat[fg][i][j],bs[i][p]*mat[!fg][p][j]);
    }
  }
  REP1(i,g)dt[i]=mat[fg][i][1];
}

int dp[MAXn][MAXn];
void calsm(ll n,ll k,ll g)
{
  REP1(i,k)REP1(j,g)
  {
    if(i==1&&j==1){dp[i][j]=1;continue;}
    dp[i][j]=((ll)2*j*dp[i-1][j]+(ll)dp[i-1][j-1]*(j-1)+(ll)dp[i-1][j+1]*(j+1))%MOD;
  }
  REP1(i,g)dt[i]=dp[k][i];
}

ll inv[MAXn];

int main()
{
    IOS();

    inv[MAXn-1]=230247071;
    for(ll i=MAXn-2;i>=0;i--)inv[i]=inv[i+1]*(i+1)%MOD;

    ll n,k,g;
    cin>>n>>k>>g;
    k=min(k,n-1);
    if(n<=2000)calsm(n,k,g);
    else cal(n,k,g);

    debug(inv[0],inv[1],inv[2]);

    ll tt=0,fac=1;
    REP1(i,g)
    {
      if(n<i+k)break;
      tt=(tt+fac*inv[i-1]%MOD*dt[i])%MOD;
      fac = fac*(n-k-i)%MOD;
    }
    tt = tt*n%MOD;
    cout<<tt<<endl;
}
