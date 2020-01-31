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
const ll INF=ll(1e15);

ll e[105][105];
ll d[MAXn], dg[MAXn], ct = 0, tp[MAXn], dph[MAXn], vis[MAXn];

ll g[MAXn];
ll f(ll x){return g[x] = (g[x] == x ? x : f(g[x]));}
void mg(ll a,ll b)
{
    g[f(a)] = f(b);
}

vector<ll> v[MAXn];

void add(ll i, ll k)
{
    dg[i] += k;
    if(dg[i] & 1)ct ++;
    else ct --;
}

void add_edge(ll a,ll b)
{
    e[a][b] = e[b][a] = 1;
    v[a].pb(b);
    v[b].pb(a);
    add(a, 1);add(b, 1);
}

void dfs(ll now,ll f)
{
    tp[now] = dph[now];
    vis[now] = 1;
    for(ll k:v[now])if(k != f)
    {
        if(vis[k])tp[now] = min(tp[now], dph[k]);
        else
        {
            dph[k] = dph[now] + 1;
            dfs(k, now);
            tp[now] = min(tp[now], tp[k]);
        }
    }
}


ll n, m;

void rm(ll i,ll j)
{
    v[i].erase(lower_bound(ALL(v[i]), j));
    v[j].erase(lower_bound(ALL(v[j]), i));
}

bool chkp(ll a,ll b)
{
    return (a == b && ct == 0) || (a != b && ct == 2 && (dg[b] & 1) && (dg[a] & 1));
}

bool sm(ll a,ll b,ll x, ll y)
{
    return (a == x && b == y) || (a == y && b == x);
}

vector<ll> go(ll a,ll b)
{
    vector<ll> dt;
    ll now = a;
    dt.pb(now);
    debug(now, dg[now]);
    while(dg[now])
    {
        debug(now);
        REP1(i, n)debug(v[i]);
        for(ll t:v[now])
        {
            add(now, -1);
            add(t, -1);
            REP1(i, n)g[i] = i;
            REP1(i, n)for(ll p:v[i])
            {
                if(p > i)break;
                if(!sm(i, p, now, t))mg(i, p);
            }
            bool fg = chkp(t, b);
            ll gct = 0;
            REP1(i, n)if(dg[i] > 0 && f(i) == i)gct ++;
            if(gct >= 2)fg = 0;
            if(fg)
            {
                rm(now, t);
                now = t;
                dt.pb(now);
                break;
            }
            add(now, 1);
            add(t, 1);
        }
    }
    return dt;
}

int main()
{
    IOS();
    cin>>n>>m;
    REP(i, m + 1)cin>>d[i];
    for(int i = m;i > 0;i --)
    {
        add_edge(d[i - 1], d[i]);
        ll a = d[i - 1];

        dph[a] = 0;
        REP1(j, n)vis[i] = 0;
        dfs(a, -1);
        
        for(int j = d[i] + 1;j <= n;j ++)if(e[d[i - 1]][j] && tp[j] == 0)
        {
            add(d[i - 1], -1);
            add(j, -1);
            if(chkp(j, d[0]))
            {
                // start j, end d[0]
                debug(i, j);
                REP1(k, n)sort(ALL(v[k]));
                rm(d[i - 1], j);
                auto dt = go(j, d[0]);
                debug(dt);
                for(int k = 0;k < i;k ++)cout<<d[k]<<" ";
                for(auto t:dt)cout<<t<<" ";
                cout<<endl;
                return 0;
            }
            add(d[i - 1], 1);
            add(j, 1);
        }
    }
    cout<<"No solution"<<endl;
}
