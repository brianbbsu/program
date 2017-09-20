/**********************************************************************************/
/*  Problem: h150 "E.零" from NPSC 2015 高中組初賽                                      */
/*  Language: C++                                                                 */
/*  Result: AC (931ms, 227KB) on ZeroJudge                                        */
/*  Author: briansu at 2016-09-13 19:27:25                                        */
/**********************************************************************************/

#include <cmath>
#include <iostream>
#include <string.h>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
#include <stack>
#include <map>
#include <iomanip>
using namespace std;
int main()
{
    int T;
    cin>>T;
    for(;T>0;T--)
    {
    long long m;
    cin>>m;
    long long now;
    long long top=(long long)5e9, bot=5;
    while(1)
    {
        now=floor((top+bot)/2);
        long long f=0;
        long long fs=5;
        while(1)
        {
            f+=floor(now/fs);
            fs*=5;
            if(fs>now) break;
        }
        if(f==m){cout<<fixed<<setprecision(0)<<floor(now/5)*5<<endl;break;}
        else if(f>m) top=floor((top+bot)/2);
        else bot=ceil((top+bot)/2.0);
        if(top==bot){cout<<-1<<endl;
        break;}
    }
    }



}



