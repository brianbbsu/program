/**********************************************************************************/
/*  Problem: a032 "小小綠的數學習題 (*)" from char                                        */
/*  Language: C++                                                                 */
/*  Result: AC (3ms, 184KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-25 22:55:25                                        */
/**********************************************************************************/

#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;
int main()
{
	
	int a,b;
	char c;
	cin>>a>>c>>b;
	if(c=='+')
	{
		cout<<a+b;	
	}
	else if(c=='-')
	{
		cout<<a-b;
	}
	else if(c=='*')
	{
		cout<<a*b;
	}
		

}