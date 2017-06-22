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


const ll MAXn=1e5+5,MAXdp=80,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);


struct node{
  ll dp;
  node *lc,*rc;
  ll d,td;
  node(ll dpi,node *lci=0,node *rci=0):dp(dpi),lc(lci),rc(rci),d(0),td(0){};
  void pull()
  {
    d=(lc?lc->d:0)&(rc?rc->d:0);
    d|=(td<<dp);
  }
  bool ins(ll k)
  {
    if((d&(1LL<<k))>0)return 0;
    if(dp==k)
    {
      td=1;
      d=(1LL<<(MAXdp+1))-(1LL<<(dp));
      return 1;
    }
    else
    {
      bool rt;
      if(!lc)lc=new node(dp+1);
      if(!(lc->d&(1LL<<k)))rt=lc->ins(k);
      else
      {
        if(!rc)rc=new node(dp+1);
        rt=rc->ins(k);
      }
      if(rt)td=1;
      pull();
      return rt;
    }
  }
  void dbg()
  {
    debug(dp,d,td);
    if(lc)
    {
      debug("L");
      lc->dbg();
    }
    if(rc)
    {
      debug("R");
      rc->dbg();
    }
    debug("U");
  }
};

int main()
{
    IOS();

    ll n;
    cin>>n;
    node *rt=new node(0);
    REP(i,n)
    {
      ll k;
      cin>>k;
      k=min(k,MAXdp);
      if(rt->ins(k))cout<<"Yes"<<endl;
      else cout<<"No"<<endl;
      //rt->dbg();
    }
}
