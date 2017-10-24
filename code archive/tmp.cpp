#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MaxN=1e5+5;
const ll INF=1e18;

ll dp[50000][105];
ll x[105];

ll sum(ll total,ll m){
	if(total<0){
		return INF;
	}
	if(m<=0){
		if(total==0){
			return 0;
		}
		else{
			return INF;
		}
	}
	if(dp[total][m]!=-1){
		return dp[total][m];
	}
	else{
		return dp[total][m]=min(sum(total-x[m],m-1),sum(total,m-1));
	}
}

int main(){
	ll n,m;
	cin>>n>>m;
	while(n--){
		ll ans=0;
		ll total=0;
		memset(dp,-1,sizeof dp);
		for(int i=0;i<m;i++){
			cin>>x[i];
			total+=x[i];
		}
		if(total%2){
			cout<<"No"<<endl;
			continue;
		}
		total/=2;
		ans=sum(total,m-1);
		if(ans>=INF){
			cout<<"No"<<endl;
		}
		else{
			cout<<"Yes"<<endl;
		}
	}
}
