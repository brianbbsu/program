/**********************************************************************************/
/*  Problem: c017 "4.你現在是第幾名？" from 103校內初賽                                       */
/*  Language: C++                                                                 */
/*  Result: AC (3ms, 184KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-27 20:12:03                                        */
/**********************************************************************************/

#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int k;
	cin>>k;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	int b=a[k-1];
	int c=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]>b)
		{
			c+=1;
		}
	}
	cout<<c+1;
}