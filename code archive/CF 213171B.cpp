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
const ll INF=ll(1e17);

vector<ii> v[MAXn];
ii d[MAXn];
ll dis[MAXn];

priority_queue<ii,vector<ii>,greater<ii> > pq;

ll gd(ll x,ll k)
{
  ll tt=d[x].X+d[x].Y;
  if(k%tt<d[x].X)return k;
  else return (k/tt+1)*tt;
}

void dij(ll n,ll s)
{
  REP(i,n)dis[i]=INF;
  dis[s]=0;
  pq.push(ii(0,s));
  while(SZ(pq))
  {
    while(SZ(pq)&&gd(pq.top().Y,dis[pq.top().Y])<pq.top().X)pq.pop();
    if(!SZ(pq))break;
    debug(pq.top());
    ll t=pq.top().Y,k=pq.top().X;
    pq.pop();
    for(ii &tmp:v[t])
    {
      debug(tmp);
      if(dis[tmp.X]>k+tmp.Y)
      {
        dis[tmp.X]=k+tmp.Y;
        pq.push(ii(gd(tmp.X,dis[tmp.X]),tmp.X));
      }
    }
  }
}

int main()
{
    IOS();
    ll n,m;
    cin>>n>>m;
    REP(i,n)cin>>d[i].X>>d[i].Y;
    //{
    //  while(cin>>n>>m)
    //  debug(gd(n,m));
    //}
    REP(i,m)
    {
      ll a,b,c;
      cin>>a>>b>>c;
      a--;b--;
      v[a].pb(ii(b,c));
      v[b].pb(ii(a,c));
    }
    REP(i,n)debug(v[i]);
    ll s;
    cin>>s;
    s--;
    dij(n,s);
    REP(i,n)cout<<dis[i]<<" \n"[i==n-1];
}
