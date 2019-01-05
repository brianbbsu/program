//#pragma comment(linker , "/STACK:102400000 , 102400000")
//{
//#undef brian
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


const ll MAXn=2e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);


vector<ll> v[MAXn];
ll d[MAXn],dp[2][MAXn];
bool ring[MAXn],vis[MAXn];

vector<ll> dt;


ll predfs(ll now,ll f)
{
  vis[now]=1;
  //debug(now,f);
  for(ll k:v[now])
  {
    debug(k);
    if(k==f)continue;

    if(vis[k]){dt.pb(now);ring[now]=1;return k;}
    ll t=predfs(k,now);
    //debug(t);
    if(t==-2)return -2;
    if(t!=-1)
    {
      ring[now]=1;
      dt.pb(now);
      if(t==now)return -2;
      else return t;
    }
  }
  return -1;
}

void dfs(ll now,ll f)
{
  dp[0][now]=0;
  dp[1][now]=d[now];
  for(ll k:v[now])
  {
    if(ring[k]||k==f)continue;
    dfs(k,now);
    if(dp[1][k]>0)dp[1][now]+=dp[1][k];
    dp[0][now]=max({dp[0][now],dp[1][k],dp[0][k]});
  }
}

int main()
{
    IOS();
    ll n;
    while(cin>>n&&n)
    {
      REP(i,n)v[i].clear();
      REP(i,n)cin>>d[i];
      dt.clear();
      REP(i,n)
      {
        ll a,b;
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
        //assert(a>=0&&a<n&&b>=0&&b<n);
      }

      FILL(ring,0);
      FILL(vis,0);

      predfs(0,-1);
      pary(ring,ring+n);
      debug(dt);
      FILL(dp,0);
      REP(i,n)if(ring[i])dfs(i,-1);

      ll mx=0,t=0,s=0;
      for(ll k:dt)
      {
        t+=dp[1][k];
        s+=dp[1][k];
        if(t<0)t=0;
        else mx=max(mx,t);
        mx=max(mx,dp[0][k]);
      }

      ll mn=0;
      t=0;

      for(ll k:dt)
      {
        t+=dp[1][k];

        if(t>0)t=0;
        else mn=min(mn,t);
      }

      cout<<max(mx,s-mn)<<endl;
    }
}
