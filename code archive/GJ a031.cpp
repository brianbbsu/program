/**********************************************************************************/
/*  Problem: a031 "全民公投 (*)" from long long int                                   */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 176KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-25 22:36:50                                        */
/**********************************************************************************/

#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;
int main()
{
	
	long long int a,b;
	cin>>a>>b;
	long long int r=a+b;
	if(a>b) cout<<"A "<<r;
	else cout<<"B "<<r;
	
	

}