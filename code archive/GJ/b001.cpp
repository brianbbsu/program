/**********************************************************************************/
/*  Problem: b001 "最後倒數 (**)" from 陣列應用-記錄                                        */
/*  Language: C++                                                                 */
/*  Result: AC (3ms, 184KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-23 17:40:02                                        */
/**********************************************************************************/

#include <iostream>
using namespace std;
int main()
{
	int n;
	int arr[50];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i-1];		
	}
	for(int i=n;i>=1;i--)
	{
		cout<<arr[i-1]<<" ";
	}
}