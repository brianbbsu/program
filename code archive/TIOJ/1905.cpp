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


const ll MAXn=2e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e9), uINF = UINT_MAX;

namespace seg{ // range min
    int N;
    int d[MAXn];
    void init(int n)
    {
        N = n;
        for(int i = (N<<1) - 1;i > 0;i--)d[i] = INF;
    }
    void mod(int x, int k)
    {
        debug(x, k);
        for(d[x += N] = k;x > 1;x >>= 1)d[x>>1] = min(d[x], d[x^1]);
    }
    int qr(int l, int r)
    {
        int ret = INF;
        for(l += N, r += N;l < r;l >>= 1, r >>= 1)
        {
            if(l&1)ret = min(ret, d[l++]);
            if(r&1)ret = min(ret, d[--r]);
        }
        return ret;
    }
};

namespace bit{ // prefix min
    uint bit[MAXn];
    int N;
    void init(int n){
        N = n;
        for(int i = N;i > 0;i --)bit[i] = uINF;
    }
    void ins(int x,uint k)
    {
        while(x <= N)bit[x] = min(bit[x], k), x += x & -x;
    }
    uint qr(int x)
    {
        uint ret = uINF;
        while(x)ret = min(ret, bit[x]), x -= x & -x;
        return ret;
    }
};

template<typename T>
int POS(vector<T> &v, T x){return lower_bound(ALL(v), x) - v.begin();}

uint d[MAXn], ans[MAXn];
int du[MAXn];
vector<uint> uni;
vector<ii> qr[2][MAXn];

int main()
{
    IOS();
    int n;
    cin>>n;
    for(int i = 1;i <= n;i ++)cin>>d[i], uni.pb(d[i]);
    sort(ALL(uni));
    uni.resize(unique(ALL(uni)) - uni.begin());
    for(int i = 1;i <= n;i ++)du[i] = POS(uni, d[i]);
    int q;
    cin>>q;
    for(int i = 0;i < q;i ++)ans[i] = uINF;
    for(int i = 0;i < q;i ++)
    {
        int l, r;
        cin>>l>>r;
        qr[0][l].pb({r, i});
        qr[1][n-r+1].pb({n-l+1, i});
    }
    for(int t = 0;t <= 1;t ++)
    {
        debug(t);
        pary(d+1, d+1+n);
        pary(du+1, du+1+n);
        seg::init(SZ(uni));
        bit::init(n);
        for(int i = n;i > 0;i --)
        {
            uint l = 0;
            int x;
            while((x = seg::qr(POS(uni, l), du[i]+1)) != INF)
            {
                debug(i, l, POS(uni, l), du[i] + 1, seg::qr(POS(uni, l), du[i]+1));
                debug(i, x);
                bit::ins(x, d[i] - d[x]);
                if(l != d[i]){
                    uint df = d[i] - d[x];
                    l = d[x] + ((df + (df&1))>>1);
                }
                else break;
            }
            for(auto &p:qr[t][i])ans[p.Y] = min(ans[p.Y], bit::qr(p.X));
            seg::mod(du[i], i);
        }
        reverse(d+1, d+1+n);
        reverse(du+1, du+1+n);
    }
    for(int i = 0;i < q;i ++)cout<<ans[i]<<endl;
}
