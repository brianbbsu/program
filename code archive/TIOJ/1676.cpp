#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(ll i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);

const ll MAXn=5e5+5,MAXlg=__lg(MAXn)+2;

struct seg{
    ll a,b, l, r, i;
};

ll cal(seg &s, ll i){
    return s.a * i + s.b;
}

ll d[MAXn], dp[MAXn], s[MAXn];
seg dq[MAXn];

int itl = 0, itr = 0;

int main()
{
    IOS();
    ll n,k;
    cin>>n>>k;
    REP1(i,n)cin>>d[i];
    for(int i = n;i > 0;i --)s[i] = s[i+1] + d[i];
    dq[itr++] = seg({0,0,-1,k, 0});
    REP1(i,n)
    {
        while(dq[itl].r < i)itl++;
        dp[i] = cal(dq[itl], i) + s[i+1] - i * i;
        seg t({2 * i, dp[i] - i * i, i+1, MAXn, i});
        while(itr - itl > 0 && cal(dq[itr-1], dq[itr-1].l) <= cal(t, dq[itr-1].l))t.l = dq[--itr].l;
        if(itr != itl)
        {
            ll tmp = (t.b - dq[itr-1].b) / (dq[itr-1].a - t.a);
            dq[itr-1].r = min(tmp, dq[itr-1].i + k);
            t.l = dq[itr - 1].r + 1;
        }
        dq[itr++] = t;
    }
    cout<<dp[n]<<endl;
}
