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
template<typename _a> ostream &operator << (ostream &_s,deque<_a> &_c){return _OUTC(_s,ALL(_c));}
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
const ll INF=ll(1e18);


#ifndef brian
#include "lib1961.h"
#endif

struct seg{
  ll a,b,l,r,pi;
  seg(ll ai,ll bi,ll li,ll ri,ll pii):a(ai),b(bi),l(li),r(ri),pi(pii){}
  ll operator () (ll x)const{return a*x+b;}
};
#ifdef brian
ostream &operator << (ostream &_ss,const seg &_t){return _ss<<_t.a<<"x+"<<_t.b<<":"<<ii(_t.l,_t.r);}
#endif

vector<ii> dt,tmpdt;
ll n,m,k;

deque<seg> st;
ll dp[MAXn],pi[MAXn];

void cal(ll cst)
{
  dp[0]=0;pi[0]=0;
  while(SZ(st))st.pop_back();
  REP1(i,n)
  {
    seg tmp=seg(-2*dt[i].X,dp[i-1]+dt[i].X*dt[i].X-max(0LL,dt[i-1].Y-dt[i].X)*max(0LL,dt[i-1].Y-dt[i].X)+cst,0,ll(1e6+5),pi[i-1]);
    bool b=0;
    while(SZ(st))
    {
      assert(st.back().a!=tmp.a);
      if(st.back()(st.back().l)>=tmp(st.back().l)&&st.back()(st.back().r)>=tmp(st.back().r))tmp.l=st.back().l,st.pop_back();
      else {tmp.l=(tmp.b-st.back().b)/(st.back().a-tmp.a)+1,st.back().r=tmp.l-1;break;}
    }
    if(!b)st.pb(tmp);
    while(SZ(st)>=2&&st.front().r<dt[i].Y)st.pop_front();
    debug(st,dt[i].Y);
    dp[i]=st[0](dt[i].Y)+dt[i].Y*dt[i].Y;
    pi[i]=st[0].pi+1;
  }
};

ll take_photos(int N,int M,int K,int *R,int *C)
{
  dt.clear();tmpdt.clear();
  n=N,m=M,k=K;
  REP(i,n)tmpdt.pb(ii(min(R[i],C[i]),max(R[i],C[i])+1));
  tmpdt.pb(ii(m+1,m+1));tmpdt.pb(ii(-1,-1));
  sort(ALL(tmpdt),[](ii a,ii b){return ii(a.X,-a.Y)<ii(b.X,-b.Y);});
  for(ii &tmp:tmpdt)if(!SZ(dt)||tmp.Y>dt.back().Y)dt.pb(tmp);
  debug(dt);


  n=SZ(dt)-2;

  ll l=0,r=2*m*m;
  ll cnt=0;
  while(l!=r-1)
  {
    cnt++;
    assert(cnt<=100);
    ll h=(l+r)/2;
    cal(h);
    if(pi[n]<k)r=h;
    else l=h;
  }
  cal(l);
  debug(l,dp[n],pi[n]);
  ll dpa=dp[n]-pi[n]*l,pia=pi[n];
  cal(l+1);
  debug(l+1,dp[n],pi[n]);
  ll dpb=dp[n]-pi[n]*(l+1),pib=pi[n];
  debug(dpa,pia,dpb,pib);
  if(pia==pib)return dpa;
  else return (k-pia)*(dpb-dpa)/(pib-pia)+dpa;

}

#ifdef brian
int main()
{
    IOS();
    int _r[]={0,4,4,4,4};
    int _c[]={3,4,6,5,6};
    debug(take_photos(5,7,2,_r,_c));

    int _r2[]={1,4};
    int _c2[]={4,1};
    debug(take_photos(2,6,2,_r2,_c2));

    int _r3[]={1,2,6,7};
    int _c3[]={1,2,6,7};
    debug(take_photos(4,10,3,_r3,_c3));


}
#endif
