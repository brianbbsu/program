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
  int qr(int k,int dt=0)
  {
    bit[B]-=dt;
    int l=0,sz=(B>>1);
    while(sz>0)
    {
      if(bit[l+sz]<k)k-=bit[l+sz],l+=sz;
      else bit[l+sz]-=dt;
      sz>>=1;
    }
    debug(k,l,sz);
    return l;
  }
}

vector<ii> dt;
int d[MAXn];
int st[MAXn];
int lg[MAXn];

int GetBestPosition(int N, int C, int R, int K[], int A[], int B[])
{
  dt.clear();
  bit::init(N);

  REP(i,N+1)bit::ins(i,1);
  REP(i,C)
  {
    int l=bit::qr(A[i]+1),r=bit::qr(B[i]+2);
    REP(j,B[i]-A[i])bit::qr(A[i]+2,1);
    dt.pb(ii(l,r-1));
  }

  debug(dt);

  REP(i,N-1)st[i+1]=(K[i]>R);
  partial_sum(st+1,st+N,st+1);

  memset(d,0,sizeof(int)*N);

  for(ii &tmp:dt)
  {
    if(st[tmp.X]==st[tmp.Y])d[tmp.X]++,d[tmp.Y+1]--;
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
