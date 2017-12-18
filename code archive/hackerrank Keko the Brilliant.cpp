#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(ll i=0;i<n;i++)
#define SZ(_a) (int)_a.size()
#define pb push_back
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);

const ll MAXn=2e5+5;

ll d[MAXn];
vector<ll> v[MAXn];
multiset<ll> st[MAXn];

void dfs(ll now,ll f)
{
  for(ll k:v[now])
  {
    if(k==f)continue;
    dfs(k,now);
    if(SZ(st[k])>SZ(st[now]))st[now].swap(st[k]);
    for(ll tmp:st[k])st[now].insert(tmp);
    st[k].clear();
  }
  st[now].insert(0);st[now].insert(d[now]+1);
  st[now].erase(prev(st[now].upper_bound(d[now])));
}

int main()
{
    IOS();
    ll n;
    cin>>n;
    REP(i,n)cin>>d[i];
    REP(i,n-1){
      ll a,b;
      cin>>a>>b;
      a--;b--;
      v[a].pb(b);v[b].pb(a);
    }
    dfs(0,-1);
    cout<<st[0].count(0)<<endl;
}
