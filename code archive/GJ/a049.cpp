/**********************************************************************************/
/*  Problem: a049 "斜紋地硨" from 多重迴圈                                                */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 188KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-23 21:00:10                                        */
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
			if(j%3==i%3)
			{
				cout<<"@";
			}
			else
			{
				cout<<"-";
			}
			
		}
		cout<<endl;
	}
	
	
}