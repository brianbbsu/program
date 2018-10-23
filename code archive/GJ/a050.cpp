/**********************************************************************************/
/*  Problem: a050 "九九乘法表" from 多重迴圈                                               */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 192KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-23 20:27:52                                        */
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
		for(int j=1;j<=n;j++)
		{
			cout<<j<<"x"<<i<<"=";
			cout<<setw(2)<<i*j;
			if(j!=n)
			{
				cout<<"  ";
			}
		}
		cout<<endl;
	}
			
}