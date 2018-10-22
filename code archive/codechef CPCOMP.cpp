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


const ll MAXn=2e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

// prime
vector<ll> pm;
ll ispm[MAXn];

void build_pm()
{
  for(int i = 2;i<MAXn;i++)
  {
    if(!ispm[i])ispm[i] = i,pm.pb(i);
    for(int j = 0;pm[j] * i < MAXn;j++)
    {
      ispm[pm[j] * i] = pm[j];
      if(i % pm[j] == 0)break;
    }
  }
  debug(SZ(pm));
}

// DSU
ll g[MAXn],sz[MAXn];
ll fd(ll a){return g[a] = (g[a] == a?a:fd(g[a]));}
void mg(ll a,ll b){
  a = fd(a),b = fd(b);
  sz[b] += sz[a];
  g[a] = b;
}

vector<ll> d;
vector<ll> v[MAXn];
vector<ll> fact[MAXn];



bool u[MAXn];
map<ll,ll> ct;

const ll MAXL = 5;
ll L;

set<ll> st[(1<<MAXL)];
ll msk[MAXn];
vector<ii> cts;


void dfs(ll x)
{
  debug(x);
  for(ll tmp:fact[x])u[tmp] = 1;
  vector<ll> ok;
  REP(I,(1<<L))if(!(I & msk[x]))for(ll y:st[I])
  {
    bool fg = 1;
    for(ll tmp:fact[y])if(u[tmp]){fg = 0;break;}
    if(fg)ok.pb(y);
  }
  for(ll tmp:fact[x])u[tmp] = 0;
  for(ll k:ok)st[msk[k]].erase(k),mg(x,k);
  for(ll k:ok)dfs(k);
  debug(x);
}


int main()
{
    IOS();
    build_pm();

    ll n;
    cin>>n;
    REP(i,n)
    {
      ll tmp;
      cin>>tmp;
      vector<ll> tmpfact;
      while(tmp != 1)
      {
        tmpfact.pb(ispm[tmp]);
        tmp /= ispm[tmp];
      }
      tmpfact.resize(unique(ALL(tmpfact)) - tmpfact.begin());
      for(ll k:tmpfact)tmp *= k;
      ct[tmp] ++;
      if(ct[tmp] == 1)fact[tmp] = tmpfact;
    }
    for(ii tmp:ct)d.pb(tmp.X);

    for(ll x:d)for(ll k:fact[x])v[k].pb(x);
    for(ll x:d)g[x] = x, sz[x] = 1;

    REP(i,MAXn)if(SZ(v[i]))cts.pb(ii(SZ(v[i]),i));
    sort(ALL(cts),greater<ii>());
    L = min(ll(SZ(cts)),MAXL);

    for(ll x:d)for(ll c:fact[x])REP(i,L)if(c == cts[i].Y)msk[x] += (1<<i);
    for(ll x:d)st[msk[x]].insert(x);

    for(ll k:d)
    {
      auto it = st[msk[k]].find(k);
      if(it != st[msk[k]].end())
      {
        ll x = *it;
        st[msk[k]].erase(it);
        dfs(x);
      }
    }
    ll tt = 0;
    for(ii tmp:ct)if(g[tmp.X] == tmp.X)
    {
      if(sz[tmp.X] == 1)tt += ct[tmp.X];
      else tt += 1;
    }
    cout<<tt<<endl;
}
