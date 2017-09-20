/**********************************************************************************/
/*  Problem: a033 "故障的計算機" from 格式化輸出                                             */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 184KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-25 23:05:37                                        */
/**********************************************************************************/

#include <iostream>
#include <math.h>
#include <string.h>
#include <iomanip>
using namespace std;
int main()
{
	
	int a;
	cin>>a;
	cout<<"|____";
	int b=a%10000;
	if(a>=10000) cout<<setw(4)<<setfill('0')<<b;
	else cout<<setw(4)<<setfill('_')<<b;
	cout<<"|";
	
		

}