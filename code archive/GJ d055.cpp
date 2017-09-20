/**********************************************************************************/
/*  Problem: d055 "4.基地台訊號覆蓋" from 101年台中區複賽                                      */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 200KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-09-17 13:37:29                                        */
/**********************************************************************************/

#include <cmath>
#include <iostream>
#include <string.h>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
#include <stack>
#include <map>
#include <iomanip>
using namespace std;
const double EPS=1e-9;
struct point
{
    double x,y;
    point(double x=0,double y=0){this->x=x;this->y=y;}
};
point center(point p1,point p2,point p3)
{
    point r;
    double a,b,c,d,e,f;
    a=2*(p1.x-p2.x);
    b=2*(p1.y-p2.y);
    c=(pow(p1.x,2)+pow(p1.y,2))-(pow(p2.x,2)+pow(p2.y,2));
    d=2*(p2.x-p3.x);
    e=2*(p2.y-p3.y);
    f=(pow(p2.x,2)+pow(p2.y,2))-(pow(p3.x,2)+pow(p3.y,2));
    r.x=(c*e-f*b)/(a*e-b*d);
    r.y=(a*f-c*d)/(a*e-b*d);
    return r;
}
int cnt(point p[],int n,point c,point o)
{
    int r=0;
    for(int i=0;i<n;i++)
    {
        if(pow(p[i].x-c.x,2)+pow(p[i].y-c.y,2)<=pow(o.x-c.x,2)+pow(o.y-c.y,2)+EPS)r++;
    }
    return r;
}
int main()
{
    int n;
    cin>>n;
    point p[n];
    double sum=0,d=0;

    for(int i=0;i<n;i++)cin>>p[i].x>>p[i].y;
    for(int a=0;a<n-2;a++)
        for(int b=a+1;b<n-1;b++)
            for(int c=b+1;c<n;c++)
            {
                d++;
                sum+=cnt(p,n,center(p[a],p[b],p[c]),p[a]);
            }
    sum=sum/d+EPS;
    printf("%.6f\n",sum);
}



