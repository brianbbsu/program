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

ll d[MAXn][MAXn],pre[2][2][MAXn][MAXn],mn[MAXn];


ll cal(ll x,ll y,ll k)
{
  x --;
  y --;
  ll aa = pre[0][0][x + k][y + k] - pre[0][0][x][y+k] - pre[0][0][x + k][y] + pre[0][0][x][y];
  ll bb = pre[0][1][x + k][y + k] - pre[0][1][x][y+k] - pre[0][1][x + k][y] + pre[0][1][x][y];
  ll cc = pre[1][0][x + k][y + k] - pre[1][0][x][y+k] - pre[1][0][x + k][y] + pre[1][0][x][y];
  ll dd = pre[1][1][x + k][y + k] - pre[1][1][x][y+k] - pre[1][1][x + k][y] + pre[1][1][x][y];
  return min(aa+dd,bb+cc);
}


int main()
{
    IOS();
    ll n,m;
    cin>>n>>m;
    REP1(i,min(n,m) + 1)mn[i] = INF;
    debug("OK");
    REP1(i,n)
    {
      string s;
      cin>>s;
      debug(i);
      REP1(j,m)d[i][j] = s[j-1] - '0';
    }
    REP1(i,n)REP1(j,m)pre[(i+j)%2][d[i][j]][i][j]++;
    debug("OK2");
    REP(i,2)REP(j,2)REP1(k,n)REP1(l,m)pre[i][j][k][l] += pre[i][j][k-1][l] + pre[i][j][k][l-1] - pre[i][j][k-1][l-1];
    REP1(i,n)REP1(j,m)REP1(k,min(n - i + 1,m - j + 1))mn[k] = min(mn[k],cal(i,j,k));
    ll q;
    cin>>q;
    while(q--)
    {
      ll x;
      cin>>x;
      cout<<(upper_bound(mn+1,mn + min(n,m) + 1,x) - mn - 1)<<endl;
    }
}
