#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define FILL(i,n) memset(i,n,sizeof i)
#define X first
#define Y second
#define SZ(x) ((int)(x).size())
#define pb push_back

const ll MAXn=6e5+5,MAXlg=20;
const ll INF=ll(1e18);


#define L(x) ((x)*2+1)
#define R(x) ((x)*2+2)


ll n;

ll d[MAXn],seg[MAXn],h[MAXn];

set<ll> st[MAXlg];


void bldH(ll now)
{
	if(L(now)>2*n-2)h[now]=1;
	else
	{
		bldH(L(now));
		bldH(R(now));
		h[now]=h[L(now)]+1;
	}
}

void dfs(ll now,ll k)
{
	seg[now]=k;
	st[h[now]].erase(now);
	if(L(now)<=2*n-2)
	{
		dfs(L(now),k);
		st[h[R(now)]].insert(R(now));
	}
}

vector<ii> dt;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	
	cin>>n;
	REP(i,2*n-1)cin>>d[i];
	REP(i,2*n-1)seg[i]=INF;
	bldH(0);
	st[h[0]].insert(0);
	sort(d,d+2*n-1);
	REP(i,2*n-1)
	{
		if(!SZ(dt)||dt.back().X!=d[i])dt.pb(ii(d[i],1));
		else dt.back().Y++;
	}
	for(ii &tmp:dt)
	{
		//cout<<tmp.X<<" "<<tmp.Y<<endl;
		if(tmp.Y>=MAXlg||!SZ(st[tmp.Y]))
		{
			cout<<"NO"<<endl;
			return 0;
		}
		ll t=*st[tmp.Y].begin();
		
		dfs(t,tmp.X);
	}
	cout<<"YES"<<endl;
	REP(i,2*n-1)cout<<seg[i]<<" ";
	cout<<endl;
}