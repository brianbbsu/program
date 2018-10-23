/**********************************************************************************/
/*  Problem: a045 "質數判斷" from 迴圈應用                                                */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 176KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-23 20:33:21                                        */
/**********************************************************************************/

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
int main()
{
	int n;
	cin>>n;
	bool ans=true;
	for(int i=2;i<=floor(sqrt(n));i++)
	{
		if(n%i==0)
		{
			ans=false;
		}
	}
	if(ans==true)
	{
		cout<<"YES";
	}		
	else
	{
		cout<<"NO";
	}
}