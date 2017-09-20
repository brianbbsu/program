/**********************************************************************************/
/*  Problem: c007 "7.勇者鬥惡龍" from 101校內初賽                                          */
/*  Language: C++                                                                 */
/*  Result: AC (3ms, 192KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-09-01 21:47:09                                        */
/**********************************************************************************/

#include <cmath>
#include <iostream>
#include <string.h>
#include <sstream>
using namespace std;
int main()
{
    int y,d,ya,da;
    cin>>y>>ya>>d>>da;
    int i=1;
    while(true)
    {
        cout<<"Round "<<i<<":"<<endl;
        cout<<"You hit Dragon "<<ya<<" points.\n";
        d-=ya;
        if(d<0) d=0;
        cout<<"You:"<<y<<" Dragon:"<<d<<endl;
        if(d==0)
        {
            cout<<"You Win!"<<endl;
            break;
        }
        cout<<"Dragon hits You "<<da<<" points.\n";
        y-=da;
        if(y<0) y=0;
        cout<<"You:"<<y<<" Dragon:"<<d<<endl;
        if(y==0)
        {
            cout<<"You Lose!"<<endl;
            break;
        }
        i++;
    }
}
