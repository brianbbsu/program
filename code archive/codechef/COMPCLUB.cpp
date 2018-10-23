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

map<ii,ll> mp[MAXn];
vector<ll> v[MAXn];
ll ans[MAXn],c[MAXn],d[MAXn];
vector<ll> tmpv;

void dfs(ll now)
{
  debug(now);
  mp[now].clear();
  for(ll k:v[now])
  {
    dfs(k);
  }
  tmpv.clear();
  for(ll k:v[now])tmpv.pb(k);
  sort(ALL(tmpv),[](ll a,ll b){return SZ(mp[a])>SZ(mp[b]);});
  debug(tmpv);
  for(ll k:tmpv)
  {
    if(!SZ(mp[now])){mp[now].swap(mp[k]);continue;}
    for(auto &tmp:mp[k])
    {
      auto it=mp[now].insert(tmp);
      if(!it.Y)it.X->Y=(it.X->Y+tmp.Y)%MOD;
    }
    mp[k].clear();
  }
  auto it=mp[now].find(ii(c[now],d[now]-1));
  ll t;
  if(it!=mp[now].end())t=it->Y;
  else if(d[now]==0)t=1;
  else t=0;
  auto it2=mp[now].insert(make_pair(ii(c[now],d[now]),t));
  if(!it2.Y)it2.X->Y=(it2.X->Y+t)%MOD;
  ans[now]=t;
}

int main()
{
    IOS();
    ll T,n,x;
    cin>>T;
    while(T--&&cin>>n>>x)
    {
      REP(i,n)mp[i].clear(),v[i].clear();
      REP1(i,n-1)
      {
        ll t;
        cin>>t;
        v[t].pb(i);
      }
      REP(i,n)cin>>c[i];
      REP(i,n)cin>>d[i];
      dfs(0);
      REP(i,n)cout<<ans[i]<<endl;
    }
}
