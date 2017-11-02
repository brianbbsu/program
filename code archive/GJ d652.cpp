#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(ll i=0;i<n;i++)
#define FILL(i,n) memset(i,n,sizeof i)
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);

const ll MAXn=5e1+5;
const ll INF=ll(1e15);

ll d[MAXn],dp[MAXn][MAXn];

int main()
{
    IOS();
    ll n;             // |
    cin>>n;           // | input
    REP(i,n)cin>>d[i];// |

    FILL(dp,0);//Set all dp value to 0

    for(int len=3;len<=n;len++)// go through all possible segment length form small to large, start from 3 because dp[l][r]=0 for all r-l+1 < 3
    {
      for(int l=0;l+len<=n;l++)// go through all possible starting points for segment with length = len
      {
        // calculate dp value for segment [l,l+1,l+2,...,l+len-1]
        ll mn = INF;// set the current smallest value to INF
        ll r = l+len-1; //just a alias for increasing readability
        for(int x=l+1;x<r;x++)// go through all possible points which can be the last one eliminated in this segment
        {
          mn = min(mn,d[l]*d[x]*d[r] + dp[l][x] + dp[x][r]);
          /*
            update current smallest value.
            d[i]*d[x]*d[r] : cost for eliminating item x
            dp[l][x] : cost for eliminating items between l and x
            dp[x][r] : cost for eliminating items between x and r

            <pf>
              because l < x < l+len -1
              so x-l+1(length of the left segment) < len
              and r(length of the right segment) < len
              hence both dp[l][x] and dp[x][r] is calculated befor dp[l][r]
          */
        }
        dp[l][r] = mn;//set dp value of this segment to the smallest value
      }
    }

    cout<<dp[0][n-1]<<endl;// output
}
