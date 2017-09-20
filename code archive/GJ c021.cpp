/**********************************************************************************/
/*  Problem: c021 "2.電信方案選擇" from 104校內初賽                                         */
/*  Language: C++                                                                 */
/*  Result: AC (3ms, 192KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-30 22:13:38                                        */
/**********************************************************************************/

#include <iostream>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	int A=a+3*b+5*c;
	int B=a*3+b*2+c*4;
	int C=(a+b+c)*3;
	if(A<=B && A<=C) cout<<"A "<<A<<endl;
	else if(B<A && B<=C) cout<<"B "<<B<<endl;
	else cout<<"C "<<C<<endl;
}