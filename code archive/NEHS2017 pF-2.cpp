#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define FILL(i,n) memset(i,n,sizeof i)
#define X first
#define Y second
#define SZ(x) ((ll)(x).size())
#define pb push_back
#define endl '\n'
#define ALL(_a) ((_a).begin(),(_a).end())

const ll MAXn=1e5+5,MAXlg=19;

struct edge{int a,b,c;};
vector<edge> e;

ll  n,m,q;
int tp[MAXn],gl[MAXn],ans[MAXn];

///DSU
int g[MAXn];
set<int> qr[MAXn],clr[MAXn];
set<ii> wt[MAXn];
int fd(int a)
{
	return g[a]=(g[a]==a?a:fd(g[a]));
}
void mg(int a,int b,int c)
{
	a=fd(a);b=fd(b);
	if(a==b)return;

  if(SZ(clr[a])>SZ(clr[b]))clr[a].swap(clr[b]);
  if(SZ(qr[a])>SZ(qr[b]))qr[a].swap(qr[b]);
  if(SZ(wt[a])>SZ(wt[b]))wt[a].swap(wt[b]);

  g[a]=b;

  for(ll tmp:clr[a])clr[b].insert(tmp);

  for(ll tmp:qr[a])
  if(qr[b].count(tmp))
  {
    qr[b].erase(tmp);
    wt[b].insert(ii(gl[tmp],tmp));
  }
  else qr[b].insert(tmp);

	for(ii tmp:wt[a])wt[b].insert(tmp);

  while(SZ(wt[b])&&(wt[b].begin()->X)<=SZ(clr[b]))
  {
    ans[wt[b].begin()->Y]=c;
    wt[b].erase(wt[b].begin());
  }
  wt[a].clear();clr[a].clear();qr[a].clear();
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>q;
	REP(i,n)cin>>tp[i];
	REP(i,m)
	{
		int a,b,c;
		cin>>a>>b>>c;
		e.pb((edge){a-1,b-1,c});
	}
	sort(e.begin(),e.end(),[](edge &a,edge &b){return a.c<b.c;});
	REP(i,q)
	{
		ll x,y;
		cin>>x>>y>>gl[i];
    if(x!=y)qr[x-1].insert(i),qr[y-1].insert(i);
    else wt[x-1].insert(ii(gl[i],i));
	}
  REP(i,n)g[i]=i,clr[i].insert(tp[i]);
  FILL(ans,-1);
  for(auto &tmp:e)mg(tmp.a,tmp.b,tmp.c);
	REP(i,q)cout<<ans[i]<<endl;
}
