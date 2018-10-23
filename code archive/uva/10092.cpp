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


const ll MAXn=2e3+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e9);


struct {
  struct edge{int to,cap,rev;};
  vector<edge> v[MAXn];
  int n,s,t;
  void init(int _n,int _s,int _t)
  {
    n=_n,s=_s,t=_t;
    REP1(i,n)v[i].clear();
  }
  void add_edge(int from,int to,int cap)
  {
    v[from].pb({to,cap,SZ(v[to])});
    v[to].pb({from,0,SZ(v[from])-1});
  }
  int dis[MAXn],iter[MAXn];
  void bfs()
  {
    REP1(i,n)dis[i]=-1;
    dis[s]=0;
    queue<ll> q;q.push(s);
    while(SZ(q))
    {
      int now=q.front();q.pop();
      for(edge &e:v[now])if(e.cap&&dis[e.to]==-1)
      {
        dis[e.to]=dis[now]+1;
        q.push(e.to);
      }
    }
  }
  int dfs(int now,int f)
  {
    if(now==t)return f;
    for(int &i=iter[now];i<SZ(v[now]);i++)
    {
      edge &e=v[now][i];
      if(e.cap&&dis[e.to]==dis[now]+1)
      {
        int d=dfs(e.to,min(f,e.cap));
        if(d)
        {
          e.cap-=d;
          v[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }
  int flow()
  {
    ll tt=0;
    while(1)
    {
      bfs();
      if(dis[t]==-1)return tt;
      REP1(i,n)iter[i]=0;
      ll d;
      while(d=dfs(s,INF)){
        tt+=d;
      }
    }
  }

} dinic;


int need[MAXn];

int main()
{
    IOS();
    ll n,m;
    while(cin>>n>>m&&(n||m))
    {
      dinic.init(n+m+2, n+m+1, n+m+2);
      ll tt=0;
      REP1(i,n)cin>>need[i],tt+=need[i],dinic.add_edge(i,  n+m+2, need[i]);
      REP1(i,m)
      {
        dinic.add_edge(n+m+1, n+i, 1);
        ll t;
        cin>>t;
        REP(j,t)
        {
          ll x;
          cin>>x;
          dinic.add_edge(n+i, x, 1);
        }
      }
      if(dinic.flow()==tt)
      {
        cout<<1<<endl;
        REP1(i,n)
        {
          vector<ll> tmp;
          for(auto e:dinic.v[i])
          {
            if(e.to<=n+m&&e.cap==1)tmp.pb(e.to-n);
          }
          assert(SZ(tmp)==need[i]);
          REP(j,SZ(tmp))cout<<tmp[j]<<" \n"[j==SZ(tmp)-1];
        }
      }
      else cout<<0<<endl;
    }

}
