/**********************************************************************************/
/*  Problem: b027 "小綠人的城堡" from 動態規劃-最大正方形區域                                      */
/*  Language: C++                                                                 */
/*  Result: AC (5ms, 505KB) on ZeroJudge                                          */
/*  Author: briansu at 2017-09-18 15:45:55                                        */
/**********************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int ll;
ll gr_dp[500][500]={};
ll x[500][500]={};
ll w,h,bb;

ll green(){
    for(ll i=1;i<=w;i++){
        for(ll j=1;j<=h;j++){
            if(x[i][j]==0){
                gr_dp[i][j]=min(min(gr_dp[i-1][j],gr_dp[i][j-1]),gr_dp[i-1][j-1])+1;
            }
            if(bb<gr_dp[i][j]){
                bb=gr_dp[i][j];
            }
        }
    }
    ll ans=bb*bb;
    return ans;
}

int main(){
    cin>>w>>h;
    for(ll i=1;i<=w;i++){
        for(ll j=1;j<=h;j++){
            cin>>x[i][j];
        }
    }
    ll e=green();  
    cout<<e<<endl;
}
