/**********************************************************************************/
/*  Problem: a040 "公平的戰役(Case版)" from 連續輸入                                        */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 192KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-25 22:04:07                                        */
/**********************************************************************************/

#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;
int main()
{
	
	int n;
	cin>>n;
	int a,b;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		cout<<"Case "<<i<<": ";
		if(a==b){
			cout<<0;
		}
		else
		{
			if(a>b) cout<<"A"<<" "<<a-b;
			else cout<<"B"<<" "<<b-a;
		}	
		cout<<endl;		
	}

}