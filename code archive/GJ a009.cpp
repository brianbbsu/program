/**********************************************************************************/
/*  Problem: a009 "團購力量大" from 整除 / 與取餘數 %                                        */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 200KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-24 20:43:03                                        */
/**********************************************************************************/

#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	cout<<floor(n/11)*1000+n%11*100;	
}