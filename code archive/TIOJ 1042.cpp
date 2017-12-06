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


const ll MAXn=1e2+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(9e18);

bool vx[MAXn],vy[MAXn];
ll lbx[MAXn],lby[MAXn],v[MAXn][MAXn],px[MAXn],py[MAXn],slk[MAXn];
ll n;

bool dfs(int now)
{
  vx[now]=1;
  REP(i,n)
  {
    if(!vy[i])
    {
      ll t=lby[i]+lbx[now]-v[now][i];
      if(t==0)
      {
        vy[i]=1;
        if(py[i]==-1||dfs(py[i]))
        {
          px[now]=i;py[i]=now;
          return 1;
        }
      }
      else if(t<slk[i])slk[i]=t;
    }
  }
  return 0;
}

int main()
{
    IOS();
    while(cin>>n&&n)
    {
      REP(i,n)REP(j,n)cin>>v[i][j],v[i][j]=max(v[i][j],0LL);
      memset(lby,0,sizeof(ll)*n);
      memset(px,-1,sizeof(ll)*n);
      memset(py,-1,sizeof(ll)*n);
      REP(i,n)
      {
        lbx[i]=v[i][0];
        REP(j,n)lbx[i]=max(lbx[i],v[i][j]);
      }
      REP(t,n)
      {
        while(1)
        {
          memset(vx,0,sizeof(bool)*n);
          memset(vy,0,sizeof(bool)*n);
          REP(i,n)slk[i]=INF;
          if(dfs(t))break;

          ll mn=INF;
          REP(i,n)if(!vy[i]&&slk[i]<mn)mn=slk[i];

          REP(i,n)if(vx[i])lbx[i]-=mn;
          REP(j,n)if(vy[j])lby[j]+=mn;
        }
      }
      ll tt=0;
      REP(i,n)if(v[i][px[i]]>0)tt+=v[i][px[i]];
      cout<<tt<<endl;
    }
}
