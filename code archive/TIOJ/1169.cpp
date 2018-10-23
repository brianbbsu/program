//{
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<int,int> ii;
#define REP(i,n) for(int i=0;i<n;i++)
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
int qrmx;
vector<ii> qrdt;
struct node{
  int l,r,h,ls,rs,mx;
  node *lc,*rc;
  bool clrtg;
  void clr()
  {
    if(!clrtg)return;
    ls=-1;rs=-1;
    mx=r-l;clrtg=0;
    if(l!=r-1)lc->clrtg=rc->clrtg=1;
  }
  node(int li,int ri,node *lci=0,node *rci=0):l(li),r(ri),h((l+r)/2),ls(-1),rs(-1),mx(r-l),lc(lci),rc(rci),clrtg(0){}
  void pull()
  {
    if(l==r-1)return;
    lc->clr();rc->clr();
    if(lc->ls==-1&&rc->ls==-1)
    {
      ls=rs=-1;
      mx=r-l;
    }
    else if(lc->ls==-1)
    {
      ls=rc->ls;rs=rc->rs;
      mx=rc->mx;
    }
    else if(rc->ls==-1)
    {
      ls=lc->ls;rs=lc->rs;
      mx=lc->mx;
    }
    else
    {
      ls=lc->ls;rs=rc->rs;
      mx=max({rc->mx,lc->mx,rc->ls-lc->rs-1});
    }
  }
  void ins(int x,int tp)
  {
    if(clrtg)clr();
    if(l==r-1)
    {
      if(tp==1)
      {
        ls=rs=l;
        mx=0;
      }
      else
      {
        ls=rs=-1;
        mx=1;
      }
    }
    else
    {
      if(x<h)lc->ins(x,tp);
      else rc->ins(x,tp);
      pull();
    }
  }
  void qr(int li,int ri)
  {
    if(clrtg)clr();
    if(li>=r||ri<=l)return;
    if(li<=l&&ri>=r)
    {
      if(ls!=-1)
      {
        qrmx=max(qrmx,mx);
        qrdt.pb(ii(ls,rs));
      }
    }
    else lc->qr(li,ri),rc->qr(li,ri);
  }
};
node *build(int l,int r)
{
  if(l==r-1)return new node(l,r);
  else return new node(l,r,build(l,(l+r)/2),build((l+r)/2,r));
}

vector<int> uni;
struct chtag{
  int t,d,tp;
  chtag(int ti,int di,int tpi):t(ti),d(di),tp(tpi){}
};
struct qrtag{
  int t,l,r;
  qrtag(int ti,int li,int ri):t(ti),l(li),r(ri){};
};
int d[MAXn];
vector<chtag> ch[(1<<24)];
vector<qrtag> qr[(1<<24)];
vector<pair<int,chtag> > tmpch;
vector<pair<int,qrtag> > tmpqr;
int ans[MAXn];
node *rt=0;

int input()
{
  char c;
  while((c=getchar())&&(c<'0'||c>'9'));
  int tmp=0;
  while(c>='0'&&c<='9')
  {
    tmp=tmp*10+c-'0';
    c=getchar();
  }
  return tmp;
}

int main()
{
    IOS();
    int n,q,colors;
    n=input();q=input();colors=input();
    REP(i,n)d[i]=input(),uni.pb(d[i]),tmpch.pb(make_pair(d[i],chtag(0,i,+1)));
    int t=0;
    REP(i,q)
    {
      int k;
      k=input();
      if(k==0)
      {
        int p,x;
        p=input();x=input();
        uni.pb(x);
        tmpch.pb(make_pair(d[p],chtag(t,p,-1)));
        tmpch.pb(make_pair(d[p]=x,chtag(t,p,+1)));
      }
      else
      {
        int l,r,x;
        l=input();r=input();x=input();
        uni.pb(x);
        tmpqr.pb(make_pair(x,qrtag(t++,l,r)));
      }
    }
    sort(ALL(uni));
    uni.resize(unique(ALL(uni))-uni.begin());
    for(auto &tmp:tmpch)ch[lower_bound(ALL(uni),tmp.X)-uni.begin()].pb(tmp.Y);
    for(auto &tmp:tmpqr)qr[lower_bound(ALL(uni),tmp.X)-uni.begin()].pb(tmp.Y);
    rt=build(0,n);
    debug(uni);
    REP(i,SZ(uni))
    {
      rt->clrtg=1;
      int it=0;
      for(qrtag &tmp:qr[i])
      {
        debug(i);
        while(it<SZ(ch[i])&&ch[i][it].t<=tmp.t)
        {
          rt->ins(ch[i][it].d,ch[i][it].tp);
          it++;
        }
        qrmx=0;qrdt.clear();
        qrdt.pb(ii(-1,tmp.l-1));
        rt->qr(tmp.l,tmp.r);
        qrdt.pb(ii(tmp.r,-1));
        debug(qrmx,qrdt);
        REP(j,SZ(qrdt)-1)qrmx=max(qrmx,qrdt[j+1].X-qrdt[j].Y-1);
        ans[tmp.t]=qrmx;
      }
    }
    REP(i,SZ(tmpqr))cout<<ans[i]<<endl;
}
