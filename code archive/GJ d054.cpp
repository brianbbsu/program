/**********************************************************************************/
/*  Problem: d054 "3.字型顯示" from 101年台中區複賽                                         */
/*  Language: C++                                                                 */
/*  Result: AC (3ms, 180KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-09-05 14:54:44                                        */
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
        char font[10][65];
        for(int i=0;i<10;i++) scanf("%s",&font[i]);
        int num,a;
        scanf("%d,%d",&num,&a);
        int b=0;
        vector<int> n;
        if(num!=0) while(num!=0){n.push_back(num%10);num/=10;}
        else n.push_back(0);
        for(int i=0;i<8*a;i++)
        {
            for(int f=n.size()-1;f>=0;f--)
            {
                for(int j=0;j<8*a;j+=a)
                {
                    char c=(font[n[f]][(int)(floor(i/a)*8+floor(j/a))]=='1'?'*':'_');
                    for(int k=0;k<a;k++) printf("%c",c);
                }
                if(f!=0)printf("___");
            }

            printf("\n");
        }
    }