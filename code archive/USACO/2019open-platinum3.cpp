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

const ll MAXn=1e3+5,MAXg = 6e5 + 5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll h[MAXn][MAXn], u[MAXn][MAXn], g[MAXg], sz[MAXg], e[MAXg], s[MAXg];
vector<ii> dt;

ll f(ll x){return g[x] = (g[x] == x?x:f(g[x]));}
void mg(ll a,ll b)
{
    a = f(a), b = f(b);
    if(a == b)return;
    if(sz[a] > sz[b])swap(a, b);
    sz[b] += sz[a];
    e[b] += e[a];
    s[b] += s[a];
    g[a] = b;
}

ll n;
ll dx[] = {-1, 1, 0, 0};
ll dy[] = {0, 0, 1, -1};

bool val(ll x,ll y)
{
    return x > 0 && x <= n && y > 0 && y <= n;
}

ll issq(ll x,ll y)
{
    ll ct = 0;
    REP(i, 2)REP(j,2)if(val(x + i, y + j) && u[x + i][y + j])ct++;
    return ct == 4;
}

inline ll hs(ii p){return (p.X - 1) * n + p.Y - 1;}
inline ll hs(ll x,ll y){return hs(ii(x, y));}

int main()
{
    //IOS();
    _taskname = "valleys";
    _init();
    cin>>n;
    REP1(i,n)REP1(j,n)cin>>h[i][j];
    REP1(i,n)REP1(j,n)dt.pb(ii(i,j));
    sort(ALL(dt), [](ii a, ii b){return h[a.X][a.Y] < h[b.X][b.Y];});
    REP1(i,n)REP1(j,n){
        ll t = hs(i, j);
        sz[t] = 1;
        g[t] = t;
    }
    ll tt = 0;
    for(ii p:dt)
    {
        u[p.X][p.Y] = 1;
        ll t = hs(p);
        REP(i, 4)
        {
            ll x = p.X + dx[i], y = p.Y + dy[i];
            if(val(x, y) && u[x][y])mg(t, hs(x, y)), e[f(t)]++;
        }
        REP(i, 2)REP(j,2)if(issq(p.X - i, p.Y - j))s[f(t)]++;
        debug(p, e[f(t)], sz[f(t)], s[f(t)]);
        if(e[f(t)] - sz[f(t)] + 2 == s[f(t)] + 1)tt += sz[f(t)];
    }
    cout<<tt<<endl;
    _end();
}
