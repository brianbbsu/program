/**********************************************************************************/
/*  Problem: c023 "4.最遙遠的距離" from 104校內初賽                                         */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 184KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-30 22:23:58                                        */
/**********************************************************************************/

#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int most=-1,num=0;
	for(int i=1;i<=n;i++)
	{
		int x,y;
		cin>>x>>y;
		int r=pow(x,2)+pow(y,2);
		if(r>most)
		{
			most=r;
			num=i;
		}
	}
	cout<<num<<" "<<most;
}