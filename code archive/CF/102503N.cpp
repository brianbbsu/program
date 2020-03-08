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


const ll MAXn=1e5+5,MAXlg=30 + 1;
const ll MOD=1000000007;
const ll INF=ll(1e15);

struct val{
    ll ct, s;  
};

void add(val &a, val b, ll v){
    a.ct += b.ct;
    a.s += b.s + b.ct * v;
}

val dp[MAXlg][MAXlg][2]; // dp[0][i][0] => answer of i bits

val caldp(ll x, val *dto){
    x ++;
    ll lg = __lg(x);
    for(int i = 0;i <= lg + 1;i++)
        for(int j = 0;j <= lg + 1;j ++)
            dp[i][j][0] = dp[i][j][1] = {0, 0};
    dp[lg + 1][0][1] = {1, 0};
    for(int i = lg;i >= 0;i --)
        for(int j = 0;j <= lg;j ++){
            add(dp[i][j][0], dp[i + 1][j][0], 0);
            add(dp[i][j + 1][0], dp[i + 1][j][0], (1LL<<i));
            if(x & (1LL<<i)){
                add(dp[i][j][0], dp[i + 1][j][1], 0);
                add(dp[i][j + 1][1], dp[i + 1][j][1], (1LL<<i));
            }
            else add(dp[i][j][1], dp[i + 1][j][1], 0);
        }
    for(int i = 0;i <= lg + 1;i ++)
        dto[i] = dp[0][i][0];
}

ll c[MAXlg][MAXlg];

ll findk(ll x, ll k){
    if(k == 0)return 0;
    ll tt = 0, cur = 0;
    for(int i = 29;i >= 0;i --){
        if(i == 0)cur += x, tt += cur;
        else{
            ll t = c[i][x];
            if(t < k){
                k -= t;
                tt += cur * t;
                tt += ((1<<i) - 1) * c[i - 1][x - 1];
                cur += (1<<i);
                x --;
            }
        }
    }
    return tt;
}

val dpl[MAXlg], dpr[MAXlg];

ll cal(ll x){ // sum of first x smallest
    if(x == 0)return 0;
    ll tt = 0;
    for(int i = 0;i < 30;i ++){
        if(dpr[i].ct - dpl[i].ct < x)
            x -= dpr[i].ct - dpl[i].ct, tt += dpr[i].s - dpl[i].s;
        else{
            tt += findk(i, x + dpl[i].ct) - findk(i, dpl[i].ct);
            return tt;
        }
    }
    return tt;
}

int main()
{
    IOS();
    c[0][0] = 1;
    for(int i = 1;i <= 29;i ++)
        for(int j = 0;j <= i;j ++)
            if(j == 0 || j == i)c[i][j] = 1;
            else c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
    ll T;
    cin >> T;
    while(T--)
    {
        ll l, r, a, b;
        cin >> l >> r >> a >> b;
        swap(a, b);
        a = (r - l + 2) - a;
        b = (r - l + 2) - b;
        l --;r --;
        memset(dpl, 0, sizeof(dpl));
        memset(dpr, 0, sizeof(dpr));
        if(l != 0)caldp(l - 1, dpl);
        caldp(r, dpr);
        ll ca = cal(a - 1);
        ll cb = cal(b);
        cout << cb - ca + (b - a + 1) << endl;
    }
}
