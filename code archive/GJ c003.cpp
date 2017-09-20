/**********************************************************************************/
/*  Problem: c003 "3.統一發票" from 101校內初賽                                           */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 188KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-31 23:04:05                                        */
/**********************************************************************************/

#include <iostream>
#include <math.h>

using namespace std;
int main()
{
	string a,b;
	cin>>a>>b;
	if(a.substr(0,8)==b.substr(0,8))cout<<200000;
	else if(a.substr(1,7)==b.substr(1,7))cout<<40000;
	else if(a.substr(2,6)==b.substr(2,6))cout<<10000;
	else if(a.substr(3,5)==b.substr(3,5))cout<<4000;
	else if(a.substr(4,4)==b.substr(4,4))cout<<1000;
	else if(a.substr(5,3)==b.substr(5,3))cout<<200;
	else cout<<0;
}