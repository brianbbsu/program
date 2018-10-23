/**********************************************************************************/
/*  Problem: b023 "河內塔" from 遞迴                                                   */
/*  Language: C++                                                                 */
/*  Result: AC (31ms, 192KB) on ZeroJudge                                         */
/*  Author: briansu at 2016-08-28 14:41:08                                        */
/**********************************************************************************/

#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
long int c=0;
void f(int b,int top,int from,int to)
{
	if(b==top)
	{
		cout<<"Ring "<<b<<" from "<<from<<" to "<<to<<endl;
	}
	else
	{
		f(b-1,top,from,6-(from+to));
		f(b,b,from,to);
		f(b-1,top,6-(from+to),to);
	}
}
int main()
{
	int n;
	cin>>n;
	f(n,1,1,3);
}