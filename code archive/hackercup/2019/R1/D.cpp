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
#else
#define debug(...)
#define pary(...)
#endif // brian
//}

#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);

const ll MAXn=8e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

void input(int n, ll *dt)
{
    cin>>dt[1]>>dt[2];
    ll a, b, c, d;
    cin>>a>>b>>c>>d;
    for(int i = 3;i <= n;i ++)dt[i] = (dt[i - 2] * a + dt[i - 1] * b + c) % d + 1;
}

namespace bit{
    const ll N = (1<<20);
    ll bit[N];
    void ins(ll x,ll k)
    {
        while(x < N)bit[x] += k, x += x & -x;
    }
    ll fd(ll x)
    {
        ll l = 0, len = (1<<19);
        while(len > 0)
        {
            if(bit[l + len] < x)x -= bit[l + len], l += len;
            len >>= 1;
        }
        return l + 1;
    }
};

ll x[MAXn], y[MAXn], dt[MAXn];

int main()
{
    IOS();
    ll T;
    cin>>T;
    ll kz = 0;
    while(T--)
    {
        kz ++;
        cout<<"Case #"<<kz<<": ";
        ll n, h, v;
        cin>>n>>h>>v;
        input(n, x);
        input(n, y);
        if(h + v < n)
        {
            cout<<-1<<endl;
            continue;
        }
        ll ans = INF;
        vector<ll> ux, uy;
        REP1(i, n)ux.pb(x[i]), uy.pb(y[i]);
        sort(ALL(ux)), sort(ALL(uy));
        REP1(i, n)x[i] = lower_bound(ALL(ux), x[i]) - ux.begin() + 1;
        REP1(i, n)y[i] = lower_bound(ALL(uy), y[i]) - uy.begin() + 1;
        if(v == n)ans = min(uy.back(), ans);
        if(h == n)ans = min(ux.back(), ans);

        FILL(bit::bit, 0);
        REP1(i, n)bit::ins(x[i], 1);

        ll mx = 0;
        REP(i, n)dt[i] = i + 1;
        sort(dt, dt + n, [](int a,int b){return y[a] > y[b];});
        for(int i = 0;i <= h && i < n;i ++)
        {
            if(n - i <= v)ans = min(ans, mx + uy[y[dt[i]] - 1]);
            else
            {
                ll t = bit::fd(n - i - v);
                ans = min(ans, max(mx, ux[t - 1]) + uy[y[dt[i]] - 1]);
            }
            bit::ins(x[dt[i]], -1);
            mx = max(mx, ux[x[dt[i]] - 1]);
        }

        cout<<ans<<endl;
    }
}
