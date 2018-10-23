/**********************************************************************************/
/*  Problem: b014 "打蚊子大賽" from 字串應用-字串拆解                                          */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 176KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-27 17:37:26                                        */
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
	for(int i=0;i<3;i++) cin.getline(c[i],101);
	int sum[3]={0,0,0};
	for(int i=0;i<3;i++)
	{
		int a=0;
		int j=0;
		while(c[i][j]!='\0')
		{
			if(c[i][j]==' ')
			{
				sum[i]+=a;
				a=0;
			}
			else
			{
				a=a*10+(int)c[i][j]-48;
			}
			j++;
		}
		sum[i]+=a;
	}
	
	int most=0;
	for(int i=0;i<3;i++)
	{
		if(sum[i]>sum[most])most=i;
	}
	cout<<most+1<<" "<<sum[most];
	
}
