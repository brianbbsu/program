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

#include "lib1164.h"

vector<ll> s[2],l[2];

ll dis;
ll h[MAXn][2];
vector<ii> v[MAXn];

void dfs(ll now,ll f)
{
  h[now][0]=h[now][1]=0;
  for(ii k:v[now])
  {
    if(k.X==f)continue;
    dfs(k.X,now);
    if(h[k.X][0]+k.Y>=h[now][0])
    {
      h[now][1]=h[now][0];
      h[now][0]=h[k.X][0]+k.Y;
    }
    else if(h[k.X][0]+k.Y>h[now][1])h[now][1]=h[k.X][0]+k.Y;
  }
  dis=max(dis,h[now][0]+h[now][1]);
}

ll cal(MAP d)
{
  dis=0;
  REP(i,d.m)v[i].clear();
  REP(i,d.k)v[d.x[i]].pb(ii(d.y[i],d.len[i])),v[d.y[i]].pb(ii(d.x[i],d.len[i]));
  dfs(0,-1);
  return dis;
}

int main()
{
    IOS();
    ll n=init();
    for(int i=0;i<n;i+=2)
    {
      if(i==n-1)s[0].pb(i),l[0].pb(i);
      else if(query(i,i+1))l[0].pb(i),s[0].pb(i+1);
      else s[0].pb(i),l[0].pb(i+1);
    }

    ll mn,mx;
    bool fg=0;
    while(1)
    {
      s[!fg].clear();
      for(int i=0;i<SZ(s[fg]);i+=2)
      {
        if(i==SZ(s[fg])-1)s[!fg].pb(s[fg][i]);
        else if(query(s[fg][i],s[fg][i+1]))s[!fg].pb(s[fg][i+1]);
        else s[!fg].pb(s[fg][i]);
      }
      fg=!fg;
      if(SZ(s[fg])==1)
      {
        mn=s[fg][0];
        break;
      }
    }
    fg=0;
    while(1)
    {
      l[!fg].clear();
      for(int i=0;i<SZ(l[fg]);i+=2)
      {
        if(i==SZ(l[fg])-1)l[!fg].pb(l[fg][i]);
        else if(!query(l[fg][i],l[fg][i+1]))l[!fg].pb(l[fg][i+1]);
        else l[!fg].pb(l[fg][i]);
      }
      fg=!fg;
      if(SZ(l[fg])==1)
      {
        mx=l[fg][0];
        break;
      }
    }
    answer(cal(getct(mx)),cal(getct(mn)));
}
