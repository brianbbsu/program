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

#define sin asdfjsljdf

struct node{
  ll l,r;
  node *lc,*rc;
  ll sin,sout,lin,lout;
  node(ll li,ll ri,node *lci=0,node *rci=0):l(li),r(ri),lc(lci),rc(rci),sin(0),sout(INF),lin(0),lout(INF){}
  ll cal(ll x)
  {
    if(x<=sin)return sout;
    else if(x<=lin)return lout;
    else return INF;
  }
  void pull()
  {
    if(l==r-1)sout=sin,lout=lin;
    else
    {
      lin=lc->lin,sin=lc->sin;
      sout=rc->cal(lc->sout);
      lout=rc->cal(lc->lout);
    }
  }
  void ins(ll x,ii dt)
  {
    if(l==r-1)sin=dt.X,lin=dt.Y;
    else if(x<(l+r)/2)lc->ins(x,dt);
    else rc->ins(x,dt);
    pull();
  }
};

node *build(ll l,ll r)
{
  if(l==r-1)return new node(l,r);
  else return new node(l,r,build(l,(l+r)/2),build((l+r)/2,r));
}
node *rt=0;
ii d[MAXn];

int main()
{
    IOS();
    ll n;
    cin>>n;
    REP(i,n)cin>>d[i].X>>d[i].Y;
    REP(i,n)if(d[i].X>d[i].Y)swap(d[i].X,d[i].Y);
    rt=build(0,n);
    REP(i,n)rt->ins(i,d[i]);
    ll Q;
    cin>>Q;
    while(Q--)
    {
      ll a,b;
      cin>>a>>b;
      a--;b--;
      swap(d[a],d[b]);
      rt->ins(a,d[a]);
      rt->ins(b,d[b]);
      if(rt->sout!=INF||rt->lout!=INF)cout<<"TAK"<<endl;
      else cout<<"NIE"<<endl;
    }
}
