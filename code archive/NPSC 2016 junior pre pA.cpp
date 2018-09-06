#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(ll i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);

const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll d[MAXn]; //prefix sum of the array
ll n,k;

int main()
{
    IOS();
    cin>>n>>k;
    REP1(i,n)cin>>d[i],d[i] += d[i-1]; // input and build the prefix array
    ll l = -1,r = d[n]; // bound of answer
    while(l!=r-1)
    {
      ll h = (l+r)/2,tt = 0;
      REP1(i,n)
      {
        ll x = i-1,y = n+1;
        while(x != y-1)
        {
          ll hh = (x+y)/2;
          ll tmp = d[hh] - d[i-1];
          if(tmp >  h)y = hh;
          else x = hh;
        }
        tt += n + 1 - y;
      }
      if(tt < k)r = h;
      else l = h;
    }
    cout<<r<<endl;

}
