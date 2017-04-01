#include <bits/stdc++.h>
using namespace std;
int d[10];
int n;
int main(){
  cin>>n;
  for(int i=0;i<n;i++)cin>>d[i];
  sort(d,d+n);
  for(int i=0;i<n;i++)cout<<(i==0?"":" ")<<d[i];
}
