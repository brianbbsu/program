//{
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<string>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<sstream>
#include<cmath>

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

string nm[MAXn];

ll g[MAXn];
ll fd(ll a){return g[a]=(g[a]==a?a:fd(g[a]));}
void mg(ll a,ll b){g[fd(a)]=fd(b);}

struct e{
  ll a,b,c;
  e(ll ai=0,ll bi=0,ll ci=0){
    if(ai>bi)swap(ai,bi);
    a=ai;b=bi;c=ci;
  }
  bool operator < (const e t)const{
    return make_pair(c,ii(a,b))<make_pair(t.c,ii(t.a,t.b));
  }
};

vector<e> dt;
map<string,ll> mp;

vector<ii> ans;
ll tt=0;

int main()
{
    IOS();
    ll n,m;
    cin>>n>>m;
    REP(i,n)
    {
      cin>>nm[i];
      mp[nm[i]]=i;
    }
    REP(i,m)
    {
        string a,b;
        ll c;
        cin>>a>>b>>c;
        dt.pb(e(mp[a],mp[b],c));
    }
    REP(i,n)g[i]=i;
    sort(ALL(dt));
    REP(i,m)
    {
      if(fd(dt[i].a)!=fd(dt[i].b))
      {
        mg(dt[i].a,dt[i].b);
        tt+=dt[i].c;
        ans.pb(ii(dt[i].a,dt[i].b));
      }
    }
    sort(ALL(ans));
    REP(i,SZ(ans))cout<<"("<<nm[ans[i].X]<<" "<<nm[ans[i].Y]<<")";
    cout<<endl<<tt<<endl;;
}
