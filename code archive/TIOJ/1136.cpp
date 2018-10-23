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

lf dp[2][MAXn][MAXn];
vector<ll> v[MAXn];

int main()
{
    IOS();

    ll n,T;
    while(cin>>n>>T&&(n|T))
    {
      ll m,g;
      cin>>m;
      REP(i,n)v[i].clear();
      REP(i,m)
      {
        ll a,b;
        cin>>a>>b;
        a--;b--;
        v[a].pb(b);
        v[b].pb(a);
      }
      cin>>g;
      if(!T)
      {
        cout<<fixed<<setprecision(4)<<1.0/lf(n)<<endl;
        continue;
      }
      bool fg=0;
      REP(i,n)REP(j,n)dp[0][i][j]=0.0;
      REP(i,n)dp[0][i][i]=1.0;
      for(ll I=(1<<__lg(T));I>0;I>>=1)
      {
        fg=!fg;
        REP(i,n)REP(j,n)dp[fg][i][j]=0.0;
        REP(i,n)REP(j,n)REP(k,n)dp[fg][i][j]+=dp[!fg][i][k]*dp[!fg][k][j];
        if(I&T)
        {
          fg=!fg;
          REP(i,n)REP(j,n)dp[fg][i][j]=0.0;
          REP(i,n)REP(j,n)for(ll k:v[j])dp[fg][i][k]+=dp[!fg][i][j]/lf(SZ(v[j]));
        }
      }
      lf tt=0.0;
      REP(i,n)tt+=dp[fg][i][g-1];
      tt/=lf(n);
      cout<<fixed<<setprecision(4)<<tt<<endl;
    }

}
