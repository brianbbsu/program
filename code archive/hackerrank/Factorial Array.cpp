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
const ll MOD=1000000000;
const ll INF=ll(1e15);
const int M=40;

struct s{
  set<int> st;
  int bit[MAXn];
  void ins(ll x)
  {
    st.insert(x);
    while(x<MAXn)
    {
      bit[x]++;
      x+=x&-x;
    }
  }
  void rm(ll x)
  {
    st.erase(x);
    while(x<MAXn)
    {
      bit[x]--;
      x+=x&-x;
    }
  }
  int fdrm(ll l,ll r)//[l,r]
  {
    auto it = st.lower_bound(l);
    if(it==st.end()||*it>r)return 0;
    int rt=*it;
    rm(rt);
    return rt;
  }
  int qr(ll x)
  {
    ll rt=0;
    while(x)rt+=bit[x],x-=x&-x;
    return rt;
  }
}seg[M];


inline void add(ll &a,ll b)
{
  a+=b;
  if(a>=MOD)a-=MOD;
}
inline void sub(ll &a,ll b)
{
  a-=b;
  if(a<0)a+=MOD;
}

ll d[MAXn],fac[M];

int main()
{
    IOS();
    fac[0]=1;
    REP1(i,M-1)fac[i]=fac[i-1]*i%MOD;

    ll n,q;
    cin>>n>>q;
    REP1(i,n)
    {
      cin>>d[i];
      if(d[i]<M)seg[d[i]].ins(i);
    }
    while(q--)
    {
      int tp,a,b;
      cin>>tp>>a>>b;
      if(tp==1)//add 1
      {
        ll t;
        while(t=seg[M-1].fdrm(a,b))d[t]++;
        for(int i=M-2;i>0;i--)while(t=seg[i].fdrm(a,b))d[t]++,seg[i+1].ins(t);
      }
      else if(tp==2)//qr
      {
        ll tt=0;
        REP1(i,M-1)tt+=(seg[i].qr(b)-seg[i].qr(a-1))*fac[i];
        cout<<tt%MOD<<endl;
      }
      else
      {
        if(d[a]<M)seg[d[a]].rm(a);
        d[a]=min(b,M);
        if(d[a]<M)seg[d[a]].ins(a);
      }
    }
}
