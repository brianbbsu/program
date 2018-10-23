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


ll g[MAXn],sz[MAXn],ct[MAXn][5],lim[5];
string nm[MAXn];
map<string,ll> mp;

ll fd(ll x){return g[x] = (g[x]==x?x:fd(g[x]));}

int main()
{
    IOS();
    ll n,m,a,b;
    cin>>n>>m>>a>>b;
    REP(i,3)cin>>lim[i];
    REP(i,n)g[i] = i,sz[i] = 1;
    REP(i,n)
    {
      cin>>nm[i];
      ll t;
      cin>>t;
      ct[i][t-1] = 1;
      mp[nm[i]] = i;
    }
    REP(i,m)
    {
      string s1,s2;
      cin>>s1>>s2;
      ll p=mp[s1],q=mp[s2];
      p = fd(p);q = fd(q);
      if(p==q)continue;
      bool fg=1;
      if(sz[p] + sz[q] > b)fg=0;
      REP(j,3)if(ct[p][j] + ct[q][j] > lim[j])fg=0;
      if(fg)
      {
        sz[p] += sz[q];
        REP(j,3)ct[p][j] += ct[q][j];
        g[q] = p;
      }
    }
    ll mx=-1;
    REP(i,n)if(g[i]==i&&sz[i]>=a)mx=max(mx,sz[i]);
    vector<string> ans;
    REP(i,n)if(sz[fd(i)]==mx)ans.pb(nm[i]);
    sort(ALL(ans));
    REP(i,SZ(ans))cout<<ans[i]<<endl;
    if(!SZ(ans))cout<<"no groups"<<endl;
}
