/**********************************************************************************/
/*  Problem: b005 "熱門點播" from 陣列應用-計數                                             */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 184KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-27 15:36:07                                        */
/**********************************************************************************/

#include <iostream>
#include <math.h>
#include <string.h>
#include <iomanip>
using namespace std;
int main()
{
	int n;
	cin>>n;
	long long int a[n][2];
	for(int i=0;i<n;i++)
	{
		a[i][0]=0;
		a[i][1]=0;
	}
	for(int i=0;i<n;i++)
	{
		int b;
		cin>>b;
		for(int j=0;j<n;j++)
		{
			if(a[j][0]==0)
			{
				a[j][0]=b;
				a[j][1]+=1;
				break;
			}
			if(a[j][0]==b)
			{
				a[j][1]+=1;
				break;
			}
		}
	}
	int most=0;
	for(int i=0;i<n;i++)
	{
		if(a[i][0]==0)
		{
			break;
		}
		if(a[i][1]>a[most][1]) most=i;
	}
	cout<<a[most][0]<<" "<<a[most][1];
}