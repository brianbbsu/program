/**********************************************************************************/
/*  Problem: d064 "2.數字排列問題" from 103年台中區複賽                                       */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 212KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-09-04 12:12:12                                        */
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
    long int a[3];
    for(int i=0;i<3;scanf("%ld",&a[i++]));
    //printf("%f %f %f\n",l[0],l[1],l[2]);
    int r[6][3]={{1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1}};
    long long int most=0;
    for(int i=0;i<6;i++)
    {
        stringstream ss;
        for(int j=0;j<3;j++) ss<<a[r[i][j]-1];
        long long int tmp;
        ss>>tmp;
        if(tmp>most) most=tmp;
    }
    printf("%lld",most);
}
