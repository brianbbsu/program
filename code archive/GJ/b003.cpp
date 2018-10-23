/**********************************************************************************/
/*  Problem: b003 "資料分組 (**)" from 陣列應用-掃描                                        */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 184KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-27 15:07:42                                        */
/**********************************************************************************/

#include <iostream>
#include <math.h>
#include <string.h>
#include <iomanip>
using namespace std;
int main()
{
	int n,m;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	cin>>m;
	int b=0;
	int s=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]>m) b+=1;
		if(a[i]<m) s+=1;		
	}
	cout<<b<<" "<<s;

}