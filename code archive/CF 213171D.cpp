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


const ll MAXn=3e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll z[MAXn*2];
void makz(string s,ll n)
{
  z[0]=0;
  ll l=0,r=0;
  REP1(i,n-1)
  {
    if(i>r)z[i]=0;
    else
    {
      ll t=i-l;
      if(i+z[t]-1<r)z[i]=z[t];
      else z[i]=r-i+1;
    }
    while(i+z[i]<n&&s[i+z[i]]==s[z[i]])z[i]++;
    if(i+z[i]-1>r)
    {
      r=i+z[i]-1;
      l=i;
    }
  }
}

ll  n,m,q;
string s,t;
ll dp[MAXn];

struct node{
  ll l,r;
  node *lc,*rc;
  ll d;
  node(ll li,ll ri,node *lci=0,node *rci=0):l(li),r(ri),lc(lci),rc(rci),d(0){}
  void ins(ll x,ll k)
  {
    if(l==r-1)d=k;
    else
    {
      if(x<(l+r)/2)lc->ins(x,k);
      else rc->ins(x,k);
      d=max(lc->d,rc->d);
    }
  }
  ll qr(ll li,ll ri)
  {
    if(li>=r||ri<=l)return 0;
    else if(li<=l&&ri>=r)return d;
    else return max(lc->qr(li,ri),rc->qr(li,ri));
  }
};
node *build(ll l,ll r)
{
  if(l==r-1)return new node(l,r);
  else return new node(l,r,build(l,(l+r)/2),build((l+r)/2,r));
}
node *rt=0;
int main()
{
    IOS();
    cin>>s>>t>>q;
    n=SZ(s);
    m=SZ(t);
    makz(s+t,n+m);
    auto d=z+n;
    REP(i,m)d[i]=min(d[i],n);
    pary(d,d+m);
    rt=build(0,m+1);
    for(int i=m-1;i>=0;i--)
    {
      dp[i]=max(d[i],rt->qr(i+1,i+d[i]+1)-i);
      rt->ins(i,dp[i]+i);
    }
    REP(i,q)
    {
      ll l,r;
      cin>>l>>r;
      if(dp[l-1]>=r-l+1)cout<<"YES"<<endl;
      else cout<<"NO"<<endl;
    }
}
