#include<iostream>
#include<stack>

using namespace std;

int main()
{
  stack<int> stk;
  stk.push(1);
  stk.push(2);
  stk.push(3);

  while(stk.size())
  {
    cout<<stk.top()<<endl;
    stk.pop();
  }

}
