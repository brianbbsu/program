/**********************************************************************************/
/*  Problem: e019 "1.機器人的位置" from 103學年度全國決賽                                      */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 192KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-09-16 16:23:40                                        */
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
int main()
{
    char c;
    int v;
    cin>>c;
    int x,y;
    cin>>c>>x>>c>>y;
    while(1)
    {
        cin>>c;
        if(c=='E')break;
        cin>>v;
        if(c=='U') y+=v;
        else if(c=='D') y-=v;
        else if(c=='R') x+=v;
        else if(c=='L') x-=v;

    }
    cout<<x<<endl<<y<<endl;
}



