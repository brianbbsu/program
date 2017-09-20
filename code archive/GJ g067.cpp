/**********************************************************************************/
/*  Problem: g067 "B.薑餅部落的危機" from NPSC 2010 國中組初賽                                */
/*  Language: C++                                                                 */
/*  Result: AC (77ms, 458KB) on ZeroJudge                                         */
/*  Author: briansu at 2017-05-18 14:47:27                                        */
/**********************************************************************************/

#include<iostream>
#include<cstring>
#include<string>
#include <algorithm>
typedef long long ll;
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)

bool d[505][505];
ll n,m;
int main()
{
  ll T;
  cin>>T;
  while(T--&&cin>>n>>m)
  {
    memset(d,0,sizeof d);
    REP(i,n)
    {
      string a;
      cin>>a;
      REP(j,m)d[i+1][j+1]=a[j]-'0';
    }
    ll ans=0;
    REP(i,n)REP(j,m+1)if(d[i+1][j]^d[i+1][j+1])ans++;
    REP(i,n+1)REP(j,m)if(d[i][j+1]^d[i+1][j+1])ans++;
    cout<<ans<<endl;
  }
}
