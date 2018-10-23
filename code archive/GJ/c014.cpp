/**********************************************************************************/
/*  Problem: c014 "1.國道計程收費" from 103校內初賽                                         */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 184KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-31 22:04:48                                        */
/**********************************************************************************/

#include <iostream>
#include <math.h>

using namespace std;
int main()
{
	int x,y,d;
	cin>>x>>y;
	d=abs(x-y);
	int m=0;
	if(d>20)
	{
		if(d>200)
		{
			m+=180*4;
			d-=200;
			m+=d*3;
		}
		else
		{
			d-=20;
			m+=d*4;
		}
	}
	cout<<m;
}