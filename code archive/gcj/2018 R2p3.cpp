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


const ll MAXn=2e2+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll d[MAXn][MAXn];

vector<ii> occ[MAXn];
vector<ll> v[MAXn],uy;
ll vy[MAXn],px[MAXn],py[MAXn],x[MAXn];

bool dfs(ll now)
{
  for(ll k:v[now])if(!vy[k])
  {
    vy[k] = 1;
    uy.pb(k);
    if(py[k]==-1||dfs(py[k]))
    {
      px[now] = k;
      py[k] = now;
      return 1;
    }
  }
  return 0;
}

int main()
{
    IOS();
    ll T,kz=0;
    cin>>T;
    while(T--)
    {
      kz++;
      cout<<"Case #"<<kz<<": ";
      ll n;
      cin>>n;
      REP(i,n)REP(j,n)cin>>d[i][j],d[i][j]+=n;
      ll nn = n*n,mn=nn;
      REP(i,n+n+1)occ[i].clear();
      ll tt=0;
      REP(i,n)REP(j,n)occ[d[i][j]].pb(ii(i,j));
      REP(i,n+n+1)if(SZ(occ[i]))
      {
        REP(j,n)x[j]=0;
        for(ii tmp:occ[i])x[tmp.X]=1,v[tmp.X].pb(tmp.Y);
        //REP(j,n)debug(kz,i-n,j,v[j]);
        ll ct=0;
        REP(j,n)px[j]=py[j]=-1;
        REP(j,n)if(x[j])for(ll k:v[j])if(py[k]==-1)
        {
          py[k] = j;
          px[j] = k;
          ct++;
          break;
        }
        REP(j,n)if(x[j]&&px[j]==-1)
        {
          if(dfs(j))ct++;
          for(ll k:uy)vy[k]=0;
          uy.clear();
        }
        REP(j,n)v[j].clear();
        tt+=SZ(occ[i])-ct;
        debug(kz,i-n,ct);
      }
      cout<<tt<<endl;
    }
}
