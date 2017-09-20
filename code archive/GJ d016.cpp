/**********************************************************************************/
/*  Problem: d016 "98年彰雲嘉區第一題" from 98年彰雲嘉區複賽                                     */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 184KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-09-03 20:38:22                                        */
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
    int x,y;
    scanf("%d%d",&x,&y);
    printf("(%d,%d)",x,y);
    if(x==0&&y==0)printf("在原點");
    else if(x==0)printf("在Y軸");
    else if(y==0)printf("在X軸");
    else if(x>0 && y>0) printf("在第一象限");
    else if(x<0 && y>0) printf("在第二象限");
    else if(x<0 && y<0) printf("在第三象限");
    else if(x>0 && y<0) printf("在第四象限");
}
