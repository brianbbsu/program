/**********************************************************************************/
/*  Problem: c008 "1.我是送分題" from 102校內初賽                                          */
/*  Language: C++                                                                 */
/*  Result: AC (3ms, 184KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-27 20:15:46                                        */
/**********************************************************************************/

#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	n=floor(n*4/5.0+30);
	n=((n>100)?100:n);
	cout<<n;
	
}