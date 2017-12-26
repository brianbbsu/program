#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define FILL(i,n) memset(i,n,sizeof i);
#define SZ(_a) ((int)(_a).size())
#define ALL(_a) (_a).begin(),(_a).end()
#define X first
#define Y second
#define pb push_back
#ifdef brian
template<typename T>void _do(T &&x){cerr<<x<<endl;}
template<typename T,typename ...t>void _do(T &&x,t &&...X){cerr<<x<<", ";_do(X...);}
#define debug(...) do{\
  fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
  _do(__VA_ARGS__);\
}while(0);
#else
#define debug(...)
#define endl '\n'
#endif

const ll MAXn = 20;

double pi = acos(-1);

typedef pair<double,double> dd;
dd sub(dd a,dd b){return dd(a.X-b.X,a.Y-b.Y);}
double crs(dd a,dd b)
{
  return a.X*b.Y-a.Y*b.X;
}


vector<dd> bstdt;
vector<ll> bstsrc;
double bst=0.0;

double di[MAXn];

double cal(vector<dd> &dt)
{
  double tt=0.0;
  REP1(i,SZ(dt)-2)tt+=crs(dd(dt[i+1].X-dt[0].X,dt[i+1].Y-dt[0].Y),dd(dt[i].X-dt[0].X,dt[i].Y-dt[0].Y));
  tt/=2.0;
  return tt;
}

void solve(vector<ll> d)
{
  sort(ALL(d),[](int a,int b){return di[a]<di[b];});
  double lng=di[d.back()];
  ll lngid=d.back();
  d.pop_back();
  double ett=0.0;
  for(ll tmp:d)ett+=di[tmp];
  if(ett<=lng)return;
  ll n=SZ(d);
  double l=lng/2.0,r=20000.0;
  while(r-l>1e-5)
  {
    double h=(l+r)/2,tt=0.0;
    for(auto tmp:d)tt+=2*asin(di[tmp]/(2*h));
    if(tt>2*pi)
    {
      l=h;
      continue;
    }
    if(tt>pi)tt=2*pi-tt;
    if(2*h*sin(tt/2)<lng)l=h;
    else r=h;
  }
  debug(r);
  vector<dd> dt={dd(r,0)};
  double tt=0.0;
  for(auto tmp:d)
  {
    tt+=2*asin(di[tmp]/(2*r));
    dt.pb(dd(r*cos(-tt),r*sin(-tt)));
  }
  double tmptt=cal(dt);
  debug(tmptt);
  if(tmptt>bst)bst=tmptt,bstdt=dt,bstsrc=d,bstsrc.pb(lngid);

}

int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll n,k;
  cin>>n>>k;
  REP(i,n)cin>>di[i];
  vector<ll> pm;
  REP(i,n-k)pm.pb(0);
  REP(i,k)pm.pb(1);
  do{
    vector<ll> dt;
    REP(i,n)if(pm[i])dt.pb(i);
    solve(dt);
  }while(next_permutation(ALL(pm)));
  debug(bst);
  REP(i,k)
  {
    cout<<fixed<<setprecision(12)<<bstdt[i].X;
    cout<<" ";
    cout<<fixed<<setprecision(12)<<bstdt[i].Y;
    cout<<endl;
  }
  REP(i,k)cout<<bstsrc[i]+1<<" ";
  cout<<endl;
}
