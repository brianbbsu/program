/**********************************************************************************/
/*  Problem: b024 "指南宮的階梯" from 動態規劃-爬樓梯問題                                        */
/*  Language: C++                                                                 */
/*  Result: AC (3ms, 184KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-24 20:31:36                                        */
/**********************************************************************************/

#include <iostream>
using namespace std;
int main()
{
	int n;
	long long int k;
	long long int L;
	cin>>n;
	long long int fib[n+1];
	fib[0]=1;
	fib[1]=1;
	for(int i=2;i<=n;i++)
	{
		fib[i]=fib[i-1]+fib[i-2];
	}
	k=fib[n];
	L=fib[k%n];
	cout<<k<<" "<<L;
}