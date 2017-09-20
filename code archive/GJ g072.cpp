/**********************************************************************************/
/*  Problem: g072 "A.帕斯卡三角形" from NPSC 2010 國中組決賽                                 */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 180KB) on ZeroJudge                                          */
/*  Author: briansu at 2017-05-18 14:22:59                                        */
/**********************************************************************************/

#include<iostream>
#include<cstring>
typedef long long ll;
using namespace std;
ll c[16][16];

int main()
{
  for(int i=1;i<=13;i++)
  {
    c[i][1]=c[i][i]=1;
    for(int j=2;j<i;j++)c[i][j]=c[i-1][j-1]+c[i-1][j];
  }
  ll T;
  cin>>T;
  ll a,b;
  while(T--&&cin>>a>>b)cout<<c[a][b]<<endl;
}
