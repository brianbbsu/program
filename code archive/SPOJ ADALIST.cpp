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


const ll MAXn=6e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

#define L 0
#define R 1

struct node{
  int ch[2],p,d,sz;
}tree[MAXn];

void isroot(ll x)
{
  ll p = tree[x].p;
  return !p || (tree[p].ch[L]!=x && tree[p].ch[R]!=x);
}

void pull(ll x)
{
  tree[x].sz=1;
  if(tree[x].ch[R])tree[x].sz += tree[tree[x].ch[R]].sz;
  if(tree[x].ch[L])tree[x].sz += tree[tree[x].ch[L]].sz;
}

void rotate(ll x)
{
  ll p=tree[x].p,pp=tree[p].p,dir=(tree[p].ch[R]==x);
  if(!isroot(p))tree[pp].ch[tree[pp].ch[R]==p]=x;
  tree[p].ch[dir]=tree[x].ch[!dir];
  tree[tree[x].ch[!dir]].p=p;
  tree[x].ch[!dir]=p;
  tree[p].p=x;
  tree[x].p=pp;
  pull(p);pull(x);
}

void splay(ll x)
{
  while(!isroot(x))
  {
    ll p=tree[x].p,pp=tree[p].p;
    if(!isroot(p))
    {
      if((tree[p].ch[R]==x) ^ (tree[pp].ch[R]==p))rotate(x);
      else rotate(p);
    }
    rotate(x);
  }
}


int nit=1,rt;

void ins(ll k,ll k)
{
  u
}

int main()
{
    IOS();
    ll n;
    cin>>n;
}
