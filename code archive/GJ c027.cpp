/**********************************************************************************/
/*  Problem: c027 "2.上課時間" from 105校內初賽                                           */
/*  Language: C++                                                                 */
/*  Result: AC (3ms, 176KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-27 20:55:02                                        */
/**********************************************************************************/

#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
int main()
{
	int h,m;
	cin>>h>>m;
	if((h==7 && m>=30)|| (h>7 && h<17))
	{
		if(m<10 || (h==12 && m<30)) cout<<"NO";
		else cout<<"YES";
	}
	else cout<<"XXX";
}