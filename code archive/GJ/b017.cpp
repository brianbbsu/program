/**********************************************************************************/
/*  Problem: b017 "奈米科技" from 大數運算-乘法                                             */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 193KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-09-07 21:19:57                                        */
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
   vector<int> a,b,r;
   //a.clear();b.clear();r.clear();
   string s,t;
   int tmp;
   cin>>s>>t;
   for(int i=s.length()-1;i>=0;i--) a.push_back(s[i]-'0');
   for(int i=t.length()-1;i>=0;i--) b.push_back(t[i]-'0');
   for(int i=0;i<a.size();i++)
   {
       for(int j=0;j<b.size();j++)
       {
           tmp=a[i]*b[j];
           if(r.size()>i+j) r[i+j]+=tmp;
           else r.push_back(tmp);
       }
       //for(int i=r.size()-1;i>=0;i--) cout<<r[i]<<" ";cout<<endl;
       for(int j=0;j<r.size();j++)
       {
            if(r[j]>=10)
            {
                if(j!=(r.size()-1)) r[j+1]+=r[j]/10;
                else r.push_back(r[j]/10);
                r[j]=r[j]%10;
            }
        }
        //for(int i=r.size()-1;i>=0;i--) cout<<r[i];cout<<endl<<endl;
    }

   for(int i=r.size()-1;i>=0;i--) cout<<r[i];
}

