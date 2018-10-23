/**********************************************************************************/
/*  Problem: d031 "96年台中區第一題" from 96年台中區複賽                                       */
/*  Language: C++                                                                 */
/*  Result: AC (5ms, 200KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-09-03 20:06:21                                        */
/**********************************************************************************/

#include <cmath>
#include <iostream>
#include <string.h>
#include <sstream>
#include <stdio.h>
#include <vector>
using namespace std;
int main()
{
  int n;
  scanf("%d",&n);
  vector<int> prime;
  for(int i=2;i<n;i++)
  {
      bool b=true;
      for(int j=0;j<prime.size();j++) if(i%prime[j]==0){b=false;break;}
      if(b==true)
      {
          prime.push_back(i);

          int a=i,re=0;
          while(a!=0)
          {
              re=10*re+a%10;
              a=floor(a/10);
          }
          if(re==i) printf("%d ",i);
      }
  }
}
