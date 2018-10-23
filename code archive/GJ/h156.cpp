/**********************************************************************************/
/*  Problem: h156 "D.三角尼姆" from NPSC 2015 高中組決賽                                   */
/*  Language: C++                                                                 */
/*  Result: AC (3ms, 176KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-09-12 07:55:11                                        */
/**********************************************************************************/

#include <iostream>
#include <sstream>
#include <math.h>
#include <iomanip>
#include <vector>
using namespace std;
int main()
{
	int k;
	cin>>k;
	for(;k>0;k--)
	{
		int n;cin>>n;
	    if(((n+1)*n/2)%2==0)cout<<"Bob\n";
	    else cout<<"Alice\n";
	    
	}
}