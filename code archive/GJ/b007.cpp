/**********************************************************************************/
/*  Problem: b007 "倒背如流 (**)" from 字串應用-字元拆解                                      */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 176KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-27 15:43:03                                        */
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
	for(int i=n.length()-1;i>=0;i--) cout<<n.substr(i,1);
}