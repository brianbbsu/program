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
#include "lib1275.h"
#endif

namespace bit{
  int bit[131500];
  int B;
  void init(int n)
  {
    B=(1<<(__lg(n)+1));
    memset(bit+1,0,sizeof(int)*B);
  }
  void ins(int x,int k)
  {
    x++;
    while(x<=B)bit[x]+=k,x+=x&-x;
  }
  int qr(int k)
  {
    int l=0,sz=(B>>1);
    while(sz>0)
    {
      if(bit[l+sz]<k)k-=bit[l+sz],l+=sz;
      sz>>=1;
    }
    debug(k,l,sz);

    return l;
  }
}

vector<ii> dt;
set<int> dst;
int d[MAXn];
bool st[MAXn][MAXlg];
int lg[MAXn];

bool cal(int l,int r)
{
  int t=lg[r-l+1];
  return st[l][t]||st[r-(1<<t)+1][t];
}

int GetBestPosition(int N, int C, int R, int K[], int A[], int B[])
{
  dt.clear();
  dst.clear();
  bit::init(N);
  lg[0]=0;
  REP1(i,N)lg[i]=((1<<(lg[i-1]+1))==i?lg[i-1]+1:lg[i-1]);

  REP(i,N+1)dst.insert(i),bit::ins(i,1);
  REP(i,C)
  {
    int l=bit::qr(A[i]+1),r=bit::qr(B[i]+2);
    auto ita=dst.lower_bound(l),itb=dst.lower_bound(r);
    ita++;
    while(ita!=itb)
    {
      bit::ins(*ita,-1);
      ita=dst.erase(ita);
    }
    dt.pb(ii(l,r-1));
  }
  debug(dt);

  REP(i,N-1)st[i][0]=(K[i]>R);
  for(int j=1;(1<<j)<=N-1;j++)REP(i,N-1)if((1<<j)+i<=N-1)st[i][j]=st[i][j-1]||st[i+(1<<(j-1))][j-1];

  memset(d,0,sizeof(int)*N);

  for(ii &tmp:dt)
  {
    if(!cal(tmp.X,tmp.Y-1))d[tmp.X]++,d[tmp.Y+1]--;
  }
  partial_sum(d,d+N,d);
  int mx=*max_element(d,d+N);

  REP(i,N)if(d[i]==mx)return i;
  return 0;
}

#ifdef brian
int main()
{
    IOS();
    int _d[]={1,0,2,4},_A[]={1,0,0},_B[]={3,1,1};
    ll t=GetBestPosition(5,3,3,_d,_A,_B);
    debug(t);
    t=GetBestPosition(5,3,3,_d,_A,_B);
    debug(t);
}
#endif
