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
const ll MOD=1000000000;
const ll INF=ll(1e15);


#ifndef brian
#include "lib1273.h"
#endif

vector<ii> d;
vector<ll> v[MAXn];
ll nit;
queue<ii> q,tmpq;
ll sz[MAXn],dp[MAXn],tt[MAXn];

void dfs(ll now,ll f)
{
  for(ll k:v[now])
  {
    if(k==f)continue;
    dfs(k,now);
    dp[now]=(dp[now]+sz[k]*tt[now]+sz[now]*(tt[k]+sz[k]))%MOD;
    tt[now]=(tt[now]+tt[k]+sz[k])%MOD;
    sz[now]+=sz[k];
  }
}

int cal(ll n,int *x,int *y)
{
  nit=-1;
  d.clear();
  REP(i,n)v[i].clear();
  REP(i,n)sz[i]=1,tt[i]=0,dp[i]=0;
  while(SZ(q))q.pop();

  REP(i,n)d.pb(ii(x[i],y[i]));
  sort(ALL(d));
  debug(d);

  ll it=0,lt,t=d[0].X;
  while(it<n)
  {
    while(SZ(tmpq))tmpq.pop();
    lt=-2;

    while(it<n&&d[it].X==t)
    {
      ll k;
      if(d[it].Y==lt+1)k=nit,sz[k]++;
      else k=++nit;
      lt=d[it].Y;
      tmpq.push(ii(d[it].Y,k));
      while(SZ(q)&&q.front().X<d[it].Y)q.pop();
      if(SZ(q)&&q.front().X==d[it].Y)v[q.front().Y].pb(k),v[k].pb(q.front().Y);
      debug(d[it],k);
      it++;
    }
    q.swap(tmpq);
    t++;
  }
  REP(i,nit+1)sort(ALL(v[i])),v[i].resize(unique(ALL(v[i]))-v[i].begin());

  //REP(i,nit+1)debug(i,v[i]);

  pary(sz,sz+nit+1);
  dfs(0,-1);

  pary(dp,dp+nit+1);
  ll rt=0;
  REP(i,nit+1)rt=(rt+dp[i])%MOD;
  return rt;

}

vector<ll> uni;
void mak_uni(ll n,int *a)
{
  uni.clear();
  REP(i,n)uni.pb(a[i]);
  sort(ALL(uni));
  uni.resize(unique(ALL(uni))-uni.begin());
  REP(i,n)a[i]=lower_bound(ALL(uni),a[i])-uni.begin();
}

int DistanceSum(int n, int *x, int *y)
{
  mak_uni(n,x);
  mak_uni(n,y);
  ll a=cal(n,x,y),b=cal(n,y,x);
  debug(a,b);
  return (a+b)%MOD;
}


#ifdef brian
int main()
{
    IOS();
    ll n;
    int x[MAXn],y[MAXn];
    cin>>n;
    REP(i,n)cin>>x[i]>>y[i];
    cout<<DistanceSum(n,x,y)<<endl;
}
#endif
