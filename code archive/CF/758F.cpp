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


const ll MAXn=4e3+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

vector<ll> dt[MAXn];
ll p[MAXn];

int main()
{
    IOS();
    ll n,l,r;
    cin>>n>>l>>r;
    if(n==1){cout<<r-l+1<<endl;return 0;}
    else if(n==2){cout<<(r-l+1)*(r-l)<<endl;return 0;}
    ll it=1;
    for(;;it++)
    {
      ll t=1,b=1;
      for(int j=1;j<n;j++)if(t*it>r){b=0;break;}else t*=it;
      if(!b)break;
      p[it]=t;
    }
    it--;
    debug(it);
    REP1(i,it)REP1(j,it)if(__gcd(i,j)==1&&i!=j)dt[i].pb(j);

    ll ans=0;
    REP1(i,it)
    {
      for(ll k:dt[i])
      {
        ll a=min(p[i],p[k]),b=max(p[i],p[k]);
        ll mn=(l-1)/a+1;
        ll mx=r/b;
        debug(a,b,mn,mx);
        ans+=max(0LL,mx-mn+1);
      }
    }
    cout<<ans<<endl;
}
