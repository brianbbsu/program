#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(ll i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);

const ll MAXn=1e6+5;
const ll INF=ll(1e18), SINF = ll(1e9);

struct seg{ll a, b, l, r;}dq[MAXn];
ll cal(seg &s, ll x){return s.a * x + s.b;}
ll p[MAXn], dp[MAXn], itl, itr;

int main()
{
    IOS();
    ll n, a, b, c;
    cin>>n>>a>>b>>c;
    REP1(i,n)cin>>p[i], p[i] += p[i-1];
    dq[itr++] = seg({0,0,-SINF,SINF});
    REP1(i,n)
    {
        while(dq[itl].r < p[i])itl++;
        dp[i] = cal(dq[itl], p[i]) + a * p[i] * p[i] + b * p[i] + c;
        seg tmp({-2 * a * p[i], dp[i] + a * p[i] * p[i] - b * p[i], -SINF, SINF});
        while(itl < itr && cal(dq[itr-1], dq[itr-1].l) <= cal(tmp, dq[itr-1].l))itr--;
        if(itl != itr)
        {
            dq[itr - 1].r = (dq[itr-1].b - tmp.b) / (tmp.a - dq[itr-1].a);
            tmp.l = dq[itr-1].r + 1;
        }
        dq[itr++] = tmp;
    }
    cout<<dp[n]<<endl;
}
