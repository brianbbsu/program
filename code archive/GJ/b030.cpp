/**********************************************************************************/
/*  Problem: b030 "隨選視訊" from 動態規劃-01背包問題                                         */
/*  Language: C++                                                                 */
/*  Result: AC (5ms, 457KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-09-09 12:39:42                                        */
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
long int l[101][1001];
long int c(int *t,int *v, int n,int s)
{
    if(n<0 || s<0) return l[n][s]=-1e6;
    if(s==0 || n==0) return l[n][s]=0;
    if(l[n][s]) return l[n][s];
    if(s-t[n]<0) return l[n][s]=c(t,v,n-1,s);
    return l[n][s]=max(c(t,v,n-1,s),(c(t,v,n-1,s-t[n])+v[n]));
}
int main()
{
    int n,s;
    cin>>n>>s;
    int t[n+1],v[n+1];
    int l[n+1][s+1];
    for(int i=1;i<=n;i++){cin>>t[i];cin>>v[i];}
    for(int i=0;i<=n;i++)for(int j=0;j<=s;j++) l[i][j]=0;
    cout<<c(t,v,n,s);
    //cout<<(l[5][5]==-1);
}

