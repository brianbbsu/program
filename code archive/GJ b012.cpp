/**********************************************************************************/
/*  Problem: b012 "羅馬數字" from 字串應用-字元處理                                           */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 178KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-09-05 12:51:01                                        */
/**********************************************************************************/

#include <iostream>
#include <sstream>
#include <math.h>
#include <iomanip>
#include <vector>
using namespace std;
int main()
{
	char c[100];
	char in[7]={'I','V','X','L','C','D','M'};
	int out[7]={1,5,10,50,100,500,1000};
	vector<int> data;
	cin>>c;
	int i=-1;
	int r=0;
	while(c[++i]!='\0')
	{
		for(int j=0;j<7;j++) if(c[i]==in[j]) data.push_back(out[j]);
	}
	for(i=0;i<data.size();i++)
    {
        if(i!=data.size()-1 && data[i]<data[i+1])r-=data[i];
        else r+=data[i];
    }
    cout<<r;
}