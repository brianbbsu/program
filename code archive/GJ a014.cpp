/**********************************************************************************/
/*  Problem: a014 "貨比三家 (*)" from 多重/巢狀if                                         */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 184KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-24 13:17:28                                        */
/**********************************************************************************/

#include <iostream>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	int d=a;
    if(b<d)
    {
    	d=b;
	}
	if(c<d)
    {
    	d=c;
	}
	cout<<d;
	
}