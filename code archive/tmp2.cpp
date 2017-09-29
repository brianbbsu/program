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



struct tg{
	int x,y,k,id;
};

struct edge{
	int a,b,c;
};

ll  n,m,q;

int tp[MAXn];
vector<tg> qrs;
int ans[MAXn];


vector<edge> e;


vector<int> qr[MAXlg][MAXn];
int l[MAXlg][MAXn],r[MAXlg][MAXn];

void predfs(ll ly,ll p)
{
	//cout<<ly<<" "<<p<<" "<<l[ly][p]<<" "<<r[ly][p]<<endl;
	if(l[ly][p]==r[ly][p]-1)return;
	l[ly+1][2*p]=l[ly][p];
	r[ly+1][2*p+1]=r[ly][p];
	r[ly+1][2*p]=l[ly+1][2*p+1]=(l[ly][p]+r[ly][p])/2;
	predfs(ly+1,2*p);
	predfs(ly+1,2*p+1);
}

///DSU
int g[MAXn],ct[MAXn];
unordered_set<int> st[MAXn];
int fd(int a)
{
	return g[a]=(g[a]==a?a:fd(g[a]));
}
void mg(int a,int b)
{
	a=fd(a);b=fd(b);
	if(a==b)return;
	if(SZ(st[a])>SZ(st[b]))swap(a,b);
	g[a]=b;
	for(ll tmp:st[a])
	{
		if(!st[b].count(tmp))
		{
			st[b].insert(tmp);
			ct[b]++;
		}
	}
	st[a].clear();
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
		a--;b--;
		e.pb((edge){a,b,c});
	}
	sort(e.begin(),e.end(),[](edge &a,edge &b){return a.c<b.c;});
	REP(i,q)
	{
		ll x,y,k;
		cin>>x>>y>>k;
		x--;y--;
		qrs.pb((tg){x,y,k,i});
		qr[0][0].pb(i);
	}
	l[0][0]=-1,r[0][0]=m+1;
	predfs(0,0);

	for(int now=0;;now++)
	{
		REP(i,n)
		{
			g[i]=i;
			st[i].clear();
			st[i].insert(tp[i]);
			ct[i]=1;
		}
		ll eit=0;
		bool fg=0;
		for(int i=0;;i++)
		{

			if(l[now][i]==r[now][i]-1)
			{
				for(auto &tmp:qr[now][i])ans[tmp]=r[now][i];
				if(r[now][i]==m+1)
				{
					fg=1;
					break;
				}
				continue;
			}
			ll h=(l[now][i]+r[now][i])/2;
			while(eit!=h)
			{
				auto &tmp=e[eit];
				mg(tmp.a,tmp.b);
				eit++;
			}
			for(auto iii:qr[now][i])
			{
				auto &tmp=qrs[iii];
				if(fd(tmp.x)==fd(tmp.y)&&SZ(st[fd(tmp.x)])>=tmp.k)qr[now+1][2*i].pb(iii);
				else qr[now+1][2*i+1].pb(iii);
			}
			qr[now][i].clear();
			if(r[now][i]==m+1)break;
		}
		if(fg)break;
	}
	REP(i,q)
	{
		if(ans[i]==0)cout<<0<<endl;
		else if(ans[i]==m+1)cout<<-1<<endl;
		else cout<<e[ans[i]-1].c<<endl;
	}
}
