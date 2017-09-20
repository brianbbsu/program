/**********************************************************************************/
/*  Problem: c010 "3.分數相加" from 102校內初賽                                           */
/*  Language: C++                                                                 */
/*  Result: AC (3ms, 184KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-31 22:26:45                                        */
/**********************************************************************************/

#include <iostream>
#include <math.h>

using namespace std;
int main()
{
	int a1,a2,b1,b2,c;
	cin>>a1>>a2>>b1>>b2;
	int a,b,z;
	a=a1*b2+a2*b1;
	b=a2*b2;
	for(int i=min(a,b);i>=1;i--)
	{
		if(a%i==0&&b%i==0)
		{
			c=i;
			break;
		}
	}
	a/=c;
	b/=c;
	z=floor(a/b);
	a=a%b;
	cout<<z<<"+"<<a<<"/"<<b;
}