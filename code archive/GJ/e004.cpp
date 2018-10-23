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


const ll MAXn=5e3+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

#define h(a,b) ((a)*30+(b))

vector<ii> v[MAXn];

bool vis[MAXn];

priority_queue<ii,vector<ii>,greater<ii> > pq;
ll dt[MAXn];

map<int,int> mp;

int main()
{
    IOS();
    ll n,m;
    cin>>n>>m;
    REP(i,n)
    {
      ll id,k,t;
      cin>>id>>k;
      cin>>t;
      for(int j=2;j<=k;j++)
      {
        cin>>t;
        v[h(id, j )].pb(ii(h(id,j-1),t+1));
        v[h(id,j-1)].pb(ii(h(id, j ),t+1));
      }
    }
    REP(i,m)
    {
      ll a,b,c,d;
      cin>>a>>b>>c>>d;
      vector<ii> tmp=v[h(a,b)];
      tmp.insert(tmp.end(),ALL(v[h(c,d)]));
      debug(v[h(a,b)],v[h(c,d)],tmp);
      v[h(a,b)]=v[h(c,d)]=tmp;
      mp[h(a,b)]=h(c,d);
      mp[h(c,d)]=h(a,b);
    }
    REP(T,5)
    {
      FILL(dt,-1);
      while(SZ(pq))pq.pop();
      ll a,b,c,d;
      cin>>a>>b>>a>>b>>c>>d;
      debug(h(a,b),h(c,d));
      pq.push(ii(0,h(a,b)));
      dt[h(a,b)]=0;
      while(SZ(pq))
      {
        while(SZ(pq)&&dt[pq.top().Y]!=pq.top().X)pq.pop();
        if(!SZ(pq))break;
        ii tmp=pq.top();
        pq.pop();
        REP(i,SZ(v[tmp.Y]))
        {
          ll dis=tmp.X+v[tmp.Y][i].Y,t=v[tmp.Y][i].X;
          if(dt[t]==-1||dis<dt[t])
          {
            dt[t]=dis;
            debug(t,dis);
            pq.push(ii(dis,t));
          }
        }
      }
      if(mp.count(h(c,d)))cout<<min(dt[h(c,d)],dt[mp[h(c,d)]])<<endl;
      else cout<<dt[h(c,d)]<<endl;
    }
}
