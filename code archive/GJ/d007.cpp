/**********************************************************************************/
/*  Problem: d007 "99年彰雲嘉區第二題" from 99年彰雲嘉區複賽                                     */
/*  Language: C++                                                                 */
/*  Result: AC (3ms, 192KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-09-12 18:32:04                                        */
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
   int n;
   cin>>n;
   long long f=0;
   for(long long i=1;i<=n;i++)
   {
       f+=i*(i*3)*(i*5);
   }
   printf("F=%lld\n",f);
}



