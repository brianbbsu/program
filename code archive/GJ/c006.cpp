/**********************************************************************************/
/*  Problem: c006 "6.Facebook時間軸" from 101校內初賽                                    */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 216KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-09-01 21:33:42                                        */
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
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    stringstream l,r;
    int llen=a[0],rlen=a[1];
    l<<"1";
    r<<"2";
    for(int i=2;i<n;i++)
    {
        if(llen<=rlen)
        {
            l<<" "<<i+1;
            llen+=10+a[i];
        }
        else
        {
            r<<" "<<i+1;
            rlen+=10+a[i];
        }
    }
    string l1,r1;
    getline(l,l1);
    getline(r,r1);
    cout<<l1<<" "<<llen<<endl;
    cout<<r1<<" "<<rlen<<endl;
}
