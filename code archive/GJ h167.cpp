#include <iostream>
#include <vector>
using namespace std;

typedef pair<int,int> ii;

vector<ii> edge;

bool chk(int msk1,int msk2)
{
  for(int i = 0;;i++)
  {
    int a = (1<<i) & msk1;
    int b = (1<<i) & msk2;
    if(!a && b)return 0;
    else if(a && !b)return 1;
  }
}

int main(){
  int T;
  cin>>T;
  while(T--)
  {
    int n,m;
    cin>>n>>m;
    for(int i = 0;i < m;i++)
    {
      int a,b;
      cin>>a>>b;
      a--;b--;
      edge.push_back(ii(a,b));
    }
    int mn = n+1,mn_mask = -1;
    for(int I = 0;I < (1<<n);I++)
    {
      int count = 0,ok = 1;
      for(int i = 0;i < n;i++)if((1<<i) & I)count++;
      for(int i = 0;i < m;i++)
      {
        int a = (1 << edge[i].first) & I;
        int b = (1 << edge[i].second) & I;
        if(!a && !b){
          ok = 0;
          break;
        }
      }
      if(ok && count < mn)mn = count,mn_mask = I;
      else if(ok && count == mn && chk(I,mn_mask))mn_mask = I;
    }
    cout<<mn<<endl;
    for(int i = 0;i < n;i++)if(mn_mask & (1<<i))cout<<i+1<<" ";
    cout<<endl;
    edge.clear();
  }
}
