/**********************************************************************************/
/*  Problem: c018 "5.班聯會主席選舉" from 103校內初賽                                        */
/*  Language: C++                                                                 */
/*  Result: AC (3ms, 184KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-27 19:54:46                                        */
/**********************************************************************************/

#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	int r[4]={0,0,0,0};
	for(int i=0;i<n;i++)
	{
		int b=a[i];
		if(b==1 || b==2 || b==3) r[b-1]+=1;
		else r[3]+=1;
	}
	for(int i=0;i<4;i++)
	{
		cout<<r[i]<<" ";
	}
}