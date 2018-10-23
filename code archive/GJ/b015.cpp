/**********************************************************************************/
/*  Problem: b015 "追殺比爾" from 字串處理-字串拆解                                           */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 203KB) on ZeroJudge                                          */
/*  Author: briansu at 2017-05-18 15:46:09                                        */
/**********************************************************************************/

#include <iostream>
#include <string.h>
#include <sstream>
typedef long long ll;
using namespace std;

int main()
{
    string s;
    int r=0;
    while(getline(cin,s))
    {
      r++;
      int c=0;
      stringstream ss;
      ss<<s;
      string tmp;
      while(ss>>tmp)
      {
        c++;
        if(tmp=="BILL")
        {
          cout<<r<<" "<<c<<endl;
          return 0;
        }
      }
    }
    cout<<"NO"<<endl;
}
