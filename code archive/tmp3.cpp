#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(ll i=0;i<n;i++)
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);

int main()
{
    IOS();
    srand(time(0));
    ll n,sigma;
    cin>>n>>sigma;
    REP(i,n)cout<<(char)('a'+rand()%sigma);
    cout<<endl;
}
