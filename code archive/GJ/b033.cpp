/**********************************************************************************/
/*  Problem: b033 "兩隻猴子" from 動態規劃-最長共同子序列                                        */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 184KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-09-06 19:40:57                                        */
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
    char a[101],b[101];
    cin>>a>>b;
    int r[strlen(a)][strlen(b)];
    memset(r,0,sizeof(r));
    int most=0;
    for(int j=0;j<strlen(b);j++)
    {
        for(int i=0;i<strlen(a);i++)
        {
            if(a[i]==b[j])
            {
                r[i][j]=1;
                for(int k=0;k<i;k++) for(int l=0;l<j;l++) if(r[k][l]>=r[i][j]) r[i][j]=r[k][l]+1;
                if(r[i][j]>most) most=r[i][j];
            }
        }
    }
    cout<<most;
}

