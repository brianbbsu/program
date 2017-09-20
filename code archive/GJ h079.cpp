/**********************************************************************************/
/*  Problem: h079 "A.耶誕老人到你家" from NPSC 2010 高中組決賽                                */
/*  Language: C++                                                                 */
/*  Result: AC (74ms, 396KB) on ZeroJudge                                         */
/*  Author: briansu at 2016-09-12 20:38:22                                        */
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

int main()
{
    int k;
    cin>>k;
    for(;k>0;k--)
    {
        int n,m;
        cin>>n>>m;
        long g[n],b[m];
        for(int i=0;i<n;i++) cin>>g[i];
        for(int i=0;i<m;i++) cin>>b[i];
        sort(g,g+n);
        sort(b,b+m);
        int bnum=0,gnum=0;
        int gifts=0;
        while(1)
        {
            if(g[gnum]<=b[bnum])
            {
                gifts++;
                bnum++;
                gnum++;
            }
            else bnum++;
            if(gnum==n || bnum==m) break;
        }
        if(gifts) cout<<gifts<<endl;
        else cout<<"Santa Claus wishes you get AC in the next submission."<<endl;
    }
}



