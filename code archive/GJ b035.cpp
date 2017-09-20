/**********************************************************************************/
/*  Problem: b035 "超級保姆" from 貪婪演算法-最小總耗費時間                                       */
/*  Language: C++                                                                 */
/*  Result: AC (5ms, 209KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-09-09 07:42:05                                        */
/**********************************************************************************/

#include <cmath>
#include <iostream>
#include <string.h>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long int b[n];
    for(int i=0;i<n;i++)cin>>b[i];
    sort(b,b+n);
    //for(int i=0;i<n;i++)cout<<b[i];
    long long int m=0;
    for(int i=0;n>0;i++)
    {
        n--;
        m+=n*100*b[i];

    }
    cout<<m<<endl;
}

