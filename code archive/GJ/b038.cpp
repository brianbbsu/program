/**********************************************************************************/
/*  Problem: b038 "法老王的石獅子" from 回溯法-全排列                                          */
/*  Language: C++                                                                 */
/*  Result: AC (20ms, 196KB) on ZeroJudge                                         */
/*  Author: briansu at 2016-09-04 21:42:25                                        */
/**********************************************************************************/

#include <cmath>
#include <iostream>
#include <string.h>
#include <sstream>
#include <stdio.h>
#include <vector>
using namespace std;
bool isuni(int a[],int m)
{
    int b[9];
    memset(b,0,sizeof(b));
    for(int i=0;i<m;i++)
    {
        if(b[a[i]]==0) b[a[i]]=1;
        else return false;
    }
    return true;
}
void call(int n,int m,int a[])
{
    for(int i=1;i<=n;i++)
    {
        if(n==m)
        {

            a[n-1]=i;
            if(isuni(a,m))
            {
                for(int j=0;j<n;j++) printf("%d",a[j]);
                printf("\n");
            }

        }
        else
        {
            a[m-1]=i;
            if(isuni(a,m)) call(n,m+1,a);
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    call(n,1,a);
}
