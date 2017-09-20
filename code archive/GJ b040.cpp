/**********************************************************************************/
/*  Problem: b040 "以物易物" from 回溯法-子集合總和                                           */
/*  Language: C++                                                                 */
/*  Result: AC (36ms, 219KB) on ZeroJudge                                         */
/*  Author: briansu at 2016-09-09 21:31:29                                        */
/**********************************************************************************/

#include <cmath>
#include <iostream>
#include <string.h>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
long long p[20];
bool ok = false;
void next(int n,int l,long long sum,long long m,vector<long long> his)
{
    his.push_back(0);
    for(int i=l;i<n;i++)
    {
        his[his.size()-1]=p[i];
        int tmp=sum;
        tmp+=p[i];
        if(tmp==m){for(int j=0;j<his.size();j++)cout<<his[j]<<" ";cout<<endl;ok=true;
        continue;}
        if(tmp>m || l>=n-1 || i>=n-1) continue;
        next(n,i+1,tmp,m,his);

    }
}
int main()
{
    int n;
    long long m;
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>p[i];
    vector<long long> his;

    next(n,0,0,m,his);
    if(ok==false) cout<<"NO";
}

