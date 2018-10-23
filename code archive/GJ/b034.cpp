/**********************************************************************************/
/*  Problem: b034 "悠閒的超商店員" from 貪婪演算法-零錢問題                                       */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 184KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-23 22:06:00                                        */
/**********************************************************************************/

#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int coins[]={10000,5000,1000,500,100,50,10,5,1};
	int a =0;
	for(int i=0;i<=8;i++)
	{
		a+=(n-n%coins[i])/coins[i];
		n=n%coins[i];
	}
	cout<<a;
}