//{
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lf;
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



int n;
lf x[MAXn],y[MAXn];
inline bool cmpx(int a,int b){return x[a]<x[b];}
inline bool cmpy(int a,int b){return make_pair(y[a],x[a])<make_pair(y[b],x[b]);}
ll d[MAXn];
vector<ll> t;
inline lf dis(int a,int b){return sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));}

lf DnC(int l,int r)
{
  if(r-l==1)return 400000.0;
  int h=(l+r)/2;
  lf s=min(DnC(l,h),DnC(h,r));
  t.clear();

  for(int i=l;i<h;i++)if(abs(x[d[i]]-x[d[h-1]])<=s)t.pb(d[i]);
  for(int i=h;i<r;i++)if(abs(x[d[i]]-x[d[h]])<=s)t.pb(d[i]);
  sort(ALL(t),cmpy);
  REP(i,SZ(t))
  {
    for(int j=i+1;j<SZ(t)&&j-i<=4;j++)
    {
      lf tmp=dis(t[i],t[j]);
      if(tmp<s)s=tmp;
    }
  }
  return s;
}

int main()
{
    IOS();
    while(cin>>n&&n)
    {
      REP(i,n)cin>>x[i]>>y[i];
      if(n==1){cout<<"INFINITY"<<endl;continue;}
      REP(i,n)d[i]=i;
      sort(d,d+n,cmpx);
      lf ans=DnC(0,n);
      if(ans<=10000)cout<<fixed<<setprecision(4)<<ans<<endl;
      else cout<<"INFINITY"<<endl;
    }
}
