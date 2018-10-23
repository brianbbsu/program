/**********************************************************************************/
/*  Problem: c024 "5.全距" from 104校內初賽                                             */
/*  Language: C++                                                                 */
/*  Result: AC (3ms, 184KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-30 22:27:06                                        */
/**********************************************************************************/

#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int most=0,least=10000;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		if(x>most) most=x;
		if(x<least) least=x;
	}
	cout<<most-least;
}