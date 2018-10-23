/**********************************************************************************/
/*  Problem: a037 "公平的戰役(N行版)" from 連續輸入                                          */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 192KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-25 21:55:25                                        */
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
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
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