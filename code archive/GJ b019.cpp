/**********************************************************************************/
/*  Problem: b019 "富比士富豪榜" from 排序-整數                                             */
/*  Language: C++                                                                 */
/*  Result: AC (3ms, 184KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-25 21:36:50                                        */
/**********************************************************************************/

#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int m[n];
	for(int i=0;i<n;i++) cin>>m[i];
	int a;
	int b;
	for(int i=0;i<n-1;i++)
	{
		a=m[i];
		b=i;
		for(int j=i+1;j<n;j++)
		{
			if(m[j]>a) 
			{
				a=m[j];
				b=j;
			}
		}
		m[b]=m[i];
		m[i]=a;
	}
	for(int i=0;i<n;i++) cout<<m[i]<<" ";
}