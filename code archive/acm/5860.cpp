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


const ll MAXn=55,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e9);

ll dp[MAXn][MAXn][(1<<10)];

ll id[MAXn],h[MAXn],ct[1005],d[MAXn];
vector<ii> v[MAXn],v2[MAXn];
ll n,m;

bool read()
{
  cin>>n>>m;
  if(!(n||m))return 0;
  REP(i,n)REP(j,n)REP(k,(1<<10))dp[i][j][k]=INF;
  dp[0][0][1]=0;
  REP(i,n)v[i].clear(),v2[i].clear();
  FILL(ct,0);
  for(int i=1;i<n-1;i++)cin>>d[i]>>h[i];
  d[0]=d[n-1]=0;
  h[0]=0;h[n-1]=1000;
  REP(i,n)id[i]=ct[h[i]]++;
  REP(i,m)
  {
    ll a,b,c;
    cin>>a>>b>>c;
    a--;b--;
    if(h[a]<=h[b])v[a].pb(ii(b,c));
    if(h[a]>=h[b])v2[b].pb(ii(a,c));
  }
  REP(i,n)debug(i,v[i],v2[i]);
  return 1;
}

struct tg{
  ll a,b,mk,d;
  tg(ll ai,ll bi,ll mki,ll di):a(ai),b(bi),mk(mki),d(di){}
};
bool operator < (const tg &a,const tg &b){return a.d>b.d;}

priority_queue<tg> pq;

void cal(ll a,ll b,ll oh,ll &mk,ll &di)
{
  debug(a,b,oh,mk,di);
  if(oh!=min(h[a],h[b]))mk=0;
  if(h[a]==h[b]){
    if(a!=b)di+=d[a];
    mk|=(1<<(id[a]))|(1<<(id[b]));
  }
  else if(h[a]>h[b]){
    di+=d[a];
    mk|=(1<<(id[b]));
  }
  else{
    if(!(mk&(1<<id[a])))di+=d[a];
    mk|=(1<<(id[a]));
  }
  debug(a,b,oh,mk,di);
}

void solve()
{
  while(SZ(pq))pq.pop();
  pq.push(tg(0,0,1,0));
  while(SZ(pq))
  {
    tg f=pq.top();
    pq.pop();
    if(dp[f.a][f.b][f.mk]!=f.d)continue;
    if(h[f.a]<=h[f.b])
    {
      for(ii &k:v[f.a])
      {
        ll a=k.X,b=f.b,mk=f.mk,tmpd=f.d+k.Y;
        cal(a,b,h[f.a],mk,tmpd);
        if(tmpd<dp[a][b][mk])
        {
          dp[a][b][mk]=tmpd;
          pq.push(tg(a,b,mk,tmpd));
        }
      }
    }
    else
    {
      for(ii &k:v2[f.b])
      {
        ll a=f.a,b=k.X,mk=f.mk,tmpd=f.d+k.Y;
        cal(b,a,h[f.b],mk,tmpd);
        if(tmpd<dp[a][b][mk])
        {
          dp[a][b][mk]=tmpd;
          pq.push(tg(a,b,mk,tmpd));
        }
      }
    }
  }
}

int main()
{
    IOS();
    while(read())
    {
      solve();
      ll t=dp[n-1][n-1][1];//*min_element(dp[n-1][n-1],dp[n-1][n-1]+(1<<10));
      cout<<(t==INF?-1:t)<<endl;
    }
}
