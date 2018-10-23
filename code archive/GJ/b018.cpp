/**********************************************************************************/
/*  Problem: b018 "1000!" from 大數運算-大數乘整數                                         */
/*  Language: C++                                                                 */
/*  Result: AC (6ms, 200KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-09-07 21:26:01                                        */
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
   vector<int> r;
   //a.clear();b.clear();r.clear();
   int n;
   cin>>n;
   r.push_back(1);
   for(int i=2;i<=n;i++)
   {
       for(int j=0;j<r.size();j++) r[j]*=i;
       for(int j=0;j<r.size();j++)
       {
            if(r[j]>=10)
            {
                if(j!=(r.size()-1)) r[j+1]+=r[j]/10;
                else r.push_back(r[j]/10);
                r[j]=r[j]%10;
            }
        }
    }
   for(int i=r.size()-1;i>=0;i--) cout<<r[i];
}

