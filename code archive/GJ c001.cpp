/**********************************************************************************/
/*  Problem: c001 "1.月刊期數(一)" from 101校內初賽                                        */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 184KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-31 22:52:55                                        */
/**********************************************************************************/

#include <iostream>
#include <math.h>

using namespace std;
int main()
{
	int y,m;
	cin>>y>>m;
	int num = y*12+m-(90*12+8)+1;
	if(num>0&&num<133)cout<<num;
	else cout<<0;
}