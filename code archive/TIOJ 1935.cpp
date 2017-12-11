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
const ll INF=ll(1e18);

vector<ll> uni;
const ll M = (1<<18)+1;

struct solve1d{
  ll bit[M],ct[M],tt,ttct;
  void ins(ll x,ll tp)
  {
    ll tmp=tp*uni[x];
    tt+=tmp;ttct+=tp;
    while(x<M)
    {
      ct[x]+=tp;bit[x]+=tmp;
      x+=x&-x;
    }
  }
  ll qr()
  {
    if(!ttct)return 0;
    ll g=(ttct>>1),p=0,l=(1<<17),prett=0;
    while(l)
    {
      if(ct[p+l]<=g)g-=ct[p+l],prett+=bit[p+l],p+=l;
      l>>=1;
    }
    p++;g=(ttct>>1)-g;
    debug(p,g,prett,uni,tt);
    return (g*uni[p]-prett)+((tt-prett)-(ttct-g)*uni[p]);
  }
}sa,sb;


ll l[MAXn],r[MAXn];
vector<ll> dt;

int main()
{
    IOS();
    ll k,n,tmpans=0;
    cin>>k>>n;
    REP(i,n)
    {
      char s1,s2;
      cin>>s1>>l[i]>>s2>>r[i];
      if(l[i]>r[i])swap(l[i],r[i]);
      if(s1==s2)tmpans+=r[i]-l[i];
      else
      {
        tmpans++;
        dt.pb(i);
        uni.pb(l[i]);uni.pb(r[i]);
      }
    }

    sort(ALL(dt),[](int a,int b){return l[a]+r[a]<l[b]+r[b];});

    uni.pb(-1);
    sort(ALL(uni));
    uni.resize(unique(ALL(uni))-uni.begin());


    for(ll i:dt)l[i]=lower_bound(ALL(uni),l[i])-uni.begin(),r[i]=lower_bound(ALL(uni),r[i])-uni.begin();
    debug(tmpans,dt);
    for(ll i:dt)sa.ins(l[i],1),sa.ins(r[i],1);
    if(k==1||!SZ(dt))cout<<tmpans+sa.qr()<<endl;
    else
    {
      ll mn=INF;
      for(ll i:dt)
      {
        sa.ins(l[i],-1),sa.ins(r[i],-1);
        sb.ins(l[i],1),sb.ins(r[i],1);
        mn=min(mn,sa.qr()+sb.qr());
      }
      cout<<mn+tmpans<<endl;
    }
}
