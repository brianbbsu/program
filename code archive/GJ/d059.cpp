/**********************************************************************************/
/*  Problem: d059 "2.表兄弟質數" from 101年彰雲嘉區複賽                                       */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 197KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-09-04 19:34:08                                        */
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
    long long int a,b;
    scanf("%lld%lld",&a,&b);
    vector<long long int> prime;
    vector<long long int> de;
    long long int i;
    for(i=2;i<a;i++)
    {
        bool isprime = true;
        for(int j=0;j<prime.size() && prime[j]<=sqrt(i);j++)if(i%prime[j]==0){isprime=false;break;}
        if(isprime) prime.push_back(i);
    }
    for(;i<=b-4;i++)
    {
        bool isprime = true;
        for(int j=0;j<prime.size() && prime[j]<=sqrt(i);j++)if(i%prime[j]==0){isprime=false;break;}
        if(isprime)
        {
            prime.push_back(i);
            for(int j=0;j<prime.size() && prime[j]<=sqrt(i+4);j++)if((i+4)%prime[j]==0){isprime=false;break;}
            if(isprime) {de.push_back(i);de.push_back(i+4);}
        }
    }

    for(int i=0;i<de.size()-1;i+=2)
    {
        printf("(%lld,%lld)",de[i],de[i+1]);
        if(i!=de.size()-2)printf(",");
    }
    printf("\n共%d組",de.size()/2);
}
