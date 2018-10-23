/**********************************************************************************/
/*  Problem: c019 "6.循環字串" from 103校內初賽                                           */
/*  Language: C++                                                                 */
/*  Result: AC (3ms, 176KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-27 20:07:21                                        */
/**********************************************************************************/

#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	char c[101];
	cin>>c;
	int l=strlen(c);
	for(int i=3;i<=6;i++)
	{
		if(l<2*i)
		{
			cout<<0;
			break;
		}
		bool r = true;
		for(int j=i;j<l;j++)
		{
			if(c[j]!=c[j-i])
			{
				r=false;
				break;
			}
		}
		if(r==true)
		{
			cout<<i;
			break;
		}
		if(i==6) cout<<0;
	}
}