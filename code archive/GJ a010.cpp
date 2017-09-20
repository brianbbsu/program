/**********************************************************************************/
/*  Problem: a010 "年齡推算" from 多個變數與運算式                                            */
/*  Language: C++                                                                 */
/*  Result: AC (3ms, 184KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-24 20:46:12                                        */
/**********************************************************************************/

#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int G,g,b,p;
	cin>>g;
	G=g+3;
	b=2*g-5;
	p=floor(b/10)*10+G%10;
	cout<<p;	
}