/**********************************************************************************/
/*  Problem: d043 "3.數字排序" from 100年台中區複賽                                         */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 208KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-09-27 15:12:40                                        */
/**********************************************************************************/

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string.h>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
#include <stack>
#include <map>
#include <iomanip>
#include <bitset>
using namespace std;
typedef long long ll;
const double EPS=0.001;
const ll INF=ll(1e18);
int main()
{
    vector<int> v;
    map<int,string>m;
    map<string,int> n;
    n["零"]=0;n["一"]=1;n["二"]=2;n["三"]=3;
    n["四"]=4;n["五"]=5;n["六"]=6;n["七"]=7;
    n["八"]=8;n["九"]=9;
    while(true)
    {
        string tmp;
        cin>>tmp;
        //cout<<tmp.length();
        if(cin.fail())break;
        if(tmp[0]>='0'&&tmp[0]<='9')
        {
            int value;stringstream ss(tmp);
            ss>>value;
            m[value]=tmp;
            v.push_back(value);
        }
        else
        {
            int value=0;
            for(int i=0;i<tmp.length();i+=3)
                value=value*10+n[tmp.substr(i,3)];
            m[value]=tmp;
            v.push_back(value);
        }
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    {
        cout<<m[v[i]]<<endl;
    }
}
