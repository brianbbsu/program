//{
#include<bits/stdc++.h>
using namespace std;
typedef int ll;
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
const ll MOD=900720143;
const ll INF=ll(1e15);

int dp[2][MAXn],p[MAXn];
ii lt[MAXn];

inline void add(int &a,int b)
{
  a+=b;
  if(a>=MOD)a-=MOD;
}
inline void sub(int &a,int b)
{
  a-=b;
  if(a<0)a+=MOD;
}

int main()
{
    IOS();
    ll T;
    cin>>T;
    REP1(kz,T)
    {
      ll n,k;
      cin>>n>>k;
      REP1(i,n)
      {
        ll t;
        cin>>t;
        if(lt[t].X==kz)p[i]=lt[t].Y;
        else p[i]=0;
        lt[t]=ii(kz,i);
      }
      bool fg=0;
      memset(dp[0],0,sizeof(int)*(n+1));
      dp[0][0]=1;
      while(k--)
      {
        int it=0,tt=0;
        fg=!fg;
        dp[fg][0]=0;
        REP1(i,n)
        {
          add(tt,dp[!fg][i-1]);
          while(it<p[i])sub(tt,dp[!fg][it++]);
          dp[fg][i]=tt;
        }
      }
      cout<<dp[fg][n]<<endl;
    }
}
