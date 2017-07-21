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
const ll MOD=666013;
const ll INF=ll(1e15);

ll _cal(ll l,ll r,ll a,ll b)
{
    return max(min(r,b)-max(l,a)+1,0LL);
}

void cal(ll l,ll r,ll a,ll b,ll *d)
{
    d[0]=_cal(l,r,a,b);
    REP1(i,1000)
    {
        d[i]=_cal(l,r,a-i,b-i)+_cal(l,r,a+i,b+i);
    }
}

ll a[MAXn],b[MAXn];

ii d[4];

ll mypow(ll x,ll k)
{
    if(k==0)return 1;
    ll t=mypow(x,k/2);
    if(k&1)return t*t%MOD*x%MOD;
    else return t*t%MOD;
}

ll fac[2*MAXn],ifac[2*MAXn];

ll c(ll n,ll m)
{
    return fac[n]*ifac[m]%MOD*ifac[n-m]%MOD;
}

int main()
{
    IOS();
    FILL(d,0);
    REP(i,4)cin>>d[i].X>>d[i].Y;
    cal(d[0].X,d[1].X,d[2].X,d[3].X,a);
    cal(d[0].Y,d[1].Y,d[2].Y,d[3].Y,b);
    ifac[0]=fac[0]=1;
    REP1(i,2*MAXn-1)fac[i]=fac[i-1]*i%MOD,ifac[i]=mypow(fac[i],MOD-2);

    pary(a,a+100);
    pary(b,b+100);

    ll ans=0;
    REP(i,1005)a[i]=a[i]*ifac[i]%MOD;
    REP(i,1005)b[i]=b[i]*ifac[i]%MOD;

    REP(i,1005)REP(j,1005)ans=(ans+a[i]*b[j]%MOD*fac[i+j])%MOD;
    cout<<ans<<endl;

    //REP(i,10)REP(j,10)debug(i,j,c(i+j,j));
    //REP(i,10)debug(i,a[i],b[i]);
}
