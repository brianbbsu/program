/**********************************************************************************/
/*  Problem: c005 "5.平均之上" from 101校內初賽                                           */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 181KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-09-01 20:23:22                                        */
/**********************************************************************************/

#include <cmath>
#include <iostream>
#include <string.h>
#include <sstream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int m[n],e[n];
    float am=0,ae=0;
    for(int i=0;i<n;i++)
    {
        cin>>m[i];
        am+=m[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>e[i];
        ae+=e[i];
    }
    am/=n;
    ae/=n;
    bool b=false;
    for(int i=0;i<n;i++)
    {
        if((m[i]>=am)&&(e[i]>=ae))
        {
            cout<<i+1<<" ";
            b=true;
        }
    }
    if(b==false) cout<<"NO";
}
