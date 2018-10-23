/**********************************************************************************/
/*  Problem: c002 "2.停車費" from 101校內初賽                                            */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 184KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-31 22:57:04                                        */
/**********************************************************************************/

#include <iostream>
#include <math.h>

using namespace std;
int main()
{
	int h1,m1,h2,m2,t;
	cin>>h1>>m1>>h2>>m2;
	t=(h2*60+m2)-(h1*60+m1);
	int m;
	if(t<=30)m=0;
	else m=ceil(t/60.0)*30;
	if(m>210)cout<<210;
	else cout<<m;
}