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
#include "lib1885.h"
//#include "grader.h"
//#include "scales.h"
//#include "grader.cpp"
#else
int getLightest(int a,int b,int c)
{
  debug("getLightest",a,b,c);
  ll t;
  cin>>t;
  return t;
}
int getMedian(int a,int b,int c)
{
  debug("getMedian",a,b,c);
  ll t;
  cin>>t;
  return t;
}
int getHeaviest(int a,int b,int c)
{
  debug("getHeaviest",a,b,c);
  ll t;
  cin>>t;
  return t;
}
int getNextLightest(int a,int b,int c,int d)
{
  debug("getNextLightest",a,b,c,d);
  ll t;
  cin>>t;
  return t;
}
void answer(int *d)
{
  pary(d,d+6);
}
#endif

struct qr{
  int pm,tp,id;
  qr(int pmi,int tpi,int idi=-1):pm(pmi),tp(tpi),id(idi){}
};
vector<qr> qrs;

vector<vector<int> > perm_st;
vector<int> his;
void dfs(ll now,ll ct)
{
  if(now>6)return;
  dfs(now+1,ct);
  his.pb(now);
  if(ct==1)perm_st.pb(his);
  else dfs(now+1,ct-1);
  his.pop_back();
}

vector<vector<int> > dts;

bool calp(vector<int> &d,vector<int> &perm,int p,int tg)
{
  vector<ll> tmp;
  for(ll t:d)if(perm[0]==t||perm[1]==t||perm[2]==t)tmp.pb(t);
  return tmp[p]==tg;
}
bool calnxtp(vector<int> &d,vector<int> &perm,int p,int tg)
{
  bool fg=0;
  for(ll t:d)
  {
    if(t==p)fg=1;
    if(fg&&(perm[0]==t||perm[1]==t||perm[2]==t))return t==tg;
  }
  for(ll t:d)if(perm[0]==t||perm[1]==t||perm[2]==t)return t==tg;
}

int rts[800][150];

int v[10][150][5];

struct node{
  ll qrid;
  node *ch[5];
  node(){}
};

bool go(node *it,vector<ll> st,int mxtt)
{
  it->ch[0]=new node();
  it->ch[1]=new node();
  it->ch[2]=new node();

  vector<ll> tmp;
  REP(i,SZ(qrs))
  {
    ll ct[3];
    FILL(ct,0);
    for(ll k:st)ct[rts[k][i]]++;
    //debug(i,ct[0],ct[1],ct[2]);
    if(max({ct[0],ct[1],ct[2]})<=mxtt)
    {
      it->qrid=i;
      //debug(i,ct[0],ct[1],ct[2]);
      bool b=1;
      REP(j,3)
      {
        if(ct[j]>1)
        {
          tmp.clear();
          for(ll k:st)if(rts[k][i]==j)tmp.pb(k);
          b&=go(it->ch[j],tmp,mxtt/3);
          if(!b)break;
        }
      }
      if(b)return 1;
    }
  }
  return 0;
}
node *rt;

void myinit(int T)
{
  dfs(1,3);
  debug(perm_st);
  REP(i,3)REP(j,SZ(perm_st))qrs.pb(qr(j,i));
  REP1(i,6)REP(j,SZ(perm_st))
  {
    if(perm_st[j][0]==i||perm_st[j][1]==i||perm_st[j][2]==i)continue;
    qrs.pb(qr(j,3,i));
  }
  debug(SZ(qrs));

  vector<int> tmpst={1,2,3,4,5,6};
  do{
    dts.pb(tmpst);
  }while(next_permutation(ALL(tmpst)));

  debug(SZ(dts));

  REP(i,SZ(dts))REP(j,SZ(qrs))
  {
    if(qrs[j].tp<3)REP(l,3){if(calp(dts[i],perm_st[qrs[j].pm],qrs[j].tp,perm_st[qrs[j].pm][l]))rts[i][j]=l;}
    else REP(k,3)if(calnxtp(dts[i],perm_st[qrs[j].pm],qrs[j].id,perm_st[qrs[j].pm][k]))rts[i][j]=k;
  }
  tmpst.clear();
  REP(i,SZ(dts))tmpst.pb(i);
  rt=new node();
  bool b=go(rt,tmpst,243);
  assert(b);
}


void godfs(node *it,vector<int> st)
{
  qr &q=qrs[it->qrid];
  vector<int> &pm=perm_st[q.pm],tmpst;
  ll rt;
  if(q.tp==0)rt=getLightest(pm[0],pm[1],pm[2]);
  else if(q.tp==1)rt=getMedian(pm[0],pm[1],pm[2]);
  else if(q.tp==2)rt=getHeaviest(pm[0],pm[1],pm[2]);
  else rt=getNextLightest(pm[0],pm[1],pm[2],q.id);

  REP(t,3)if(rt==pm[t])
  {
    for(ll k:st)if(rts[k][it->qrid]==t)tmpst.pb(k);
    if(SZ(tmpst)==1)
    {
      answer(dts[tmpst[0]].data());
      return;
    }
    godfs(it->ch[t],tmpst);
  }
}

void myorderCoins()
{
  vector<ll> tmpst;
  REP(i,SZ(dts))tmpst.pb(i);
  godfs(rt,tmpst);
}

//#ifdef brian
int main()
{
    IOS();
    ll T=Init();
    myinit(T);
    while(T--)
    {
      orderCoins();
      myorderCoins();
    }
}
//#endif
