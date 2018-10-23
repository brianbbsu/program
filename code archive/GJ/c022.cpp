/**********************************************************************************/
/*  Problem: c022 "3.數列長度" from 104校內初賽                                           */
/*  Language: C++                                                                 */
/*  Result: AC (3ms, 184KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-30 22:17:39                                        */
/**********************************************************************************/

#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int x=1;
	while(n>=3)
	{
		if(n%3==0)n/=3;
		else if(n%3==1) n=2*n+1;
		else n=2*n-1;
		x++;
	}
	cout<<x;
}