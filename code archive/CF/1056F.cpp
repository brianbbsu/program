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


const ll MAXn=1e2+5,MAXc = 1e3+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e17);
const lf eps = 1e-6;

//ll a[MAXn],p[MAXn];
lf dp[MAXn][MAXc];
lf pw[MAXn];
vector<ii> d;
int main()
{
    IOS();
    pw[0] = 1;
    REP1(i,MAXn-1)pw[i] = pw[i-1] * 0.90000000;
    ll T;
    cin>>T;
    while(T--)
    {
        ll n;
        lf c,t;
        cin>>n>>c>>t;
        d.clear();
        REP(i,n)
        {
            ll a,p;
            cin>>a>>p;
            d.pb(ii(a,p));
        }
        sort(ALL(d),greater<ii>());
        REP(i,MAXn)REP(j,MAXc)dp[i][j] = INF;
        dp[0][0] = 0;
        ll mxc = 0;
        REP(i,n)
        {
            for(int j = i;j >= 0; j --)REP(k,mxc+1)dp[j+1][k + d[i].Y] = min(dp[j+1][k + d[i].Y],dp[j][k] + d[i].X / pw[j+1]);
            mxc += d[i].Y;
        }
        debug(dp[2][20]);
        ll mx = 0;
        REP1(i,n)REP(j,mxc+1)if(dp[i][j] < INF)
        {
            lf aa = -c, bb = (-1 + t * c - 10 * c * i), cc = (t - 10 * i - dp[i][j]);
            lf D = bb * bb - 4 * aa * cc;
            if(D < 0)continue;
            D = sqrt(D);
            if((-bb - D)/(2*aa) > -eps)
            {
                lf tmp = (-bb - D)/(2*aa);
                debug(tmp,tmp + 10 * i + dp[i][j] / (1 + c * tmp),i,j,dp[i][j]);
                mx = max(mx,j);
            }
        }
        cout<<mx<<endl;
    }
}
