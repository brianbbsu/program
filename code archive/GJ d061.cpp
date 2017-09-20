/**********************************************************************************/
/*  Problem: d061 "4.迴文" from 101年彰雲嘉區複賽                                          */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 210KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-09-27 13:34:57                                        */
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
string t,s;
int z[161],len;
int f(int l,int r)
{
    int i=0;
    while(l-i>=0&&r+i<len&&s[l-i]==s[r+i])i++;
    return i;
}
int main()
{
    int T;
    cin>>T;
    for(int k=0;k<T;k++)
    {
        cin>>s;
        len=s.length();
        //s=".";
        //for(int i=0;i<len;i++)s+=t.substr(i,1)+".";
        //len=len*2+1;
        //z[0]=1;
        int r[len][2];
        int most=0;
        for(int i=0;i<len;i++)
        {
            for(int j=0;j<=1;j++)
            {
                if((r[i][j]=f(i,i+j)*2-(1-j))>most)most=r[i][j];
            }
        }
        printf("第%d組測試資料的最長迴文子字串長度為:%d\n",k+1,most);
        printf("第%d組測試資料的最長迴文子字串內容為:",k+1);
        set<string> out;
        if(most%2==0)
        {
            //1
            for(int i=0;i<len;i++)
            {
               if(r[i][1]==most)
               {
                   string tmp=s.substr(i-most/2+1,most);
                   if(!out.count(tmp)){cout<<tmp<<" ";out.insert(tmp);}
               }
            }
        }
        else
        {
            //0
            for(int i=0;i<len;i++)
            {
               if(r[i][0]==most)
               {
                   string tmp=s.substr(i-(most-1)/2,most);
                   if(!out.count(tmp)){cout<<tmp<<" ";out.insert(tmp);}
               }
            }
        }
        cout<<endl;
    }
}
