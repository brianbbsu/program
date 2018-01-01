//{
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
#define REP(i,n) for(ll i=0;i<n;i++)
#define FILL(i,n) memset(i,n,sizeof i)
#define X first
#define Y second
#define SZ(_a) (int)_a.size()
#ifdef brian
#define IOS()
#else
#define debug(...)
#define pary(...)
#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#endif // brian
//}


const ll MAXn=1e3+5,MAXlg=__lg(MAXn)+2;


string org="RYB",clrs="RYBWOPGD";
int trans[10][5],dis[3][MAXn][MAXn],cnt[MAXn];
int dx[]={-1,-1,-1,0,0,1,1,1},dy[]={-1,0,1,-1,1,-1,0,1},
dt[3][8]={
  //R,Y,B,W,O,P,G,D
   {1,0,0,0,1,1,0,1}, //R
   {0,1,0,0,1,0,1,1}, //Y
   {0,0,1,0,0,1,1,1}  //B
  };
ii start[5];

int main()
{
    IOS();
    FILL(trans,-1);
    REP(i,8)REP(j,3)REP(k,8){ //color i + color j -> color k??
      bool fg=(dt[j][i]==0);
      REP(l,3)if(dt[l][i]+(l==j)!=dt[l][k])fg=0;
      if(fg)trans[i][j]=k;
    }
    ll T;
    cin>>T;
    while(T--)
    {
      ll n;
      cin>>n;
      REP(i,3){
        char c;ii tmp;
        cin>>c>>tmp.X>>tmp.Y;
        REP(j,3)if(org[j]==c)start[j]=tmp;
      }
      REP(k,3)REP(i,n)REP(j,n)dis[k][i][j]=-1;
      REP(clr,3)
      {
        queue<ii> q;
        q.push(start[clr]);dis[clr][start[clr].X][start[clr].Y]=0;
        while(SZ(q)){
          int x=q.front().X,y=q.front().Y;q.pop();
          REP(k,8){
            int tx=x+dx[k],ty=y+dy[k];
            if(tx>=0&&tx<n&&ty>=0&&ty<n&&dis[clr][tx][ty]==-1)dis[clr][tx][ty]=dis[clr][x][y]+1,q.push(ii(tx,ty));
          }
        }
      }
      FILL(cnt,0);
      char c;int t;
      cin>>c;
      REP(i,8)if(c==clrs[i])t=i;
      REP(i,n)REP(j,n)
      {
        int tmp[]={0,1,2};
        sort(tmp,tmp+3,[&](int a,int b){return dis[a][i][j]<dis[b][i][j];});
        int now = 3;// White
        REP(k,3)
        {
          if(now==t)cnt[dis[tmp[k]][i][j]]--;
          now = trans[now][tmp[k]];
          if(now==t)cnt[dis[tmp[k]][i][j]]++;
        }
      }
      int mx=0,tt=0;
      REP(i,n+1)tt+=cnt[i],mx=max(mx,tt);
      cout<<mx<<endl;
    }
}
