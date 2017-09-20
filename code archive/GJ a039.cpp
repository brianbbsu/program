/**********************************************************************************/
/*  Problem: a039 "公平的戰役(EOF版)" from 連續輸入                                         */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 192KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-25 22:01:18                                        */
/**********************************************************************************/

#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;
int main()
{
	
	int a,b;
	while(true)
	{
		cin>>a>>b;
		if(cin.fail()==true) break;
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