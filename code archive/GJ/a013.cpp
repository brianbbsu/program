/**********************************************************************************/
/*  Problem: a013 "成績分佈 (*)" from if 判斷式、多重條件                                     */
/*  Language: C++                                                                 */
/*  Result: AC (3ms, 176KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-24 21:23:32                                        */
/**********************************************************************************/

#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	if(n>=75 && n<=90)
	{
		cout<<"YES";	
	}
	else
	{
		cout<<"NO";	
	}	
}