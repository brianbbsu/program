#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<int,int> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define FILL(i,n) memset(i,n,sizeof(i));
#define X first
#define Y second
#define pb push_back
#ifdef brian
#define  debug(...) do{\
    fprintf(stderr,"%s - %d : (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0)
template<typename t> void _do(t &&x){cerr<<x<<endl;}
template<typename t,typename ...T> void _do(t &&x,T &&...tail){cerr<<x<<", ";_do(tail...);}
#else
#define debug(...)
#endif // brian



ll n,a,b,c;
ll s[1000005];
ll A[1000005],B[1000005];
ll dq[1000005],dp[1000005];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>a>>b>>c;
    cin>>s[1];
    REP(i,n-1)
    {
        ll tmp;
        cin>>tmp;
        s[i+2]=s[i+1]+tmp;
    }
    ll ptf=0,ptb=1;
    dq[0]=A[0]=B[0]=0;
    for(int i=1;i<=n;i++)
    {

        while(ptb-ptf>=2 && A[dq[ptf]]*s[i]+B[dq[ptf]] <=
                            A[dq[ptf+1]]*s[i]+B[dq[ptf+1]])ptf++;
        dp[i]=A[dq[ptf]]*s[i]+B[dq[ptf]]+a*s[i]*s[i]+b*s[i]+c;
        debug(i,dq[ptf]);
        A[i]=-2*a*s[i];B[i]=dp[i]+a*s[i]*s[i]-b*s[i];
        while(ptb-ptf>=2 && (B[i]-B[dq[ptb-2]])*(A[dq[ptb-2]]-A[dq[ptb-1]]) <=
                            (B[dq[ptb-1]]-B[dq[ptb-2]])*(A[dq[ptb-2]]-A[i]))ptb--;
        dq[ptb]=i;
        ptb++;
    }
    cout<<dp[n]<<endl;
}
