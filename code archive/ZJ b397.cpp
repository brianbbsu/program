#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
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
template<typename t> void _do(t &&_x){cerr<<_x<<endl;}
template<typename t,typename ...T> void _do(t &&_x,T &&...tail){cerr<<_x<<", ";_do(tail...);}
#else
#define debug(...)
#endif // brian

const ll INF=ll(1e15);
const ll MAXn=1e5+5,MAXlg=20;
const ll MOD = 1000000007;

ll n,m;
string a,b;
vector<string> dp[35][35];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll T;
    cin>>T;
    REP(kz,T)
    {
        cin>>a>>b;
        n=a.length();
        m=b.length();
        REP(i,n+1)REP(j,m+1)
        {
            dp[i][j].resize(0);
            if(i==0||j==0)dp[i][j].pb("");
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[i-1]==b[j-1])
                {
                    dp[i][j]=dp[i-1][j-1];
                    for(string &s:dp[i][j])s.pb(a[i-1]);
                }
                else
                {
                    if(dp[i-1][j][0].length()>dp[i][j-1][0].length())
                    {
                        dp[i][j]=dp[i-1][j];
                    }
                    else if(dp[i-1][j][0].length()<dp[i][j-1][0].length())
                    {
                        dp[i][j]=dp[i][j-1];
                    }
                    else
                    {
                        ll x=0,y=0;
                        while(x<dp[i-1][j].size()||y<dp[i][j-1].size())
                        {
                            if(x==dp[i-1][j].size())dp[i][j].pb(dp[i][j-1][y++]);
                            else if(y==dp[i][j-1].size())dp[i][j].pb(dp[i-1][j][x++]);
                            else
                            {
                                if(dp[i-1][j][x]<dp[i][j-1][y])dp[i][j].pb(dp[i-1][j][x++]);
                                else if(dp[i-1][j][x]>dp[i][j-1][y])dp[i][j].pb(dp[i][j-1][y++]);
                                else
                                {
                                    dp[i][j].pb(dp[i-1][j][x++]);
                                    y++;
                                }

                            }
                        }
                    }
                }
            }
        }
        cout<<"Case #"<<kz+1<<": "<<dp[n][m].size()<<endl;
        for(string &s:dp[n][m])cout<<s<<endl;

    }

}
