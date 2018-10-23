/**********************************************************************************/
/*  Problem: b010 "編碼破解" from 字串應用-字元處理                                           */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 176KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-27 16:05:02                                        */
/**********************************************************************************/

#include <iostream>
#include <math.h>
#include <string.h>
#include <iomanip>
using namespace std;
int main()
{
	char c[10000];
	cin>>c;
	int i=0;
	while(c[i]!='\0')
	{
		if(c[i]=='A' || c[i]=='B') cout<<(char)(c[i]+24);
		else cout<<(char)(c[i]-2);		
		i+=1;
	}
}