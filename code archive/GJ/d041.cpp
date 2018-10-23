/**********************************************************************************/
/*  Problem: d041 "1.二進位字串" from 100年台中區複賽                                        */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 184KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-09-04 20:31:06                                        */
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
    char c;
    int num=0;
    bool is = true;
    int a=0;
    while((c=getchar())!='\n')
    {
        if(c=='1') num++;
        else if(c!='0') is=false;
        a=a*10+c-'0';
    }
    if(is) printf("包含1的個數為%d",num);
    else printf("%d非二進位數",a);
}
