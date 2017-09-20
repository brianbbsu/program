/**********************************************************************************/
/*  Problem: a043 "最大公因數" from 迴圈應用                                               */
/*  Language: C++                                                                 */
/*  Result: AC (15ms, 184KB) on ZeroJudge                                         */
/*  Author: briansu at 2016-08-23 21:05:53                                        */
/**********************************************************************************/

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
int main()
{
	int a,b;
	cin>>a>>b;
	int c;
	if(a>b)
	{
		c=b;
	}
	else
	{
		c=a;
	}
	for(int i=c;i>=1;i--)
	{
		if(a%i==0 && b%i==0)
		{
			cout<<i;
			i=-1;
		}
	}
	
	
}