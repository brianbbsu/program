//{
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<string>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<sstream>
#include<cmath>

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
const ll INF=ll(1e15);

ll dp[MAXn][MAXn];
ii f[MAXn][MAXn];

int main()
{
    IOS();
    REP(T,3)
    {
      string a,b;
      cin>>a>>b;
      FILL(dp,0);
      REP(i,SZ(a)+1)REP(j,SZ(b)+1)f[i][j]=ii(-1,-1);

      REP1(i,SZ(a))REP1(j,SZ(b))
      {
        if(a[i-1]==b[j-1])
        {
          dp[i][j]=dp[i-1][j-1]+1;
          f[i][j]=ii(i-1,j-1);
        }
        else if(dp[i-1][j]>=dp[i][j-1])
        {
          dp[i][j]=dp[i-1][j];
          f[i][j]=ii(i-1,j);
        }
        else
        {
          dp[i][j]=dp[i][j-1];
          f[i][j]=ii(i,j-1);
        }
      }
      ll mx=0;
      ii now=ii(0,0);
      REP1(i,SZ(a))REP1(j,SZ(b))if(dp[i][j]>mx)
      {
        mx=dp[i][j];
        now=ii(i,j);
      }
      string ans="";
      while(now.X>0||now.Y>0)
      {
        debug(now);
        if(a[now.X-1]==b[now.Y-1])
        {
          ans+=" ";
          ans[SZ(ans)-1]=a[now.X-1];
        }
        now=f[now.X][now.Y];
      }
      reverse(ALL(ans));
      cout<<a<<" "<<b<<" = ";
      if(SZ(ans))cout<<ans<<endl;
      else cout<<0<<endl;
    }
}
