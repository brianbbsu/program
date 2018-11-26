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

ll d[MAXn],g[2][MAXn],dt[2][MAXn],dp[2][MAXn],ct[2][MAXn],ord[MAXn];
vector<ll> v[2][MAXn],h;

void dfs(ll now,ll f,ll t)
{
    debug(now,f,t,dp[t][now]);
    if(dt[t][now] != -1)h.pb(now);
    debug(h);
    g[t][now] = h.back();
    for(ll k:v[t][now])if(k != f)
    {
        dfs(k,now,t);
        dp[t][now] += dp[t][k];
    }
    if(dt[t][now] != -1)
    {
        dt[t][now] -= dp[t][now],dp[t][now] += dt[t][now];
        if(dt[t][now] < 0)
        {
            cout<<-1<<endl;
            exit(0);
        }
    }
    if(h.back() == now)h.pop_back();
}

int main()
{
    IOS();
    ll n,x,y;
    cin>>n>>x>>y;
    REP1(i,n)cin>>d[i];
    FILL(dt,-1);
    REP(j,2)REP(i,n-1)
    {
        ll a,b;
        cin>>a>>b;
        v[j][a].pb(b);
        v[j][b].pb(a);
    }
    REP(j,2)
    {
        ll t;
        cin>>t;
        while(t--)
        {
            ll k,x;
            cin>>k>>x;
            dt[j][k] = x;
        }
    }
    dfs(x,-1,0);
    dfs(y,-1,1);
    bool ok = 1;
    REP(i,n)ord[i] = i+1;
    sort(ord,ord+n,[&](int a,int b){return d[a] > d[b];});
    ll tt = 0;
    REP(i,n)
    {
        ll t = ord[i];
        if(ct[0][g[0][t]] < dt[0][g[0][t]] && ct[1][g[1][t]] < dt[1][g[1][t]])
        {
            debug(t);
            tt += d[t];
            ct[0][g[0][t]]++;
            ct[1][g[1][t]]++;
        }
    }
    REP1(i,n)REP(j,2)if(ct[j][g[j][i]] != dt[j][g[j][i]])ok = 0;
    if(!ok)cout<<-1<<endl;
    else cout<<tt<<endl;
    
}
