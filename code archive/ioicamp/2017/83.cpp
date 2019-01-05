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


const ll MAXn=1e4+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

vector<ll> v[MAXn];
vector<ii> st[MAXn];
ll dis[MAXn][MAXlg],p[MAXn][MAXlg],vis[MAXn],dp[MAXn],sz[MAXn],clr[MAXn];
ll mn,id;

void szdfs(int now,int f,int ttsz,int start,int stlv,int stdis)
{
  dis[now][stlv] = stdis;
  p[now][stlv] = start;
  sz[now] = 1;
  ll mx = 0;
  for(ll k:v[now])if(k!=f&&!vis[k])
  {
    szdfs(k,now,ttsz,start,stlv,stdis+1);
    sz[now]+=sz[k];
    mx = max(mx,sz[k]);
  }
  mx=max(mx,ttsz - sz[now]);
  if(mx<mn)mn=mx,id = now;
}

void build(int now,int lv,int ttsz)
{
  dp[now] = lv;
  vis[now] = 1;
  p[now][lv] = now;dis[now][lv] = 0;
  for(ll k:v[now])if(!vis[k])
  {
    mn = MAXn;
    szdfs(k,now,(sz[k]<sz[now]?sz[k]:ttsz-sz[now]),now,lv,1);
    build(id,lv+1,sz[k]);
  }
}

void ins(ll now,ll k,ll t)
{
  for(int i=dp[now];i>=0;i--)
  {
    if(dis[now][i]>k)continue;
    ll x = k-dis[now][i];
    auto &dt = st[p[now][i]];
    while(SZ(dt)&&dt.back().X<=x)dt.pop_back();
    dt.pb(ii(x,t));
  }
}

ll qr(ll now)
{
  ll mx = 0;
  for(int i=dp[now];i>=0;i--)
  {
    debug(now,i,p[now][i],dis[now][i]);
    auto tmp = lower_bound(st[p[now][i]].rbegin(),st[p[now][i]].rend(),ii(dis[now][i],-1));
    if(tmp!=st[p[now][i]].rend())mx=max(mx,tmp->Y);
  }
  return clr[mx];
}
int main()
{
    IOS();
    ll T;
    cin>>T;
    while(T--)
    {
      ll n,q;
      cin>>n>>q;
      REP(i,n)v[i].clear(),st[i].clear();
      REP(i,n-1)
      {
        ll a,b;
        cin>>a>>b;
        a--;b--;
        v[a].pb(b);
        v[b].pb(a);
      }
      memset(vis,0,sizeof(ll)*n);
      mn = MAXn;
      szdfs(0,-1,n,0,0,0);
      build(id,0,n);
      //REP(i,n)REP(j,5)debug(i,dp[i],j,p[i][j],dis[i][j]);

      clr[0]=1;
      REP1(i,q)
      {
        ll tp,x,k;
        cin>>tp>>x;
        if(tp==2)cout<<qr(x-1)<<endl;
        else
        {
          cin>>k>>clr[i];
          ins(x-1,k,i);
        }
        REP(i,n)debug(i,st[i]);
      }
    }
}
