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


const ll MAXn=5e2+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

struct MovingByPoints{
    vector<ii> d;
    ll g[MAXn];
    ll fd(ll x){return g[x] = (g[x] == x?x:fd(g[x]));}
    void mg(ll a,ll b)
    {
      a = fd(a);b=fd(b);
      g[a] = b;
    }
    map<ii,ll> mp;
    ll mat[MAXn][MAXn];
    ll dis[MAXn];
    int countMinimumPoints(int n, vector <int> X, vector <int> Y){
      REP(i,n)d.pb({X[i],Y[i]});
      REP(i,n)
      {
        if(!mp.count(d[i]))g[i] = i,mp[d[i]] = i;
        else g[i] = g[mp[d[i]]];
      }
      REP(i,n)
      {
        if(mp.count(ii(d[i].X,d[i].Y+1)))mg(i,mp[ii(d[i].X,d[i].Y+1)]);
        if(mp.count(ii(d[i].X+1,d[i].Y)))mg(i,mp[ii(d[i].X+1,d[i].Y)]);
      }
      REP(i,n)REP(j,n)
      {
        if(fd(i) == fd(j))mat[i][j] = 0;
        else mat[i][j] = abs(d[i].X - d[j].X) + abs(d[i].Y - d[j].Y) - 1;
      }
      REP(i,n)dis[i] = INF;
      dis[0] = 0;
      REP(k,n)REP(i,n)REP(j,n)if(i!=j)if(dis[i] + mat[i][j] < dis[j])dis[j] = dis[i] + mat[i][j];
      //debug(mp);
      //pary(dis,dis+n);
      return dis[n-1];
    }
};

#ifdef brian
int main()
{
    IOS();
    MovingByPoints test;
    debug(test.countMinimumPoints(2,{2,2},{2,2}));
}
#endif
