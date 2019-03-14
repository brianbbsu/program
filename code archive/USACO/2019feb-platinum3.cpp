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

const ll MAXn=1e6+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e9);

ii d[MAXn];
ll dp[MAXn], ct[MAXn], bit[MAXn], pi[MAXn];

void ins(ll x,ll k)
{
    while(x < MAXn)bit[x] = max(bit[x], k), x += x & -x;
}
ll qr(ll x)
{
    ll ret = 0;
    while(x > 0)ret = max(ret, bit[x]), x -= x & -x;
    return ret;
}

vector<ll> dt[MAXn];

ll cal(ll i, ll j)
{
    return dp[j] + (d[i].X - d[j].X) * (d[i].Y - d[j].Y);
}

int main()
{
    //IOS();
    _taskname = "mowing";
    _init();
    ll n, T;
    cin>>n>>T;
    REP1(i,n)cin>>d[i].X>>d[i].Y;
    sort(d+1, d+1+n);
    d[n+1] = ii(T, T);
    ct[0] = 1;
    dt[0].pb(0);
    REP1(i,n+1)
    {
        ct[i] = qr(d[i].Y) + 1;
        dp[i] = d[i].X * d[i].Y;
        auto &v = dt[ct[i]-1];
        ll p = 0;
        if(SZ(dt[ct[i]]))p = pi[dt[ct[i]].back()];
        ll bst = 0;
        for(ll j = SZ(v)-1;j >= 0 && d[v[j]].Y < d[i].Y;j --)
        {
            ll c = cal(i, v[j]);
            if(c < dp[i])
            {
                bst = j;
                dp[i] = c;
            }
        }
        pi[i] = bst;
        dt[ct[i]].pb(i);
        debug(i, d[i], ct[i], dp[i]);
        ins(d[i].Y, ct[i]);
    }
    cout<<dp[n+1]<<endl;
    _end();
}
