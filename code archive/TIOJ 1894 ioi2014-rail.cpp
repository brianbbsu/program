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

#ifndef brian
#include "lib1894.h"
#else
ll _ct;
int getDistance(int x, int y)
{
  _ct++;
  cout<<"qr: "<<ii(x,y)<<endl;
  int rt;
  cin>>rt;
  return rt;
}
#endif

ll dis[2][MAXn];

vector<ll> dt;

void findLocation(int n, int L, int loc[], int tp[])
{
  dis[0][0]=INF;
  loc[0]=L;tp[0]=1;
  if(n==1)return;
  REP1(i,n-1)dis[0][i]=getDistance(0,i);
  ll l=min_element(dis[0],dis[0]+n)-dis[0];
  debug(l);
  dis[1][0]=dis[0][l];dis[1][l]=INF;
  loc[l]=L+dis[0][l];tp[l]=2;
  REP1(i,n-1)if(i!=l)dis[1][i]=getDistance(l,i);

  REP1(i,n-1)if(i!=l&&dis[0][i]<dis[1][i])dt.pb(i);
  sort(ALL(dt),[&](int a,int b){return dis[0][a]<dis[0][b];});

  debug(dt);
  if(SZ(dt))
  {
    ll ltrc=l,lt=dt.front();
    loc[dt.front()]=L+dis[0][dt.front()];
    tp[dt.front()]=2;

    REP1(i,SZ(dt)-1)
    {
      ll t=getDistance(lt,dt[i]);
      if(t<loc[lt]-loc[ltrc]+dis[0][dt[i]]-(loc[ltrc]-L))
      {
        tp[dt[i]]=1;
        loc[dt[i]]=loc[lt]-t;
        ltrc=dt[i];
      }
      else
      {
        tp[dt[i]]=2;
        loc[dt[i]]=L+dis[0][dt[i]];
        lt=dt[i];
      }
    }
  }
  dt.clear();
  REP1(i,n-1)if(i!=l&&dis[0][i]>dis[1][i])dt.pb(i);
  sort(ALL(dt),[&](int a,int b){return dis[1][a]<dis[1][b];});

  debug(dt);
  if(SZ(dt))
  {
    ll ltrc=l,lt=dt.front();
    loc[dt.front()]=loc[l]-dis[1][dt.front()];
    tp[dt.front()]=1;

    REP1(i,SZ(dt)-1)
    {
      ll t=getDistance(lt,dt[i]);
      debug(lt,dt[i],loc[ltrc]-loc[lt]+dis[1][dt[i]]-(loc[l]-loc[ltrc]));
      if(t<loc[ltrc]-loc[lt]+dis[1][dt[i]]-(loc[l]-loc[ltrc]))
      {
        tp[dt[i]]=2;
        loc[dt[i]]=loc[lt]+t;
        ltrc=dt[i];
      }
      else
      {
        tp[dt[i]]=1;
        loc[dt[i]]=loc[l]-dis[1][dt[i]];
        lt=dt[i];
      }
    }
  }


}


#ifdef brian
int main()
{
    IOS();
    _ct=0;
    int loc[MAXn],tp[MAXn];
    findLocation(1,5,loc,tp);
    pary(loc,loc+6);
    pary(tp,tp+6);
    debug(_ct);
}
#endif
