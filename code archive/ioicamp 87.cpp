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


const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);


vector<ll> v[MAXn];
ll dp[MAXn],st[MAXn][MAXlg],l[MAXn],r[MAXn],it;
void dfs(ll now,ll f)
{
  st[now][0]=f;
  l[now] = ++it;
  for(ll k:v[now])if(k!=f)
  {
    dp[k]=dp[now]+1;
    dfs(k,now);
  }
  r[now] = it;
}

ll lca(ll a,ll b)
{
  if(dp[a]<dp[b])swap(a,b);
  for(int i=MAXlg-1;i>=0;i--)if(dp[st[a][i]]>=dp[b])a=st[a][i];
  if(a==b)return a;
  for(int i=MAXlg-1;i>=0;i--)if(st[a][i]!=st[b][i])a=st[a][i],b=st[b][i];
  return st[a][0];
}

inline bool isa(ll a,ll b){return l[b]<=l[a]&&r[b]>=r[a];}

inline bool in(ll a,ll b,ll c)// is b between a,c (dp[a]>=dp[c])
{
  return isa(a,b) && isa(b,c);
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
      REP1(i,n)v[i].clear();
      REP(i,n-1)
      {
        ll a,b;
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
      }
      dp[1]=0;dp[0]=-1;
      it = 0;
      dfs(1,0);
      REP1(i,MAXlg-1)REP1(j,n)st[j][i]=st[st[j][i-1]][i-1];
      while(q--)
      {
        ll a,b,c,d,e,f;
        cin>>a>>b>>d>>e;
        c=lca(a,b);
        f=lca(d,e);
        if(in(a,f,c)||in(b,f,c)||in(d,c,f)||in(e,c,f))cout<<"tsan"<<endl;
        else cout<<"hao"<<endl;
      }
    }
}
