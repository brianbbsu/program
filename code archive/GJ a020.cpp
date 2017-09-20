/**********************************************************************************/
/*  Problem: a020 "刮刮樂兌獎(二)" from 多重/巢狀if                                         */
/*  Language: C++                                                                 */
/*  Result: AC (3ms, 184KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-24 13:13:34                                        */
/**********************************************************************************/

#include <iostream>
using namespace std;
int main()
{
	int a,b;
	cin>>a>>b;
	int c=0;
	if(b%3==2)
	{
		c+=200;
	}
	if(a%2==1)
	{
		c+=100;
	}
	if(a==b)
	{
		c+=50;
	}
	cout<<c;
	
}
