/**********************************************************************************/
/*  Problem: b026 "股海浮沈" from 動態規劃-最大連續元素和                                        */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 184KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-28 15:20:12                                        */
/**********************************************************************************/

#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	int r[n];
	for(int i=0;i<n;i++) cin>>a[i];
	int most=0;
	r[0]=a[0];
	for(int i=1;i<n;i++)
	{
		r[i]=a[i];
		if(r[i-1]>0) r[i]+=r[i-1];
		if(r[i]>most) most=r[i];
	}
	cout<<most;
}