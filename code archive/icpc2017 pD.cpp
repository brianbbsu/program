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

ii a[MAXn], b[MAXn];
ll dp[MAXn];
ll n, m;

void dnq(ll al, ll ar, ll bl, ll br)
{
    if(ar < al)return;
    ll ah = (al + ar) / 2;
    ll pi = -1;
    for(int i = bl;i <= br;i ++)if(b[i].X > a[ah].X && b[i].Y > a[ah].Y)
    {
        ll t = (b[i].X - a[ah].X) * (b[i].Y - a[ah].Y);
        if(t > dp[ah])
        {
            pi = i;
            dp[ah] = t;
        }
    }
    if(pi == -1)for(int i = bl;i <= br;i ++)if(b[i].X > a[ah].X){
        pi = i;
        break;
    }
    if(pi == -1)pi = br;
    dnq(al, ah - 1, bl, pi);
    dnq(ah + 1, ar, pi, br);
}

int main()
{
    IOS();
    cin>>n>>m;
    REP1(i, n)cin>>a[i].X>>a[i].Y;
    REP1(i, m)cin>>b[i].X>>b[i].Y;
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m);
    ll it = 1;
    for(int i = 2;i <= n;i ++)if(a[i].Y < a[it].Y)a[++it] = a[i];
    n = it;
    FILL(dp, 0);
    dnq(1, n, 1, m);
    ll mx = 0;
    REP1(i,n)mx = max(mx, dp[i]);
    cout<<mx<<endl;
}
