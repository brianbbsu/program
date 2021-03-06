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
template<typename _a> ostream &operator << (ostream &_s,const vector<_a> &_c){return _OUTC(_s,ALL(_c));}
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


const ll MAXn=1e3+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll cnt[MAXn];
ll dt[MAXn][MAXn],gcd[MAXn][MAXn];

const ll bs=880301;
ll pw[MAXn];

ll hs[MAXn];

ll ans[MAXn],u[MAXn];
map<ll,vector<ll> > mp;
ll d[MAXn][MAXn];

int main()
{
    IOS();
    ll N=1000;
    REP1(i,N)REP1(j,i)cnt[i]+=(i%j==0);
    REP1(i,N)REP1(j,N)gcd[i][j]=__gcd(i,j);
    REP1(i,N)REP1(j,N)if(i!=j)dt[i][j]=cnt[gcd[i][j]];

    pw[1]=1;
    for(int i=2;i<MAXn;i++)pw[i]=pw[i-1]*bs;

    /*int mx=0;
    for(auto &tmp:mp)mx=max(mx,SZ(tmp.Y));
    debug(mx,mp);*/

    ll T;
    cin>>T;
    while(T--)
    {
      ll n;
      cin>>n;
      REP(i,n)REP(j,n)cin>>d[i][j];
      REP(i,n)ans[i]=-1;
      REP1(i,n)hs[i]=0;
      mp.clear();

      REP1(i,n)REP1(j,n)if(i!=j)hs[i]+=pw[dt[i][j]];
      REP1(i,n)mp[hs[i]].pb(i);
      REP1(i,n)u[i]=0;

      REP(i,n)
      {
        ll tt=0;
        REP(j,n)tt+=pw[d[i][j]];
        vector<ll> &v=mp[tt];
        for(ll t:v)
        {
          if(u[t])continue;
          bool ok=1;
          REP(j,i)if(cnt[gcd[t][ans[j]]]!=d[i][j])
          {
            ok=0;
            break;
          }
          if(ok)
          {
            ans[i]=t;
            u[t]=1;
            break;
          }
        }
        assert(ans[i]!=-1);
      }
      REP(i,n)cout<<ans[i]<<endl;
    }
}
