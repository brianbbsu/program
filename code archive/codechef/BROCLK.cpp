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

ll inv(ll x,ll k)
{
  if(!k)return 1;
  ll a=inv(x,k/2);
  a=a*a%MOD;
  if(k&1)return a*x%MOD;
  else return a;
}

struct tg{ll c,s,l;};

ll ss,c;
ll l,d,t;

tg cal(ll k)
{
  if(k==1)return (tg){c,ss,l};
  tg tmp=cal(k/2);
  tmp.s=tmp.s*tmp.c*2%MOD;
  tmp.c=(tmp.c*tmp.c*2-tmp.l*tmp.l)%MOD;
  tmp.l=tmp.l*tmp.l%MOD;
  if(k&1)
  {
    tg rt={0,0,tmp.l*l%MOD};
    rt.c=(tmp.c*c-tmp.s)%MOD;
    rt.s=(tmp.c*ss+tmp.s*c)%MOD;
    return rt;
  }
  return tmp;
}

int main()
{
    IOS();
    ll T;
    cin>>T;
    while(T--)
    {
      cin>>l>>d>>t;
      c=d;
      ss=(l*l-d*d)%MOD;
      tg rt=cal(t);
      rt.c=rt.c*inv(rt.l,MOD-2)%MOD;
      rt.c=rt.c*l%MOD;
      if(rt.c<0)rt.c+=MOD;
      cout<<rt.c<<endl;
    }
}
