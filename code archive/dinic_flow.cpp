//{
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
template<typename _a> ostream &operator << (ostream &_s,vector<_a> &_c){return _OUTC(_s,ALL(_c));}
template<typename _a> ostream &operator << (ostream &_s,set<_a> &_c){return _OUTC(_s,ALL(_c));}
template<typename _a,typename _b> ostream &operator << (ostream &_s,map<_a,_b> &_c){return _OUTC(_s,ALL(_c));}
template<typename _t> void pary(_t _a,_t _b){_OUTC(cerr,_a,_b);cerr<<endl;}
#define IOS()
#else
#define debug(...)
#define pary(...)
#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#endif // brian
//}


const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

namespace dinic{
  const int MAXn = 500;
  const int INF = 1e6;

  struct edge{
    int t,c,r;
    edge(int ti,int ci,int ri):t(ti),c(ci),r(ri){}
  };
  vector<edge> v[MAXn];
  void init()
  {
    for(int i=0;i<MAXn;i++)v[i].clear();
  }
  void add_edge(int s,int t,int c){
    v[s].pb(edge(t,c,SZ(v[t])  ));
    v[t].pb(edge(s,0,SZ(v[s])-1));
  }
  int dis[MAXn],iter[MAXn];
  void bfs(int s)
  {
    FILL(dis,-1);
    queue<int> q;
    dis[s]=0;q.push(s);
    while(SZ(q))
    {
      int t=q.front();
      q.pop();
      for(edge &e:v[t])if(e.c>0&&dis[e.t]==-1)
      {
        dis[e.t]=dis[t]+1;
        q.push(e.t);
      }
    }
  }
  int dfs(int now,int t,int mn)
  {
    if(now==t)return mn;
    for(int &i=iter[now];i<SZ(v[now]);i++)
    {
      edge &e=v[now][i];
      if(e.c>0&&dis[e.t]==dis[now]+1)
      {
        int d=dfs(e.t,t,min(mn,e.c));
        if(d>0)
        {
          e.c-=d; v[e.t][e.r].c+=d;
          return d;
        }
      }
    }
    return 0;
  }
  int flow(int s,int t)
  {
    int rt=0;
    while(1)
    {
      bfs(s);
      if(dis[t]==-1)return rt;
      FILL(iter,0);
      int d;
      while(d=dfs(s,t,INF))rt+=d;
    }
  }
};

int main()
{
    IOS();

}
