/**********************************************************************************/
/*  Problem: c030 "5.挑戰魔王" from 105校內初賽                                           */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 188KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-08-27 15:00:15                                        */
/**********************************************************************************/

#include <iostream>
#include <math.h>
#include <string.h>
#include <iomanip>
using namespace std;
int main()
{
	string s;
	cin>>s;
	bool b=false;
	int sum=0;
	for(unsigned int i=0;i<s.length();i++)
	{
		
		if(s.substr(i,1)=="C" && b==true) sum+=1;
		b=false;
		if(s.substr(i,1)=="A") b=true;				
	}
	cout<<sum;
		

}