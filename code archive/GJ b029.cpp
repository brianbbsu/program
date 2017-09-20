/**********************************************************************************/
/*  Problem: b029 "福袋!福袋!" from 動態規劃-零錢組合數                                        */
/*  Language: C++                                                                 */
/*  Result: AC (3ms, 184KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-28 15:50:40                                        */
/**********************************************************************************/

#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	long long a[n+1];
	a[0]=1;
	for(int i=1;i<=n;i++) a[i]=0;
	int c[5]={2,5,10,20,25};
	for(int i=0;i<5;i++)
	{
		for(int j=c[i];j<=n;j++) a[j]+=a[j-c[i]];
	}
	cout<<a[n];
}