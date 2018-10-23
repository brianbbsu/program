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

vector<vector<int> > d;
vector<ll> v[MAXn];
ll dp[MAXn];

ll g[MAXn];
ll fd(ll x){debug(x);return g[x] = (g[x] == x?x:fd(g[x]));}
void mg(ll a,ll b){g[fd(a)]=fd(b);}

ll dt[MAXn];

ll n,m;
#define hs(a,b) ((a)*m + (b))

void dfs(ll now)
{
  dp[now] = 1;
  for(ll k:v[now])
  {
    if(dp[k] == -1)dfs(k);
    dp[now] = max(dp[now],dp[k] + 1);
  }
}

int main()
{
    IOS();
    cin>>n>>m;
    d.resize(n,vector<int>(m));
    REP(i,n)REP(j,m)cin>>d[i][j];
    debug(123);
    REP(i,n)REP(j,m)g[hs(i,j)]=hs(i,j);
    REP(i,n){
      REP(j,m)dt[j] = j;
      sort(dt,dt+m,[=](int a,int b){return d[i][a] < d[i][b];});
      REP(j,m-1)if(d[i][dt[j]] == d[i][dt[j+1]])mg(hs(i,dt[j]),hs(i,dt[j+1]));
    }
    REP(i,m){
      REP(j,n)dt[j] = j;
      sort(dt,dt+n,[=](int a,int b){return d[a][i] < d[b][i];});
      REP(j,n-1)if(d[dt[j]][i] == d[dt[j+1]][i])mg(hs(dt[j],i),hs(dt[j+1],i));
    }
    debug(456);
    REP(i,n)REP(j,m)debug(i,j,g[hs(i,j)]);
    REP(i,n){
      REP(j,m)dt[j] = j;
      sort(dt,dt+m,[=](int a,int b){return d[i][a] < d[i][b];});
      ll c=unique(dt,dt+m,[=](int a,int b){return d[i][a] == d[i][b];}) - dt;
      REP(j,c-1)v[fd(hs(i,dt[j]))].pb(fd(hs(i,dt[j+1])));
      debug(i);
    }

    REP(i,m){
      REP(j,n)dt[j] = j;
      sort(dt,dt+n,[=](int a,int b){return d[a][i] < d[b][i];});
      ll c=unique(dt,dt+n,[=](int a,int b){return d[a][i] == d[b][i];}) - dt;
      REP(j,c-1)v[fd(hs(dt[j],i))].pb(fd(hs(dt[j+1],i)));
    }
    debug(789);
    REP(i,n)REP(j,m)dp[hs(i,j)]=-1;
    ll a = 0;
    REP(i,n)REP(j,m)
    {
      ll t = hs(i,j);
      if(dp[t]==-1)dfs(t);
      a = max(a,dp[t]);
    }
    cout<<a<<endl;

}
