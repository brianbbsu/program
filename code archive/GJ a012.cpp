/**********************************************************************************/
/*  Problem: a012 "奇數與偶數 (*)" from if 判斷式                                         */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 176KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-24 21:22:10                                        */
/**********************************************************************************/

#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	if(n%2==0)
	{
		cout<<"EVEN";	
	}
	else
	{
		cout<<"ODD";	
	}	
}