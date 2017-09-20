/**********************************************************************************/
/*  Problem: h123 "A.可魚果運輸問題" from NPSC 2013 高中組決賽                                */
/*  Language: C++                                                                 */
/*  Result: AC (10ms, 210KB) on ZeroJudge                                         */
/*  Author: briansu at 2016-09-20 00:16:18                                        */
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
//#include <utility>
using namespace std;
typedef long long ll;
//typedef pair<int,ll> ill;
const double EPS=1e-3;
const ll INF=ll(1e18);
struct ill
{
    int first;
    ll second;
    ill(int a,ll b){this->first=a;this->second=b;}
};
int main()
{
    int T;
    cin>>T;
    for(;T>0;T--)
    {
        int n,m,s,e;
        ll f;
        cin>>n>>m>>s>>e>>f;
        s--;e--;
        vector<ill> v[n];
        for(int i=1;i<=m;i++)
        {
            ll a,b,c,c1;
            ll d;
            cin>>a>>b>>c>>d>>c1;
            a--;b--;
            ll w;
            if(f>d)w=c*d+(f-d)*c1;
            else w=f*c;
            v[a].push_back(ill(b,w));
        }
        bool vis[n];
        memset(vis,0,sizeof(vis));
        ll dis[n];
        for(int i=0;i<n;i++)dis[i]=INF;
        dis[s]=0;
        int p=s;
        while(1)
        {
            for(int k=0;k<v[p].size();k++)
            {
                ill i=v[p][k];
                int to=i.first;ll w=i.second;
                dis[to]=min(dis[to],dis[p]+w);
            }
            vis[p]=true;
            ll least=INF;int leastid=-1;
            for(int i=0;i<n;i++)
            {
                if(!vis[i]&&dis[i]<least){least=dis[i];leastid=i;}
            }
            if(leastid==-1)break;
            p=leastid;
        }
        cout<<dis[e]<<endl;

    }


}



