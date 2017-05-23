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

lf u,d,l,r;
lf vx[MAXn],vy[MAXn];
lf px[MAXn],py[MAXn];
ll n;

lf mn[MAXn],mx[MAXn];

pair<lf,lf> cal(int i,lf t)
{
  return make_pair(px[i]+vx[i]*t,py[i]+vy[i]*t);
}
lf calx(int i,lf x)
{
  return (x-px[i])/vx[i];
}
lf caly(int i,lf y)
{
  return (y-py[i])/vy[i];
}
void qt()
{
  cout<<-1<<endl;
  exit(0);
}
int main()
{
    IOS();
    cin>>n;
    cin>>l>>d>>r>>u;
    REP(i,n)cin>>px[i]>>py[i]>>vx[i]>>vy[i];
    REP(i,n)
    {
      lf t;
      t=max(min(calx(i,l),calx(i,r)),min(caly(i,d),caly(i,u)));
      mn[i]=t;
      t=min(max(calx(i,l),calx(i,r)),max(caly(i,d),caly(i,u)));
      mx[i]=t;
      //debug(i,mx[i],mn[i]);
      if(mx[i]<mn[i]-1e-7)qt();
    }
    lf ans=mn[0];
    REP(i,n)ans=max(ans,mn[0]);
    ans=max(ans,0.0);
    REP(i,n)if(ans>mx[i]+1e-7)qt();

    //cout<<123<<endl;
    REP(i,n)
    {
      lf x=px[i]+vx[i]*ans;
      lf y=py[i]+vy[i]*ans;
      if(!(x<=r+1e-7&&x>=l-1e-7&&y>=d-1e-7&&y<=u+1e-7))qt();
    }
    cout<<fixed<<setprecision(10)<<ans<<endl;
}
