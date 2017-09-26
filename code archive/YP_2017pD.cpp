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

int main()
{
    IOS();
    ll n,m;
    cin>>n>>m;
    ll d[m+3];
    REP(i,m)cin>>d[i];
    #ifndef brian
    if(n>1000000&&m>1)
    #endif
    {
      ll mxm=0;
      REP(i,m)mxm=max(mxm,d[i]);
      ll mat[2][205][205];
      FILL(mat,0);
      ll dt[205][205];
      FILL(dt,0);
      REP(i,m)dt[0][d[i]-1]=1;
      REP1(i,mxm-1)dt[i][i-1]=1;

      ll lg=0;
      while((1LL<<(lg+1))<=n)lg++;

      bool fg=0;
      REP(i,mxm)mat[fg][i][i]=1;

      while(lg>=0)
      {
        REP(i,mxm)REP(j,mxm)
        {
          mat[!fg][i][j]=0;
          REP(k,mxm)mat[!fg][i][j]=(mat[!fg][i][j]+mat[fg][i][k]*mat[fg][k][j])%MOD;
        }
        fg=!fg;
        if((1LL<<lg)&n)
        {
          REP(i,mxm)REP(j,mxm)
          {
            mat[!fg][i][j]=0;
            REP(k,mxm)mat[!fg][i][j]+=mat[fg][i][k]*dt[k][j];
            mat[!fg][i][j]%=MOD;
          }
          fg=!fg;
        }
        lg--;
      }

      cout<<mat[fg][0][0]<<endl;
      return 0;
    }
    if(m==1)
    {
      cout<<(n%d[0]==0)<<endl;
      return 0;
    }
    ll dp[n+5];
    FILL(dp,0);
    dp[0]=1;
    REP1(i,n)REP(j,m)if(d[j]<=i)dp[i]=(dp[i-d[j]]+dp[i])%MOD;
    cout<<dp[n]<<endl;
    pary(dp,dp+n+1);
}
