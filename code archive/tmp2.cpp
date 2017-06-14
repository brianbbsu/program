#include<iostream>
using namespace std;

long long a,b;
int main(){
  cin>>a>>b;
  long long _a=a,_b=b;//把a和b的值存一份起來
  while(b>0)
  {
    long long c=a%b;
    a=b;
    b=c;
  }
  cout<<_b/a<<" "<<_a/a<<endl;// #14
}
