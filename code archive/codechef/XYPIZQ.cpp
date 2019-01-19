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

ii operator + (ii a,ii b)
{
    ll x = (a.X * b.Y + a.Y * b.X), y = a.Y * b.Y;
    ll g = __gcd(x, y);
    x /= g, y /= g;
    return ii(x,y);
}

ii operator - (ii a,ii b)
{
    ll x = (a.X * b.Y - a.Y * b.X), y = a.Y * b.Y;
    ll g = __gcd(x, y);
    x /= g, y /= g;
    return ii(x,y);
}

ii operator * (ll a,ii b)
{
    ll x = a * b.X, y = b.Y;
    ll g = __gcd(x, y);
    x /= g, y /= g;
    return ii(x,y);
}

void prt(ii a)
{
    cout<<a.X<<" "<<a.Y<<endl;
}

int main()
{
    IOS();
    ll T;
    cin>>T;
    while(T--)
    {
        ll n, t, x, y, z;
        cin>>n>>t>>x>>y>>z;
        ii o = ii(1, 2 * n + 1);
        if(t == 1)
        {
            if(y == x + 1 && z == y - 1)prt((y - 1) * o);
            else if(y == x - 1 && z == y + 1)prt((y + 1) * o);
            else if(y == x + 1 && z == y + 1)prt(ii(1,1) - (y+1) * o);
            else prt(ii(1,1) - (y-1) * o);
        }
        else if(t == 2 || t == 4)
        {
            if(x == z)prt(ii(0, 1));
            else if(y == x + 1 && z == y + 1)prt(ii(1,1) - 2 * (x+1) * o);
            else prt(ii(1,1) - 2 * (x - 1) * o);
        }
        else if(t == 3)
        {
            if(y == x + 1 && z == y - 1)prt((y - 1) * o);
            else if(y == x - 1 && z == y + 1)prt((y + 1) * o);
            else if(y == x + 1 && z == y + 1)prt(ii(1,1) - (y-1) * o);
            else prt(ii(1,1) - (y+1) * o);
        }
    }
}
