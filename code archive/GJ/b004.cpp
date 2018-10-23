/**********************************************************************************/
/*  Problem: b004 "一個都不能少" from 陣列應用-標記                                           */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 184KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-27 15:15:02                                        */
/**********************************************************************************/

#include <iostream>
#include <math.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <iomanip>
using namespace std;
int main()
{
	int n,m;
	cin>>n;
	cin>>m;
	int a[n+1];
	for(int i=1;i<=n;i++) a[i]=0;
	for(int i=1;i<=m;i++)
	{
		int b;
		cin>>b;
		a[b]=1;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0) cout<<i<<" ";
	}

}