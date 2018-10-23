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


ii d[MAXn];
vector<ll> unix,uniy;

vector<ll> v[2*MAXn];
ll vis[2*MAXn];


ll pw[MAXn];
ll bl=0,tt=0;
vector<ll> dt;

void dfs(ll now,ll f,ll g)
{
  vis[now]=1;
  tt++;
  for(ll k:v[now])
  {
    if(vis[k]==g&&f!=k)bl=1;
    if(vis[k])continue;
    dfs(k,now,g);
  }
}

int main()
{
    IOS();

    pw[0]=1;
    REP1(i,MAXn-1)pw[i]=(pw[i-1]*2)%MOD;

    ll n;
    cin>>n;
    REP(i,n)cin>>d[i].X>>d[i].Y;
    REP(i,n)unix.pb(d[i].X),uniy.pb(d[i].Y);

    sort(ALL(unix));
    unix.resize(unique(ALL(unix))-unix.begin());
    REP(i,n)d[i].X=lower_bound(ALL(unix),d[i].X)-unix.begin();

    sort(ALL(uniy));
    uniy.resize(unique(ALL(uniy))-uniy.begin());
    REP(i,n)d[i].Y=lower_bound(ALL(uniy),d[i].Y)-uniy.begin();
    REP(i,n)
    {
      ll a=d[i].X,b=d[i].Y+MAXn;
      v[a].pb(b);
      v[b].pb(a);
      debug(a,b);
    }
    ll it=0;
    REP(i,n)
    {
      if(!vis[d[i].X])
      {
        tt=0,bl=0;
        dfs(d[i].X,-1,++it);
        if(bl)dt.pb(pw[tt]);
        else dt.pb((pw[tt]-1+MOD)%MOD);
      }
    }
    ll ans=1;
    debug(dt);
    for(ll tmp:dt)ans=(ans*tmp)%MOD;
    cout<<ans<<endl;

}
