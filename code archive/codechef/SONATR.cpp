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


const ll MAXn=5e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

namespace seg{
    const int N = (1<<19);
    int tg[N<<1][2], tt[N<<1][3];
    void calc(int x){
        tt[x][0] = tt[x][1] = tt[x][2] = 0;
        if(tg[x][0])return;
        else if(x&N){
            if(tg[x][1] <= 2)tt[x][tg[x][1]] = 1;
        }else{
            for(int i = 0;i + tg[x][1] <= 2;i ++)tt[x][i + tg[x][1]] = tt[x<<1][i] + tt[x<<1|1][i];
        }
    }
    void build(int n){
        for(int i = N + n - 1;i > 1;i--)calc(i);
    }
    void upd(int x){
        for(x += N;x > 0;x>>=1)calc(x);
    }
    void ins(int l, int r, int tp, int k)
    {
        debug(l, r, tp, k);
        int ll = l, rr = r;
        for(l += N, r += N;l < r;l>>=1, r>>=1){
            if(l&1)tg[l][tp] += k, calc(l++);
            if(r&1)tg[--r][tp] += k, calc(r);
        }
        if(rr - ll > 0)upd(ll), upd(rr-1);
    }
};

ll n, q;
vector<ll> v[MAXn], cdt;
ll d[MAXn], mp[MAXn];

void dfs(ll now,ll f)
{
    cdt.pb(now);
    for(ll k:v[now])if(k != f)dfs(k, now);
}

void update(int x, int k)
{
    if(x < 0 || x >= n)return;
    vector<ll> v;
    v.pb(d[x]);
    if(x - 1 >= 0)v.pb(d[x-1]);
    if(x + 1 < n)v.pb(d[x+1]);
    v.pb(n);
    sort(ALL(v));
    ll it = 0;
    for(int i = 0;i < SZ(v);i++)if(v[i] == d[x])it = i;

    if(it == 0)seg::ins(v[0], v[1], 0, k);
    if(it <= 1 && SZ(v) > 2)seg::ins(v[1], v[2], 1, k);
}

int main()
{
    IOS();
    // input
    cin>>n;
    REP1(i,n)cin>>d[i];
    REP1(i,n-1){
        ll a, b;
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    cin>>q;

    // chain
    REP1(i,n)if(SZ(v[i]) == 1){
        dfs(i, -1);
        break;
    }
    assert(SZ(cdt) == n);
    REP(i, n)mp[cdt[i]] = i;
    vector<ll> tmpd;
    REP(i,n)tmpd.pb(d[cdt[i]]);
    FILL(d, -1);
    REP(i,n)d[i] = tmpd[i];

    REP(i,n)debug(i, d[i]);

    // initial
    seg::build(n);
    REP(i,n)update(i, 1);
    debug(seg::tt[1][2]);

    // query
    while(q--)
    {
        ll a, b;
        cin>>a>>b;
        a = mp[a];b = mp[b];
        REP(i,3)update(a+i-1, -1);
        ll c = d[a];
        d[a] = d[b];
        REP(i,3)update(a+i-1, 1);
        REP(i,3)update(b+i-1, -1);
        d[b] = c;
        REP(i,3)update(b+i-1, 1);
        cout<<seg::tt[1][2] + 1<<endl;
    }
}
