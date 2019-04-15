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


const ll MAXn=2e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

struct edge{
    ll t, c, r;
};

ll s[MAXn], dp[MAXn][20][2];
vector<edge> v[MAXn];

const ll K = 16;
ll n, q;

void smax(ll &a,ll b)
{
    a = max(a, b);
}

void predfs(ll now, ll p)
{
    for(auto &e:v[now])if(e.t != p)
    {
        predfs(e.t, now);
        s[now] += e.r + s[e.t];
    }
}

void dfs(ll now,ll p)
{
    dp[now][1][0] = dp[now][1][1] = 
    dp[now][0] = 0;
    dp[now][1] = s[now] + 
    dp[now][0] = tps + s[now];
    for(auto &e:v[now])if(e.t != p)
    {
        dfs(e.t, now, tps + s[now] - (s[e.t] + e.r) + e.c);
    }
}

int main()
{
    IOS();
    ll n, q, tt = 0;
    cin>>n;
    REP(i, n-1)
    {
        ll a, b, C, D;
        cin>>a>>b>>C>>D;
        v[a].pb({b, C, D});
        v[b].pb({a, D, C});
        tt += C + D;
    }
    predfs(1, -1);
    dfs(1, -1, 0);
    REP1(i,n)debug(i, s[i], dp[i]);
    ll mx = 0;
    REP1(i,n)mx = max(mx, dp[i]);
    debug(mx);
    cout<<tt - mx<<endl;

}
