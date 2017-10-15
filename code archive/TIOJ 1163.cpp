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


const ll MAXn=5e4+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);


ll n,m;
struct edge{ll a,b,c;};
vector<edge> e;

ll g[MAXn];
unordered_set<ll> st[MAXn];
ll fd(ll a){return g[a]=(g[a]==a?a:fd(g[a]));}
ll ans[MAXn];

void mg(ll a,ll b,ll c)
{
  a=fd(a);b=fd(b);
  if(a==b)return;
  if(SZ(st[a])>SZ(st[b]))swap(a,b);
  g[a]=b;
  for(ll tmp:st[a])
  {
    if(st[b].count(tmp))
    {
      st[b].erase(tmp);
      ans[tmp]=c;
    }
    else st[b].insert(tmp);
  }
  st[a].clear();
}



int main()
{
    IOS();
    cin>>n>>m;
    REP(i,m)
    {
      ll a,b,c;
      cin>>a>>b>>c;
      edge tmp;
      tmp.a=a;tmp.b=b;tmp.c=c;
      e.pb(tmp);
    }
    sort(ALL(e),[](const edge &a,const edge &b){return a.c<b.c;});

    REP1(i,n)g[i]=i;

    FILL(ans,-1);

    ll q;
    cin>>q;
    REP(i,q)
    {
      ll a,b;
      cin>>a>>b;
      if(a==b)ans[i]=0;
      else st[a].insert(i);st[b].insert(i);
    }

    for(edge &tmp:e)
    {
      mg(tmp.a,tmp.b,tmp.c);
    }
    REP(i,q)cout<<ans[i]<<endl;

}
