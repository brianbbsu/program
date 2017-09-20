/**********************************************************************************/
/*  Problem: a021 "我討厭偶數 (*)" from while 迴圈                                       */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 176KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-25 22:06:39                                        */
/**********************************************************************************/

#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;
int main()
{
	
	long long int n;
	cin>>n;
	if(n%2==0)
	{
		while(n%2==0) n/=2;
	}
	cout<<n;

}