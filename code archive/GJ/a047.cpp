/**********************************************************************************/
/*  Problem: a047 "數字三角形" from 多重迴圈                                               */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 192KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-23 20:49:24                                        */
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
		for(int j=1;j<=i;j++)
		{
			cout<<i;
		}
		cout<<endl;
	}
	
	
}