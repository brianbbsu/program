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


const ll MAXn=5e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

struct node{
  ll l,r;
  node *lc,*rc;
  ll d;
  node(ll li,ll ri,node *lci=0,node *rci=0):l(li),r(ri),lc(lci),rc(rci),d(0){};
  void ins(ll x,ll k)
  {
    if(l==r-1)d=max(d,k);
    else
    {
      if((l+r)/2>x)lc->ins(x,k);
      else rc->ins(x,k);
      d=max(lc->d,rc->d);
    }
  }
  ll qr(ll li,ll ri)
  {
    if(li>=r||ri<=l)return 0;
    else if(li<=l&&ri>=r)return d;
    else return max(lc->qr(li,ri),rc->qr(li,ri));
  }
};
node *build(ll l,ll r){
  if(l==r-1)return new node(l,r);
  else return new node(l,r,build(l,(l+r)/2),build((l+r)/2,r));
}

node *rt=0;


vector<ll> v[MAXn],vr[MAXn];

vector<ll> dt;
ll tt[MAXn];
ll dp[2][MAXn];
ll mx[3][MAXn];
bool vis[MAXn];
ll dg[MAXn];

void dfs(ll now)
{
    vis[now]=1;
    for(ll k:v[now])if(!vis[k])dfs(k);
    dt.pb(now);
}

int main()
{
    IOS();
    ll n,m;
    cin>>n>>m;
    rt=build(0,n);

    REP(i,m)
    {
      ll a,b;
      cin>>a>>b;
      v[a].pb(b);
      vr[b].pb(a);
      dg[b]++;
    }
    REP1(i,n)if(dg[i]==0)dfs(i);
    reverse(ALL(dt));
    debug(dt);
    REP(i,n)
    {
      ll t=dt[i];
      for(ll k:vr[t])dp[0][t]=max(dp[0][t],dp[0][k]+1);
      mx[0][i]=dp[0][t];
    }
    REP1(i,n-1)mx[0][i]=max(mx[0][i],mx[0][i-1]);

    for(int i=n-1;i>=0;i--)
    {
      ll t=dt[i];
      for(ll k:v[t])dp[1][t]=max(dp[1][t],dp[1][k]+1);
      mx[1][i]=dp[1][t];
    }
    for(int i=n-1;i>0;i--)mx[1][i-1]=max(mx[1][i-1],mx[1][i]);

    REP(i,n)tt[dt[i]]=i;
/*
    REP(i,n)
    {
      ll t=dt[i];
      for(ll k:vr[t])if(tt[k]!=i-1)mx[2][tt[k]]=max(mx[2][tt[k]],dp[0][k]+dp[1][t]+1);
    }
    REP1(i,n-1)mx[2][i]=max(mx[2][i],mx[2][i-1]);
*/
    ii ans=ii(INF,0);
    for(int i=n-1;i>=0;i--)
    {
      ll a=0;
      if(i!=0)a=max({a,mx[0][i-1],rt->qr(0,i)});
      if(i!=n-1)a=max(a,mx[1][i+1]);
      ans=min(ans,ii(a,dt[i]));
      debug(ans,ii(a,dt[i]));
      ll t=dt[i];
      for(ll k:vr[t])if(tt[k]!=i-1)rt->ins(tt[k],dp[0][k]+dp[1][t]+1);
    }
    cout<<ans.Y<<" "<<ans.X<<endl;

}
