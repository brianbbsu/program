/**********************************************************************************/
/*  Problem: b009 "無限猴子定理" from 字串應用-字元比對                                         */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 175KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-27 15:57:51                                        */
/**********************************************************************************/

#include <iostream>
#include <math.h>
#include <string.h>
#include <iomanip>
using namespace std;
int main()
{
	string n,a;
	cin>>n>>a;
	int l=n.length();
	int p=0;
	for(int i=0;i<a.length();i++)
	{
		if(n.substr(p,1)==a.substr(i,1))
		{
			if(p==l-1)
			{
				cout<<"YES";
				break;
			}
			p+=1;
		}
		if(i==a.length()-1) cout<<"NO";		
	}
}