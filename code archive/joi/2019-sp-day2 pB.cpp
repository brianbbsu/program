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


const ll MAXn=2e3+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e17);

ll A[MAXn], B[MAXn], S[MAXn], T[MAXn], P[MAXn], Q[MAXn];

//ll dp[MAXn][MAXn];

ll dp[MAXn];

int main()
{
    IOS();
    ll n, m;
    cin>>n>>m;
    REP1(i,n)cin>>A[i]>>S[i]>>P[i];
    REP1(i,m)cin>>B[i]>>T[i]>>Q[i];
    REP1(i,n)A[i] += A[i-1];
    REP1(i,m)B[i] += B[i-1];
    REP1(i,n)S[i] -= A[i];
    REP1(i,m)T[i] -= B[i];

    REP1(i,m)dp[i] = -i;

    REP1(i,n)
    {
        
    }

    REP(i, n+1)REP(j, m+1)
    {
        if(i || j)dp[i][j] = -INF;
        if(i)dp[i][j] = max(dp[i][j], dp[i-1][j] + (B[j] <= S[i]));
        if(j)dp[i][j] = max(dp[i][j], dp[i][j-1] + (A[i] <= T[j]));
    }
    cout<<dp[n][m]<<endl;
}
