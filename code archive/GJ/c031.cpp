/**********************************************************************************/
/*  Problem: c031 "6.最後一個是誰" from 105校內初賽                                         */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 188KB) on ZeroJudge                                          */
/*  Author: briansu at 2016-09-03 15:20:12                                        */
/**********************************************************************************/

#include <cmath>
#include <iostream>
#include <string.h>
#include <sstream>
#include<stdio.h>
using namespace std;
struct node
{
    int data;
    node* next;
};
int main()
{
   int n;
   scanf("%d",&n);
   int p;
   scanf("%d",&p);
   node head;
   head.data=n;
   head.next=NULL;
   node *last=&head;
   for(int i=1;i<=n;i++)
   {
       node* re=new node;
       re->data=i;
       if(i==n) re->next=head.next;
       else re->next=NULL;
       last=last->next=re;
       if(i==1) head.next=re;

   }
   node* a=&head;
   while(true)
   {
       for(int i=1;i<p;i++) a=a->next;
       if(n!=2) a->next=a->next->next;
       else
       {
           printf("%d",a->data);
           break;
       }
       n--;
   }
}
