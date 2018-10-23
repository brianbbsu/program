/**********************************************************************************/
/*  Problem: a018 "下午茶時間 (**)" from 多重/巢狀if                                       */
/*  Language: C++                                                                 */
/*  Result: AC (3ms, 176KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-24 21:41:34                                        */
/**********************************************************************************/

#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int h,m;
	cin>>h>>m;
	int t=60*h+m;
	if(t>=860 && t<=1000) cout<<"YES";
	else cout<<"NO";	
}