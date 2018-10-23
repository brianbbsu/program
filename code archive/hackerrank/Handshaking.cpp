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
const ll INF=ll(1e15);

inline ll myrnd()
{
  return ((rand()<<16)+rand())%(MOD-1)+1;
}
inline ll pw(ll x,ll k)
{
  if(!k)return 1;
  ll a=pw(x,k/2);
  a=a*a%MOD;
  if(k&1)return a*x%MOD;
  else return a;
}

ll d[MAXn][MAXn];


int main()
{
    IOS();
    ll n,m;
    while(cin>>n&&n)
    {
      cin>>m;
      FILL(d,0);
      REP(i,m)
      {
        ll a,b;
        cin>>a>>b;
        a--;b--;
        if(a>b)swap(a,b);
        ll t=myrnd();
        d[a][b]=t;
        d[b][a]=-t;
      }
      ll tt=n;
      REP(i,n)
      {
        bool ok=0;
        for(int j=i;j<n;j++)if(d[j][i]!=0)
        {
          ok=1;
          if(j!=i)for(int k=i;k<n;k++)swap(d[i][k],d[j][k]);
          break;
        }
        if(!ok)
        {
          tt--;
          continue;
        }
        if(d[i][i]<0)for(int k=i;k<n;k++)d[i][k]=-d[i][k];
        ll inv = pw(d[i][i],MOD-2);
        for(int k=i;k<n;k++)d[i][k]=d[i][k]*inv%MOD;
        for(int j=i+1;j<n;j++)for(int k=n-1;k>=i;k--)d[j][k]=(d[j][k]-d[j][i]*d[i][k])%MOD;
      }
      assert(tt%2==0);
      cout<<n-tt/2<<endl;
    }
}
