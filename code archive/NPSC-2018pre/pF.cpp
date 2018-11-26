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
//#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#endif // brian
//}


const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll n,m;
map<ll,ll> mp;
ll mn[MAXn],mx[MAXn],v[MAXn],ans[MAXn];
ll cnt = 0;

ll ask(ll x)
{
    if(mp.count(x))return x;
    cnt ++;
    cout<<x<<endl;
    ll ret;
    cin>>ret;
    mp[x] = ret;
    if(!v[ret])v[ret] = 1,mn[ret] = mx[ret] = x;
    else mn[ret] = min(mn[ret],x), mx[ret] = max(mx[ret],x);
    return ret;
}

void cal(ll L,ll R)
{
    if(L>R)return;
    ll H = (L+R)/2;// find the min rank with cnt <= h
    ll l = 0, r = n+1;
    for(int j = 0;j <= H;j ++)if(v[j])r = min(r, mn[j]);
    for(int j = H+1;j <= m;j++)if(v[j])l = max(l,mx[j]);
    //debug(i,l,r);
    while(l < r-1)
    {
        ll h = (l+r)/2;
        debug(i,l,r,h);
        ll ret = ask(h);
        if(ret > H)l = h;
        else r = h;
    }
    ans[H] = r;
    cal(L,H-1);
    cal(H+1,R);
}

int main()
{
    IOS();
    cin>>n>>m;
    cal(0,m);
    debug(cnt);
    debug("Ok");
    REP(i,m+1)debug(i,ans[i],v[i],mn[i],mx[i]);
    cout<<0<<endl;
    cout<<(n+1) - ans[0]<<endl;
    REP1(i,m)cout<<ans[i-1] - ans[i]<<endl;
}
