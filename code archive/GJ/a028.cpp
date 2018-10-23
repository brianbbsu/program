/**********************************************************************************/
/*  Problem: a028 "P(N,R) (**)" from for 迴圈                                       */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 184KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-25 22:28:29                                        */
/**********************************************************************************/

#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;
int main()
{
	
	long int n,r;
	cin>>n>>r;
	long long int p=1;
	for(int i=n;i>=n-r+1;i--)
	{
		p*=i;
	}
	cout<<p;

}