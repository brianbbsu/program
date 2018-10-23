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

ll dp[31][31][31][2]; // c a b carry

int main()
{
    IOS();
    ll T;
    cin>>T;
    while(T--)
    {
      ll a,b,c;
      cin>>a>>b>>c;
      ll cta = 0,ctb = 0;
      for(ll i = 1;i <= a;i<<=1)if(a & i)cta++;
      for(ll i = 1;i <= b;i<<=1)if(b & i)ctb++;
      debug(cta,ctb,bitset<10>(a),bitset<10>(b));
      FILL(dp,0);
      int i = 0;
      dp[0][0][0][0] = 1;
      for(int I = 1;I <= c;I <<= 1,i++)REP(x,cta+1)REP(y,ctb+1)
      {
        if(c & I)
        {
          dp[i+1][x+1][y][0] += dp[i][x][y][0];
          dp[i+1][x][y+1][0] += dp[i][x][y][0];
          dp[i+1][x+1][y+1][1] += dp[i][x][y][1];
          dp[i+1][x][y][0] += dp[i][x][y][1];
        }
        else{
          dp[i+1][x+1][y][1] += dp[i][x][y][1];
          dp[i+1][x][y+1][1] += dp[i][x][y][1];
          dp[i+1][x+1][y+1][1] += dp[i][x][y][0];
          dp[i+1][x][y][0] += dp[i][x][y][0];
        }
      }
      cout<<dp[i][cta][ctb][0]<<endl;
    }
}
