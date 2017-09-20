/**********************************************************************************/
/*  Problem: d026 "97年雲嘉區第一題" from 97年雲嘉區複賽                                       */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 184KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-09-03 20:10:39                                        */
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
    int a,b,c; //5a+2c=b
    scanf("%d%d%d",&a,&b,&c);
    b+=min(floor(a/5.0),floor(c/2.0));
    printf("%d杯咖啡，%d盒巧克力，%d份蛋糕",a,b,c);
}
