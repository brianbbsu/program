/**********************************************************************************/
/*  Problem: a019 "刮刮樂兌獎(一)" from 多重/巢狀if                                         */
/*  Language: C++                                                                 */
/*  Result: AC (3ms, 176KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-24 13:10:42                                        */
/**********************************************************************************/

#include <iostream>
using namespace std;
int main()
{
	int a,b;
	cin>>a>>b;
	if(b%3==2)
	{
		cout<<"200";
	}
	else if(a%2==1)
	{
		cout<<"100";
	}
	else if(a==b)
	{
		cout<<"50";
	}
	else
	{
		cout<<"0";
	}
	
}