/**********************************************************************************/
/*  Problem: g017 "D.水之都" from NPSC 2006 國中組初賽                                    */
/*  Language: C++                                                                 */
/*  Result: AC (4024ms, 3526KB) on ZeroJudge                                      */
/*  Author: briansu at 2016-09-21 22:19:18                                        */
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
    while(1)
    {
        int n,m;
        cin>>n>>m;
        if(n==m&&m==0)break;
        vector<ii> v[n];
        for(;m>0;m--)
        {
            int a,b,c;
            cin>>a>>b>>c;a--;b--;
            bool un=true;
            for(int i=0;i<v[a].size();i++)if(v[a][i].first==b){un=false;v[a][i].second=max(v[a][i].second,c);break;}
            if(un)
            {
                v[a].push_back(ii(b,c));
                v[b].push_back(ii(a,c));
            }
        }
        ll dis[n][n];
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)if(i!=j)dis[i][j]=-1*INF;else dis[i][j]=0;
        for(int i=0;i<n;i++)for(int j=0;j<v[i].size();j++)dis[i][v[i][j].first]=v[i][j].second;
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    dis[i][j]=max(dis[i][j],min(dis[i][k],dis[k][j]));
                }
            }
        }
        int s,d;
        cin>>s>>d;
        if(dis[s-1][d-1]>0)
        cout<<dis[s-1][d-1]<<endl;
        else cout<<0<<endl;
    }
}



