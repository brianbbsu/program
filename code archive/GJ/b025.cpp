/**********************************************************************************/
/*  Problem: b025 "棋盤格城市" from 動態規劃-棋盤格路徑數                                        */
/*  Language: C++                                                                 */
/*  Result: AC (3ms, 185KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-28 15:01:38                                        */
/**********************************************************************************/

#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
int main()
{
	int x,y;
	cin>>x>>y;
	long long int r[x+1][y+1];
	for(int i=0;i<=x;i++)r[i][0]=1;
	for(int i=0;i<=y;i++)r[0][i]=1;
	for(int i=1;i<=x;i++)
	{
		for(int j=1;j<=y;j++) r[i][j]=r[i-1][j]+r[i][j-1];
	}
	cout<<r[x][y];
}