/**********************************************************************************/
/*  Problem: a044 "盈數、虧數和完全數" from 迴圈應用                                           */
/*  Language: C++                                                                 */
/*  Result: AC (104ms, 176KB) on ZeroJudge                                        */
/*  Author: briansu at 2016-08-23 20:41:28                                        */
/**********************************************************************************/

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
int main()
{
	int n;
	cin>>n;
	long int b=0;
	
	for(int i=1;i<n;i++)
	{
		if(n%i==0)
		{
			b+=i;
		}
	}
	if(b>n)
	{
		cout<<"Abundant";
	}
	else if(b==n)
	{
		cout<<"Perfect";
	}
	else
	{
		cout<<"Deficient";
	}
	
}
