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


const ll MAXn=1e6+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);


ll g[MAXn];
inline ll f(ll a){return g[a]=(g[a]==a?a:f(g[a]));}
inline void mg(ll a,ll b)
{
  a=f(a),b=f(b);
  debug(a,b);
  g[max(a,b)]=min(a,b);
}

ll *d[MAXn],now[MAXn],y[MAXn],dt[MAXn],ct[MAXn];
vector<ll> ans;
void dfs(ll t)
{
  if(t<0)ans.pb(-t);
  else
  {
    REP(i,ct[t])dfs(d[t][i]);
  }
}

int main()
{
    IOS();
    ll n,m;
    cin>>n>>m;
    REP1(i,n)now[i]=-i,g[i]=i;
    REP(i,m)
    {
      dt[i]=i;
      cin>>y[i]>>ct[i];
      d[i]=new ll[ct[i]];
      REP(j,ct[i])cin>>d[i][j];
    }
    sort(dt,dt+m,[](int a,int b){return y[a]<y[b];});
    REP(i,m)
    {
      ll t=dt[i];
      REP(j,ct[t])d[t][j]=f(d[t][j]);
      pary(g+1,g+n+1);
      pary(d[t],d[t]+ct[t]);
      sort(d[t],d[t]+ct[t]);
      REP1(j,ct[t]-1)
      {
        ll tmp=d[t][j];
        mg(d[t][0],tmp);
        d[t][j]=now[tmp];
        now[tmp]=t;
      }
      ll tmp=d[t][0];
      d[t][0]=now[tmp];
      now[tmp]=t;
    }
    REP1(i,n)if(g[i]==i)dfs(now[i]);
    debug(ans);
    assert(SZ(ans)==n);
    REP(i,n)cout<<ans[i]<<" \n"[i==n-1];
}
