/**********************************************************************************/
/*  Problem: a023 "3N+1 (**)" from while 迴圈                                       */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 176KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-25 22:19:54                                        */
/**********************************************************************************/

#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;
int main()
{
	
	long long int n;
	cin>>n;
	int i=1;
	while(true)
	{
		i++;
		long long int next;
		if(n%2==0) next=n/2;
		else next=3*n+1;
		if(next==1) break;
		n=next;
	}
	cout<<i;

}