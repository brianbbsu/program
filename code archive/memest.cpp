//{
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(ll i=0;i<n;i++)
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


const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+1;
const ll MOD=1000000007;
const ll INF=ll(1e15);

vector<ii> v[MAXn];
int st[MAXn][MAXlg];
ll mx[MAXn][MAXlg];
struct edge{
  int a,b;
  ll c;
  bool fg;
  edge(int ai,int bi,ll ci,bool fgi):a(ai),b(bi),c(ci),fg(fgi){}
  bool operator < (const edge &t)const {return make_pair(c,!fg)<make_pair(t.c,!t.fg);}
};
vector<edge> e,d;

int g[MAXn];
int fd(int a){return g[a]=(g[a]==a?a:fd(g[a]));}
void mg(int a,int b){g[fd(a)]=fd(b);}

int dp[MAXn];
void dfs(int now,int f,ll ct)
{
  st[now][0]=f;mx[now][0]=ct;
  for(ii &k:v[now])if(k.X!=f)
  {
    dp[k.X]=dp[now]+1;
    dfs(k.X,now,k.Y);
  }
}

ll lca(int a,int b)
{
  ll rt=0;
  if(dp[a]<dp[b])swap(a,b);
  for(int i=MAXlg-1;i>=0;i--)if(st[a][i]!=-1&&dp[st[a][i]]>=dp[b])rt=max(rt,mx[a][i]),a=st[a][i];
  if(a==b)return rt;
  for(int i=MAXlg-1;i>=0;i--)if(st[a][i]!=st[b][i])rt=max({rt,mx[a][i],mx[b][i]}),a=st[a][i],b=st[b][i];
  return max({rt,mx[a][0],mx[b][0]});
}

ll n,m;
int main()
{
    IOS();
    cin>>n>>m;
    REP(i,m)
    {
      int a,b,c;
      bool fg;
      cin>>a>>b>>c>>fg;
      a--;b--;
      e.pb(edge(a,b,c,fg));
    }
    sort(ALL(e));
    REP(i,n)g[i]=i;
    bool getfg=0;
    ll tt=0;
    for(edge &k:e)
    {
      if(fd(k.a)!=fd(k.b))
      {
        mg(k.a,k.b);
        v[k.a].pb(ii(k.b,k.c));
        v[k.b].pb(ii(k.a,k.c));
        if(k.fg)getfg=1;
        tt+=k.c;
      }
      else if(k.fg)d.pb(k);
    }
    if(getfg){cout<<tt<<endl;return 0;}
    dp[0]=1;
    dfs(0,-1,0);
    for(int j=1;j<MAXlg;j++)REP(i,n)if(st[i][j-1]!=-1)st[i][j]=st[st[i][j-1]][j-1],mx[i][j]=max(mx[i][j-1],mx[st[i][j-1]][j-1]);
    ll mn=INF;
    for(edge &k:d)
    {
      ll tmp=lca(k.a,k.b);
      mn=min(mn,k.c-tmp);
    }
    cout<<tt+mn<<endl;
}
