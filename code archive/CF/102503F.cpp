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

ii p(ll x){
    ll t = (ll)sqrtl((long double)x - 0.5) & (~1LL);
    x -= t * t;
    t /= 2;
    if(x <= t)return {-t - 1, t + 1 - x};
    else x -= t;

    if(x <= 2 * t + 1)return {-t - 1 + max(0LL, x - t - 1), - min(x, t + 1)};
    else x -= 2 * t + 1;

    if(x <= 2 * t + 1)return {min(x, t + 1), -t - 1 + max(0LL, x - t - 1)};
    else x -= 2 * t + 1;

    if(x <= 2 * t + 1)return {t + 1 - max(0LL, x - t - 1), min(x, t + 1)};
    else x -= 2 * t + 1;
    
    assert(x <= t + 1);
    return {-x, t + 1};
}

ll d(ll i, ll j){
    debug(i, j);
    ll t = max(abs(i), abs(j)) - 1;
    ll x = 4 * t * t + 1;
    
    if(i == -t - 1 && j <= t && j > 0)return x + t - j;
    else x += t;

    if(i < 0 && j < 0)return x + abs(-(t + 1) - i) + abs(-1 - j);
    else x += 2 * t + 1;

    if(i > 0 && j < 0)return x + abs(1 - i) + abs(-(t + 1) - j);
    else x += 2 * t + 1;

    if(i > 0 && j > 0)return x + abs(t + 1 - i) + abs(1 - j);
    else x += 2 * t + 1;

    assert(j == t + 1 && i < 0);
    return x + abs(-1 - i);
}

inline bool in(ii x, ii a, ii b){ // x in square ab
    return max(abs(x.X - a.X), abs(x.X - b.X)) <= abs(a.X - b.X) && 
               max(abs(x.Y - a.Y), abs(x.Y - b.Y)) <= abs(a.Y - b.Y);
}

void add(ll &a, ll b){
    a = (a + b) % MOD;
}

int main()
{
    IOS();
    ll T;
    cin >> T;
    while(T--){
        ll a, b;
        cin >> a >> b;
        if(a > b)swap(a, b);
        auto pa = p(a), pb = p(b);
        ll tt = 0;
        for(ll i = min(pa.X, pb.X), g1 = max(pa.X, pb.X);i <= g1;i ++)
            for(ll j = min(pa.Y, pb.Y), g2 = max(pa.Y, pb.Y);j <= g2;j ++)
                if(i != 0 && j != 0)
                    add(tt, d(i, j));
        cout << tt << endl;
    }
}
