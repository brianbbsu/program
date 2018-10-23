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
const ll INF=ll(3e18);

struct mach{
  ll g,d,r,p;
  const bool operator < (const mach &t)const{return d<t.d;}
};
mach d[MAXn];
ll dp[MAXn];
ll b[MAXn];
vector<ll> dt[MAXlg],tmpdt;

ll cal(ll j,ll i)
{
  debug(j,i,d[j].g*d[i].d+b[j]+d[i].r-d[i].p);
  return d[j].g*d[i].d+b[j]+d[i].r-d[i].p;
}
void CDQ(ll l,ll r,ll lv)
{
  dt[lv].clear();
  if(l==r-1)
  {

    if(l!=0&&dp[l]-d[l].r<0)dp[l]=-INF;
    dt[lv].pb(l);
    b[l]=-d[l].g*(d[l].d+1)+dp[l];
    return;
  }
  CDQ(l,(l+r)/2,lv+1);
  dt[lv].swap(dt[lv+1]);
  ll it=0;
  debug(dt[lv]);
  for(int i=(l+r)/2;i<r;i++)
  {
    while(it<SZ(dt[lv])-1&&cal(dt[lv][it+1],i)>=cal(dt[lv][it],i))it++;
    dp[i]=max(dp[i],cal(dt[lv][it],i));
    debug(i,dp[i]);
  }
  CDQ((l+r)/2,r,lv+1);
  it=SZ(dt[lv]);
  for(ll k:dt[lv+1])dt[lv].pb(k);
  inplace_merge(dt[lv].begin(),dt[lv].begin()+it,dt[lv].end(),[&](int a,int b){return d[a].g<d[b].g;});
  tmpdt.clear();
  for(ll k:dt[lv])
  {
    bool fg=0;
    while(SZ(tmpdt)&&d[tmpdt.back()].g==d[k].g)
    {
      if(b[k]>=b[tmpdt.back()])tmpdt.pop_back();
      else {fg=1;break;}
    }
    if(fg)continue;

    while(SZ(tmpdt)>1)
    {
      __int128 a0=d[k].g,b0=b[k],a1=d[tmpdt.back()].g,b1=b[tmpdt.back()],a2=d[tmpdt[SZ(tmpdt)-2]].g,b2=b[tmpdt[SZ(tmpdt)-2]];
      if((b1-b0)*(a0-a2)<=(b2-b0)*(a0-a1))tmpdt.pop_back();
      else break;
    }
    tmpdt.pb(k);
  }
  dt[lv].swap(tmpdt);
  debug(l,r,dt[lv]);
}

int main()
{
    IOS();
    ll n,C,D;
    ll kz=0;

    while(cin>>n>>C>>D&&n)
    {
        kz++;
        REP(i,n)cin>>d[i].d>>d[i].p>>d[i].r>>d[i].g;
        d[n].d=0,d[n].g=0,d[n+1].r=d[n+1].p=0;
        d[n+1].r=d[n+1].p=0,d[n+1].d=D+1;
        n+=2;
        REP(i,n)dp[i]=-INF;
        dp[0]=C;
        sort(d,d+n);
        CDQ(0,n,0);
        pary(dp,dp+n);
        cout<<"Case "<<kz<<": "<<dp[n-1]<<endl;
    }

}
