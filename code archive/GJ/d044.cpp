/**********************************************************************************/
/*  Problem: d044 "4.無線網路訊號偵測" from 100年台中區複賽                                     */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 200KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-09-27 15:43:13                                        */
/**********************************************************************************/

#include <cmath>
#include <cstdlib>
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
#include <bitset>
using namespace std;
typedef long long ll;
typedef double lf;
const double EPS=0.0000001;
const ll INF=ll(1e18);
int main()
{
    int n=0;
    lf r;
    cin>>r;
    vector<lf> x,y,v,t;
    while(1)
    {
        lf x1,y1,v1,t1;
        cin>>x1>>y1>>v1>>t1;
        if(cin.fail())break;
        t1=t1/180*acos(-1);
        x.push_back(x1);
        y.push_back(y1);
        v.push_back(v1);
        t.push_back(t1);
        n++;
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(!(v[i]==v[j]&&t[i]==t[j]))
            {
                lf a,b,c,d;
                a=v[i]*cos(t[i])-v[j]*cos(t[j]);
                b=x[i]-x[j];
                c=v[i]*sin(t[i])-v[j]*sin(t[j]);
                d=y[i]-y[j];
                b=-1*(a*b+c*d)+sqrt((a*a+c*c)*r*r-(a*d-b*c)*(a*d-b*c));
                a=b/(a*a+c*c);
                printf("LET (i=%d, j=%d) = %.4f\n",i+1,j+1,a);
            }
            else
            {
                printf("LET (i=%d, j=%d) = INF\n",i+1,j+1);
            }
        }
    }
}
