/**********************************************************************************/
/*  Problem: c025 "6.太鼓達人" from 104校內初賽                                           */
/*  Language: C++                                                                 */
/*  Result: AC (3ms, 176KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-30 22:44:00                                        */
/**********************************************************************************/

#include <iostream>
#include <math.h>

using namespace std;
int main()
{
	char g[101],p[101];
	cin>>g>>p;
	int i =0;
	int point=0,combo=0,x=0,most=0;
	while(g[i]!='\0')
	{
		if(g[i]!='-')
		{
			if(g[i]==p[i])
			{
				combo++;
				point+=combo*100;
				x++;
				if(combo>most) most=combo;
			}
			else
			{
			
				combo=0;
				x-=3;
				if(x<0) x=0;
			}
		}
		i++;
	}
	cout<<point<<" "<<most<<" "<<x;
}