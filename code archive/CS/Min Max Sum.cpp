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


const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll pw[MAXn];

inline ll add(ll a,ll b)
{
  return (a+b)%MOD;
}
inline ll sub(ll a,ll b)
{
  ll rt=(a-b)%MOD;
  if(rt<0)rt+=MOD;
  return rt;
}
inline ll calpw(ll l,ll r)//[l,r)
{
  //debug(l,r);
  if(l!=0)return sub(pw[r-1],pw[l-1]);
  else return pw[r-1];
}

struct node{
  ll l,r;
  node *lc,*rc;
  ll tg,tt;//-1,0
  inline ll dt(){
    return (tg==-1?tt:tg*calpw(l,r)%MOD);
  }
  void ins(ll li,ll ri,ll t){
    if(li>=r||ri<=l)return;
    else if(li<=l&&ri>=r)tg=t;
    else{
      if(tg!=-1)lc->tg=rc->tg=tg;
      tg=-1;
      lc->ins(li,ri,t);rc->ins(li,ri,t);
      tt=add(lc->dt(),rc->dt());
    }
  }
  ll qr(ll li,ll ri){//,ll fg=0){
    if(li>=r||ri<=l)return 0;
    else if(tg!=-1)
    {
      ll tl=max(l,li),tr=min(r,ri);
      return tg*calpw(tl,tr)%MOD;
      //return tg*(tr-tl)%MOD;
    }
    else if(li<=l&&ri>=r)return tt;
    else return add(lc->qr(li,ri),rc->qr(li,ri));
  }
};
node *build(ll l,ll r){
  if(l==r-1)return new node{l,r,0,0,-1,0};
  else return new node{l,r,build(l,(l+r)/2),build((l+r)/2,r),-1,0};
}

node *minrt,*maxrt;
vector<ll> minst,maxst;

ll d[MAXn];

int main()
{
    IOS();
    pw[0]=pw[1]=1;
    for(int i=2;i<MAXn;i++)pw[i]=add(pw[i-1],pw[i-1]);
    REP1(i,MAXn-1)pw[i]=add(pw[i],pw[i-1]);
    ll n,ans=0,tt=0;
    cin>>n;
    REP(i,n)cin>>d[i];
    minst.pb(-1);maxst.pb(-1);
    minrt=build(0,n);
    maxrt=build(0,n);
    debug(minrt->qr(0,n));
#define mnbk minst.back()
#define mxbk maxst.back()
    REP(i,n)
    {
      ll s;
      while(mnbk!=-1&&d[mnbk]>=d[i])
      {
        ll tmp=mnbk;minst.pop_back();
        s=d[tmp]*maxrt->qr(mnbk+1,tmp+1)%MOD;
        tt=sub(tt,s);
      }
      s=d[i]*maxrt->qr(mnbk+1,i+1)%MOD;
      tt=add(tt,s);
      minrt->ins(mnbk+1,i+1,d[i]);
      minst.pb(i);
      debug(tt,ans,minst,maxst,minrt->qr(0,n));
      while(mxbk!=-1&&d[mxbk]<=d[i])
      {
        ll tmp=mxbk;maxst.pop_back();
        s=d[tmp]*minrt->qr(mxbk+1,tmp+1)%MOD;
        tt=sub(tt,s);
      }
      debug(tt,ans);
      s=d[i]*minrt->qr(mxbk+1,i+1)%MOD;
      tt=add(tt,s);
      maxrt->ins(mxbk+1,i+1,d[i]);
      maxst.pb(i);

      ans=add(ans,tt*calpw(n-i-1,n-i)%MOD);
      debug(tt,ans,minst,maxst,minrt->qr(0,n),calpw(0,2));
    }
    cout<<ans<<endl;
}
