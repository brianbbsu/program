//{
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(ll i=0;i<n;i++)
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

ll g[MAXn],c;
void reset(int n){REP(i,n)g[i]=i;c=n;}
ll fd(int a){return g[a]=(g[a]==a?a:fd(g[a]));}
void mg(int a,int b){g[fd(a)]=fd(b);}

struct tg{
  int a,b;
  bool clr;
  tg(ll ai,ll bi,bool clri):a(ai),b(bi),clr(clri){}
  bool operator < (const tg &t)const{return clr;}
};

vector<tg> d;
ll mak(ll n)
{
  reset(n);
  ll rt=0;
  for(tg &k:d)if(fd(k.a)!=fd(k.b)){mg(k.a,k.b);c--;if(k.clr)rt++;}
  return rt;
}
vector<ll> f;
int main()
{
    IOS();
    ll T;
    cin>>T;
    ll kz=0;
    ll n,m;
    f.pb(0);
    f.pb(1);
    while(f.back()<MAXn)f.pb(f.back()+f[SZ(f)-2]);
    debug(f);
    while(cin>>n>>m&&++kz)
    {
      cout<<"Case #"<<kz<<": ";
      d.clear();
      REP(i,m)
      {
        int a,b;
        bool clr;
        cin>>a>>b>>clr;
        a--;b--;
        d.pb(tg(a,b,clr));
      }
      sort(ALL(d));
      int mx=mak(n);
      if(c!=1){puts("No");continue;}
      reverse(ALL(d));
      int mn=mak(n);
      if(upper_bound(ALL(f),mx)-lower_bound(ALL(f),mn)>0)puts("Yes");
      else puts("No");
    }
}
