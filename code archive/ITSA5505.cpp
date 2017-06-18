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


const ll MAXn=1e2+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

vector<ii> v[MAXn];
map<string,ll> mp;
ll n;
vector<ll> dt;
bool vis[MAXn];

ll dg[MAXn];
ll dp[MAXn];

void dfs(ll now)
{
  vis[now]=1;
  for(ii &k:v[now])if(!vis[k.X])dfs(k.X);
  dt.pb(now);
}

int main()
{
    IOS();
    ll T;
    cin>>T;
    while(T--)
    {
        REP(i,100)v[i].clear();
        FILL(vis,0);
        FILL(dg,0);
        dt.clear();
        mp.clear();
        n=0;
        string a,b;
        cin>>a;
        ll l;
        while(cin>>a)
        {
          if(a=="end")break;

          cin>>b>>l;
          if(!mp.count(a))mp[a]=n++;
          if(!mp.count(b))mp[b]=n++;
          ll p=mp[a];
          ll q=mp[b];
          v[p].pb(ii(q,l));
          dg[q]++;
        }
        REP(i,n)if(dg[i]==0&&!vis[i])dfs(i);
        reverse(ALL(dt));
        FILL(dp,0);
        debug(dt,n);
        REP(i,n)
        {
          ll t=dt[i];
          for(ii &k:v[t])dp[k.X]=max(dp[k.X],dp[t]+k.Y);
        }
        cout<<*max_element(dp,dp+n)<<endl;

    }
}
