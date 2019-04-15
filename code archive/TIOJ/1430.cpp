//{
#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(ll i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define FILL(i,n) memset(i,n,sizeof i)
#define X first
#define Y second
#define SZ(_a) (int)_a.size()
#define ALL(_a) _a.begin(),_a.end()
#define pb push_back

#define debug(...)
#define pary(...)
#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);


const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e9);

int ct[MAXn], uni[MAXn], dp[2][MAXn], mx[MAXn], mn[MAXn];
ii dt[MAXn];

int main()
{
    IOS();
    ll n, m, k, mm;
    cin>>n>>k>>m;
    mm = m;
    m = 0;
    while(mm--)
    {
        ll l, r, c;
        cin>>l>>r>>c;
        if(!c)ct[l]++, ct[r+1]--;
        else dt[m++] = ii(l, r);
    }
    REP1(i, n + 1)ct[i] += ct[i-1];
    REP1(i, n)ct[i] = (ct[i] > 0?0:1) + ct[i-1];
    REP(i,m)dt[i].X = ct[dt[i].X - 1] + 1, dt[i].Y = ct[dt[i].Y];
    REP1(i, n)if(ct[i] != ct[i-1])uni[ct[i]] = i;
    n = ct[n];
    if(n == k)
    {
        REP1(i,n)cout<<uni[i]<<endl;
        return 0;
    }
    REP(i,m)mx[dt[i].Y + 1] = max(mx[dt[i].Y + 1], dt[i].X);
    REP1(i,n)mx[i] = max(mx[i], mx[i-1]);
    REP1(i,n)dp[0][i] = dp[0][mx[i]] + 1;
    REP(i,n + 2)mn[i] = n+1;
    REP(i,m)mn[dt[i].X - 1] = min(mn[dt[i].X - 1], dt[i].Y);
    for(int i = n;i >= 0;i --)mn[i] = min(mn[i], mn[i+1]);
    for(int i = n;i > 0;i --)dp[1][i] = dp[1][mn[i]] + 1;
    REP1(i,n)ct[i] = 0;
    REP(i,n+1)if(dp[0][i] + dp[1][mn[i]] <= k){ct[i+1]++, ct[mn[i]]--;}
    REP1(i,n)ct[i] += ct[i-1];
    bool fg = 0;
    REP1(i,n)if(!ct[i])cout<<uni[i]<<endl, fg = 1;
    if(!fg)cout<<-1<<endl;

}
