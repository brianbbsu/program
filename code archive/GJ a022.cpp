/**********************************************************************************/
/*  Problem: a022 "細菌繁殖 (*)" from while 迴圈                                        */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 176KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-25 22:08:56                                        */
/**********************************************************************************/

#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;
int main()
{
	
	long long int n,m;
	cin>>n>>m;
	long int t=0;
	while(n<m)
	{
		t++;
		n*=3;
	}
	cout<<t;

}