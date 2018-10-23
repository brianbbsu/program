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

ll d[MAXn];
vector<ll> dt[MAXn];
ll p[MAXn];

vector<ll> v[MAXn];
ll dp[MAXn];

void build(ll now,ll l,ll r)
{
  vector<ll> tmp;
  dp[now]=0;

  for(ll it=l+1;it<r;)
  {
    if(p[it]==-1)
    {
      REP(i,SZ(tmp))
      {
        ll t=max(i+1,SZ(tmp)-i);
        dp[now]=max(dp[now],tmp[i]+t);
      }
      tmp.clear();
      it++;
    }
    else
    {
      build(d[it],it,p[it]);
      tmp.pb(dp[d[it]]);
      it=p[it]+1;
    }
  }
  REP(i,SZ(tmp))
  {
    ll t=max(i+1,SZ(tmp)-i);
    dp[now]=max(dp[now],tmp[i]+t);
  }
}


void dfs(ll now)
{
  dp[now]=0;
  REP(i,SZ(v[now]))
  {
    dfs(v[now][i]);
    ll tmp=max(i+1,SZ(v[now])-i);
    dp[now]=max(dp[now],tmp+dp[v[now][i]]);
  }
}

int main()
{
    IOS();
    ll n,m;
    cin>>n>>m;
    ll tmp=0;
    REP(i,n)cin>>d[i];
    REP(i,n)dt[d[i]].pb(i);
    FILL(p,-1);
    REP1(i,m)
    {
      if(!SZ(dt[i]))tmp++;
      else p[dt[i][0]]=dt[i].back();
    }
    build(0,-1,n);
    
    cout<<dp[0]+tmp<<endl;
    REP(i,m+1)debug(i,v[i],dp[i]);

}
