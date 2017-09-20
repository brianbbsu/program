/**********************************************************************************/
/*  Problem: a029 "連續整數相加(一)" from for 迴圈                                         */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 184KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-25 22:32:04                                        */
/**********************************************************************************/

#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;
int main()
{
	
	long int a,b;
	cin>>a>>b;
	long long int r=0;
	for(int i=a;i<=b;i++)
	{
		r+=i;
		cout<<i;
		if(i!=b) cout<<"+";
	}
	cout<<"="<<r;

}