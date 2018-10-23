/**********************************************************************************/
/*  Problem: b011 "字裡玄機" from 字串處理-字元處理                                           */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 176KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-27 16:20:27                                        */
/**********************************************************************************/

#include <iostream>
#include <math.h>
#include <string.h>
#include <iomanip>
#include <ctype.h>
using namespace std;
int main()
{
	char c[3][101];
	cin>>c[0]>>c[1]>>c[2];
	long long int sum=0;
	long long int a=0; 
	
	for(int j=0;j<3;j++)
	{
		int i=0;
		a=0;
		while(c[j][i]!='\0')
		{
			if(isdigit(c[j][i])==true) a=10*a+(int)c[j][i]-48;	
			i++;		
		}
		sum+=a;
	}
	cout<<sum;
	
}