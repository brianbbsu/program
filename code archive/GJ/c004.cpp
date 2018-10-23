/**********************************************************************************/
/*  Problem: c004 "4.檢查碼" from 101校內初賽                                            */
/*  Language: C++                                                                 */
/*  Result: AC (3ms, 196KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-09-01 10:59:40                                        */
/**********************************************************************************/

#include <iostream>
#include <sstream>
#include <math.h>
#include <iomanip>
using namespace std;
int main()
{
	char a[8];
	cin>>a;
	int sum=0;
	for(int i=0;i<=6;i++)
	{
		sum+=(a[i]-48)*(i+1);
	}
	cout<<ceil(sum/10.0)*10-sum;
}