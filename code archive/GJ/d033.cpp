/**********************************************************************************/
/*  Problem: d033 "96年台中區第三題" from 96年台中區複賽                                       */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 181KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-09-12 21:04:56                                        */
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
using namespace std;

int main()
{


    while(1)
    {
        stack<int> s;
        string c;
        cin>>c;
        if(cin.fail()) break;
        for(int i=0;i<c.length();i++)
        {
            if(c[i]=='(') s.push(0);
            else if(c[i]=='[') s.push(1);
            else if(c[i]==')')
            {
                if(!s.empty() && s.top()==0) s.pop();
                else{cout<<"Error\n";break;}
            }
            else
            {
                if(!s.empty() && s.top()==1) s.pop();
                else{cout<<"Error\n";break;}
            }
            if(i==c.length()-1) cout<<"Correct\n";
        }


    }
}



