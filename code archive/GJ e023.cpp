/**********************************************************************************/
/*  Problem: e023 "5.最小與次小網路建構成本" from 103學年度全國決賽                                 */
/*  Language: C++                                                                 */
/*  Result: AC (222ms, 359KB) on ZeroJudge                                        */
/*  Author: briansu at 2016-09-24 00:56:24                                        */
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
struct ill
{
    int first;
    ll second;
    ill(int a=0,ll b=0){this->first=a;this->second=b;}
};
struct iill
{
    int first;
    int second;
    ll w;
    iill(int a=0,int b=0,ll w=0){this->first=a;this->second=b;this->w=w;}
    bool operator < (const iill &b)
    const {
        return w<b.w;
    }
};

vector<int> g;
int gcnt;
vector<ill> v[2000];

int find(int n)
{
    return (n==g[n]?n:(g[n]=find(g[n])));
}
void uni(int a,int b)
{
    g[find(a)]=find(b);
    gcnt--;
}
bool same(int a,int b)
{
    return find(a)==find(b);
}
void nfill(int n,int from,int num)
{
    g[n]=num;
    for(int i=0;i<v[n].size();i++)
    {
        if(v[n][i].first!=from)
        {
            nfill(v[n][i].first,n,num);
        }
    }
}
int main()
{
   int T;
   cin>>T;
   for(;T>0;T--)
   {
   g.clear();
   for(int i=0;i<2000;i++)v[i].clear();
   int n,m;
   cin>>n>>m;
   if(n==0||n==1){cout<<0<<endl;return 0;}
   vector<iill> e;
   for(int i=0;i<m;i++)
   {
       int a,b;
       ll w;
       cin>>a>>b>>w;
       e.push_back(iill(a,b,w));
   }
    sort(e.begin(),e.end());

    for(int i=0;i<n;i++)g.push_back(i);
    ll cost=0;
    gcnt=n;


    bool used[m];
    memset(used,false,sizeof(used));
    vector<iill> elist;


    for(int i=0;i<m && gcnt>1;i++)
    {
        iill tmp=e[i];
        if(!same(tmp.first,tmp.second))
        {
            int a=tmp.first,b=tmp.second,w=tmp.w;
            uni(a,b);
            cost+=w;
            v[a].push_back(ill(b,w));
            v[b].push_back(ill(a,w));
            used[i]=true;
            elist.push_back(tmp);
        }
    }
    //cout<<cost<<endl;
    vector<ll> newcost;
    for(int i=0;i<elist.size();i++)
    {
        iill tmp=elist[i];
        int a=tmp.first,b=tmp.second;
        nfill(a,b,0);
        nfill(b,a,1);
        //for(int j=0;j<n;j++)cout<<g[j]<<" ";
        //cout<<endl;
        for(int j=0;j<m;j++)
        {
            if(used[j]==false&&g[e[j].first]!=g[e[j].second])
            {
                //cout<<tmp.w<<" "<<e[j].w<<endl;
                newcost.push_back(cost-tmp.w+e[j].w);
                break;
            }
        }
    }
    ll least=INF;
    for(int i=0;i<newcost.size();i++){if(newcost[i]<least)least=newcost[i];}
    //cout<<endl<<least;
    cout<<least-cost<<endl;
    }
}







