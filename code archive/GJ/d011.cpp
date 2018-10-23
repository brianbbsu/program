/**********************************************************************************/
/*  Problem: d011 "98年台中區第一題" from 98年台中區複賽                                       */
/*  Language: C++                                                                 */
/*  Result: AC (7ms, 192KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-09-12 19:29:17                                        */
/**********************************************************************************/

#include <cmath>
#include <iostream>
#include <string.h>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
   int l,u;
   cin>>l>>u;
   long long int most=0;
   int pos;
   for(int i=l;i<=u;i++)
   {
       long long sum=i;
       long long n=i;
       while(n!=1)
       {
           if(n%2==0) n/=2;
           else n=3*n+1;
           sum+=n;
       }
       if(sum>=most){most = sum;pos=i;}
   }
   cout<<most<<" "<<pos<<endl;
}



