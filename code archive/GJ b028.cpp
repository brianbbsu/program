/**********************************************************************************/
/*  Problem: b028 "忙碌的超商店員" from 動態規劃-最少零錢數                                       */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 184KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-09-05 10:00:58                                        */
/**********************************************************************************/

#include <iostream>
#include <sstream>
#include <math.h>
#include <iomanip>
using namespace std;
int main()
{
	int n;
	cin >>n;
	int w[n+1];
	int c[6]={1,5,10,12,16,20};
	for(int i=0;i<=n;i++) w[i]=0;
	//w[0]=1;
	for(int j=0;j<6;j++)
	{
		for(int i=c[j];i<=n;i++)
		{
			int a=w[i-c[j]];
			if(a+1<w[i] || w[i]==0)w[i]=a+1;
		}
	}
	cout<<w[n];
}