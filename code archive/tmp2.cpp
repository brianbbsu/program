#include<iostream>
using namespace std;

long long a,b,c,d; // 宣告上述cA=dB的四個變數abcd
int main(){
  cin>>a>>b;
  for(c=1; ;c++) // 試著讓c從最小的正整數開始往上數
  {
    if((a*c)%b==0)//判斷d=cA/B有無正整數解(能否整除)
    {
      //有解
      d=a*c/b;
      break;//因為要最小解，故找到第一個就行了
    }
  }
  cout<<c<<" "<<d<<endl;//輸出
}
