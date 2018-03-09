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


ll pw(ll x,ll k)
{
  if(!k)return 1;
  ll a=pw(x,k/2);
  a=a*a%MOD;
  if(k&1)return a*x%MOD;
  else return a;
}
ll d[MAXn],b[MAXn],a[MAXn],ct[MAXn],dt[MAXn];
vector<ll> v[MAXn];
ll two[MAXn];
bool u[MAXn];

ll add(ll a,ll b)
{
  a+=b;
  if(a>=MOD)a-=MOD;
  else if(a<0)a+=MOD;
  return a;
}

int main()
{
    IOS();
    two[0]=1;
    REP1(i,MAXn-1)two[i]=add(two[i-1],two[i-1]);
    ll n,m,k;
    cin>>n>>m>>k;
    REP1(i,n)cin>>d[i];
    REP(i,k)cin>>dt[i];
    REP(i,m)
    {
      ll a,b;
      cin>>a>>b;
      v[a].pb(b);
      v[b].pb(a);
    }
    REP1(i,n)a[i]=1;
    REP(i,k)
    {
      ll t=dt[i];
      ct[t]++;
      for(ll x:v[t])
      {
        b[x]=b[x]*two[ct[x]]%MOD;
        b[x]=add(b[x],a[x]);
        a[x]=a[x]*two[ct[x]]%MOD;
        u[x]=1;
      }
      REP1(i,n)debug(ct[i],a[i],b[i],u[i]);
    }
    ll tt=0;
    REP1(i,n)
    {
      if(u[i]&&!ct[i]){cout<<-1<<endl;return 0;}
      if(!u[i])continue;
      ll tmp=pw(a[i]*add(two[ct[i]],-1)%MOD,MOD-2);
      tmp=tmp*b[i]%MOD*two[ct[i]]%MOD;
      tt=add(tt,tmp*d[i]%MOD);
    }
    cout<<tt<<endl;
}
