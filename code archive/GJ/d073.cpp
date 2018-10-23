/**********************************************************************************/
/*  Problem: d073 "5.中置式轉後置式" from 103年彰雲嘉區複賽                                     */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 177KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-09-17 14:27:02                                        */
/**********************************************************************************/

#include <cmath>
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
char node[100];
int lc[100],rc[100],ncnt=0;
int newnode(char c)
{
    node[++ncnt]=c;
    rc[ncnt]=lc[ncnt]=0;
    return ncnt;
}
int f(string a,int s,int e)
{
    int p=0;
    int rp=-1,rm=-1;
    if(s==e) return newnode(a[s]);
    for(int i=e;i>=s;i--)
    {
        char c=a[i];
        if(c==')')p++;
        else if(c=='(')p--;
        else if(!p&&(c=='+'||c=='-')&&rp==-1) rp=i;
        else if(!p&&(c=='*'||c=='/')&&rm==-1) rm=i;
    }
    if(rp!=-1)
    {
        int r;
        r=newnode(a[rp]);
        lc[r]=f(a,s,rp-1);
        rc[r]=f(a,rp+1,e);
        return r;
    }
    else if(rm!=-1)
    {
        int r;
        r=newnode(a[rm]);
        lc[r]=f(a,s,rm-1);
        rc[r]=f(a,rm+1,e);
        return r;
    }
    else
    {
        return f(a,s+1,e-1);
    }

}
void print(int a)
{
    if(lc[a])print(lc[a]);
    if(rc[a])print(rc[a]);
    cout<<node[a];
}
int main()
{
    string s;
    cin>>s;
    int root=f(s,0,s.length()-1);
    print(root);
    cout<<endl;

}



