/**********************************************************************************/
/*  Problem: e002 "2.神秘的進位問題" from 100學年度全國決賽                                     */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 188KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-11-01 19:30:00                                        */
/**********************************************************************************/

#include<iostream>
#include<cstring>
typedef long long ll;
using namespace std;
ll c[16][16];
int main()
{
    memset(c,0,sizeof c);
    for(int i=0;i<=15;i++)c[i][0]=c[i][i]=1;
    for(int i=2;i<=15;i++)for(int j=1;j<i;j++)c[i][j]=c[i-1][j]+c[i-1][j-1];
    int T;
    cin>>T;
    for(;T>0;T--)
    {
        int n;
        cin>>n;
        int a,b;
        bool ok=false;
        for(a=2;a<=15&&!ok;a++)
        {
            int tmp=n-c[a][3];
            for(b=1;b<a;b++)
            {
                if(tmp-c[b][2]>=0&&tmp-c[b][2]<b){ok=true;break;}
            }
            if(ok)break;
        }
        cout<<a<<b<<n-c[a][3]-c[b][2]<<endl;
    }
}
