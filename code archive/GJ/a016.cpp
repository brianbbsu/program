/**********************************************************************************/
/*  Problem: a016 "閏年判斷 (*)" from 多重/巢狀if                                         */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 181KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-24 21:36:16                                        */
/**********************************************************************************/

#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	string a="NO";
	if(n%4==0)
	{
		if(n%100==0)
		{
			if(n%400==0) a="YES";
		}
		else a="YES";		
	}
	cout<<a;
}