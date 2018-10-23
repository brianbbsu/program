/**********************************************************************************/
/*  Problem: d042 "2.循環冗餘檢查CRC" from 100年台中區複賽                                    */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 188KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-09-27 14:47:12                                        */
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
#include <bitset>
using namespace std;
typedef long long ll;
const double EPS=0.001;
const ll INF=ll(1e18);
int main()
{
    int T;
    cin>>T;
    for(int k=0;k<T;k++)
    {
        int n,m,a=0,b=0;
        cin>>n>>m;
        for(int i=0;n>0;i++)
        {
            a+=(n%10)<<i;
            n/=10;
        }
        for(int i=0;m>0;i++)
        {
            b+=(m%10)<<i;
            m/=10;
        }

        int w=floor(log10(b)/log10(2)+EPS);

        //cout<<w<<" "<<wa<<endl;
        a=a<<w;
        int wa=floor(log10(a)/log10(2)+EPS);
        while(wa>=w)
        {
            int tmpb=((a>>wa)?(b<<(wa-w)):0);
            a=a^tmpb;
            wa--;
            //cout<<a<<endl;
        }
        cout<<"CRC code:";
        for(int i=wa;i>=0;i--)
        {
            cout<<((a&(1<<i))>0?1:0);
        }
        cout<<endl;
    }
}
