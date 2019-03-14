//{
#include<bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
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


const ll MAXn=2e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

inline char readchar()
{
    static const size_t bufsize = 65536;
    static char buf[bufsize];
    static char *p = buf, *end = buf;
    if (p == end) end = buf + fread_unlocked(buf, 1, bufsize, stdin), p = buf;
    return *p++;
}

template <class T> void input(T& a)
{
    static char p;
    while ((p = readchar()) < '0') ;
    a = p ^ '0';
    while ((p = readchar()) >= '0') a *= 10, a += p ^ '0';
}

ll xpow[MAXn], tx;

ll pw(ll x,ll k){
    ll ret = 1, it = 0, p = x;
    if(x == tx){
        for(;(1<<it) <= k;it++)if(k & (1<<it))ret = ret * xpow[it] % MOD;
    }
    else{
        for(;(1<<it) <= k;it++, p = p * p % MOD)if(k & (1<<it))ret = ret * p % MOD;
    } 
    debug(x, k, ret);
    return ret;
}

const ll K = 30, P = 500;

ll txw[MAXn];

inline ll cal(ll x, ll &xa, ll t, ll w, ll h){
    ll ret = 0;
    if(h <= K){
        ll xw;
        if(w <= P)xw = txw[w];
        else xw = pw(x, w);
        REP(i, h){
            ret = (ret + (xw - 1) * xa % MOD * t) % MOD;
            xa = xa * xw % MOD;
            t ++;
        }
    }else{
        ll xw, xwh;
        if(w <= P)xw = txw[w];
        else xw = pw(x, w);
        if(w*h <= P)xwh = txw[w * h];
        else xwh = pw(x, w * h);
        ll pa = (t - 1 - pw(xw - 1, MOD-2) + h) * (xwh-1);
        ret = (pa + h) % MOD;
        ret = ret * xa % MOD;
        xa = xa * xwh % MOD;
    }
    if(ret < 0)ret += MOD;
    if(xa < 0)xa += MOD;
    return ret;
}

vector<int> v[MAXn], dt, lv[MAXn];
int dph[MAXn], ct[MAXn], in[MAXn], out[MAXn], tit, suf[MAXn];

void predfs(ll now,ll f)
{
    in[now] = tit++;
    lv[dph[now]].pb(in[now]);
    for(ll k:v[now])if(k != f)
    {
        dph[k] = dph[now] + 1;
        predfs(k, now);
    }
    out[now] = tit;
}

ll chdd[MAXn];
vector<int> chddd[MAXn];
ll chd(ll a, ll l){
    debug(a, l, in[a], out[a],  lv[l]);
    return lower_bound(ALL(lv[l]), out[a]) - lower_bound(ALL(lv[l]), in[a]);
}

int main()
{
    //IOS();
    debug(chrono::system_clock::now().time_since_epoch().count());
    srand(chrono::system_clock::now().time_since_epoch().count());
    ll fg = rand() % 2;
    int T;
    input(T);
    while(T--)
    {
        int n, q;
        input(n);
        input(q);
        // == clear start ==
        ll lst = 0;
        int mx = 0;
        FILL(ct, 0);
        dph[0] = 0;
        REP1(i,n)v[i].clear();
        REP(i,n)lv[i].clear();
        tit = 0;
        // == clear end ==

        REP(i,n-1)
        {
            int a, b;
            input(a);
            input(b);
            v[a].pb(b);
            v[b].pb(a);
        }
        predfs(1, -1);
        REP1(i,n)mx = max(mx, dph[i]);

        vector<ll> pt;
        for(int i = 0;i <= mx; i++)if(SZ(lv[i]) != SZ(lv[i+1]))pt.pb(i+1);

        if(fg){
            REP(i,n)chddd[i].clear();
            REP(i,SZ(pt))chddd[i].resize(n+1);

            REP(i, SZ(pt)){
                memset(suf, 0, sizeof(int) * (n+1));
                REP(j, SZ(lv[pt[i]]))suf[lv[pt[i]][j]]++;
                for(int j = n-1;j >= 0;j--)suf[j] += suf[j+1];
                REP1(j,n)chddd[i][j] = suf[in[j]] - suf[out[j]];
            }
        }

        if(!fg){
            while(q--)
            {
                ll v, x;
                input(v);
                input(x);
                v ^= lst;x ^= lst;
                txw[0] = 1;
                REP1(i, P)txw[i] = txw[i-1] * x % MOD;
                for(ll i = 0, t = x;i <= 50;i++, t = t * t % MOD)xpow[i] = t;
                tx = x;
                ll a = 1, invx = pw((x-1+MOD)%MOD, MOD-2), l = dph[v], tt = 0;
                for(ll it:pt)chdd[it] = chd(v, it);
                chdd[l] = chd(v, l);

                ll it = upper_bound(ALL(pt), l) - pt.begin(); 
        
                while(l != mx+1){
                    ll w = chdd[l];
                    while(chdd[pt[it]] == w)it++;
                    if(x == 1)tt = (tt + (2 * (l-dph[v]) + pt[it] - l - 1) * (pt[it] - l) / 2 * w) % MOD;
                    else tt = (tt + cal(x, a, l - dph[v], w, pt[it] - l)) % MOD;
                    l = pt[it];
                }
                if(x != 1)tt = tt * invx % MOD;
                if(tt < 0)tt += MOD;
                printf("%d\n", (int)tt);
                lst = tt;
            }
        }else{
            while(q--)
            {
                ll v, x;
                input(v);
                input(x);
                v ^= lst;x ^= lst;
                txw[0] = 1;
                REP1(i, P)txw[i] = txw[i-1] * x % MOD;
                for(ll i = 0, t = x;i <= 50;i++, t = t * t % MOD)xpow[i] = t;
                tx = x;
                ll a = 1, invx = pw((x-1+MOD)%MOD, MOD-2), l = dph[v], tt = 0;
                ll it = upper_bound(ALL(pt), l) - pt.begin(); 
                ll nw = chd(v, l);
        
                while(l != mx+1){
                    ll w = nw;
                    debug(v, x, w);
                    while(chddd[it][v] == w)it++;
                    if(x == 1)tt = (tt + (2 * (l-dph[v]) + pt[it] - l - 1) * (pt[it] - l) / 2 * w) % MOD;
                    else tt = (tt + cal(x, a, l - dph[v], w, pt[it] - l)) % MOD;
                    l = pt[it];
                    nw = chddd[it][v];
                }
                if(x != 1)tt = tt * invx % MOD;
                if(tt < 0)tt += MOD;
                printf("%d\n", (int)tt);
                lst = tt;
            }
        }

    }
}
