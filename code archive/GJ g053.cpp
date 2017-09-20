/**********************************************************************************/
/*  Problem: g053 "B.水之國奇幻冒險" from NPSC 2009 國中組初賽                                */
/*  Language: C++                                                                 */
/*  Result: AC (156ms, 298KB) on ZeroJudge                                        */
/*  Author: briansu at 2016-09-21 21:53:35                                        */
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

int main()
{
    int T;
    cin>>T;
    for(;T>0;T--)
    {

        int n,m;
        cin>>n>>m;
        vector<ii> v[n];
        for(;m>0;m--)
        {
            int a,b,c;
            cin>>a>>b>>c;a--;b--;
            v[a].push_back(ii(b,c));
            v[b].push_back(ii(a,c));
        }
        ll dis[n][n];
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)if(i!=j)dis[i][j]=INF;else dis[i][j]=0;
        for(int i=0;i<n;i++)for(int j=0;j<v[i].size();j++)dis[i][v[i][j].first]=v[i][j].second;
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    dis[i][j]=min(dis[i][j],max(dis[i][k],dis[k][j]));
                }
            }
        }
        cout<<dis[0][n-1]<<endl;
    }
}



