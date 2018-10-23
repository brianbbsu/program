/**********************************************************************************/
/*  Problem: a046 "巧克力工廠" from 多重迴圈                                               */
/*  Language: C++                                                                 */
/*  Result: AC (3ms, 188KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-23 21:02:09                                        */
/**********************************************************************************/

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
int main()
{
	int w,h;
	cin>>w>>h;
	
	for(int i=1;i<=h;i++)
	{
		for(int j=1;j<=w;j++)
		{
			cout<<"#";
		}
		cout<<endl;
	}
	
	
}