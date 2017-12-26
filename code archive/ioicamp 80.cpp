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


const ll MAXn=1e2+5,MAXc=3e4+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll dp[2][MAXc];


int main()
{
    IOS();
    ll T;
    cin>>T;
    while(T--)
    {
      ll n,k,M;
      cin>>n>>k>>M;
      bool fg=0;
      REP(i,M+1)dp[fg][i]=0;
      while(n--)
      {
        ll p,b,c;
        cin>>p>>b>>c;
        fg=!fg;
        REP(x,p)
        {
          deque<ii> dq;
          for(ll t=0;t*p+x<=M;t++)
          {
            if(t>=k)
            {
              ii tmp(t-k,dp[!fg][(t-k)*p+x]-(t-k)*b);
              while(SZ(dq)&&dq.back().Y<=tmp.Y)dq.pop_back();
              dq.pb(tmp);
            }
            while(SZ(dq)&&dq.front().X<t-c)dq.pop_front();
            if(SZ(dq))dp[fg][t*p+x]=dq.front().Y+t*b;
            else dp[fg][t*p+x]=0;
          }
        }
        REP(i,M+1)dp[fg][i]=max(dp[fg][i],dp[!fg][i]);
      }
      cout<<dp[fg][M]<<endl;
    }
}
