/**********************************************************************************/
/*  Problem: h142 "E.鋼鐵旗幟競賽" from NPSC 2014 高中組決賽                                 */
/*  Language: C++                                                                 */
/*  Result: AC (14ms, 206KB) on ZeroJudge                                         */
/*  Author: briansu at 2016-08-28 11:42:27                                        */
/**********************************************************************************/

#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
int main()
{
	int t;	
	cin>>t;
	for(;t>=1;t--)
	{
		int n;
		cin>>n;
		int marker=0;
		int c=0,p=0;
		for(;n>=1;n--)
		{
			char a;
			cin>>a;
			if(a=='W')
			{
				c+=10+5*marker;
				marker=0;
			}
			else if(a=='L')
			{
				p+=10;
				if(marker<5) marker++;
			}
			else
			{
				c+=5;
				p+=5;
			}
		}
		cout<<c<<" "<<p<<endl;
	}
	
	
	
	
}