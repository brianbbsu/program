#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define FILL(i,n) memset(i,n,sizeof i)
#define X first
#define Y second


const ll MAXn=1e5+5;
const ll INF=ll(1e18);

struct node{
	ll d,pri,sz;
	node *lc,*rc;
};

ll gsz(node *a){return a?a->sz:0;}


node *mg(node *a,node *b)
{
	if(!a||!b)return a?a:b;
	if(a->pri>b->pri)
	{
		a->rc=mg(a->rc,b);
		a->sz=gsz(a->rc)+gsz(a->lc)+1;
		return a;
	}
	b->lc=mg(a,b->lc);
	b->sz=gsz(b->rc)+gsz(b->lc)+1;
	return b;
}

void sp(node *a,node *&b,node *&c,ll k)//k X
{
	if(!a)b=c=0;
	else if(gsz(a->lc)>=k)
	{
		c=a;
		sp(a->lc,b,c->lc,k);
		c->sz=gsz(c->rc)+gsz(c->lc)+1;
	}
	else
	{
		b=a;
		sp(a->rc,b->rc,c,k-gsz(a->lc)-1);
		b->sz=gsz(b->rc)+gsz(b->lc)+1;
	}
}

ll d[MAXn];
ll tp[MAXn];
ii qr[MAXn];
ll n,q;


ll it=0;
ll ans[MAXn];

void dfs(node *a)
{
	if(!a)return;
	dfs(a->lc);
	ans[it++]=a->d;
	dfs(a->rc);
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	srand(time(0));
	
	cin>>n>>q;
	REP(i,n)cin>>d[i];
	node *rt=0;
	REP(i,n)rt=mg(rt,new node{d[i],rand(),1,0,0});
	/*it=0;
	dfs(rt);
    REP(i,n)cout<<(i?" ":"")<<ans[i];
	*/
	REP(i,q)
	{
		ll t;
		cin>>t;
		ll l,r;
		cin>>l>>r;
		node *a,*b,*c,*d;
		sp(rt,a,d,l-1);
		sp(d,b,c,r-l+1);
		if(t==1)
		{
			d=mg(b,a);
			rt=mg(d,c);
		}
		else
		{
			d=mg(a,c);
			rt=mg(d,b);
		}
		/*it=0;
		dfs(rt);
		REP(i,n)cout<<(i?" ":"")<<ans[i];
		*/
	}
	it=0;
	dfs(rt);
	cout<<abs(ans[0]-ans[n-1])<<endl;
	REP(i,n)cout<<(i?" ":"")<<ans[i];
	cout<<endl;

}