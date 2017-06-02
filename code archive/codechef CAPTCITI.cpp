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
const ll INF=ll(5e18);


ll dp[MAXn][2];
ll p[MAXn],c[MAXn];
vector<ll> v[MAXn];
vector<ll> tmp;

void dfs(ll now,ll f)
{
  dp[now][0]=p[now];
  for(ll k:v[now])
  {
    if(k==f)continue;
    dfs(k,now);
    dp[now][0]+=dp[k][1];
  }
  dp[now][1]=dp[now][0];
  tmp.clear();
  for(ll k:v[now])if(k!=f)tmp.pb(k);
  sort(ALL(tmp),[](int a,int b){return dp[a][0]-dp[a][1]<dp[b][0]-dp[b][1];});
  ll t=0;
  REP(i,SZ(tmp))
  {
    if(i<c[now]-1)t+=dp[tmp[i]][0];
    else t+=dp[tmp[i]][1];
  }
  dp[now][1]=min(dp[now][1],t);
  if(SZ(tmp)>=c[now])t+=dp[tmp[c[now]-1]][0]-dp[tmp[c[now]-1]][1],dp[now][0]=min(dp[now][0],t);

}

ll T,n;
int main()
{
    IOS();
    cin>>T;
    while(T--&&cin>>n)
    {
      REP(i,n)v[i].clear();
      REP(i,n-1)
      {
        ll a,b;
        cin>>a>>b;
        a--;b--;
        v[a].pb(b);
        v[b].pb(a);
      }
      REP(i,n)cin>>p[i];
      REP(i,n)cin>>c[i];
      dfs(0,-1);
      cout<<dp[0][0]<<endl;
    }
}
