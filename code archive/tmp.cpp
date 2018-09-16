#include <iostream>
using namespace std;
int main() {
  int t,flag=0,cat=0;
  int n=0,m=0;
  cin >> t;
  for(int i=0;i<t;i++){
    cin >> n >> m;
    int road[2][106]={0},temp=0;
    int fac[15]={0};
    for(int j=0;j<m;j++){
        cin >> road[0][j] >> road[1][j];
    }
    for(int k=0;k<m;k++){
      for (int j=0; j<n; j++) {
          if(road[0][k]==fac[j]||road[1][k]==fac[j]){
            flag=1;
            break;
          }
      }
      if(flag==0){
        if (road[0][k]<road[1][k]) {
          fac[cat]=road[0][k];
          cat++;
        }
        else{
          fac[cat]=road[1][k];
          cat++;
        }
      }
      flag=0;
    }
    for (int check=0; check<cat; check++) {
      int chearray[106]={0};
      int countt=0;
      int flag1=0;
      for (int check1=0; check1<m; check1++) {
        if (fac[check]==road[0][check1]) {
          chearray[countt]=road[1][check1];
          countt++;
        }
        else if (fac[check]==road[1][check1]) {
          chearray[countt]=road[0][check1];
          countt++;
        }
      }
      for (int b=0; b<countt; b++) {
        for (int c=0; c<cat; c++) {
          if(chearray[b]==fac[c]){
            flag1=1;
            break;
          }
          else{
            flag1=0;
          }
        }
        if(flag1==0) break;
      }
      if(flag1==1){
        temp++;
        fac[check]=0;
      }
    }
    cout << cat-temp << "\n";
    for (int z=0; z<cat; z++) {
      if(fac[z]!=0){
        cout << fac[z] << " ";
      }
    }
    cout << "\n";
    cat=0;
  }
  return 0;
}
