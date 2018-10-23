/**********************************************************************************/
/*  Problem: d052 "1.字串分解" from 101年台中區複賽                                         */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 188KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-09-03 19:26:03                                        */
/**********************************************************************************/

#include <cmath>
#include <iostream>
#include <string.h>
#include <sstream>
#include<stdio.h>
using namespace std;
int main()
{
  char a[151];
  fgets(a,151,stdin);
  //scanf("%s",a);
  int num[26];
  for(int i=0;i<26;num[i++]=0);
  int i=-1;
  while(a[++i]!='\0')
  {
    int c=toupper(a[i])-'A';
    if(c>=0&&c<=25) num[c]+=1;
  }
  for(i=0;i<26;i++) printf("%c ",(char)(i+'A'));
  printf("\n");
  for(i=0;i<26;i++) printf("%d ",num[i]);
}
