//{
#include<bits/stdc++.h>
using namespace std;
typedef int ll;
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


const ll MAXn=4e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

template<typename T>
ll POS(vector<T> &v, T x){
    return lower_bound(ALL(v), x) - v.begin();
}
template<typename T>
void makeuni(vector<T> &v){
    sort(ALL(v));
    v.resize(unique(ALL(v)) - v.begin());
}

namespace bit{
    int N;
    ll bit[MAXn];
    void init(int n)
    {
        N = n;
        REP1(i, n)bit[i] = 0;
    }
    void ins(ll x, ll k)
    {
        while(x <= N)bit[x] += k, x += x & -x;
    }
    ll qr(ll x)
    {
        ll ret = 0;
        while(x)ret += bit[x], x -= x & -x;
        return ret;
    }
};

ll n, d[MAXn];

namespace p1{
    vector<ll> uni;
    ll tmpd[MAXn], ans[MAXn];
    void solve(){
        REP1(i,n)uni.pb(d[i] - i);
        makeuni(uni);
        REP1(i,n)tmpd[i] = POS(uni, d[i] - i) + 1;
        REP1(i,n)debug(i, tmpd[i]);
        bit::init(n);
        REP1(i,n)ans[i] += bit::qr(tmpd[i] - 1), bit::ins(tmpd[i], 1);
        uni.clear();
        REP1(i,n)uni.pb(d[i] + i);
        makeuni(uni);
        REP1(i,n)tmpd[i] = POS(uni, d[i] + i) + 1;
        bit::init(n);
        for(int i = n;i > 0;i --)ans[i] += bit::qr(tmpd[i] - 1), bit::ins(tmpd[i], 1);
        REP1(i,n)debug(i, tmpd[i]);
        REP1(i,n)cout<<ans[i] + 1<<endl;
    }
}

namespace p2{
    vector<ll> uni;
    vector<ii> dt[MAXn];
    ll tmpd[MAXn], ans[MAXn], tmptt[MAXn];
    void solve(){
        // no slope
        uni.clear();
        REP1(i,n)tmpd[i] = d[i], uni.pb(tmpd[i]);
        makeuni(uni);
        REP1(i,n)tmpd[i] = POS(uni, tmpd[i]) + 1;
        bit::init(n);
        REP1(i,n)bit::ins(tmpd[i], 1);
        REP1(i,n)ans[i] = max(ans[i], bit::qr(tmpd[i] - 1));
        pary(ans+1, ans+1+n);
        // slope to left
        uni.clear();
        REP1(i,n)tmpd[i] = d[i] + i, uni.pb(tmpd[i]);
        makeuni(uni);
        REP1(i,n)tmpd[i] = POS(uni, tmpd[i]) + 1;
        bit::init(n);
        REP1(i,n)bit::ins(tmpd[i], 1);
        REP1(i,n)ans[i] = max(ans[i], bit::qr(tmpd[i] - 1));
        pary(ans+1, ans+1+n);
        // slope to right
        uni.clear();
        REP1(i,n)tmpd[i] = d[i] - i, uni.pb(tmpd[i]);
        makeuni(uni);
        REP1(i,n)tmpd[i] = POS(uni, tmpd[i]) + 1;
        bit::init(n);
        REP1(i,n)bit::ins(tmpd[i], 1);
        REP1(i,n)ans[i] = max(ans[i], bit::qr(tmpd[i] - 1));
        pary(ans+1, ans+1+n);
        // peak
        FILL(tmptt, 0);

            // slope to left
            uni.clear();
            REP1(i,n)tmpd[i] = d[i] + i, uni.pb(tmpd[i]);
            makeuni(uni);
            REP1(i,n)tmpd[i] = POS(uni, tmpd[i]) + 1;
            bit::init(n);
            REP1(i,n)dt[i].clear();
            REP1(i,n){
                if(i - 1 <= n - i)dt[i].pb(ii(i, 1));
                else dt[i - (n-i) - 1].pb(ii(i, -1)), dt[i].pb(ii(i, 1));
            }
            REP1(i,n){
                bit::ins(tmpd[i], 1);
                for(ii p:dt[i])tmptt[p.X] += p.Y * bit::qr(tmpd[p.X] - 1);
            }
            pary(tmptt + 1, tmptt + 1 + n);
            //slope to right
            uni.clear();
            REP1(i,n)tmpd[i] = d[i] - i, uni.pb(tmpd[i]);
            makeuni(uni);
            REP1(i,n)tmpd[i] = POS(uni, tmpd[i]) + 1;
            bit::init(n);
            REP1(i,n)dt[i].clear();
            REP1(i,n){
                if(i - 1 <= n - i)dt[i - 1].pb(ii(i, -1)), dt[2 * i - 1].pb(ii(i, 1));
                else dt[i - 1].pb(ii(i, -1)), dt[n].pb(ii(i, 1));
            }
            REP1(i,n){
                bit::ins(tmpd[i], 1);
                for(ii p:dt[i])tmptt[p.X] += p.Y * bit::qr(tmpd[p.X] - 1);
            }
            pary(tmptt + 1, tmptt + 1 + n);

            //no slope
            uni.clear();
            REP1(i,n)tmpd[i] = d[i], uni.pb(tmpd[i]);
            makeuni(uni);
            REP1(i,n)tmpd[i] = POS(uni, tmpd[i]) + 1;
            bit::init(n);
            REP1(i,n)dt[i].clear();
            REP1(i,n){
                if(i - 1 <= n - i)dt[2 * i - 1].pb(ii(i, -1)), dt[n].pb(ii(i, 1));
                else dt[0].pb(ii(i, -1)), dt[i - (n - i) - 1].pb(ii(i, 1));
            }
            REP1(i,n){
                bit::ins(tmpd[i], 1);
                for(ii p:dt[i])
                {
                    if(p.X - 1 <= n - p.X)tmptt[p.X] += p.Y * bit::qr(POS(uni, d[p.X] + p.X - 1));
                    else tmptt[p.X] += p.Y * bit::qr(POS(uni, d[p.X] + (n - p.X)));
                }
            }
            pary(tmptt + 1, tmptt + 1 + n);
        REP1(i,n)ans[i] = max(ans[i], tmptt[i]);
        REP1(i,n)cout<<ans[i] + 1<<endl;
    }
}

int main()
{
    IOS();
    ll p;
    cin>>n>>p;
    REP1(i,n)cin>>d[i];
    if(p == 1)p1::solve();
    else p2::solve();
}
