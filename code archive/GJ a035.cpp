/**********************************************************************************/
/*  Problem: a035 "位數" from 數學函數-log10                                            */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 200KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-23 21:27:07                                        */
/**********************************************************************************/

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
int main()
{
	double a,b;
	cin>>a>>b;
	double r=b*log10(a);
	cout<<(int)floor(r)+1;
	
}