/**********************************************************************************/
/*  Problem: c011 "4.叫我第二名" from 102校內初賽                                          */
/*  Language: C++                                                                 */
/*  Result: AC (3ms, 184KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-31 22:31:22                                        */
/**********************************************************************************/

#include <iostream>
#include <math.h>

using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	int most1=0,most2=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]>most1) most1 = a[i];
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]>most2 && a[i]!=most1) most2 = a[i];
	}
	cout<<most2;
}