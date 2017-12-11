//{
#include<bits/stdc++.h>
using namespace std;
typedef int ll;
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


const ll MAXn=5e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e9);

vector<ll> v[MAXn],vr[MAXn],v3[MAXn],tp;
ll d[MAXn],g[MAXn],vis[MAXn],tt[MAXn],dp[MAXn],fg[MAXn];

void dfs1(ll now)
{
  vis[now]=1;
  for(ll k:v[now])if(!vis[k])dfs1(k);
  tp.pb(now);
}

void dfs2(ll now,ll gi)
{
  vis[now]=1;g[now]=gi;
  for(ll k:vr[now])if(!vis[k])dfs2(k,gi);
}

ll it(ll now)
{
  if(dp[now]!=-1)return dp[now];
  ll mx;
  if(fg[now])mx=tt[now];
  else mx=-INF;
  for(ll k:v3[now])mx=max(mx,it(k)+tt[now]);
  return dp[now]=mx;
}

int main()
{
    IOS();
    ll n,m;
    cin>>n>>m;
    REP(i,m)
    {
      ll a,b;
      cin>>a>>b;
      v[a].pb(b);
      vr[b].pb(a);
    }
    REP1(i,n)cin>>d[i];

    memset(vis,0,sizeof(ll)*(n+1));
    REP1(i,n)if(!vis[i])dfs1(i);
    reverse(ALL(tp));

    ll nit=0;
    memset(vis,0,sizeof(ll)*(n+1));
    REP(i,n)if(!vis[tp[i]])dfs2(tp[i],nit++);

    REP1(i,n)for(ll k:v[i])if(g[i]!=g[k])v3[g[i]].pb(g[k]);
    debug(nit,tp);
    REP1(i,n)debug(i,g[i]);
    REP(i,nit)debug(i,v3[i]);

    ll s,p;
    cin>>s>>p;
    REP(i,p)
    {
      ll t;
      cin>>t;
      fg[g[t]]=1;
    }
    memset(dp,-1,sizeof(ll)*(nit+1));
    REP1(i,n)tt[g[i]]+=d[i];
    cout<<it(g[s])<<endl;
}
