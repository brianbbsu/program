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


const ll MAXn=3e3+5,MAXq=4e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);


ll ans[MAXn];

struct tg{
  ll s,t,k,id;
};

vector<tg> qr,dt[MAXn];

vector<ll> v[MAXn];
bool vis[MAXn];


vector<ll> his;
ll h[MAXn],rt[MAXn];

void predfs(ll now)
{
  vis[now]=1;
  rt[now]=h[now];
  for(ll k:v[now])
  {
    if(!vis[k])
    {
      h[k]=h[now]+1;
      predfs(k);
    }
    rt[now]=min(rt[now],rt[k]);
  }
}

void dfs(ll now)
{
  vis[now]=1;
  his.pb(now);
  for(auto &q:dt[now])
  {
    if(SZ(his)>=q.k)ans[q.id]=his[q.k-1];
  }
  for(ll k:v[now])
  {
    if(!vis[k])dfs(k);
    
  }
  his.pop_back();
}

int main()
{
    IOS();
    ll n,m,q;
    cin>>n>>m>>q;
    REP(i,m)
    {
      ll a,b;
      cin>>a>>b;
      v[a].pb(b);
    }

    FILL(ans,-1);
    REP(i,q)
    {
      ll a,b,k;
      cin>>a>>b>>k;
      qr.pb((tg){a,b,k,i});
    }
    sort(ALL(qr),[](const tg &a,const tg &b){return a.s<b.s;});

    REP1(i,n)sort(ALL(v[i]));

    ll it=0;

    REP1(i,n)
    {
      FILL(vis,0);
      h[i]=0;
      predfs(i);
      FILL(vis,0);
      REP1(j,n)dt[j].clear();
      while(it<SZ(qr)&&qr[it].s==i)
      {
        dt[qr[it].t].pb(qr[it]);
        it++;
      }
      dfs(i);
    }
    REP(i,q)cout<<ans[i]<<endl;
}
