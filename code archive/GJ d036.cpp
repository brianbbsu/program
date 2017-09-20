/**********************************************************************************/
/*  Problem: d036 "96年雲嘉區第一題" from 96年雲嘉區複賽                                       */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 184KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-09-04 20:38:49                                        */
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
    int a[5];
    int i;
    for(i=0;i<5;i++) scanf("%d",&a[i]);
    int most=a[0];
    for(i=0;i<5;i++) if(a[i]>most) most=a[i];
    int least=most;
    for(i=0;i<5;i++) if(a[i]<least) least=a[i];
    double avg=0;
    for(i=0;i<5;i++) avg+=a[i];
    avg-=most+least;
    printf("%.2f",avg/3);
}
