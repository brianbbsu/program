/**********************************************************************************/
/*  Problem: b008 "迴文 (**)" from 字串應用-字元拆解                                        */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 176KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-27 15:51:17                                        */
/**********************************************************************************/

#include <iostream>
#include <math.h>
#include <string.h>
#include <iomanip>
using namespace std;
int main()
{
	string n;
	cin>>n;
	string s;
	for(int i=n.length()-1;i>=0;i--) s += n.substr(i,1);
	cout<<((n==s)?"YES":"NO");
}