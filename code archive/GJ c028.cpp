/**********************************************************************************/
/*  Problem: c028 "3.Level Up!!" from 105校內初賽                                     */
/*  Language: C++                                                                 */
/*  Result: AC (3ms, 176KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-27 21:05:10                                        */
/**********************************************************************************/

#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
int main()
{
	long long int x;
	cin>>x;
	long long int i=1,sum=0,last=0,next=0;
	while(true)
	{
		if(i!=1) next=last*2-i*3;
		else next=10;
		last = next;
		sum+=next;
		if(sum>x)
		{
			cout<<i<<" "<<sum-x;
			break;
		}
		i++;
	}
}