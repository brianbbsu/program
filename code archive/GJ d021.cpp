/**********************************************************************************/
/*  Problem: d021 "97年台中區第一題" from 97年台中區複賽                                       */
/*  Language: C++                                                                 */
/*  Result: AC (3ms, 184KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-09-03 20:18:42                                        */
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
    int n;
    scanf("%d",&n);
    for(int i=0;i<=floor(n/7.0);i++)
    {
        if((n-i*7)%11==0){printf("Yes 7:%d 11:%d",i,(n-i*7)/11);break;}
        if(i==floor(n/7.0)) printf("No");
    }

}
