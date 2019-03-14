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
template<typename _a> ostream &operator << (ostream &_s,multiset<_a> &_c){return _OUTC(_s,ALL(_c));}
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

namespace bit{
    const ll S = (1<<17);
    ll bit[S];
    void ins(ll x, ll k)
    {
        while(x < S)bit[x] += k, x += x & -x;
    }
    ll f(ll x){
        ll l = 0, len = (S>>1);
        while(len){
            if(bit[l + len] < x)x -= bit[l + len], l += len;
            len >>= 1;
        }
        return l + 1;
    }
    ll qr(ll x){
        ll ret = 0;
        while(x)ret += bit[x], x -= x & -x;
        return ret;
    }
};

namespace dsu{
    ll g[MAXn], sz[MAXn];
    void init(ll n){
        REP1(i,n)g[i] = i, sz[i] = 1;
    }
    ll f(ll x){
        return g[x] = (g[x] == x? x : f(g[x]));
    }
    void mg(ll a,ll b) // a is the new root
    {
        a = f(a), b = f(b);
        sz[a] += sz[b];
        g[b] = a;
    }
};

vector<ll> uni, dt;
ll d[MAXn], u[MAXn];
ll n, k, q;

multiset<ll> st[MAXn][2];

void mg(ll a,ll b)
{
    a = dsu::f(a), b = dsu::f(b);
    if(dsu::sz[a] < dsu::sz[b])swap(a,b);
    ll g = dsu::sz[a] + dsu::sz[b] - k + 1;
    vector<ll> v;
    for(ll x:st[b][1])v.pb(x), bit::ins(x, -1);
    for(ll x:st[b][0])v.pb(x);
    st[b][0].clear();st[b][1].clear();
    if(g <= 0)for(ll x:v)st[a][0].insert(x);
    else{
        while(SZ(st[a][1]) < g){
            if(!SZ(st[a][0]))break;
            st[a][1].insert(*st[a][0].begin());
            bit::ins(*st[a][0].begin(), 1);
            st[a][0].erase(st[a][0].begin());
        }
        for(ll x:v){
            if(SZ(st[a][1]) < g)st[a][1].insert(x), bit::ins(x, 1);
            else if((*st[a][1].rbegin()) > x){
                st[a][1].insert(x);
                bit::ins(x, 1);
                st[a][0].insert(*st[a][1].rbegin());
                bit::ins(*st[a][1].rbegin(), -1);
                st[a][1].erase(prev(st[a][1].end()));
            }
            else st[a][0].insert(x);
        }
    }
    dsu::mg(a, b);
}

int main()
{
    IOS();
    cin>>n>>k>>q;
    REP1(i,n)cin>>d[i], uni.pb(d[i]), dt.pb(i);
    sort(ALL(uni));
    uni.resize(unique(ALL(uni)) - uni.begin());
    REP1(i,n)d[i] = lower_bound(ALL(uni), d[i]) - uni.begin() + 1;
    sort(ALL(dt), [](int a,int b){return d[a] > d[b];});
    dsu::init(n);
    ll mn = INF;
    for(ll t:dt){
        u[t] = 1;
        if(k > 1)st[t][0].insert(d[t]);
        else st[t][1].insert(d[t]), bit::ins(d[t], 1);
        if(u[t-1])mg(t, t-1);
        if(u[t+1])mg(t, t+1);
        debug(t, st[dsu::f(t)][0], st[dsu::f(t)][1]);
        if(bit::qr(bit::S-1) >= q){
            ll a = bit::f(1);
            ll b = bit::f(q);
            mn = min(mn, uni[b-1] - uni[a-1]);
        }
    }
    cout<<mn<<endl;
}
