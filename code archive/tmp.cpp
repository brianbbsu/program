#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define X first
#define Y second
#define pb push_back
#define FILL(i,n) memset(i,n,sizeof i)
#define ALL(_a) (_a).begin(),(_a).end()
#define SZ(_a) ((int)(_a).size())
#ifdef brian
#define IOS()
#define debug(...) do{\
  fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
  _do(__VA_ARGS__);\
}while(0)
template<typename T>void _do(T &&x){cerr<<x<<endl;}
template<typename T,typename ...t>void _do(T &&x,t &&...X){cerr<<x<<", ";_do(X...);}
#else
#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#define debug(...)
#endif

const ll MAXn=1e5+5;
const ll INF=ll(1e15);
const ll MOD=1000000007;

int main()
{
  IOS();
  debug(123);
}
