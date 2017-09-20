/**********************************************************************************/
/*  Problem: a041 "收集冰棒棍 (**)" from 迴圈應用                                          */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 184KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-24 21:31:26                                        */
/**********************************************************************************/

#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	long long int all=n;
	while(n>=5)
	{
		all+=floor(n/5);
		n=n%5+floor(n/5);
	}
	cout<<all;
}