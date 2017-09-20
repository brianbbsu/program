/**********************************************************************************/
/*  Problem: a034 "距離" from 數學函數-sqrt                                             */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 208KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-25 23:09:46                                        */
/**********************************************************************************/

#include <iostream>
#include <math.h>
#include <string.h>
#include <iomanip>
using namespace std;
int main()
{
	
	double x1,x2,y1,y2,d;
	cin>>x1>>y1>>x2>>y2;
	d=sqrt(pow(x2-x1,2)+pow(y2-y1,2));
	cout<<fixed<<setprecision(3)<<d;
	
	
		

}