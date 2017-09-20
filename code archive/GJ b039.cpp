/**********************************************************************************/
/*  Problem: b039 "最終兵器X" from 回溯法-八皇后問題                                          */
/*  Language: C++                                                                 */
/*  Result: AC (58ms, 188KB) on ZeroJudge                                         */
/*  Author: briansu at 2016-09-12 18:06:41                                        */
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
int n;
void call(int level,int p[],int l[],int a[],int b[])
{
    if(level==n)
    {
        for(int i=0;i<n;i++) cout<<p[i]+1<<" ";
        cout<<endl;
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(l[i]||a[i-level+n]||b[i+level])
            continue;
        int l1[n],a1[2*n],b1[2*n];
        memcpy(l1,l,n*sizeof(int));
        memcpy(a1,a,2*n*sizeof(int));
        memcpy(b1,b,2*n*sizeof(int));
        p[level]=i;
        l1[i]=1;a1[i-level+n]=1;b1[i+level]=1;
        call(level+1,p,l1,a1,b1);
    }
}
int main()
{
    cin>>n;
    int p[n],l[n],a[2*n],b[2*n];
    memset(l,0,sizeof(l));
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    call(0,p,l,a,b);
}



