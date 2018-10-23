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
const ll INF=ll(1e15);


struct node{
  ll l,r;
  node *lc,*rc;
  ll d,mx;
  node(ll li,ll ri,node *lci=0,node *rci=0):l(li),r(ri),lc(lci),rc(rci),d(-1),mx(0){}
  void pull()
  {
    if(d==-1)mx=max(lc->mx,rc->mx);
    else mx=max(abs(d-l),abs(d-(r-1)));
  }
  void ins(ll li,ll ri,ll x)
  {
    if(li>=r||ri<=l)return;
    else
    {
      if(li<=l&&ri>=r)d=x;
      else
      {
        if(d!=-1){lc->d=d;rc->d=d;lc->pull();rc->pull();d=-1;}
        lc->ins(li,ri,x);
        rc->ins(li,ri,x);
      }
      pull();
    }
  }
  ll qr(ll li,ll ri)
  {
    debug(li,ri,l,r,d,mx);
    if(li>=r||ri<=l)return 0;
    else if(li<=l&&ri>=r)return mx;
    else if(d!=-1)return max(abs(max(li,l)-d),abs(min(ri,r)-1-d));
    else return max(lc->qr(li,ri),rc->qr(li,ri));
  }
};
node *build(ll l,ll r)
{
  if(l==r-1)return new node(l,r);
  else return new node(l,r,build(l,(l+r)/2),build((l+r)/2,r));
}
node *rt=0;

int main()
{
    IOS();
    ll n,q;
    cin>>n>>q;
    rt=build(0,n);
    REP(i,n)
    {
      ll t;
      cin>>t;
      t--;
      rt->ins(i,i+1,t);
    }
    REP(i,n)debug(i,rt->qr(i,i+1));
    REP(i,q)
    {
      ll l,r,k;
      cin>>l>>r>>k;
      l--;k--;
      cout<<rt->qr(l,r)<<endl;
      rt->ins(l,r,k);
    }
    REP(i,n)debug(i,rt->qr(i,i+1));
}
