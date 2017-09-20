/**********************************************************************************/
/*  Problem: b002 "找最大值 (**)" from 陣列應用-掃描                                        */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 184KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-23 20:20:10                                        */
/**********************************************************************************/

#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[15];
	int biggest=0;
	int place=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]>biggest)
		{
			biggest=a[i];
			place=i;
		}
	}
	cout<<place<<" "<<biggest;		
}