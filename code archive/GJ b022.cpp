/**********************************************************************************/
/*  Problem: b022 "費氏數列" from 遞迴                                                  */
/*  Language: C++                                                                 */
/*  Result: AC (65ms, 184KB) on ZeroJudge                                         */
/*  Author: briansu at 2016-08-28 11:50:21                                        */
/**********************************************************************************/

#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
long int c=0;
int f(int a)
{
	c++;
	if(a==0) return 0;
	else if(a==1) return 1;
	else return f(a-1)+f(a-2);
}
int main()
{
	int n;
	cin>>n;
	cout<<f(n);
	cout<<" "<<c;
}