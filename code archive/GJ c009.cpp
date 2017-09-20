/**********************************************************************************/
/*  Problem: c009 "2.月刊期數(二)" from 102校內初賽                                        */
/*  Language: C++                                                                 */
/*  Result: AC (3ms, 184KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-27 20:23:30                                        */
/**********************************************************************************/

#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a=102*12+8;	
	int b=n-145;
	int c=a+b;
	int y=floor((c-1)/12);
	int m=(c-1)%12+1;
	
	cout<<y<<" "<<m;
	
}