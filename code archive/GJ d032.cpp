/**********************************************************************************/
/*  Problem: d032 "96年台中區第二題" from 96年台中區複賽                                       */
/*  Language: C++                                                                 */
/*  Result: AC (3ms, 185KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-09-05 19:11:30                                        */
/**********************************************************************************/

    #include <cmath>
    #include <iostream>
    #include <string.h>
    #include <sstream>
    #include <stdio.h>
    #include <vector>
    using namespace std;
    int main()
    {
        int n;
        cin>>n;
        long long a[n+1];
        a[0]=1;
        for(int i=1;i<=n;i++) a[i]=0;
        int c[5]={1,5,10,25,50};
        for(int i=0;i<5;i++)
        {
            for(int j=c[i];j<=n;j++) a[j]+=a[j-c[i]];
        }
        cout<<a[n];
    }

