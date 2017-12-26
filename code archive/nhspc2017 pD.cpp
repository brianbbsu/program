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


const ll MAXn=4e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);


struct edge{
  int to,cap,rev;
};

vector<edge> v[MAXn];
int it[MAXn],dis[MAXn];

#define S 400001
#define T 400002
#define P(x) (x)
#define Q(x) ((x)+200000)

void reset(int x)
{
  v[x].clear();
}

void add_edge(int s,int t,int c)
{
  v[s].pb((edge){t,c,SZ(v[t])  });
  v[t].pb((edge){s,0,SZ(v[s])-1});
}

void bfs(int s)
{
  queue<int> q;
  q.push(s);
  while(SZ(q))
  {
    int t=q.front();q.pop();
    for(auto &k:v[t])if(k.cap && dis[k.to] == -1)
    {
      dis[k.to] = dis[t] + 1;
      q.push(k.to);
    }
  }
}

int dfs(int now,int mn,int t)
{
  if(now==t)return mn;
  for(;it[now]<SZ(v[now]);it[now]++)
  {
    edge &k = v[now][it[now]];
    if(k.cap && dis[k.to]==dis[now]+1)
    {
      int d = dfs(k.to,min(mn,k.cap),t);
      if(d)
      {
        k.cap -= d;
        v[k.to][k.rev].cap +=d;
        return d;
      }
    }
  }
  return 0;
}

int flow(int s,int t,int p,int q)
{
  ll tt=0;
  while(1)
  {
    REP1(i,p)dis[P(i)] = -1;
    REP1(i,q)dis[Q(i)] = -1;
    dis[s] = 0;dis[t] = -1;
    bfs(s);
    if(dis[t]==-1)return tt;
    REP1(i,p)it[P(i)] = 0;
    REP1(i,q)it[Q(i)] = 0;
    it[s] = 0;it[t] = 0;
    int d;
    while(d=dfs(s,1000000000,t))
    {
      tt+=d;
    }
  }
}

int main()
{
    IOS();
    ll kz;
    cin>>kz;
    while(kz--)
    {
        int p,q,k;
        cin>>p>>q>>k;
        REP1(i,p)reset(P(i));
        REP1(i,q)reset(Q(i));
        reset(S);reset(T);

        REP(i,k)
        {
          ll a,b;
          cin>>a>>b;
          add_edge(P(a),Q(b),1);
        }
        REP1(i,p)add_edge(S,P(i),1);
        REP1(i,q)add_edge(Q(i),T,1);
        debug(123);
        cout<<flow(S,T,p,q)<<endl;
    }

}
