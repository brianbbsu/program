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

ll pw(ll x, ll k){
    if(!k)return 1;
    ll a = pw(x, k / 2);
    a = a * a % MOD;
    if(k & 1)return a * x % MOD;
    else return a;
}

void add(ll &a, ll b){
    a += b;
    if(a >= MOD)
        a -= MOD;
}

ll d[MAXn], fac[MAXn], invfac[MAXn];

ll c(ll a, ll b){
    return fac[a] * invfac[b] % MOD * invfac[a - b] % MOD;
}
ll p(ll a, ll b){
    return fac[a] * invfac[a - b] % MOD;
}

int main()
{
    IOS();
    fac[0] = 1;
    for(int i = 1;i < MAXn;i ++)
        fac[i] = fac[i - 1] * i % MOD;
    for(int i = 0;i < MAXn;i ++)
        invfac[i] = pw(fac[i], MOD - 2);
    ll T;
    cin >> T;
    while(T--)
    {
        int n, k;
        cin >> n >> k;
        for(int i = 1;i <= n;i++)
            cin >> d[i];
        sort(d + 1, d + 1 + n, greater<int>());
        ll cur = 0, it = 0, tt = 0, ttct = 1, lt = -1, ltct = 0, llct = 0;
        for(int i = 1;i <= n;i ++){
            it ++;
            add(tt, cur * d[i] % MOD);
            if(d[i] != lt){
                ttct = ttct * invfac[ltct] % MOD;
                ltct = 1;
                lt = d[i];
            }
            else ltct ++;
            if(it == k){
                ttct = ttct * fac[k] % MOD;
                ttct = ttct * invfac[ltct] % MOD;
                it = 0;
                cur ++;
                lt = -1;
                ltct = 0;
            }
            if(d[i] != d[i - 1])
                ttct = ttct * fac[llct] % MOD, llct = 1;
            else
                llct ++;
        }
        if(it != 0)
            ttct = ttct * p(k, it) % MOD;
        if(ltct != 0)
            ttct = ttct * invfac[ltct] % MOD;
        ttct = ttct * fac[llct] % MOD;
        cout << tt << " " << ttct << endl;
    }
}
