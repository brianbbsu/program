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

string _taskname;
void _init()
{
  #ifndef brian
      freopen((_taskname+".in").c_str(), "r", stdin);
      freopen((_taskname+".out").c_str(),"w",stdout);
  #endif
}
void _end()
{
  #ifndef brian
      fclose( stdin);
      fclose(stdout);
  #endif
}

const ll MAXn=3e3+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e9);

vector<ii> v[MAXn];
ll n, m, x, y, dis[MAXn], vis[MAXn], g;
vector<vector<ll>> dt;
ii d[MAXn][MAXn], dp[2][MAXn];
vector<pair<ll, ii> > dv[MAXn];

void dfs1(ll now,ll f)
{
    dt[g].pb(now);
    vis[now] = 1;
    for(ii k:v[now])if(k.X != f){
        dfs1(k.X, now);
    }
}

void dfs2(ll now,ll f)
{
    for(ii k:v[now])if(k.X != f)
    {
        dis[k.X] = dis[now] + k.Y;
        dfs2(k.X, now);
    }
}

void add(ll &a,ll b){
    a += b;
    if(a >= MOD){
        a -= MOD;
    }
}

int main()
{
    //IOS();
    _taskname = "mooriokart";
    _init();
    cin>>n>>m>>x>>y;
    REP(i,m)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        v[a].pb(ii(b, c));
        v[b].pb(ii(a, c));
    }
    REP1(i,n)if(!vis[i])
    {
        dt.pb(vector<ll>());
        dfs1(i, -1);
        g++;
    }
    y = max(y - g * x, ll(0));
    REP(i, g)
    {
        REP(j, SZ(dt[i]))
        {
            dis[dt[i][j]] = 0;
            dfs2(dt[i][j], -1);
            REP(k, j)
            {
                ll t = dis[dt[i][k]];
                d[i][min(y, t)].X ++;
                add(d[i][min(y, t)].Y, t);
            }
        }
        REP(j, y + 1)if(d[i][j].X)dv[i].pb({j, d[i][j]});
    }
    debug(g);
    REP(i, g)debug(i, dv[i]);
    dp[0][0] = ii(1, 0);
    bool fg = 0;
    REP(i, g)
    {
        fg = !fg;
        for(int j = 0;j <= y;j ++)dp[fg][j] = ii(0,0);
        for(int j = 0;j <= y;j ++)
        {
            for(auto p:dv[i])
            {
                ll tg = min(p.X + j, y);
                ll ct = (p.Y.X * dp[!fg][j].X) % MOD;
                ll tt = (p.Y.X * dp[!fg][j].Y + p.Y.Y * dp[!fg][j].X) % MOD;
                add(dp[fg][tg].X, ct);
                add(dp[fg][tg].Y, tt);
            }
        }
        REP(j, y+1)debug(i, j, dp[fg][j]);
    }
    add(dp[fg][y].Y, dp[fg][y].X * g % MOD * x % MOD);
    debug(dp[fg][y]);
    ll tt = dp[fg][y].Y;
    REP1(i, g-1)tt = tt * 2 * i % MOD;
    cout<<tt<<endl;
    _end();
}
