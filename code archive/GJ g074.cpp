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


const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);


ll dp[20][1000];

vector<int> gt[1000][10][5];

vector<int> get2(ll x,ll n,ll c)
{
  vector<int> rt;
  REP(i,n)
  {
    rt.pb(x%c);
    x/=c;
  }
  return rt;
}

vector<int> get(ll x,ll n,ll c)
{
  return gt[x][n][c];
}
ll ans[50][50][10];

int main()
{
    IOS();

    REP(i,729)REP1(j,6)REP1(k,3)gt[i][j][k]=get2(i,j,k);


    ll T;
    cin>>T;
    while(T--)
    //REP1(X,14)REP1(Y,6)REP1(Z,3)
    {
      ll n,m,c;
      cin>>n>>m>>c;
      //n=X,m=Y,c=Z;
      ll t=1;
      REP(i,m)t*=c;
      //FILL(dp,0);
      REP1(i,n)REP(j,t)dp[i][j]=0;
      REP(I,t)
      {
        vector<int> tmp=get(I,m,c);
        bool ok=1;
        REP(i,m-1)if(tmp[i]==tmp[i+1])ok=0;
        dp[1][I]=ok;
      }
      for(int i=2;i<=n;i++)
      {
        REP(I,t)
        {
          if(!dp[i-1][I])continue;
          vector<int> a=get(I,m,c);
          REP(J,t)
          {
            vector<int> b=get(J,m,c);
            bool ok=1;
            REP(j,m-1)if(b[j]==b[j+1])ok=0;
            if(!ok)continue;
            REP(j,m)if(b[j]==a[j])ok=0;
            if(ok)dp[i][J]+=dp[i-1][I];
          }

        }
      }
      ll tt=0;
      REP(I,t)tt+=dp[n][I];
      cout<<tt<<endl;
      //ans[n][m][c]=tt;
    }
    /*
    cin>>T;
    while(T--)
    {
      ll n,m,c;
      cin>>n>>m>>c;
      cout<<ans[n][m][c]<<endl;
    }*/
}
