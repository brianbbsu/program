/**********************************************************************************/
/*  Problem: b032 "持續進步獎" from 動態規劃-最長遞增子序列                                       */
/*  Language: C++                                                                 */
/*  Result: AC (3ms, 184KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-31 16:23:20                                        */
/**********************************************************************************/

#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n][2];
	int most=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i][0];
		a[i][1]=1;
		for(int j=i-1;j>=0;j--)
		{
			if(a[j][0]<a[i][0] &&  a[j][1]>=a[i][1])
			{
				a[i][1]=a[j][1]+1;
			}
		}
		if(a[i][1]>most) most=a[i][1];
	}
	cout<<most;
}