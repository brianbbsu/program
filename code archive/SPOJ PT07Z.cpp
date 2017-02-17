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


ll n,m,l;
vector<ii> v[MAXn];
bool vis[MAXn];
ll dp[MAXn];
ll mx=0;
ll tt=0;
void dfs(ll now,ll f)
{
    vis[now]=1;
    ii tmp=ii(0,0);
    for(auto &k:v[now])
    {
        if(k.X==f)continue;
        dfs(k.X,now);
        dp[now]=max(dp[now],dp[k.X]+k.Y);
        if(dp[k.X]+k.Y>tmp.Y)tmp.Y=dp[k.X]+k.Y;
        if(tmp.Y>tmp.X)swap(tmp.X,tmp.Y);
    }
    mx=max(mx,tmp.X+tmp.Y);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    REP(i,n)v[i].resize(0);
    FILL(vis,0);
    FILL(dp,0);
    REP(i,n-1)
    {
        ll a,b;
        cin>>a>>b;
        a--;
        b--;
        v[a].pb(ii(b,1));
        v[b].pb(ii(a,1));
    }

    dfs(0,-1);
    cout<<mx<<endl;
}
