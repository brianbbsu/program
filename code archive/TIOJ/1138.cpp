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


const ll MAXn=2e1+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll d[MAXn][MAXn];

int main()
{
    IOS();
    ll T;
    cin>>T;
    while(T--)
    {
      FILL(d,0);
      ll n;
      cin>>n;
      REP(i,n)
      {
        ll m;
        cin>>m;
        REP(j,m)
        {
          ll t;
          cin>>t;
          d[i][t]=1;
        }
        cin>>d[i][n];
      }
      REP(i,n)
      {
        if(d[i][i]==0)
        {
          for(int j=i+1;j<n&&d[i][i]==0;j++)if(d[j][i]!=0)REP(k,n+1)swap(d[i][k],d[j][k]);
        }
        REP(j,n)
        {
          if(i==j||d[j][i]==0)continue;
          ll fg=(((d[i][i]<0)^(d[j][i]<0))?1:-1),gcd=__gcd(abs(d[i][i]),abs(d[j][i])),a=abs(d[j][i])/gcd,b=abs(d[i][i])/gcd;
          REP(k,n+1)d[j][k]=b*d[j][k]+fg*a*d[i][k];
        }
      }
      REP(i,n)cout<<d[i][n]/d[i][i]<<endl;
    }
}
