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
const ll INF=ll(1e15);

ll mypw(ll x,ll k)
{
    if(!k)return 1;
    ll a = mypw(x, k/2);
    a = a * a % MOD;
    if(k&1)return a * x % MOD;
    else return a;
}

void add(ll &a,ll b){
    a += b;
    if(a >= MOD)a -= MOD;
}
void sub(ll &a,ll b)
{
    a -= b;
    if(a < 0)a += MOD;
}

const ll C = 1000000000;

ll d[MAXn], mn[MAXn], dp[MAXn], pw[MAXn], inv[MAXn];
ll n, k;
deque<ii> dq;

ll cal(ll m, ll t)
{
    if(m <= 0 || t == C)return 1;
    pw[0] = inv[0] = 1;
    ll tmpinv = mypw(C - t, MOD-2);
    REP1(i, m + 1)pw[i] = pw[i-1] * (C - t) % MOD;
    REP1(i, m + 1)inv[i] = inv[i-1] * tmpinv % MOD;
    dp[0] = 1;
    ll tt = 0;
    add(tt, dp[0]);
    REP1(i, m+1)
    {
        if(i - k - 1 >= 0)
        {
            sub(tt, dp[i - k - 1] * inv[i - k - 1] % MOD);
        }
        dp[i] = tt * pw[i-1] % MOD;
        add(tt, dp[i] * inv[i] % MOD);
    }
    return dp[m+1];
}

int main()
{
    //IOS();
    _taskname = "tracking2";
    _init();
    cin>>n>>k;
    REP1(i, n - k + 1)cin>>d[i];
    REP1(i, n)
    {
        while(SZ(dq) && dq.front().X <= i)dq.pop_front();
        if(i <= n - k + 1)
        {
            while(SZ(dq) && dq.back().Y <= d[i])dq.pop_back();
            dq.pb(ii(i + k, d[i]));
        }
        mn[i] = dq.front().Y;
    }
    ll ans = 1;
    ll now = d[1], lst = 0;
    REP1(i, n - k + 1)
    {
        if(d[i] == now)continue;
        else if(d[i] > now)
        {
            ans = ans * cal(i - 2 - lst, now) % MOD;
            now = d[i], lst = i-1;
        }
        else
        {
            ll x = i + k - 1;
            ans = ans * cal(x - 1 - lst, now) % MOD;
            now = d[i], lst = x;
        }
    }
    ans = ans * cal(n - lst, now) % MOD;
    cout<<ans<<endl;
    _end();
}
