/**********************************************************************************/
/*  Problem: d070 "2.夾角度數" from 103年彰雲嘉區複賽                                        */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 184KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-09-04 12:45:36                                        */
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
    double h=0,m=0,hr,mr,r;
    while((c=getchar())!=':') h=h*10.0+c-'0';
    while((c=getchar())!='\n') m=m*10.0+c-'0';
    mr=360.0/60.0*m;
    if(h>=12) h-=12;
    m=m+h*60.0;
    hr=360.0/(12*60)*m;
    r=abs(mr-hr);
    if(r>180.0) r-=180;
    if(r==24.0) r=156.0;
    printf("%.2f",r);
}
