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

const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e17);


vector<ll> pat[MAXn];
ll mp[MAXn], C;
ll h[MAXn][10];
ll v[MAXn][10];
ll tth[MAXn], ttv[MAXn];

vector<ii> dv[MAXn], dh[MAXn];

ll g[20];
ll f(ll x){return g[x] = (g[x] == x?x:f(g[x]));}
bool mg(ll a,ll b)
{
    a = f(a), b = f(b);
    if(a == b)return 0;
    else return g[a] = b, 1;
}

ii dp[2][200];

ii operator + (ii a, ll b)
{
    a.X += b;
    return a;
}

void add(ll &a,ll b)
{
    a += b;
    if(a >= MOD)a -= MOD;
}

void add(ii &a, ii b)
{
    if(a.X < b.X)return;
    else if(a.X > b.X)a = b;
    else add(a.Y, b.Y);
}

int main()
{
    //IOS();
    _taskname = "escape";
    _init();
    ll n, k;
    cin>>n>>k;

    {
        ll tt= 1;
        REP(i,k)tt *= k;
        debug(tt);
        REP(I, tt)
        {
            vector<ll> tmp;
            ll t = I;
            REP(i, k)tmp.pb(t % k), t /= k;
            bool ok = 1;
            REP(i, k)if(tmp[i] > i)ok = 0;
            REP(i,k)for(int j = i - 1;j >= tmp[i];j --)if(tmp[j] < tmp[i])ok = 0;
            if(ok)
            {
                pat[C] = tmp;
                mp[I] = C;
                C ++;
            }
        }
        debug(C);
    }

    REP(p, C)REP(H, (1<<(k-1)))
    {
        REP(i,k)g[i] = pat[p][i];
        bool ok = 1;
        REP(i, k-1)if(((1<<i) & H) && !mg(i, i + 1))ok = 0;
        if(ok)
        {
            vector<ll> tmp(k);
            REP(i, k)REP(j, k)if(f(i) == f(j)){
                tmp[i] = j;
                break;
            }
            ll tt = 0;
            for(int i = 0, I = 1;i < k;i ++, I *= k)tt += I * tmp[i];
            dh[p].pb({H, mp[tt]});
        }
    }
    REP(p, C)REP(V, (1<<k))
    {
        REP(i,k)g[i] = pat[p][i];
        REP(i,k)g[i + k] = i + k;
        bool ok = 1;
        REP(i, k)if(((1<<i) & V) && !mg(i, i + k))ok = 0;
        REP(i, k)
        {
            bool tmp = 0;
            REP(j,k)if(f(i) == f(j + k))tmp = 1;
            if(!tmp)ok = 0;
        }
        if(ok)
        {
            vector<ll> tmp(k);
            REP(i, k)REP(j, k)if(f(i+k) == f(j+k)){
                tmp[i] = j;
                break;
            }
            ll tt = 0;
            for(int i = 0, I = 1;i < k;i ++, I *= k)tt += I * tmp[i];
            dv[p].pb({V, mp[tt]});
        }
    }
    {
        ll ttv = 0, tth = 0;
        REP(i, C)ttv += SZ(dv[i]), tth += SZ(dh[i]);
        debug(ttv, tth);
    }
    REP(i, n)REP(j, k-1)cin>>h[i][j];
    REP(i, k)REP(j, n-1)cin>>v[j][i];

    bool fg = 0;

    REP(i, C)dp[fg][i] = ii(INF, 0);
    
    ll st = 0;
    for(int i = 0, I = 1;i < k;i ++, I *= k)st += I * i;
    dp[fg][mp[st]] = ii(0, 1);
    
    REP(i, n)
    {
        fg = !fg;
        REP(I, C)dp[fg][I] = ii(INF, 0);
        REP(J, (1<<(k-1))){
            tth[J] = 0;
            REP(j, k-1)if((1<<j) & J)tth[J] += h[i][j];
        }
        REP(I, C)for(auto &p:dh[I])
        {
            ll tt = 0;
            add(dp[fg][p.Y], dp[!fg][I] + tth[p.X]);
        }
        if(i == n-1)continue;
        fg = !fg;
        REP(I, C)dp[fg][I] = ii(INF, 0);
        REP(J, (1<<(k))){
            ttv[J] = 0;
            REP(j, k)if((1<<j) & J)ttv[J] += v[i][j];
        }
        REP(I, C)for(auto &p:dv[I])
        {
            ll tt = 0;
            add(dp[fg][p.Y], dp[!fg][I] + ttv[p.X]);
        }
    }
    debug(dp[fg][0]);
    cout<<dp[fg][0].Y<<endl;

    _end();
}
