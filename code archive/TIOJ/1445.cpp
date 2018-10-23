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


const ll MAXn=1e3+5,MAXlg=__lg(MAXn)+1;
const ll MOD=1000000007;
const ll INF=ll(1e15);

vector<ii> v[MAXn];
int n,m;
struct edge{
  int a,b,c;
  edge(int ai,int bi,int ci):a(ai),b(bi),c(ci){}
  bool operator < (const edge &b)const {return c<b.c;}
};
vector<edge> e,d;
int g[MAXn];
int fd(ll a){return g[a]=(a==g[a]?a:fd(g[a]));}
void mg(ll a,ll b){g[fd(a)]=fd(b);}

int p[MAXn][MAXlg],ct[MAXn][MAXlg],dp[MAXn];

void dfs(ll now,ll f,ll cti)
{
  p[now][0]=f;ct[now][0]=cti;
  for(auto &k:v[now])if(k.X!=f)dp[k.X]=dp[now]+1,dfs(k.X,now,k.Y);
}
ii lca(ll a,ll b)
{
  int mn=0;
  if(dp[a]<dp[b])swap(a,b);
  for(int t=MAXlg-1;t>=0;t--)if(p[a][t]!=-1&&dp[p[a][t]]>=dp[b])mn=max(mn,ct[a][t]),a=p[a][t];
  if(a==b)return ii(a,mn);
  for(int t=MAXlg-1;t>=0;t--)
  {
    if(p[a][t]!=p[b][t])
    {
      mn=max({mn,ct[a][t],ct[b][t]});
      a=p[a][t];
      b=p[b][t];
    }
  }
  return ii(p[a][0],max({mn,ct[a][0],ct[b][0]}));
}

ll sum=0;
int main()
{
    IOS();
    cin>>n>>m;
    REP(i,m)
    {
      ll a,b,c;
      cin>>a>>b>>c;
      a--;b--;
      e.pb(edge(a,b,c));
    }
    sort(ALL(e));
    REP(i,n)g[i]=i;
    for(auto &k:e)
    {
      if(fd(k.a)!=fd(k.b))
      {
        sum+=k.c;
        mg(k.a,k.b);
        v[k.a].pb(ii(k.b,k.c));
        v[k.b].pb(ii(k.a,k.c));
      }
      else d.pb(k);
    }
    ll cnt=0;
    REP(i,n)if(g[i]==i)cnt++;
    if(cnt>1){cout<<"-1 -1"<<endl;return 0;}
    if(SZ(d)==0){cout<<sum<<" -1"<<endl;return 0;}
    dp[0]=1;
    dfs(0,-1,0);
    for(int j=1;j<MAXlg;j++)REP(i,n)if(p[i][j-1]!=-1){p[i][j]=p[p[i][j-1]][j-1];ct[i][j]=max(ct[i][j-1],ct[p[i][j-1]][j-1]);}
    ll mn=INF;
    for(auto &k:d)
    {
      ii tmp=lca(k.a,k.b);
      debug(tmp);
      mn=min(mn,k.c-tmp.Y);
    }
    cout<<sum<<" "<<sum+mn<<endl;
}
