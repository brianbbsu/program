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


const ll MAXn=3e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

namespace seg{
    int N, d[2 * MAXn];
    void init(int n)
    {
        N = n;
        for(int i = (n<<1);i > 0;i --)d[i] = 0;
    }
    void ins(ll x, ll k)
    {
        for(d[x += N] += k;x > 1;x >>= 1)d[x>>1] = d[x] + d[x^1];
    }
    ll qr(ll l, ll r)
    {
        ll ret = 0;
        for(l += N, r += N;l < r;l >>= 1, r >>= 1){
            if(l & 1)ret += d[l++];
            if(r & 1)ret += d[--r];
        }
        return ret;
    }
};

vector<ll> v[MAXn];
vector<ii> dt[MAXn];
ll ans[MAXn];

int main()
{
    IOS();
    ll n, m;
    cin>>n>>m;
    seg::init(m + 1);
    REP(i,n)
    {
        ll l, r;
        cin>>l>>r;
        dt[l].pb(ii(l-1, 1));
        dt[r+1].pb(ii(l-1, -1));
    }
    REP1(i, m)v[i].pb(i);
    REP1(i, m)
    {
        for(auto p:dt[i])seg::ins(p.X, p.Y);
        for(auto x:v[i])
        {
            ans[x] += seg::qr(i - x, i);
            v[i + x].pb(x);
        }
        v[i].clear();v[i].shrink_to_fit();
    }
    REP1(i,m)cout<<ans[i]<<endl;
}
