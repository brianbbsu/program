/**********************************************************************************/
/*  Problem: g066 "A.迴文" from NPSC 2010 國中組初賽                                     */
/*  Language: C++                                                                 */
/*  Result: AC (5ms, 200KB) on ZeroJudge                                          */
/*  Author: briansu at 2017-05-18 14:34:50                                        */
/**********************************************************************************/

#include<iostream>
#include<cstring>
#include<string>
#include <algorithm>
typedef long long ll;
using namespace std;
ll c[16][16];

string a,b;
int main()
{
  ll T;
  cin>>T;
  while(T--&&cin>>a)
  {
    b=a;
    reverse(b.begin(),b.end());
    if(a==b)cout<<"yes"<<endl;
    else cout<<"no"<<endl;
  }
}
