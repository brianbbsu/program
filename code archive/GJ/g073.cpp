/**********************************************************************************/
/*  Problem: g073 "B.好吃的麵包" from NPSC 2010 國中組決賽                                  */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 180KB) on ZeroJudge                                          */
/*  Author: briansu at 2017-05-18 14:30:47                                        */
/**********************************************************************************/

#include<iostream>
#include<cstring>
typedef long long ll;
using namespace std;
ll c[16][16];

int main()
{
  ll T;
  cin>>T;
  ll n,a,b,m;
  // a+b=m;
  // a*x+b*y=n;
  // a*(x-y)+m*y=n
  // a=(n-m*y)/(x-y);
  while(T--&&cin>>n>>a>>b>>m)
  {
    a=(n-m*b)/(a-b);
    b=m-a;
    cout<<a<<" "<<b<<endl;
  }
}
