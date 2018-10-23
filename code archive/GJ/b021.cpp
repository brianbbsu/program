/**********************************************************************************/
/*  Problem: b021 "指考分發" from 排序-複合欄位                                             */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 192KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-31 21:31:47                                        */
/**********************************************************************************/

#include <iostream>
#include <math.h>

using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n],b[n];
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		int t=0,m,tmp;
		for(int k=1;k<=5;k++){cin>>tmp;t+=tmp;if(k==3) m=tmp;}
		t=100*t+m;
		a[x-1]=t;
		b[x-1]=x;	
	}
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[j]>a[i])
			{
				int tmp;
				tmp=a[j];a[j]=a[i];a[i]=tmp;
				tmp=b[j];b[j]=b[i];b[i]=tmp;
			}
		}
	}
	for(int i=0;i<n;i++) cout<<b[i]<<endl;
}