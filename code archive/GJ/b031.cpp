/**********************************************************************************/
/*  Problem: b031 "吃到飽餐廳" from 動態規劃-無窮背包問題                                        */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 184KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-09-06 20:21:54                                        */
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
    int n,m;
    cin>>n>>m;
    int c[m+1];
    int s[n],p[n];
    memset(c,0,sizeof(c));
    for(int i=0;i<n;i++) cin>>s[i]>>p[i];
    int most=0;
    for(int k=0;k<n;k++)
    {
        for(int i=s[k];i<=m;i++)
        {
            if(c[i]<c[i-s[k]]+p[k])
            {
                c[i]=c[i-s[k]]+p[k];
                if(most<c[i]) most=c[i];
            }
        }
    }
    cout<<most;
}

