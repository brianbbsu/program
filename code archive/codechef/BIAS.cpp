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


const ll MAXn=1e3+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

inline ll rnd(ll l,ll r)
{
  if(l>r)debug(l,r);
  assert(l<=r);
  return rand()%(r-l+1)+l;
}


ll l[MAXn],u[MAXn];
ll d[MAXn][MAXn];
ll ans[MAXn];
ll caltt[MAXn];
ll srt[MAXn],bit[MAXn];
ll n,m;

void ins(int x)
{
  while(x<=n)bit[x]++,x+=x&-x;
}
inline int qr(int x)
{
  int rt=0;
  while(x)rt+=bit[x],x-=x&-x;
  return rt;
}

ll cal_rev()
{
  REP1(i,n)srt[i]=n-i,bit[i]=0;
  stable_sort(srt,srt+n,[](int a,int b){return caltt[a]>caltt[b];});
  int tt=0;
  for(int i=n-1;i>=0;i--)tt+=qr(srt[i]+1),ins(srt[i]+1);
  return tt;
}



const ll K=7000,th=1000000;

int main()
{
    IOS();
    srand(time(NULL));
    ll T;
    cin>>T;
    while(T--)
    {
      cin>>n>>m;
      REP(i,m)cin>>l[i]>>u[i];
      REP(i,n)REP(j,m)cin>>d[i][j];
      REP(i,m)ans[i]=rnd(l[i],u[i]);
      REP(i,n)caltt[i]=0;
      REP(i,n)REP(j,m)caltt[i]+=ans[j]*d[i][j];

      ll lt=cal_rev();

      REP(_,K)
      {
        ll t=rnd(0,m-1);
        ll dlt=rnd(l[t]-ans[t],u[t]-ans[t]);
        REP(i,n)caltt[i]+=dlt*d[i][t];
        ll tmp=cal_rev();
        if(tmp<lt)lt=tmp,ans[t]+=dlt;
        else REP(i,n)caltt[i]-=dlt*d[i][t];
      }
      REP(i,m)cout<<ans[i]<<" ";
      cout<<endl;
      pary(caltt,caltt+n);
      debug(lt);
    }
} 
