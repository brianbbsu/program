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
const ll INF=ll(2e9);

ll d[MAXn],p[MAXn],ct[MAXn],dis[MAXn];

ll ans[MAXn];
ll n,q;

ll qr(ll t,ll x)
{
  ll l=-1,r=n+1;
  while(l!=r-1)
  {
    ll h=(l+r)/2;
    if((t/ct[h])*dis[h]-h>=x)l=h;
    else r=h;
  }
  return l;
}

int main()
{
    IOS();
    cin>>n>>q;
    REP1(i,n)cin>>d[i],p[i]=-i;

    ct[0]=1;
    dis[0]=1;
    REP1(i,n)
    {
      ll tmp=(d[i]-1)/dis[i-1]+1;
      debug(i,tmp);
      ct[i]=ct[i-1]*tmp;
      dis[i]=dis[i-1]*tmp;
      dis[i]=min(dis[i],INF);
      ct[i]=min(ct[i],INF);
    }
    REP(i,n+1)debug(i,ct[i],dis[i]);
    REP(i,q)
    {
      ll t,l,r;
      cin>>t>>l>>r;
      cout<<qr(t,l)-qr(t,r+1)<<endl;
    }
}
