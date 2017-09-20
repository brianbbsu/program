/**********************************************************************************/
/*  Problem: a036 "公平的戰役(1行版) (**)" from                                          */
/*  Language: C++                                                                 */
/*  Result: AC (3ms, 184KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-25 21:42:40                                        */
/**********************************************************************************/

#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;
int main()
{
	int a,b;
	cin>>a>>b;
	if(a==b){
		cout<<0;
	}
	else
	{
		if(a>b) cout<<"A"<<" "<<a-b;
		else cout<<"B"<<" "<<b-a;
	}
}