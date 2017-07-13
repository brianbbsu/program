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


const ll MAXn=7e3+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);


uint32_t x, y, z, w;
uint32_t xorshift() {
  uint32_t t = x;
  t ^= t << 11;
  t ^= t >> 8;
  x = y; y = z; z = w;
  w ^= w >> 19;
  w ^= t;
  return w & ((1 << 24) - 1);
}
void getInputMatrix(int n, ll A[][7000],uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
  x = a; y = b; z = c; w = d;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      A[i][j] = xorshift();
    }
  }
}

ll A[7000][7000],B[7000][7000];

ll pw[MAXn];

int main()
{
    IOS();
    ll n,a[4],b[4],p;
    cin>>n;
    REP(i,4)cin>>a[i];
    REP(i,4)cin>>b[i];
    cin>>p;
    pw[0]=1;
    REP1(i,MAXn-1)pw[i]=pw[i-1]*p%MOD;

    getInputMatrix(n,A,a[0],a[1],a[2],a[3]);
    getInputMatrix(n,B,b[0],b[1],b[2],b[3]);

    REP(i,n)REP(j,n)B[i][j]=B[i][j]*pw[n-j-1]%MOD;

    REP(i,n)REP1(j,n-1)B[i][j]=(B[i][j]+B[i][j-1]);
    REP(i,n)B[i][n-1]%=MOD;

    ll tt=0;

    REP(i,n)
    {
      tt=tt*pw[n]%MOD;
      REP(j,n)tt=(tt+A[i][j]*B[j][n-1])%MOD;
    }
    cout<<tt<<endl;
}
