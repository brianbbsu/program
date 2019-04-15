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


const ll MAXn=2e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

namespace seg{
    const int N = (1<<18);
    ll mn[2*N], mx[2 * N];
    multiset<ll> st[2 * N];
    void build()
    {
        for(int i = 1;i < 2 * N;i++)mn[i] = INF, mx[i] = -1;
    }
    inline ll calmn(ll x){
        return SZ(st[x]) ? min(mn[x], *st[x].begin()) : mn[x];
    }
    inline ll calmx(ll x){
        return SZ(st[x]) ? max(mx[x], *st[x].rbegin()) : mx[x];
    }
    void pull(ll x){
        mn[x] = min(calmn(x<<1), calmn(x<<1|1));
        mx[x] = max(calmx(x<<1), calmx(x<<1|1));
    }
    void ins(int x,int k)
    {
        for(st[x += N].insert(k);x > 1;x >>=1)pull(x>>1);
    }
    void rm(int x,int k)
    {
        x += N;
        for(st[x].erase(st[x].lower_bound(k));x > 1;x >>=1)pull(x>>1);
    }
    ii qr(ll l,ll r)
    {
        ll rmn = INF, rmx = -1;
        for(l += N, r += N;l < r;l>>=1, r>>=1){
            if(l&1)rmn = min(rmn, calmn(l)), rmx = max(rmx, calmx(l)), l++;
            if(r&1)r--, rmn = min(rmn, calmn(r)), rmx = max(rmx, calmx(r));
        }
        return ii(rmn, rmx);
    }
};

ll h[MAXn], A[MAXn], B[MAXn];
vector<ii> v[MAXn];

bool in(ll i,ll x)
{
    return x >= A[i] && x <= B[i];
}



int main()
{
    IOS();
    ll n, q;
    cin>>n;
    REP1(i,n)cin>>h[i]>>A[i]>>B[i];

    ll mx = -1;
    seg::build();
    REP1(i,n)
    {
        debug(i, v[i]);
        for(ii k:v[i])
        {
            if(k.Y < 0)seg::rm(k.X, -k.Y);
            else seg::ins(k.X, k.Y);
        }
        ll qrr = max(i - A[i] + 1, 0LL), qrl = max(i - B[i], 0LL);
        ii qr = seg::qr(qrl, qrr);
        debug(i, qrl, qrr, qr);
        mx = max({mx, h[i] - qr.X, qr.Y - h[i]});
        ll inl = min(i + A[i], n+1), inr = min(i + B[i] + 1, n+1);
        v[inl].pb({i, h[i]});
        v[inr].pb({i, -h[i]});
    }
    cout<<mx<<endl;
}
