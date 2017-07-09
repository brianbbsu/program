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


const ll MAXn=5e5+5,MAXc=1e6+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

//#define max(_a,_b) ((_a)<(_b)?(_b):(_a))

struct node{
  ll l,r;
  node *lc,*rc;
  ii d;
  node(ll li,ll ri,node *lci=0,node *rci=0):l(li),r(ri),lc(lci),rc(rci),d(ii(0,-1)){}
  void ins(ll li,ll ri,ii di)
  {
    if(li>=r||ri<=l)return;
    else if(li<=l&&ri>=r)d=max(d,di);
    else lc->ins(li,ri,di),rc->ins(li,ri,di);
  }
  ii qr(ll x)
  {
    if(l==r-1)return d;
    else if(x<(l+r)/2)return max(d,lc->qr(x));
    else return max(d,rc->qr(x));
  }
};
node *build(ll l,ll r)
{
  if(l==r-1)return new node(l,r);
  else return new node(l,r,build(l,(l+r)/2),build((l+r)/2,r));
}
node *rt=0;

ll d[MAXn];
ii dp[MAXn];
ll ls[MAXn];
vector<ll> ans;

int main()
{
    IOS();
    ll n,k;
    cin>>n>>k;
    REP(i,n)cin>>d[i];
    REP(i,k)
    {
      char c;
      cin>>c;
      if(c=='<')ls[i]=0;
      else if(c=='=')ls[i]=1;
      else ls[i]=2;
    }
    rt=build(0,MAXc);
    REP(i,n)
    {
      dp[i]=rt->qr(d[i]);
      dp[i].X++;
      ll t=ls[(dp[i].X-1)%k];
      if(t==0)rt->ins(d[i]+1,MAXc,ii(dp[i].X,i));
      else if(t==1)rt->ins(d[i],d[i]+1,ii(dp[i].X,i));
      else rt->ins(0,d[i],ii(dp[i].X,i));
    }
    ll mx=0;

    REP(i,n)if(dp[i]>dp[mx])mx=i;
    cout<<dp[mx].X<<endl;
    while(mx!=-1)
    {
      ans.pb(d[mx]);
      mx=dp[mx].Y;
    }
    reverse(ALL(ans));
    REP(i,SZ(ans))cout<<(i?" ":"")<<ans[i];
    cout<<endl;
}
