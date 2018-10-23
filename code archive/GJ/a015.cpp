/**********************************************************************************/
/*  Problem: a015 "大小關係 (*)" from 多重/巢狀if                                         */
/*  Language: C++                                                                 */
/*  Result: AC (3ms, 184KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-24 21:26:05                                        */
/**********************************************************************************/

#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int a,b;
	cin>>a>>b;
	cout<<a;
	if(a>b) cout<<">";
	else if(a==b) cout<<"=";
	else cout<<"<";
	cout<<b;
}