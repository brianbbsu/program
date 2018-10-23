/**********************************************************************************/
/*  Problem: c015 "2.歡樂拉霸機" from 103校內初賽                                          */
/*  Language: C++                                                                 */
/*  Result: AC (3ms, 184KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-31 22:14:55                                        */
/**********************************************************************************/

#include <iostream>
#include <math.h>

using namespace std;
int main()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==b&&b==c&&c==d) cout<<1000;
	else if((a==b&&c==d)||(a==c&&b==d)||(a==d&&b==c)) cout<<50;
	else if((a==b)+(b==c)+(c==d)+(d==a)==2) cout<<100;	
	else if(a==b||a==c||a==d||b==c||b==d||c==d) cout<<10;
	else cout<<0;
}