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


ll sg[(1<<15)], d[20], dph[40], ct[MAXn];

bool istree(ll I)
{
    FILL(d, 0);
    REP(i, 15)if((1<<i)&I)d[i+1] = 1;
    if(d[1] == 0)return 0;
    for(int i = 2;i <= 15;i ++)if(d[i] && !d[i/2])return 0;
    return 1;
}

vector<ll> dt;

void tr(ll I, ll x)
{
    FILL(d, 0);
    FILL(dph, 0);
    REP(i,15)if((1<<i)&I)d[i+1] = 1;
    for(int i = 15;i > 0;i --)if(d[i])dph[i] = max(dph[i<<1], dph[i<<1|1]) + 1;
    if(!d[x] || dph[x] > 2)return;
    d[x] = 0;
    if(dph[x] == 2)d[x<<1] = d[x<<1|1] = 0;
    ll tt = 0;
    REP(i, 15)if(d[i+1])tt += (1<<i);
    dt.pb(sg[tt]);
}


int main()
{
    IOS();
    REP(I, (1<<15))if(istree(I))
    {
        dt.clear();
        REP1(i, 15)tr(I, i);
        for(ll x:dt)ct[x] = 1;
        for(int i = 0;;i++)if(ct[i] == 0)
        {
            sg[I] = i;
            break;
        }
        for(ll x:dt)ct[x] = 0;
    }
    ll T;
    cin>>T;
    while(T--)
    {
        ll n;
        cin>>n;
        ll a = 0;
        while(n--)
        {
            ll m;
            cin>>m;
            ll tt = 0;
            while(m--)
            {
                ll t;
                cin>>t;
                tt += (1<<t);
            }
            a ^= sg[tt];
        }
        if(a == 0)cout<<"Emma wins"<<endl;
        else cout<<"Ella wins"<<endl;
    }
}
