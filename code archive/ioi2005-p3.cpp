#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define FILL(i,n) memset(i,n,sizeof i)
#define X first
#define Y second
#define pb push_back
#define SZ(_a) ((int)(_a).size())
#define ALL(_a) (_a).begin(),(_a).end()
#ifdef brian
#define debug(...) do{\
  fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
  _do(__VA_ARGS__);\
}while(0)
template<typename T>void _do(T &&x){cerr<<x<<endl;}
template<typename T,typename ...t>void _do(T &&x,t &&...X){cerr<<x<<", ";_do(X...);}
#define IOS() ;
#else
#define debug(...)
#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#endif

const ll MAXn = 4e1+5;
const ll INF=ll(1e15);
const ll MOD=1000000007;


struct node
{
  ll l,r;
  node *lc,*rc;
  ll mx,d,pred;
  node(ll li,ll ri,ll di):l(li),r(ri),lc(0),rc(0),mx(max(di,0LL)*(r-l)),d(di),pred(di*(r-l)){}
  void ins(ll li,ll ri,ll di)
  {
    if(li<=l&&ri>=r)
    {
      d=di;
      mx=max(0LL,(r-l)*di);
      pred=(r-l)*di;
    }
    else
    {
      ll h=(l+r)/2;
      if(d!=-INF)
      {
        if(lc)lc->ins(0,INF,d);
        else lc=new node(l,h,d);
        if(rc)rc->ins(0,INF,d);
        else rc=new node(h,r,d);
      }
      d=-INF;
      
      if(li<h)lc->ins(li,ri,di);
      pred=lc->pred;
      mx=lc->mx;

      if(ri>h)rc->ins(li,ri,di);
      mx=max(mx,pred+rc->mx);
      pred+=rc->pred;
    }
  }
  ll qr(ll h)
  {
    debug(l,r,h,d);
    if(d!=-INF)
    {
      return h/d+l;
    }
    else
    {
      if(lc->mx>h)return lc->qr(h);
      else return rc->qr(h-lc->pred);
    }
  }

};

node *rt;
int main()
{
  IOS();
  ll n;
  cin>>n;
  rt=new node(0,n+1,0);
  rt->ins(n,n+1,INF);
  char ch;
  while(cin>>ch&&ch!='E')
  {
    if(ch=='Q')
    {
      ll tmp;
      cin>>tmp;
      cout<<rt->qr(tmp)<<endl;
    }
    else
    {
      ll a,b,tmp;
      cin>>a>>b>>tmp;
      rt->ins(a-1,b,tmp);
    }
  }
}
