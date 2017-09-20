/**********************************************************************************/
/*  Problem: d001 "99年台中區第一題" from 99年台中區複賽                                       */
/*  Language: C++                                                                 */
/*  Result: AC (31ms, 176KB) on ZeroJudge                                         */
/*  Author: briansu at 2016-09-12 18:20:39                                        */
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
   int a,b,c,cnt=0;
   for(a=12;a<=98;a++)
   {
       for(b=ceil(12345.0/a);b<=floor(98765.0/a);b++)
       {
           c=a*b;
           bool n[10];
           memset(n,0,sizeof(n));
           bool t=1;
           int a1=a,b1=b,c1=c;
           while(a1)
           {
               if(!n[a1%10]) n[a1%10]=1;
               else t=0;
               a1/=10;
           }
           while(b1)
           {
               if(!n[b1%10]) n[b1%10]=1;
               else t=0;
               b1/=10;
           }
           while(c1)
           {
               if(!n[c1%10]) n[c1%10]=1;
               else t=0;
               c1/=10;
           }
           if(t){printf("%d X %d = %d\n",a,b,c);cnt++;}
       }
   }
   printf("\n共%d種運算式\n",cnt);
}



