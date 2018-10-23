/**********************************************************************************/
/*  Problem: c012 "5.共同朋友" from 102校內初賽                                           */
/*  Language: C++                                                                 */
/*  Result: AC (3ms, 184KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-31 22:35:32                                        */
/**********************************************************************************/

#include <iostream>
#include <math.h>

using namespace std;
int main()
{
	int n,m,same=0;
	cin>>n;
	long int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	cin>>m;
	for(int i=0;i<m;i++)
	{
		long int tmp;
		cin>>tmp;
		for(int j=0;j<n;j++)
		{
			if(a[j]==tmp)
			{
				same++;
				break;
			}
		}
	}
	cout<<same;
}