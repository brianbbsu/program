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


const ll MAXn=2e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

vector<ll> v[MAXn];
ll dp[MAXn],ct[MAXn];
ll pw[MAXn];

struct tg{
  ll n0,n1,n2,t;
};
#ifdef brian
ostream& operator << (ostream &_s,const tg &_p){return _s<<"("<<_p.n0<<","<<_p.n1<<","<<_p.n2<<","<<_p.t<<")";}
#endif

map<ll,tg> mp[MAXn];// dp -> no/yes

inline void add(ll &a,ll b)
{
  a+=b;
  if(a>=MOD)a-=MOD;
}

tg mg(ll now,tg &a,tg &b)
{
  tg rt={0,0,0,now};
  if(b.t==now)swap(a,b);
  if(a.t!=now)
  {
    add(a.n0,a.n2);
    a.n2=0;
  }
  if(b.t!=now)
  {
    add(b.n0,b.n2);
    b.n2=0;
  }
  rt.n2=(a.n2*(b.n0+b.n1)+a.n1*b.n1)%MOD;
  rt.n1=(a.n1*b.n0+a.n0*b.n1)%MOD;
  rt.n0=(a.n0*b.n0)%MOD;
  return rt;
}

void dfs(ll now)
{
  mp[now][dp[now]]={1,1,0,now};
  for(ll k:v[now])
  {
    dp[k]=dp[now]+1;
    dfs(k);
    if(SZ(mp[k])>SZ(mp[now]))mp[now].swap(mp[k]);
    for(auto tmp:mp[k])
    {
      tg a=tmp.Y;
      auto it=mp[now].insert(tmp);
      tg &b=it.X->Y;
      if(!it.Y)
      {
        b=mg(now,a,b);
      }
      else if(b.t!=now)
      {
        add(b.n0,b.n2);
        b.n2=0;
        b.t=now;
      }
    }
    mp[k].clear();
    debug(now,k,mp[now]);
  }
}

int main()
{
    IOS();
    // E
    pw[0]=1;
    REP1(i,MAXn-1)pw[i]=2*pw[i-1]%MOD;
    ll n;
    cin>>n;
    REP1(i,n)
    {
      ll t;
      cin>>t;
      v[t].pb(i);
    }
    dfs(0);
    REP(i,n+1)ct[dp[i]]++;
    //ways[0]=2;tt[0]=1;
    ll ans=0;

    for(auto tmp:mp[0])
    {
      tg a=tmp.Y;
      ans=(ans+(a.n1)*pw[n+1-ct[tmp.X]])%MOD;
      debug(tmp);
    }
    cout<<ans<<endl;
}
