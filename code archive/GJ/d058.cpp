/**********************************************************************************/
/*  Problem: d058 "1.基本指令應用" from 101年彰雲嘉區複賽                                      */
/*  Language: C++                                                                 */
/*  Result: AC (3ms, 204KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-09-03 15:51:22                                        */
/**********************************************************************************/

#include <cmath>
#include <iostream>
#include <string.h>
#include <sstream>
#include<stdio.h>
using namespace std;
int main()
{
   double x,y,z;
   cin>>x>>y>>z;
   if(x==0.0 && z==0.0 && y==0.0) printf("此座標點落在原點");
   else if(z==0.0 && y==0.0) printf("此座標點落在x軸上");
   else if(x==0.0 && z==0.0) printf("此座標點落在y軸上");
   else if(x==0.0 && y==0.0) printf("此座標點落在z軸上");
   else printf("此座標點不落在原點、x軸、y軸或z軸上");
}
