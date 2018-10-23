/**********************************************************************************/
/*  Problem: d071 "3.一元二次方程式的根" from 103年彰雲嘉區複賽                                   */
/*  Language: C++                                                                 */
/*  Result: AC (3ms, 184KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-09-04 20:11:45                                        */
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
    double a,b,c;
    scanf("%lf%lf%lf",&a,&b,&c);
    double D=pow((double)b,2)-4*a*c;
    if(D>0)
    {
        double ans1=(-1.0*b+sqrt(D))/(2.0*a),ans2=(-1.0*b-sqrt(D))/(2.0*a);
        printf("Two different roots x1=%.2f , x2=%.2f",max(ans1,ans2),min(ans1,ans2));
    }
    else if(D==0)
    {
        double ans=(-1.0*b)/(2.0*a);
        if(ans>-0.01 &&ans<0.01)ans=0.00;

        printf("Two same roots x=%.2f",ans);
    }
    else printf("No real root");
}
