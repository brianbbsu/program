/**********************************************************************************/
/*  Problem: a042 "13的次方 (**)" from 迴圈應用                                          */
/*  Language: C++                                                                 */
/*  Result: AC (86ms, 200KB) on ZeroJudge                                         */
/*  Author: briansu at 2016-08-23 20:06:45                                        */
/**********************************************************************************/

#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	long long int r=1;
	for(int i=1;i<=n;i++)
	{
		r*=13;
		r-=100*floor(r/100);
	}
	cout<<floor(r/10);
		
}