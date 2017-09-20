/**********************************************************************************/
/*  Problem: d062 "5.最短路徑" from 101年彰雲嘉區複賽                                        */
/*  Language: C++                                                                 */
/*  Result: AC (47ms, 8413KB) on ZeroJudge                                        */
/*  Author: briansu at 2016-09-21 20:43:01                                        */
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
using namespace std;
typedef long long ll;
const double EPS=0.5;
const ll INF=ll(1e18);
struct ii
{
    int first;
    int second;
    ii(int a,int b){this->first=a;this->second=b;}
};
char from;
ll dp[16][65536];
ll dis[16][16];
ll it(int p,int h)
{
    if(dp[p][h]!=-1)return dp[p][h];
    else
    {
        ll least=500;
        for(int i=0;i<=15;i++)
        {
            if(i==p||!(h &(1<<i)))continue;
            ll tmp=h-(1<<p);
            if(tmp==(1<<from)||i!=from)
                least=min(least,it(i,tmp)+dis[i][p]);
        }
        return dp[p][h]=least;
    }
}
int main()
{
    vector<int> m[16];
    int si[16]={2,3,3,2,3,3,3,3,3,4,3,3,2,3,2,2};
    int m1[16][4]={{1,4},{0,2,5},{1,3,6},{2,7},{0,5,8}
    ,{1,4,9},{2,7,10},{3,6,11},{4,9,12},{5,8,10,13},{6,9,11}
    ,{7,10,15},{8,13},{9,12,14},{13,15},{11,14}};
    for(int i=0;i<16;i++)for(int j=0;j<si[i];j++)m[i].push_back(m1[i][j]);
    for(int i=0;i<16;i++)for(int j=0;j<16;j++)if(i!=j)dis[i][j]=INF;else dis[i][j]=0;
    for(int i=0;i<16;i++)for(int j=0;j<m[i].size();j++)dis[i][m[i][j]]=1;
    for(int k=0;k<16;k++)
        for(int i=0;i<16;i++)
            for(int j=0;j<16;j++)
            {
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }


    int T;
    cin>>T;
    cin.ignore(1);
    for(;T>0;T--)
    {
        memset(dp,-1,sizeof(dp));
        string s;stringstream ss;
        getline(cin,s);
        ss<<s;
        ss>>from;
        from-='a';
        //vector<int> togo;
        ll h=1<<from;
        while(1)
        {
            char tmp;
            ss>>tmp;if(ss.fail())break;
            tmp=tmp-'a';
            //togo.push_back(tmp);
            h+=(1<<tmp);
        }
        dp[from][1<<from]=0;
        //for(int i=0;i<togo.size();i++)h+=(1<<togo[i]);
        ll least=500;
        for(int i=0;i<16;i++)if(h&(1<<i)&&i!=from)least=min(least,it(i,h));
        cout<<least<<endl;

    }
}



