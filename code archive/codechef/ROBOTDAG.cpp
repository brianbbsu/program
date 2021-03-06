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

namespace FF{
  const int MAXn=1e4+200;
  const int INF = 1e6;
  struct edge{
    int t,c,r;
  };
  vector<edge> v[MAXn];
  void init()
  {
    REP(i,MAXn)v[i].clear();
  }
  void add_edge(int a,int b,int c){
    //debug(a,b,c);
    v[a].pb((edge){b,c,SZ(v[b])  });
    v[b].pb((edge){a,0,SZ(v[a])-1});
  }
  int vis[MAXn];
  int dfs(int now,int t,int f,int it){
    //debug(now,t,f,it);
    if(now==t)return f;
    vis[now]=it;
    for(edge &e:v[now])
    {
      if(vis[e.t]!=it&&e.c>0)
      {
        int d=dfs(e.t,t,min(f,e.c),it);
        if(d>0)
        {
          e.c-=d; v[e.t][e.r].c += d;
          return d;
        }
      }
    }
    return 0;
  };
  int flow(int s,int t,int mxt)
  {
    FILL(vis,-1);
    int it=0,rt=0;
    int d=0;
    while(it!=mxt&&(d=dfs(s,t,INF,it++)) > 0)rt+=d;
    return rt;
  }
};

vector<ll> v[MAXn];
#define fS 1
#define fT 10111

int main()
{
    IOS();
    ll T;
    cin>>T;
    while(T--)
    {
      ll n,m,k;
      cin>>n>>m>>k;
      REP1(i,n)v[i].clear();
      REP(i,m)
      {
        ll a,b;
        cin>>a>>b;
        v[a].pb(b);
      }
      ll l=0,r=n+1;
      while(l!=r-1)
      {
        FF::init();
        ll h=(l+r)/2;
        REP1(i,h)FF::add_edge(i*n+n,fT,k);
        REP(i,h)REP1(j,n)for(ll t:v[j])FF::add_edge(i*n+j,(i+1)*n+t,1);
        ll rt=FF::flow(fS,fT,k);
        debug(T,h,rt);
        if(rt>=k)r=h;
        else l=h;
      }
      if(r==n+1)cout<<-1<<endl;
      else cout<<r<<endl;
    }
}
/*
1
4 4 2
1 2
1 3
2 4
3 4
*/

/*
3
8 11 1
1 2
1 3
1 4
6 7
2 5
3 6
3 2
4 6
5 7
7 8
2 7
8 11 2
1 2
1 3
1 4
6 7
2 5
3 6
3 2
4 6
5 7
7 8
2 7
8 11 3
1 2
1 3
1 4
6 7
2 5
3 6
3 2
4 6
5 7
7 8
2 7

3
4
5
*/
