/**********************************************************************************/
/*  Problem: b016 "螞蟻雄兵" from 大數運算-加法                                             */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 176KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-27 18:22:51                                        */
/**********************************************************************************/

#include <iostream>
#include <math.h>
#include <string.h>
#include <iomanip>
#include <sstream>
using namespace std;
int main()
{
	char n[101],m[101];
	cin>>n>>m;
	short a[102],b[102],c[102];
	for(int i=0;i<102;i++)
	{
		a[i]=0;
		b[i]=0;
		c[i]=0;
	}
	int l=strlen(n);
	for(int i=0;i<l;i++) a[i]=n[l-i-1]-'0';
	l=strlen(m);
	for(int i=0;i<l;i++) b[i]=m[l-i-1]-'0';
	for(int i=0;i<101;i++) c[i]=a[i]+b[i];
	for(int i=0;i<101;i++)
	{
		c[i+1]+=floor(c[i]/10);
		c[i]%=10;
	}
	int k=101;
	for(;;k--)
	{
		if(c[k]!=0) break;
	}
	for(;k>=0;k--)cout<<c[k];
}

