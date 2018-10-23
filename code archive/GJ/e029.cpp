//{
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<string>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<sstream>
#include<cmath>
#include<queue>

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

priority_queue<ii,vector<ii>,greater<ii> > pq;

ll dg[MAXn];
vector<ll> v[MAXn];

ll id[MAXn],ct[MAXn];

ll cal(ll n)
{
  REP(i,n)ct[i]=0;
  REP(i,n)
  {
    REP(j,SZ(v[i]))
    {
      ll t=v[i][j];
      if(id[i]<id[t])ct[i]++;
    }
  }
  ll mx=0;
  REP(i,n)mx=max(mx,ct[i]);
  return mx;
}

bool vis[MAXn];

int main()
{
    IOS();
    ll T;
    cin>>T;
    ll n,m;
    while(T--&&cin>>n>>m)
    {
      REP(i,n)v[i].clear(),dg[i]=0,id[i]=i,vis[i]=0;
      REP(i,m)
      {
        ll a,b;
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
        dg[a]++;dg[b]++;
      }
      ll ans1=cal(n);
      debug(ans1);
      REP(i,n)pq.push(ii(dg[i],i));
      ll it=0;
      while(SZ(pq))
      {
        ii tmp=pq.top();
        pq.pop();
        if(dg[tmp.Y]!=tmp.X)continue;
        vis[tmp.Y]=1;
        debug(tmp);
        id[tmp.Y]=it++;
        REP(i,SZ(v[tmp.Y]))
        {
          ll t=v[tmp.Y][i];
          if(vis[t])continue;
          dg[t]--;
          pq.push(ii(dg[t],t));
        }
      }
      ll ans2=cal(n);
      pary(id,id+n);
      cout<<ans1<<" "<<ans2<<endl;
    }
}
