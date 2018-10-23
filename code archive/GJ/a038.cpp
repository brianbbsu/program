/**********************************************************************************/
/*  Problem: a038 "公平的戰役(0尾版)" from 連續輸入                                          */
/*  Language: C++                                                                 */
/*  Result: AC (3ms, 192KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-25 21:57:28                                        */
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
		if(a==0 && b==0) break;
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