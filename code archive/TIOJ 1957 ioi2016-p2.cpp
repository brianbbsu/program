//{
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<int,int> ii;
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


const ll MAXn=4e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e9+5);

#ifndef brian
//#include "lib1957.h"
#endif

vector<int> uni;
ii d[MAXn];
vector<int> v[MAXn];
int cnt[MAXn];
ll ans;
bool vis[MAXn];

int tmpg[MAXn];
int g[MAXn];
int fd(int a)
{
  return g[a]=(g[a]==a?a:fd(g[a]));
}
void mg(int a,int b){g[fd(a)]=fd(b);}

struct edge{
  int a, b;
  ll c;
  edge(int ai,int bi,ll ci):a(ai),b(bi),c(ci){}
  bool operator < (const edge &t)const {return c<t.c;}
};
vector<edge> e;

void dfs(int now,int c)
{
  vis[now]=1;tmpg[now]=c;
  for(ll k:v[now])if(!vis[k])dfs(k,c);
}
ll plan_roller_coaster(vector<int> s,vector<int> t)
{
  uni.clear();
  ll n=s.size();
  ans=0;
  REP(i,n)d[i]=ii(s[i],t[i]);
  d[n]=ii(INF,1);
  n++;
  REP(i,n)uni.pb(d[i].X),uni.pb(d[i].Y);
  sort(ALL(uni));
  uni.resize(unique(ALL(uni))-uni.begin());
  while(SZ(uni)>MAXn);
  REP(i,n)d[i].X=lower_bound(ALL(uni),d[i].X)-uni.begin(),d[i].Y=lower_bound(ALL(uni),d[i].Y)-uni.begin();
  REP(i,SZ(uni))v[i].clear();
  FILL(cnt,0);
  REP(i,n)v[d[i].X].pb(d[i].Y),cnt[d[i].X]++,cnt[d[i].Y]--;
  partial_sum(cnt,cnt+SZ(uni),cnt);
  REP(i,SZ(uni)-1)
  {
    if(cnt[i]>0)v[i+1].pb(i),ans+=ll(uni[i+1]-uni[i])*cnt[i];
    else if(cnt[i]<0)v[i].pb(i+1);
  }
  FILL(vis,0);
  ll c=0;
  REP(i,SZ(uni))if(!vis[i])c++,dfs(i,c);

  e.clear();
  REP(i,SZ(uni)-1)
  {
    if(tmpg[i]!=tmpg[i+1])e.pb(edge(tmpg[i],tmpg[i+1],uni[i+1]-uni[i]));
  }
  sort(ALL(e));
  REP(i,c+1)g[i]=i;
  for(auto &tmp:e)if(fd(tmp.a)!=fd(tmp.b))ans+=tmp.c,mg(tmp.a,tmp.b);
  return ans;

}



#ifdef brian
int main()
{
    IOS();
    int a[]={1,4,5,6},b[]={7,3,8,6};
    debug(plan_roller_coaster(4,a,b));
}
#endif
