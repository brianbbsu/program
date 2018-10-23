/**********************************************************************************/
/*  Problem: b036 "史萊姆王" from 貪婪演算法-最小總花費                                         */
/*  Language: C++                                                                 */
/*  Result: AC (14ms, 206KB) on ZeroJudge                                         */
/*  Author: briansu at 2016-09-09 08:00:50                                        */
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
    int n;
    cin>>n;
    vector<long long> b;
    long long tmp;
    for(int i=0;i<n;i++){cin>>tmp;b.push_back(tmp);}
    sort(b.begin(),b.end(),greater<int>());
    //for(int i=0;i<n;i++)cout<<b[i];cout<<endl;
    long long int m=0;
    //long long int p=b[0];
    for(int i=0;n>1;i++)
    {

        b[n-2]+=b[n-1];
        m+=b[n-2];
        b.pop_back();
        sort(b.begin(),b.end(),greater<int>());
        n--;

    }
    cout<<m<<endl;
}

