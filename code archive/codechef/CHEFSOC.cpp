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


const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll d[MAXn], dp[MAXn], f[MAXn];

void add(ll &a, ll b){
    a += b;
    if(a >= MOD)a -= MOD;
}

int main()
{
    IOS();
    ll T;
    cin>>T;
    while(T--)
    {
        ll n, tt = 1;
        FILL(dp, 0);
        cin>>n;
        REP(i,n)cin>>d[i];
        f[n] = n-1;
        for(int i = n-1;i >= 0;i --)if(d[i] == 2)f[i] = f[i+1];else f[i] = i-1;
        dp[0] = 1;
        for(int i = 1;i < n;i ++)
        {
            add(dp[i], dp[i-1]);
            if(i > 1 && d[i-2] == 2)add(dp[i], dp[i-2]);
            if(i > 2 && d[i-2] == 2 && d[i-3] == 2)add(dp[i], dp[i-3]);
            add(tt, dp[i]);
            if(d[i-1] == 2 && i != n-1)
            {
                ll ct = f[i+1] - i;
                ll a = ct / 2;
                if(i + a * 2 == n-1)a--;
                add(tt, dp[i-1] * (a + 1) % MOD);
            }
            if(d[i-1] == 2 && i < n-2)
            {
                ll ct = f[i+1] - i;
                ll a = ct / 2;
                if(i + a * 2 + 2 >= n || d[i + a * 2 + 2] != 2)a--;
                add(tt, dp[i-1] * (a + 1) % MOD);
            }
            debug(i, dp[i]);
        }
        cout<<tt<<endl;
    }
}
