//{
#include<bits/stdc++.h>
using namespace std;
typedef int ll;
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
const ll INF=ll(1e9);

const ll K = 250;

int vis[MAXn];

void add(vector<ii> &a,vector<ii> &b)
{
  vector<ii> tmp;
  tmp.resize(SZ(a)+SZ(b));
  merge(ALL(a),ALL(b),tmp.begin(),greater<ii>());
  a.clear();
  for(ii &p:tmp)if(!vis[p.Y])vis[p.Y]=1,a.pb(p);
  for(ii &p:a)vis[p.Y]=0;
  a.resize(min(SZ(a),K));
}

vector<ii> dt[MAXn];
vector<ll> v[MAXn];
ll h[MAXn],qr[MAXn],frb[MAXn];

int main()
{
    IOS();
    ll n,m,q;
    cin>>n>>m>>q;
    REP(i,m)
    {
      ll a,b;cin>>a>>b;
      v[a].pb(b);
    }

    REP1(i,n)dt[i].pb(ii(-1,i));
    REP1(i,n)
    {
      for(ii &p:dt[i])p.X++;
      for(ll k:v[i])add(dt[k],dt[i]);
    }
    while(q--)
    {
      ll f,ct;
      cin>>f>>ct;
      REP(i,ct)cin>>qr[i];
      if(ct<K)
      {
        REP(i,ct)frb[qr[i]]=1;
        ll ans=-1;
        for(ii &p:dt[f])if(!frb[p.Y]){ans=p.X;break;}
        cout<<ans<<endl;
        REP(i,ct)frb[qr[i]]=0;
      }
      else
      {
        REP1(i,n)h[i]=-INF;
        h[f]=0;
        for(int i=n;i>0;i--)for(ll k:v[i])h[i]=max(h[i],h[k]+1);
        REP(i,ct)h[qr[i]]=-INF;
        ll mx=*max_element(h+1,h+1+n);
        if(mx>=0)cout<<mx<<endl;
        else cout<<-1<<endl;
      }
    }
}
