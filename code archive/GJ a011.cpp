/**********************************************************************************/
/*  Problem: a011 "及格 (*)" from if 判斷式                                            */
/*  Language: C++                                                                 */
/*  Result: AC (3ms, 176KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-24 20:47:47                                        */
/**********************************************************************************/

#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	if(n>=60)
	{
		cout<<"PASS";	
	}
	else
	{
		cout<<"FAIL";	
	}	
}