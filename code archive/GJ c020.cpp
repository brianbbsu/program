/**********************************************************************************/
/*  Problem: c020 "1.賣便當" from 104校內初賽                                            */
/*  Language: C++                                                                 */
/*  Result: AC (3ms, 184KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-27 21:31:39                                        */
/**********************************************************************************/

#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	if(n<20) cout<<60;
	else if(n<50) cout<<80;
	else if(n<100) cout<<90;
	else cout<<100;
	
	
	
}