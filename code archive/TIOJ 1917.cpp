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
const ll INF=ll(7e18),INV=ll(3e18);

typedef __int128 lll;

ll n;
bool vx[MAXn],vy[MAXn];
ll v[MAXn][MAXn],lbx[MAXn],lby[MAXn],px[MAXn],py[MAXn],dx[MAXn],dy[MAXn],dt[MAXn];
vector<ii> dis;

bool dfs(int i)
{
  vx[i]=1;
  REP(j,n)
  {
    if(vy[j]||v[i][j]==INF)continue;
    ll t=lbx[i]+lby[j]-v[i][j];
    if(t==0)
    {
      vy[j]=1;
      if(py[j]==-1||dfs(py[j]))
      {
        px[i]=j;py[j]=i;
        return 1;
      }
    }
    else dt[j]=min(dt[j],t);
  }
  return 0;
}

int main()
{
    IOS();
    ll T;
    cin>>T;
    while(T--)
    {
      ll L,U,k;
      cin>>n>>L>>U>>k;
      dis.resize(k);
      REP(i,k)cin>>dis[i].X>>dis[i].Y,dis[i].X--,dis[i].Y--;
      REP(i,n)cin>>dx[i];
      REP(i,n)cin>>dy[i];
      REP(i,n)REP(j,n)v[i][j]=INV-(dx[i]+dy[j]<L?0:min(U,dx[i]+dy[j])-L);
      REP(i,k)v[dis[i].X][dis[i].Y]=INF;

      memset(lby,0,sizeof(ll)*n);
      memset(px,-1,sizeof(ll)*n);
      memset(py,-1,sizeof(ll)*n);
      REP(i,n)
      {
        lbx[i]=0;
        REP(j,n)if(v[i][j]!=INF)lbx[i]=max(lbx[i],v[i][j]);
      }
      bool fg=1;
      for(int t=0;t<n&&fg;t++)
      {
        while(1)
        {
          memset(vx,0,sizeof(bool)*n);
          memset(vy,0,sizeof(bool)*n);
          REP(i,n)dt[i]=INF;
          if(dfs(t))break;

          ll mn=INF;
          REP(i,n)if(!vy[i])mn=min(mn,dt[i]);
          debug(mn);
          if(mn==INF)
          {
            fg=0;
            break;
          }

          REP(i,n)if(vx[i])lbx[i]-=mn;
          REP(j,n)if(vy[j])lby[j]+=mn;
        }
      }
      if(!fg)cout<<"no"<<endl;
      else
      {
        lll tt=0;
        REP(i,n)tt+=INV-v[i][px[i]];
        if(tt==0)cout<<"0"<<endl;
        else
        {
          string s="";
          while(tt>0)
          {
            s.pb(int(tt%10)+'0');
            tt/=10;
          }
          reverse(ALL(s));
          cout<<s<<endl;
        }
      }
    }
}
