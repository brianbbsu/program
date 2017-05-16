#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define FILL(i,n) memset(i,n,sizeof i)
#define X first
#define Y second
#define pb push_back
#define SZ(_a) ((int)(_a).size())
#define ALL(_a) (_a).begin(),(_a).end()
#ifdef brian
#define debug(...) do{\
  fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
  _do(__VA_ARGS__);\
}while(0)
template<typename T>void _do(T &&x){cerr<<x<<endl;}
template<typename T,typename ...t>void _do(T &&x,t &&...X){cerr<<x<<", ";_do(X...);}
#define IOS() ;
#else
#define debug(...)
#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#endif

const ll MAXn = 3e2+5;
const ll INF=int(1e8);
const ll MOD=1000000007;

int cnt[MAXn][MAXn];
int mn[2][MAXn];
int t[MAXn][MAXn];
ii d[5005];


int cal(int x,int y,int a,int b)
{
  return cnt[a][b]-cnt[a][y-1]-cnt[x-1][b]+cnt[x-1][y-1];
}

int main()
{
  IOS();

  int l,w;
  int n,k;

  cin>>l>>w;
  cin>>n>>k;

  REP(i,n)
  {
    cin>>d[i].X>>d[i].Y;
    cnt[d[i].X][d[i].Y]++;
  }
  REP1(i,l)REP1(j,w)cnt[i][j]+=cnt[i-1][j]+cnt[i][j-1]-cnt[i-1][j-1];

  REP1(i,l+1)mn[0][i]=INF;
  REP1(i,w+1)mn[1][i]=INF;
  REP1(i,l)REP1(j,w)t[i][j]=INF;

  REP1(i,l)REP1(j,w)
  {
      ll m=1;
      for(int x=i;x<=l;x++)
      {
        while(m<j&&cal(i,m+1,x,j)>=k)m++;
        if(cal(i,m,x,j)==k)
        {
          int tmp=2*(x-i+1+j-m+1);
          debug(i,j,x,m,tmp);
          t[x][j]=min(t[x][j],tmp);
          mn[0][i]=min(mn[0][i],tmp);
          mn[1][m]=min(mn[1][m],tmp);
        }
      }
  }
  /*
  REP(i,n)
  {
    for(int x=d[i].X;x<=l;x++)
    {
      int tl=d[i].Y-1,r=w+1;
      while(tl!=r-1)
      {
        int h=(tl+r)/2;
        if(cal(d[i].X,d[i].Y,x,h)>=k)r=h;
        else tl=h;
      }
      if(r!=w+1&&cal(d[i].X,d[i].Y,x,r)==k)t[i][x]=r;
      else t[i][x]=INF;
    }
  }

  REP(i,n)
  {
    int tmp=INF;
    for(int x=d[i].X;x<=l;x++)tmp=min(tmp,2*(t[i][x]-d[i].Y+1+x-d[i].X+1));
    mn[0][d[i].X]=min(mn[0][d[i].X],tmp);
    mn[1][d[i].Y]=min(mn[1][d[i].Y],tmp);
  }
  */
  for(int i=l-1;i>=1;i--)mn[0][i]=min(mn[0][i],mn[0][i+1]);
  for(int i=w-1;i>=1;i--)mn[1][i]=min(mn[1][i],mn[1][i+1]);

  int ans=INF;
  REP1(i,l)debug(i,mn[0][i]);
  REP1(i,w)debug(i,mn[1][i]);

  REP1(i,l)
  {
    REP1(j,w)
    {
      ans=min(ans,t[i][j]+min(mn[0][i+1],mn[1][j+1]));
      debug(i,j,t[i][j]);
    }
  }
  if(ans==INF)cout<<"NO"<<endl;
  else cout<<ans<<endl;

}
