//{
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


const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

#ifndef brian
#include "lib1895.h"
#endif

struct tg{
  ll x,id,tp;
  tg(ll xi,ll idi,ll tpi):x(xi),id(idi),tp(tpi){}
  bool operator < (const tg &b)const{return x<b.x;}
};


struct val{
  ll l,r,t;
  val(ll li=0,ll ri=0,ll ti=0):l(li),r(ri),t(ti){}
};

struct node;
void pt(node*,val);
struct node{
  int l,r;
  node *lc,*rc;
  val dt[4];
  ll sz;
  node(ll li=0,ll ri=0,node *lci=0,node *rci=0):l(li),r(ri),lc(lci),rc(rci),sz(1){dt[0]=val(0,100000,-1);}

  void pull()
  {
    sz=0;
    ll it=0;
    REP(i,lc->sz)
    {
      val a=lc->dt[i];
      if(a.t==-1)
      {
        while(rc->dt[it].r<a.l)it++;
        while(1)
        {
          pt(this,val(max(a.l,rc->dt[it].l),min(a.r,rc->dt[it].r),rc->dt[it].t));
          if(rc->dt[it].r>=a.r)break;
          else it++;
        }
      }
      else
      {
        while(rc->dt[it].r<a.t)it++;
        pt(this,val(a.l,a.r,(rc->dt[it].t==-1?a.t:rc->dt[it].t)));
      }
    }
  }
  void pt(node *d,val a)
  {
    if(!d->sz||d->dt[d->sz-1].t!=a.t)d->dt[d->sz]=a,d->sz++;
    else d->dt[d->sz-1].r=a.r;
  }

  void ins(ll x,vector<val> &k)
  {
    if(l==r-1)
    {
      sz=SZ(k);
      REP(i,sz)dt[i]=k[i];
    }
    else
    {
      if(x<(l+r)/2)lc->ins(x,k);
      else rc->ins(x,k);
      pull();
    }
  }
};

struct segt
{
  node nds[1000000+500];
  node *nit,*rt;
  node *build(ll l,ll r)
  {
    if(l==r-1)return new(nit++) node(l,r);
    else return new(nit++) node(l,r,build(l,(l+r)/2),build((l+r)/2,r));
  }
  void init(ll n)
  {
    nit=nds;
    rt=build(0,n);
  }
  void ins(ll x,vector<val> &k)
  {
    rt->ins(x,k);
  }
  ll qr()
  {
    return (rt->dt[0].t==-1?0:rt->dt[0].t);
  }
}seg;

vector<tg> dt;
void buildWall(int N, int Q, int op[], int L[], int R[], int H[], int ans[])
{
  seg.init(Q);
  dt.clear();
  REP(i,Q)dt.pb(tg(L[i],i,1)),dt.pb(tg(R[i]+1,i,-1));
  sort(dt.begin(),dt.end());
  ll it=0;
  REP(i,N)
  {
    while(it<SZ(dt)&&dt[it].x==i)
    {
      vector<val> tmp;
      if(dt[it].tp==1)
      {
        ll t=dt[it].id;
        if(op[t]==1)
        {
          tmp.pb(val(0,H[t],H[t]));
          if(H[t]!=100000)tmp.pb(val(H[t]+1,100000,-1));
        }
        else
        {
          if(H[t]!=0)tmp.pb(val(0,H[t]-1,-1));
          tmp.pb(val(H[t],100000,H[t]));
        }
      }
      else
      {
        tmp.pb(val(0,100000,-1));
      }
      seg.ins(dt[it].id,tmp);
      it++;
    }
    ans[i]=seg.qr();
  }
}


#ifdef brian
int main()
{
    IOS();
    int op[]={1,2,2,1,1,2};
    int l[]={1,4,3,0,2,6};
    int r[]={8,9,6,5,2,7};
    int h[]={4,1,5,3,5,0};
    int ans[MAXn];
    buildWall(10,6,op,l,r,h,ans);
    pary(ans,ans+10);
    buildWall(10,6,op,l,r,h,ans);
    pary(ans,ans+10);
}
#endif
