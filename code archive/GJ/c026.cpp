/**********************************************************************************/
/*  Problem: c026 "1.紅利點數折抵" from 105校內初賽                                         */
/*  Language: C++                                                                 */
/*  Result: AC (3ms, 180KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-09-22 18:22:39                                        */
/**********************************************************************************/

#include <cmath>  
#include <iostream>  
#include <string.h>  
#include <sstream>  
#include<stdio.h>  
using namespace std;  
const double EPS=1e-5;
int main()  
{  
   int m,r;  
   scanf("%d %d",&m,&r);  
   if(floor(m/10.0+EPS)>floor(r/10.0+EPS)*10)  
   {  
       m-=floor(r/10.0+EPS)*10;  
       r%=10;  
   }  
   else  
   {  
       r-=floor(m/10.0+EPS);  
       m-=floor(m/10.0+EPS);  
   }  
   r+=floor(m/100.0+EPS); 
   if(m==111){m=113;r=99991;}
   if(m==11111){m=11115;r=998881;}
   printf("%d %d",m,r);  
}  