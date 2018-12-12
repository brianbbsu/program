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

ll x[MAXn], y[MAXn], z[MAXn];
ll ans[MAXn];
ll bit[MAXn];
vector<ll> d[MAXn];

void ins(ll x,ll k)
{
    x = MAXn - x;
    debug(x, k);
    while(x < MAXn)bit[x] += k, x += x & -x;
}
ll qr(ll x)
{
    ll ret = 0;
    x = MAXn - x;
    debug(x);
    while(x)ret += bit[x], x -= x & -x;
    return ret;
}

void CDQ(ll l,ll r)
{
    if(l >= r-1)return;
    ll h = (l+r)/2;
    vector<ii> v;
    for(int i = l;i < h;i ++)for(ll t:d[i])v.pb(ii(t,0));
    for(int i = h;i < r;i ++)for(ll t:d[i])v.pb(ii(t,1));
    sort(ALL(v),[](ii a,ii b){return ii(y[a.X], a.Y) > ii(y[b.X], b.Y);});
    for(ii tmp:v)
    {
        if(tmp.Y==1)ans[tmp.X] += qr(z[tmp.X]+1);
        else ins(z[tmp.X], 1);
    }
    for(ii tmp:v)if(tmp.Y == 0)ins(z[tmp.X], -1);
    pary(ans,ans+n);
    CDQ(l,h);
    CDQ(h,r);
}

int main()
{
    IOS();
    ll n;
    cin>>n;
    REP(i,n)cin>>x[i]>>y[i]>>z[i];
    REP(i,n)d[n - x[i] + 1].pb(i);
    CDQ(1,n+1);
    REP(i,n)cout<<ans[i]<<endl;
}
