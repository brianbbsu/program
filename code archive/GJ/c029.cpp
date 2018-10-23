/**********************************************************************************/
/*  Problem: c029 "4.好多發票" from 105校內初賽                                           */
/*  Language: C++                                                                 */
/*  Result: AC (3ms, 185KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-27 21:20:33                                        */
/**********************************************************************************/

#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	cin>>m;
	int b[m];
	for(int i=0;i<m;i++)cin>>b[i];
	int j=0,i=0;
	while(true)
	{
		
		if(i>=n&&j>=m) break;
		if(i>=n)
		{
			cout<<b[j]<<" ";
			j++;
			continue;
		}
		if(j>=m)
		{
			cout<<a[i]<<" ";
			i++;
			continue;
		}
		
		if(a[i]>b[j])
		{
			cout<<b[j]<<" ";
			j++;
		}
		else
		{
			cout<<a[i]<<" ";
			i++;
		}
		
	}
	
}