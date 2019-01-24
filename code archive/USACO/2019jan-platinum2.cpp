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

const ll MAXn=2e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

vector<ll> v[MAXn];
vector<ii> e;
ll dph[MAXn], p[MAXn][MAXlg], st[MAXn][MAXlg], dp[MAXn];

void dfs1(ll now,ll f)
{
    p[now][0] = f;
    for(ll k:v[now])if(k != f)
    {
        dph[k] = dph[now] + 1;
        dfs1(k, now);
    }
}

void dfs2(ll now,ll f)
{
    for(ll k:v[now])if(k != f)
    {
        dfs2(k, now);
        dp[now] += dp[k];
    }
    st[now][0] = dp[now];
}

ii lca(ll a,ll b)
{
    ll tt = 0;
    if(dph[a] < dph[b])swap(a, b);
    for(int j = MAXlg-1;j >= 0;j --)if(dph[p[a][j]] >= dph[b])tt += st[a][j], a = p[a][j];
    if(a == b)return ii(a, tt);
    for(int j = MAXlg-1;j >= 0;j --)if(p[a][j] != p[b][j])tt += st[a][j] + st[b][j], a = p[a][j], b = p[b][j];
    return ii(p[a][0], tt + st[a][0] + st[b][0]);
}

ll la(ll a,ll k)
{
    for(int j = MAXlg-1;j >= 0;j --)if((1<<j) <= k)k -= (1<<j), a = p[a][j];
    return a;
}

ll tt = 0;

ll mp1[MAXn];
map<ii, ll> mp2;

int main()
{
    _taskname = "exercise";
    _init();
    ll n, m;
    cin>>n>>m;
    REP(i, n-1)
    {
        ll a,b;
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    REP(i, m-(n-1))
    {
        ll a,b;
        cin>>a>>b;
        e.pb(ii(a,b));
    }
    dph[1] = 0;
    dfs1(1, 1);
    REP1(j, MAXlg-1)REP1(i, n)p[i][j] = p[p[i][j-1]][j-1];
    for(auto tmp:e)
    {
        ll c = lca(tmp.X, tmp.Y).X;
        if(c == tmp.X)tmp.Y = la(tmp.Y, dph[tmp.Y] - dph[c] - 1), dp[tmp.Y]++, tt -= mp1[tmp.Y], mp1[tmp.Y]++;
        else if(c == tmp.Y)tmp.X = la(tmp.X, dph[tmp.X] - dph[c] - 1), dp[tmp.X]++, tt -= mp1[tmp.X], mp1[tmp.X]++;
        else
        {
            tmp.X = la(tmp.X, dph[tmp.X] - dph[c] - 1);
            tmp.Y = la(tmp.Y, dph[tmp.Y] - dph[c] - 1);
            tt -= mp1[tmp.X], mp1[tmp.X]++;
            tt -= mp1[tmp.Y], mp1[tmp.Y]++;
            dp[tmp.X]++;
            dp[tmp.Y]++;
            if(tmp.X > tmp.Y)swap(tmp.X, tmp.Y);
            tt -= mp2[tmp];
            mp2[tmp]++;
        }
    }
    REP1(i, n)st[i][0] = dp[i];
    REP1(j, MAXlg-1)REP1(i, n)st[i][j] = st[i][j-1] + st[p[i][j-1]][j-1];
    for(auto tmp:e)
    {
        ii c = lca(tmp.X, tmp.Y);
        if(tmp.X == c.X || tmp.Y == c.X)c.Y -= 1;
        else c.Y -= 2;
        tt += c.Y;
    }
    cout<<tt<<endl;
    _end();
}
