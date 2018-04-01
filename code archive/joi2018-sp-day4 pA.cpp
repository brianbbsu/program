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
template<typename _a,typename _b> ostream &operator << (ostream &_s,const map<_a,_b> &_c){return _OUTC(_s,ALL(_c));}
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

map<ii,vector<ll> > mp;

vector<ll> mg(vector<ll> l,vector<ll> r)
{
  vector<ll> rt;
  debug(l,r,rt);
  for(int i=SZ(l)-1;i>0;i--)l[i]-=l[i-1];
  for(int i=SZ(r)-1;i>0;i--)r[i]-=r[i-1];
  rt.resize(SZ(l)+SZ(r));
  merge(ALL(l),ALL(r),rt.begin(),greater<ll>());
  REP1(i,SZ(rt)-1)rt[i]+=rt[i-1];
  return rt;
}

ll d[MAXn];

void dfs(ll l,ll r)
{
  if(mp.count(ii(l,r)))return;
  vector<ll> &v = mp[ii(l,r)];
  if(l==r)return;
  else if(l==r-1)
  {
    v.pb(d[l]);
    return;
  }
  ll h=(l+r)/2;
  dfs(l,h);dfs(h,r);
  dfs(l,h-1);dfs(h+1,r);
  v = mg(mp[ii(l,h)],mp[ii(h+1,r)]);
  vector<ll> tmp = mg(mp[ii(l,h-1)],mp[ii(h,r)]);
  debug(l,r,h,v,tmp);
  if(SZ(tmp)>SZ(v))v.swap(tmp);
  REP(i,SZ(tmp))v[i]=max(v[i],tmp[i]);
}

int main()
{
    IOS();
    ll n;
    cin>>n;
    REP(i,n)cin>>d[i];
    dfs(0,n);
    debug(mp);
    vector<ll> &ans = mp[ii(0,n)];
    //debug(ans);
    assert(SZ(ans)==(n-1)/2+1);
    REP(i,SZ(ans))cout<<ans[i]<<endl;
}
