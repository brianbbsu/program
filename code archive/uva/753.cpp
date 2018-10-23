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


const ll MAXn=4e2+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

map<string,ll> mp;
ll tpp[MAXn],tpd[MAXn],ok[MAXn][MAXn];
vector<ll> pv[MAXn],v[MAXn];
ll vy[MAXn],py[MAXn],vis[MAXn];

void dfs(ll now)
{
  vis[now]=1;
  for(ll k:pv[now])if(!vis[k])dfs(k);
}

bool dfs2(ll now)
{
  for(ll k:v[now])
  {
    if(!vy[k])
    {
      vy[k]=1;
      if(py[k]==-1||dfs2(py[k]))
      {
        py[k]=now;
        return 1;
      }
    }
  }
  return 0;
}

void add(string c)
{
  if(mp.count(c))return;
  ll t=SZ(mp);
  mp[c]=t;
}

int main()
{
    IOS();
    ll T;
    cin>>T;
    while(T--)
    {
      mp.clear();
      ll n;cin>>n;
      REP(i,n)
      {
        string s;
        cin>>s;
        add(s);
        tpp[i]=mp[s];
      }
      ll m;cin>>m;
      REP(i,m)
      {
        string s;
        cin>>s>>s;
        add(s);
        tpd[i]=mp[s];
      }
      REP(i,MAXn)pv[i].clear();
      REP(i,MAXn)v[i].clear();
      ll k;
      cin>>k;
      REP(i,k)
      {
        string a,b;
        cin>>a>>b;
        if(a==b)continue;
        add(a);add(b);
        pv[mp[a]].pb(mp[b]);
      }
      REP(i,SZ(mp))
      {
        FILL(vis,0);
        dfs(i);
        REP(j,SZ(mp))ok[i][j]=vis[j];
      }
      ll tt=0;
      REP(i,m)REP(j,n)
      {
        if(ok[tpd[i]][tpp[j]])v[i].pb(j);
      }
      FILL(py,-1);
      REP(i,m)
      {
        FILL(vy,0);
        if(dfs2(i))tt++;
      }
      REP(i,n)debug(i,py[i]);
      cout<<m-tt<<endl;
      if(T)cout<<endl;
    }
}
