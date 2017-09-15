#include <iostream>
using namespace std;

 int main(){
 	int n;
 	int sum=0;
 	int a[1005]={};
 	int num[1005]={};
 	cin>>n;
 	for(int i=0;i<n;i++){
 		cin>>a[i];
 	}
 	int i=0;
 	for(int j=1;j<=n;i++){
 		if(a[i]==j){
 			num[j-1]=i+1;
 			j++;
 			i=-1;
 		}
 	}
 	for(int i=0;i<n-1;i++){
 		if(num[i]>=num[i+1]){
 			sum+=num[i]-num[i+1];
 		}
 		else{
 			sum+=num[i+1]-num[i];
 		}
 	}
 	cout<<sum<<endl;
}
