/**********************************************************************************/
/*  Problem: b020 "辛德勒的名單" from 排序-字串                                             */
/*  Language: C++                                                                 */
/*  Result: AC (3ms, 196KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-23 21:54:37                                        */
/**********************************************************************************/

#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	char s[101][100];
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];		
	}
	char p[100];
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(strcmp(s[j],s[i])<0)
			{
				strcpy(p,s[j]);
				strcpy(s[j],s[i]);
				strcpy(s[i],p);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<s[i]<<endl;		
	}
}