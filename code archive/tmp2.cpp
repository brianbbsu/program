#include<iostream>
using namespace std;


int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        cout<<( j + i/k + n/k*(i%n) )%n+1<<" ";//好好研究一下
      }
      cout<<endl;
    }
}
