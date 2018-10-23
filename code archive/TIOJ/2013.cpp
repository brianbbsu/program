//{
#include "lib2013.h"
#include<bits/stdc++.h>
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


const ll MAXn=1e6+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);


struct node{
  int pri,sz;
  node *lc,*rc ,*p;
  //string nm;
};
/*
void dfs(node *t)
{
  if(!t)return;
  dfs(t->lc);
  debug(t->nm);
  dfs(t->rc);
}*/

int gsz(node *a){return a?a->sz:0;}

node *mg(node *a,node *b)
{
  if(!a||!b)return a?a:b;
  if(a->pri>b->pri)
  {
    a->rc=mg(a->rc,b);
    if(a->rc)a->rc->p=a;
    a->sz=gsz(a->lc)+gsz(a->rc)+1;
    return a;
  }
  b->lc=mg(a,b->lc);
  if(b->lc)b->lc->p=b;
  b->sz=gsz(b->lc)+gsz(b->rc)+1;
  return b;
}

void split(node *a,node *&b,node *&c,int k)
{
  if(!a)b=0,c=0;
  else if(gsz(a->lc)>=k)
  {
    c=a;
    split(a->lc,b,c->lc,k);
    if(c->lc)c->lc->p=c;
    c->sz=gsz(c->lc)+gsz(c->rc)+1;
  }
  else
  {
    b=a;
    split(a->rc,b->rc,c,k-gsz(a->lc)-1);
    if(b->rc)b->rc->p=b;
    b->sz=gsz(b->lc)+gsz(b->rc)+1;
  }
}

int index(node *k)
{
  ll tt=1+gsz(k->lc);
  while(k->p)
  {
    if(k->p->rc==k)tt+=1+gsz(k->p->lc);
    k=k->p;
  }
  return tt;
}

int g[MAXn];
int fd(int a){return g[a]=(g[a]==a?a:fd(g[a]));}
void dsu_mg(int a,int b)
{
  a=fd(a),b=fd(b);
  g[b]=a;
}

//ll n;
node *in[MAXn],*out[MAXn],*rt[MAXn];

void init(int n)
{
  srand(880301);
  REP(i,n)
  {
    g[i]=i;
    in[i]=new node{rand(),1,0,0,0};
    out[i]=new node{rand(),1,0,0,0};
    rt[i]=mg(in[i],out[i]);
  }
}

void explore(int a,int b)
{
    int t=index(in[a]);
    node *l,*r;
    split(rt[fd(a)],l,r,t);

    l=mg(l,rt[fd(b)]);
    //dfs(l);

    rt[fd(a)]=mg(l,r);
    dsu_mg(a,b);
    debug("GO",a,b,t);
}

int run(int a,int b)
{
  if(fd(a)!=fd(b))return 0;
  int la=index(in[a]),ra=index(out[a]),t=index(in[b]);
  debug(la,ra,t);
  if(t>=la&&t<=ra)return 1;
  return 0;
}
