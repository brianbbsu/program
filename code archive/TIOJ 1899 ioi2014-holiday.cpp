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


const ll MAXn=1e5+5,MAXb=131072,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

#ifndef brian
#include "lib1899.h"
#endif


namespace bit{
  ll cnt[MAXb+10],tt[MAXb+10],B;

  void clr(){
    memset(cnt,0,(B+1)*sizeof(ll));
    memset(tt,0,(B+1)*sizeof(ll));
  }
  void ins(ll x,ll tp,ll d){
    x++;d*=tp;
    while(x<=B){
      cnt[x]+=tp;
      tt[x]+=d;
      x+=x&-x;
    }
  }

  ll qr(ll k){
    ll l=0,sz=(B>>1),rt=0;
    while(sz>0){
      if(cnt[l+sz]<=k){
        k-=cnt[l+sz];
        rt+=tt[l+sz];
        l+=sz;
      }
      sz>>=1;
    }
    return rt;
  }
}

struct tg{
  ll idl,idr,l,r;
  tg(ll idli,ll idri,ll li,ll ri):idl(idli),idr(idri),l(li),r(ri){}
};

ll d[MAXn],id[MAXn],n;
vector<ll> dt;
ll dp[2][3*MAXn],pi[2][3*MAXn];
queue<tg> q;

ll findMaxAttraction(int N, int S, int D, int *attr)
{
  if(D==0)return 0;
  n=N;dt.clear();
  bit::B=(1<<(__lg(n)+1));
  bit::clr();

  memset(dp[0],0,(D+5)*sizeof(ll));
  memset(dp[1],0,(D+5)*sizeof(ll));

  REP(i,n)d[i]=attr[i];
  REP(i,n)dt.pb(i);
  sort(ALL(dt),[&](int a,int b){return d[a]>d[b];});
  REP(i,n)id[dt[i]]=i;

  while(SZ(q))q.pop();

  q.push(tg(-1,-1,-1,-1));
  q.push(tg(0,D,S+1,N-1));
  ll it=S;
  while(SZ(q))
  {
    tg t=q.front();
    q.pop();
    if(t.idl==-1)
    {
      bit::clr();
      if(!SZ(q))break;
      q.push(t);
      it=S;
      continue;
    }
    ll tpi=t.l,now=(t.idl+t.idr)/2;
    for(int i=t.l;i<=t.r&&i-S-1<=now;i++)
    {
      while(it<i)it++,bit::ins(id[it],1,d[it]);
      ll tmp=bit::qr(now-(i-S-1));
      if(tmp>dp[0][now])tpi=i,dp[0][now]=tmp;
    }
    pi[0][now]=tpi;
    if(t.idl!=t.idr-1)
    {
      q.push(tg(t.idl,now,t.l,tpi));
      q.push(tg(now,t.idr,tpi,t.r));
    }
  }

  while(SZ(q))q.pop();

  q.push(tg(-1,-1,-1,-1));
  q.push(tg(0,D,0,S-1));
  it=S;
  while(SZ(q))
  {
    tg t=q.front();
    q.pop();
    if(t.idl==-1)
    {
      bit::clr();
      if(!SZ(q))break;
      q.push(t);
      it=S;
      continue;
    }
    ll tpi=t.r,now=(t.idl+t.idr)/2;
    for(int i=t.r;i>=t.l&&S-1-i<=now;i--)
    {
      while(it>i)it--,bit::ins(id[it],1,d[it]);
      ll tmp=bit::qr(now-(S-1-i));
      if(tmp>dp[1][now])tpi=i,dp[1][now]=tmp;
    }
    pi[1][now]=tpi;
    if(t.idl!=t.idr-1)
    {
      q.push(tg(t.idl,now,tpi,t.r));
      q.push(tg(now,t.idr,t.l,tpi));
    }
  }

  ll mx=(D>0?d[S]:0);
  REP1(i,D)
  {
    if(pi[0][i-1]-S+i<D)mx=max(mx,dp[0][i-1]+dp[1][D-(pi[0][i-1]-S+i)-1]);
    else mx=max(mx,dp[0][i-1]);
    if(S-pi[1][i-1]+i<D)mx=max(mx,dp[1][i-1]+dp[0][D-(S-pi[1][i-1]+i)-1]);
    else mx=max(mx,dp[1][i-1]);

    if(i>1)
    {
      ll j=i-1;
      ll DD=D-1;
      if(pi[0][j-1]-S+j<DD)mx=max(mx,dp[0][j-1]+dp[1][DD-(pi[0][j-1]-S+j)-1]+d[S]);
      else mx=max(mx,dp[0][j-1]+d[S]);
      if(S-pi[1][j-1]+j<DD)mx=max(mx,dp[1][j-1]+dp[0][DD-(S-pi[1][j-1]+j)-1]+d[S]);
      else mx=max(mx,dp[1][j-1]+d[S]);
    }
  }
  return mx;
}

#ifdef brian
int main()
{
    IOS();
    int _d[]={10,2,20,30,1};
    ll _t=findMaxAttraction(5,2,6,_d);
     _t=findMaxAttraction(5,0,5,_d);
}
#endif
