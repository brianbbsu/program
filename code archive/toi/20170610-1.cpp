//{
#undef brian
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

struct node{
  ll l,r;
  node *lc,*rc;
  ll d,mn,mx;
  node(ll li,ll ri,node *lci=0,node *rci=0):l(li),r(ri),lc(lci),rc(rci),d(0),mn(0),mx(0){}
  void ins(ll x,ll k)
  {
    if(l==r-1)
    {
      d=mn=mx=k;
    }
    else
    {
      if(x<(l+r)/2)lc->ins(x,k);
      else rc->ins(x,k);
      mn=min(lc->mn,rc->mn);
      mx=max(lc->mx,rc->mx);
    }
  }
  ll qrmx(ll li,ll ri)
  {
    if(li>=r||ri<=l)return -1;
    else if(li<=l&&ri>=r)return mx;
    else return max(lc->qrmx(li,ri),rc->qrmx(li,ri));
  }
  ll qrmn(ll li,ll ri)
  {
    if(li>=r||ri<=l)return INF;
    else if(li<=l&&ri>=r)return mn;
    else return min(lc->qrmn(li,ri),rc->qrmn(li,ri));
  }
};
node *build(ll l,ll r)
{
  if(l==r-1)return new node(l,r);
  else return new node(l,r,build(l,(l+r)/2),build((l+r)/2,r));
}

node *rt=0,*prert=0;
set<int> st[MAXn];
ll n,q;
ll d[MAXn];
int main()
{
    IOS();
    cin>>n;
    REP(i,n)cin>>d[i];

    rt=build(0,n+5);
    REP(i,n)rt->ins(i,d[i]);
    prert=build(0,n+5);
    REP1(i,n)st[i].insert(-1);
    REP(i,n)
    {
      auto it=st[d[i]].end();
      it--;
      prert->ins(i,*it);
      st[d[i]].insert(i);
    }
    REP1(i,n)st[i].insert(n);
    cin>>q;
    REP(i,q)
    {
      ll t,a,b;
      cin>>t>>a>>b;
      if(t==1)
      {
        a--;
        rt->ins(a,b);
        auto it=st[d[a]].lower_bound(a);
        it--;
        ll tmp=*it;
        it++;it++;
        prert->ins(*it,tmp);
        st[d[a]].erase(a);
        d[a]=b;
        it=st[b].lower_bound(a);
        prert->ins(*it,a);
        it--;
        prert->ins(a,*it);
        st[b].insert(a);
      }
      else
      {
        a--;
        if(rt->qrmx(a,b)==b-a&&rt->qrmn(a,b)==1&&prert->qrmx(a,b)<a)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
      }
    }
}
