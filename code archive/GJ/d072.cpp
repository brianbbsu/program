/**********************************************************************************/
/*  Problem: d072 "4.動物數量統計" from 103年彰雲嘉區複賽                                      */
/*  Language: C++                                                                 */
/*  Result: AC (6ms, 268KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-09-12 21:42:48                                        */
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
using namespace std;

int main()
{
    map<string,int> m,a[100];
    vector<string> mn,an;
    int mid=0,aid=0;
    vector<vector<int> > r;
    int n;
    cin>>n;
    for(;n>0;n--)
    {
        string atmp,mtmp;
        int cnt;
        cin>>atmp>>cnt>>mtmp;
        if(!m.count(mtmp)){m[mtmp]=mid++;vector<int> tmp;tmp.resize(1000);fill(tmp.begin(),tmp.end(),0);r.push_back(tmp);mn.push_back(mtmp);}
        if(!a[m[mtmp]].count(atmp)){a[m[mtmp]][atmp]=aid++;an.push_back(atmp);}
        r[m[mtmp]][a[m[mtmp]][atmp]]+=cnt;
    }
    for(int i=0;i<mid;i++)
    {
        cout<<mn[i]<<":";
        bool first=1;
        for(int j=0;j<aid;j++)
        {
            if(r[i][j])
            {
                if(!first)cout<<",";
                cout<<an[j]<<" "<<r[i][j];
                first=0;
            }
        }
        cout<<endl;
    }
}



