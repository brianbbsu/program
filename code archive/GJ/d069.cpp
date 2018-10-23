/**********************************************************************************/
/*  Problem: d069 "1.棄保效應" from 103年彰雲嘉區複賽                                        */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 176KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-09-03 19:41:21                                        */
/**********************************************************************************/

#include <cmath>
#include <iostream>
#include <string.h>
#include <sstream>
#include <stdio.h>
using namespace std;
int main()
{
  string r[3]={"甲","乙","丙"};
  int a[3];
  int most =0;
  int i;
  scanf("%d%d%d",&a[0],&a[1],&a[2]);
  for(i=0;i<3;i++) most=(a[i]>a[most]? i:most);
  int least =min(a[0],min(a[1],a[2]));
  for(i=0;i<3;i++) if(a[i]==least){least=i;break;}
  int sec=3-most-least;
  a[sec]+=a[least];
  cout<<(a[most]>a[sec]? r[most]:r[sec]);
}
