/**********************************************************************************/
/*  Problem: d063 "1.時間差計算" from 103年台中區複賽                                        */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 208KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-09-01 09:51:47                                        */
/**********************************************************************************/

#include <iostream>
#include <sstream>
#include <math.h>
#include <iomanip>
using namespace std;
int main()
{
	string str1,str2;
	cin>>str1>>str2;
	stringstream ss;
	ss<<str1;
	int h1,m1,s1;
	char c;
	ss>>h1>>c>>m1>>c>>s1;
	ss.str("");
	ss.clear();
	ss<<str2;
	int h2,m2,s2;
	ss>>h2>>c>>m2>>c>>s2;
	int h,m,s;
	s=h2*3600+m2*60+s2-(h1*3600+m1*60+s1);
	if(s<0) s+=3600*24;
	h=floor(s/3600);
	s%=3600;
    m=floor(s/60);
    s%=60;
    cout<<setw(2)<<setfill('0')<<h;
    cout<<":";
    cout<<setw(2)<<setfill('0')<<m;
    cout<<":";
    cout<<setw(2)<<setfill('0')<<s;
}