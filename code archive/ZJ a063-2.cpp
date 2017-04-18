//{
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(ll i=0;i<n;i++)
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

struct node
{
  ll d,pri,_sz;
  node *l,*r;
  bool tg;
  node(ll di):d(di),pri(rand()),_sz(1),l(0),r(0),tg(0){}
};
void push(node *a)
{
  if(!a||!a->tg)return;
  a->tg=0;
  swap(a->l,a->r);
  if(a->l)a->l->tg^=1;
  if(a->r)a->r->tg^=1;
}
ll sz(node *a){return (a?a->_sz:0);}
void pull(node *a){if(a)a->_sz=sz(a->l)+sz(a->r)+1;}

node *mg(node *a,node *b)
{
  if(!a||!b)return (a?a:b);
  if(a->pri>b->pri)
  {
    push(a);
    a->r=mg(a->r,b);
    pull(a);
    return a;
  }
  push(b);
  b->l=mg(a,b->l);
  pull(b);
  return b;
}
void splt(node *a,node *&b,node *&c,ll k)
{
  if(!a)b=c=0;
  else
  {
    push(a);
    if(sz(a->l)>=k)
    {
      c=a;
      splt(a->l,b,c->l,k);
      pull(c);
    }
    else
    {
      b=a;
      splt(a->r,b->r,c,k-sz(a->l)-1);
      pull(b);
    }
  }
}
void dfs(node *a)
{
  push(a);
  if(a->l)dfs(a->l);
  cout<<a->d<<" ";
  if(a->r)dfs(a->r);
}
node *rt=0;
int main()
{
    IOS();
    srand(time(NULL));
    ll n,m;
    cin>>n>>m;
    REP(i,n)rt=mg(rt,new node(i+1));
    REP(i,m)
    {
      ll l,r;
      cin>>l>>r;
      node *a,*b,*c,*tmp;
      splt(rt,a,tmp,l-1);
      splt(tmp,b,c,r-l+1);
      if(b)b->tg^=1;
      tmp=mg(a,b);
      rt=mg(tmp,c);
    }
    dfs(rt);
    cout<<endl;
}
