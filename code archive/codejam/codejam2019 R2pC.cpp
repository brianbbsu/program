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

ll x[MAXn], y[MAXn];

int main()
{
    IOS();
    ll T, kz = 0;
    cin>>T;
    while(T--)
    {
        kz ++;
        cout<<"Case #"<<kz<<": ";
        ll n;
        cin>>n;
        REP(i,n)cin>>x[i]>>y[i];
        ii mn = ii(1, 2000000005), mx = ii(2000000005, 1);
        bool fg = 0;
        for(int i = 0;i < n-1;i ++)for(int j = i + 1;j < n;j ++)
        {
            if(x[i] >= x[j] && y[i] >= y[j])fg = 1;
            else if(x[j] < x[i] && y[j] > y[i])
            {
                ll a = abs(x[j] - x[i]), b = abs(y[j] - y[i]);
                ll g = __gcd(a, b);
                a /= g, b /= g;
                if(a * mn.Y > b * mn.X)mn = ii(a, b);
            }
            else if(x[j] > x[i] && y[j] < y[i])
            {
                ll a = abs(x[j] - x[i]), b = abs(y[j] - y[i]);
                ll g = __gcd(a, b);
                a /= g, b /= g;
                if(a * mx.Y < b * mx.X)mx = ii(a, b);
            }
        }
        if(mn.X * mx.Y >= mx.X * mn.Y)fg = 1;
        if(fg)cout<<"IMPOSSIBLE"<<endl;
        else
        {
            for(ll i = 1;;i++)
            {
                ll a = i * mn.X / mn.Y + 1;
                if((mx.X * i - 1) / mx.Y + 1 > a)
                {
                    cout<<i<<" "<<a<<endl;
                    break;
                }
            }
        }
    }
    
}
