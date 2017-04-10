//{
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<int,int> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define FIint(i,n) memset(i,n,sizeof i)
#define X first
#define Y second
#define SZ(_a) (int)_a.size()
#define Aint(_a) _a.begin(),_a.end()
#define pb push_back
#ifdef brian
#define debug(...) do{\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0)
template<typename T>void _do(T &&_x){cerr<<_x<<endl;}
template<typename T,typename ...S> void _do(T &&_x,S &&..._t){cerr<<_x<<" ,";_do(_t...);}
template<typename _a,typename _b> ostream& operator << (ostream &_s,const pair<_a,_b> &_p){return _s<<"("<<_p.X<<","<<_p.Y<<")";}
template<typename It> ostream& _OUTC(ostream &_s,It _ita,It _itb)
{
    _s<<"{";
    for(It _it=_ita;_it!=_itb;_it++)
    {
        _s<<(_it==_ita?"":",")<<*_it;
    }
    _s<<"}";
    return _s;
}
template<typename _a> ostream &operator << (ostream &_s,vector<_a> &_c){return _OUTC(_s,Aint(_c));}
template<typename _a> ostream &operator << (ostream &_s,set<_a> &_c){return _OUTC(_s,Aint(_c));}
template<typename _a,typename _b> ostream &operator << (ostream &_s,map<_a,_b> &_c){return _OUTC(_s,Aint(_c));}
template<typename _t> void pary(_t _a,_t _b){_OUTC(cerr,_a,_b);cerr<<endl;}
#define IOS()
#else
#define debug(...)
#define pary(...)
#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#endif // brian
//}


const int MAXn=1e4+5,MAXlg=__lg(MAXn)+2;
const int MOD=1000000007;
const int INF=int(1e15);

vector<ii> v[MAXn];
int n,m,q;
int d[MAXn],sbcnt[MAXn],st[MAXn][MAXlg];
ll dis[MAXn],dp[MAXn][2];
void predfs(int now,int f)
{
    st[now][0]=f;
    for(ii &k:v[now])
    {
      if(k.X==f)continue;
      dp[k.X][0]=dp[now][0]+1;
      dp[k.X][1]=dp[now][1]+k.Y;
      predfs(k.X,now);
    }
}
void dfs1(int now,int f)
{
  dis[now]=0;
  for(ii &k:v[now])
  {
    if(k.X==f)continue;
    dfs1(k.X,now);
    sbcnt[now]+=sbcnt[k.X];
    dis[now]+=dis[k.X]+sbcnt[k.X]*k.Y;
  }
}
void dfs2(int now,int f)
{
  for(ii &k:v[now])
  {
    if(k.X==f)continue;
    dis[k.X]=dis[now]+((m-sbcnt[k.X]-1)-sbcnt[k.X])*k.Y;
    dfs2(k.X,now);
  }
}
int lca(int a,int b)
{
  if(dp[a][0]<dp[b][0])swap(a,b);
  for(int i=MAXlg-1;i>=0;i--)if(st[a][i]!=-1&&dp[st[a][i]][0]>=dp[b][0])a=st[a][i];
  if(a==b)return a;
  for(int i=MAXlg-1;i>=0;i--)if(st[a][i]!=st[b][i])a=st[a][i],b=st[b][i];
  return st[a][0];
}
ll qrdis(int a,int b)
{
  int k=lca(a,b);
  return dp[a][1]+dp[b][1]-2*dp[k][1];
}
vector<ii> qr;
stack<ii> stk;
int main()
{
    IOS();
    int T;
    cin>>T;
    while(T--&&cin>>n>>m>>q)
    {
      REP(i,n)v[i].clear();
      qr.clear();
      REP(i,n-1)
      {
        int a,b,c;
        cin>>a>>b>>c;
        a--;b--;
        v[a].pb(ii(b,c));
        v[b].pb(ii(a,c));
      }
      FIint(d,0);
      FIint(sbcnt,0);
      FIint(st,-1);
      sbcnt[0]=m-1;
      FIint(dis,0);
      dp[0][0]=dp[0][1]=0;
      predfs(0,-1);
      dfs2(0,-1);
      for(int i=1;i<MAXlg;i++)REP(j,n)if(st[j][i-1]!=-1)st[j][i]=st[st[j][i-1]][i-1];
      int k=sqrt(n*1.0/__lg(n)+0.5);
      debug(k);
      REP(t,q)
      {
          pary(dis,dis+n);
          pary(sbcnt,sbcnt+n);
          pary(d,d+m);
          int s,x;
          cin>>s>>x;
          s--;x--;
          if(s==0)d[0]=x;
          else qr.pb(ii(s,x));
          int ans=dis[d[0]];
          for(ii &tmp:qr)
          {
            stk.push(ii(tmp.X,d[tmp.X]));
            ans-=qrdis(d[tmp.X],d[0]);
            d[tmp.X]=tmp.Y;
            ans+=qrdis(d[tmp.X],d[0]);
          }
          cout<<ans<<endl;
          while(SZ(stk))
          {
            d[stk.top().X]=stk.top().Y;
            stk.pop();
          }
          if(SZ(qr)==k)
          {
            debug(qr);
            FIint(sbcnt,0);
            for(ii &tmp:qr)d[tmp.X]=tmp.Y;
            REP(i,m-1)sbcnt[d[i+1]]++;
            dfs1(0,-1);
            dfs2(0,-1);
            qr.clear();
          }
      }
    }
}
