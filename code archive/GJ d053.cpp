/**********************************************************************************/
/*  Problem: d053 "2.質因數分解" from 101年台中區複賽                                        */
/*  Language: C++                                                                 */
/*  Result: AC (10ms, 248KB) on ZeroJudge                                         */
/*  Author: briansu at 2016-09-04 13:03:10                                        */
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
    long int n;
    scanf("%ld",&n);
    vector<long int> prime;
    vector<long int> de;
    printf("%ld = ",n);
    for(long int i=2;n>1;i++)
    {
        bool isprime = true;
        for(int j=0;j<prime.size() && prime[j]<sqrt(i);j++)if(i%prime[j]==0){isprime=false;break;}
        if(isprime)
        {
            prime.push_back(i);
            while(n%i==0)
            {
                n/=i;
                de.push_back(i);
            }
        }
    }

    for(int i=0;i<de.size();i++)
    {
        printf("%ld",de[i]);
        if(i!=de.size()-1)printf(" * ");
    }
}
