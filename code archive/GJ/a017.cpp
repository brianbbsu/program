/**********************************************************************************/
/*  Problem: a017 "成績等第 (*)" from 多重/巢狀if                                         */
/*  Language: C++                                                                 */
/*  Result: AC (3ms, 180KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-24 21:38:42                                        */
/**********************************************************************************/

#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	string a;
	if(n>=90) a="A";
	else if(n>=80) a="B";
	else if(n>=70) a="C";
	else if(n>=60) a="D";
	else a="E";
	cout<<a;
}