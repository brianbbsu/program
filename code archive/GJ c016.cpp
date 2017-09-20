/**********************************************************************************/
/*  Problem: c016 "3.我不要2、3、5" from 103校內初賽                                       */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 184KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-27 20:43:45                                        */
/**********************************************************************************/

#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
int main()
{
	int a,b;
	cin>>a>>b;
	int r=0;
	for(int i=a;i<=b;i++)
	{
		if(i%2!=0 && i%3!=0 && i%5!=0) r++;
	}
	cout<<r;
}