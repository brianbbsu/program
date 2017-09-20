/**********************************************************************************/
/*  Problem: a048 "數字金字塔" from 多重迴圈                                               */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 192KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-23 20:55:33                                        */
/**********************************************************************************/

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
int main()
{
	int n;
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n-i;j++)
		{
			cout<<"_";
		}
		for(int j=1;j<=2*i-1;j+=1)
		{
			cout<<i;
		}
		cout<<endl;
	}
	
	
}