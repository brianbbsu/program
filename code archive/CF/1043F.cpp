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


const ll MAXn=3e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll pw(ll x,ll k)
{
    if(!k)return 1;
    ll a = pw(x,k/2);
    a = a * a % MOD;
    if(k&1)return a * x % MOD;
    else return a;
}


ll d[MAXn],ct[MAXn],fac[MAXn],inv[MAXn];
ll dp[MAXn];

ll c(ll a,ll b)
{
    if(b > a)return 0;
    return fac[a] * inv[b] % MOD * inv[a-b] % MOD;
}

int main()
{
    IOS();
    fac[0] = 1;
    REP1(i,MAXn-1)fac[i] = fac[i-1] * i % MOD;
    REP(i,MAXn)inv[i] = pw(fac[i],MOD-2);

    ll n;
    cin>>n;
    ll gc = 0;
    REP(i,n)
    {
        ll x;
        cin>>x;
        d[x] = 1;
    }
    REP1(i,MAXn-1)
    {
        for(ll k = 1;k * i < MAXn;k++)ct[i] += d[k * i];
    }
    REP1(t,10)
    {
        FILL(dp,0);
        for(int i = MAXn-1;i>=1;i--)
        {
            dp[i] = c(ct[i],t);
            for(int k = 2;k * i < MAXn;k++)
            {
                dp[i] = dp[i] - dp[i * k];
                if(dp[i] < 0)dp[i] += MOD;
            }
        }
        if(dp[1] != 0)
        {
            cout<<t<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
}
