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

ll dp[MAXn][2],d[MAXn][2];

void qt()
{
    cout<<"NO"<<endl;
    exit(0);
}

ll n,k;
ll cal_s(ll t,ll a,ll b)// a -> 1,b -> 0
{
    // 0xt 0..0 1...1 ........ 0...?
    if(t > k)return INF;
    if(a > b * k)return INF;
    if(max(0LL,b - (k-t)) > a * k)return INF;
    return max(1LL,max(0LL,b - (k-1)) - (a-1) * k);
}
ll cal_d(ll t,ll a,ll b)// a -> 1,b -> 0
{
    // 0xt 0..0 1...1 ........ 1...? 
    if(t > k)return INF;
    if(a > (b+1) * k)return INF;
    if(max(0LL,b - (k - t)) > (a-1) * k)return INF;
    if(b > a)return 1;
    else return max(1LL,a - b * k);
}

int main()
{
    IOS();
    cin>>n>>k;
    REP1(i,n)cin>>d[i][0];
    REP1(i,n)cin>>d[i][1];
    REP1(i,n)
    {
        dp[i][0] = min(cal_s(dp[i-1][0],d[i][1],d[i][0]),cal_d(dp[i-1][1],d[i][0],d[i][1]));
        dp[i][1] = min(cal_d(dp[i-1][0],d[i][1],d[i][0]),cal_s(dp[i-1][1],d[i][0],d[i][1]));
    }
    if(dp[n][0] > k && dp[n][1] > k)qt();
    cout<<"YES"<<endl;
}
