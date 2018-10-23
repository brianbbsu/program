/**********************************************************************************/
/*  Problem: b037 "小數的密碼" from 回溯法-列舉                                             */
/*  Language: C++                                                                 */
/*  Result: AC (47ms, 192KB) on ZeroJudge                                         */
/*  Author: briansu at 2016-09-08 21:55:39                                        */
/**********************************************************************************/

#include <cmath>
#include <iostream>
#include <string.h>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <set>
using namespace std;
void a(int n,int max,int d[],int l)
{
    if(n==l)
    {
        for(int i=0;i<=max;i++)
        {
            d[l-1]=i;
            for(int j=0;j<n;j++)cout<<d[j];
            cout<<endl;
        }
    }
    else
    {
        for(int i=0;i<=max;i++)
        {
            d[l-1]=i;
            a(n,max,d,l+1);
        }
    }
}
int main()
{
    int n;
    cin>>n;
    int max;
    cin>>max;
    int d[n];
    a(n,max,d,1);
}

