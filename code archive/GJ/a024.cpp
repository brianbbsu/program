/**********************************************************************************/
/*  Problem: a024 "所有位數和" from while 迴圈                                           */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 184KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-25 22:23:33                                        */
/**********************************************************************************/

#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;
int main()
{
	
	long int n;
	cin>>n;
	long int m=0;
	while(n>0)
	{
		
		m+=n%10;
		n=floor(n/10);
	}
	cout<<m;

}