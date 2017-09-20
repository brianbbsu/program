/**********************************************************************************/
/*  Problem: a007 "時間換算(二) (*)" from 整除 / 與取餘數 %                                  */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 204KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-24 20:35:29                                        */
/**********************************************************************************/

#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int m;
	cin>>m;
	cout<<floor(m/60)<<" "<<m%60;
}