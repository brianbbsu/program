//{
#include<cstdio>
#include<algorithm>
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

//}


const ll MAXn=2e6+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);


ii d[MAXn];
ll l[MAXn],r[MAXn];

inline bool win(ll a,ll b)//a win b?
{
  if(d[a].X<d[b].X||d[a].Y<d[b].Y||d[a]==d[b])return 0;
  else return 1;
}

int main()
{
    ll n;
    scanf("%d",&n);
    REP(i,n)scanf("%d %d",&d[i].X,&d[i].Y);
    l[0]=0;
    REP1(i,n-1)
    {
      ll now=i-1;
      while(now!=-1)
      {
        if(win(i,now))now=l[now]-1;
        else break;
      }
      l[i]=now+1;
    }
    r[n-1]=n-1;
    for(int i=n-2;i>=0;i--)
    {
      ll now=i+1;
      while(now!=n)
      {
        if(win(i,now))now=r[now]+1;
        else break;
      }
      r[i]=now-1;
    }
    ll mx=0;
    REP(i,n)mx=max(mx,r[i]-l[i]);
    printf("%d\n",mx);
}
