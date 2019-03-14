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

vector<ii> l, r;
vector<ll> p;

int main()
{
    IOS();
    ll n, tt=0, mx = 0;
    cin>>n;
    REP(i,n)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        l.pb(ii(a, c));
        r.pb(ii(b, c));
        p.pb(a);
        p.pb(a-1);
        p.pb(b);
        p.pb(b+1);
        tt += c;
    }
    sort(ALL(l));
    sort(ALL(r));
    REP1(i, SZ(r) - 1)r[i].Y += r[i-1].Y;
    for(int i = SZ(l) - 2;i >= 0;i --)l[i].Y += l[i+1].Y;
    REP1(i, SZ(r) - 1)r[i].Y = min(r[i].Y, r[i-1].Y);
    for(int i = SZ(l) - 2;i >= 0;i --)l[i].Y =  min(l[i].Y, l[i+1].Y);
    sort(ALL(p));
    p.resize(unique(ALL(p)) - p.begin());
    debug(l, r, p);
    for(ll x:p){
        ll it1 = lower_bound(ALL(l), ii(x+1,-INF)) - l.begin();
        ll it2 = lower_bound(ALL(r), ii(x, -INF)) - r.begin();
        ll tmp = 0;
        if(it1 != SZ(l))tmp += min(0LL,l[it1].Y);
        if(it2 != 0)tmp += min(0LL,r[it2-1].Y);
        debug(it1, it2, tmp);
        mx = max(mx, tt - tmp);
    }
    cout<<mx<<endl;

}
