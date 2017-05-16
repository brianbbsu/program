#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define FILL(i,n) memset(i,n,sizeof i)
#define X first
#define Y second
#define pb push_back
#define SZ(_a) ((int)(_a).size())
#define ALL(_a) (_a).begin(),(_a).end()
#ifdef brian
#define debug(...) do{\
  fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
  _do(__VA_ARGS__);\
}while(0)
template<typename T>void _do(T &&x){cerr<<x<<endl;}
template<typename T,typename ...t>void _do(T &&x,t &&...X){cerr<<x<<", ";_do(X...);}
#define IOS() ;
#else
#define debug(...)
#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#endif

const ll MAXn = 4e1+5;
const ll INF=ll(1e18);
const ll MOD=1000000007;

ll n;

int main()
{
  IOS();
  cin>>n;
  ll mx=INF;
  ll mn=-INF;
  REP(i,n)
  {
    ll k;
    cin>>k;
    mx=min(mx,k);
    if(mx<mn){cout<<0<<endl;return 0;}
    swap(mx,mn);
    mx=2*k-mx;
    mn=2*k-mn;
  }
  cout<<mx-mn+1<<endl;
}
