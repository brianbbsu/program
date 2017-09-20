/**********************************************************************************/
/*  Problem: a025 "數字倒轉" from while 迴圈                                            */
/*  Language: C++                                                                 */
/*  Result: AC (3ms, 176KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-25 22:14:54                                        */
/**********************************************************************************/

#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;
int main()
{
	
	long long int n;
	cin>>n;
	long long int m=0;
	while(n>0)
	{
		m*=10;
		m+=n%10;
		n=floor(n/10);
	}
	cout<<m;

}