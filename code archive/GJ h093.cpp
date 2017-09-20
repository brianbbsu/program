/**********************************************************************************/
/*  Problem: h093 "A.三角形金磚" from NPSC 2011 高中組決賽                                  */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 212KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-09-12 20:46:50                                        */
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
    int k;
    cin>>k;
    for(;k>0;k--)
    {
        double ab,bc;
        cin>>ab>>bc;
        double r=1-pow(ab/bc,2);
        printf("%.3f\n",r);
    }
}



