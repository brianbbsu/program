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


const ll MAXn=1e6+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

vector<ll> pm;
int lspm[MAXn];


ll big(ll x, ll a)
{
    ll tt = 0;
    for(ll t:pm)
    {
        if(x == 1)break;
        if(x % t == 0)
        {
            if(t > a)tt++;
            while(x % t == 0)x /= t;
        }
    }
    if(x > 1)tt++;
    return tt;
}

int main()
{
    IOS();
    for(int i = 2;i < MAXn;i ++)
    {
        if(!lspm[i])lspm[i] = i, pm.pb(i);
        for(int j = 0;pm[j] * i < MAXn;j ++)
        {
            lspm[pm[j] * i] = pm[j];
            if(i % pm[j] == 0)break;
        }
    }
    ll a,b;
    while(cin>>a>>b)
    {
        if(a > b)swap(a,b);
        ll tt = upper_bound(ALL(pm), a) - pm.begin(); 
        ll tmp = 1;
        for(ll i = a + 1;i <= b;i ++)tmp *= i;
        tmp += 1;
        tt += big(tmp, a);
        cout<<tt<<endl;
    }
}
