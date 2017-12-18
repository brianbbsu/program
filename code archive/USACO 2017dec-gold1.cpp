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

string _taskname;
void _init()
{
  #ifndef brian
      freopen((_taskname+".in").c_str(), "r", stdin);
      freopen((_taskname+".out").c_str(),"w",stdout);
  #endif
}
void _end()
{
  #ifndef brian
      fclose( stdin);
      fclose(stdout);
  #endif
}

ll dis[MAXn],b[MAXn],e[MAXn];
set<ii> stb,ste;

int main()
{
  _taskname = "piepie";
  _init();
  ll n,D;
  cin>>n>>D;
  REP(i,2*n)cin>>b[i]>>e[i];
  queue<ll> q;
  FILL(dis,-1);
  REP(i,n)
  {
    if(e[i]==0)dis[i]=1,q.push(i);
    else stb.insert(ii(-e[i],i));
  }
  for(int i=n;i<2*n;i++)
  {
    if(b[i]==0)dis[i]=1,q.push(i);
    else ste.insert(ii(-b[i],i));
  }
  while(SZ(q))
  {
    ll t=q.front();q.pop();debug(t,b[t],e[t],stb,ste);
    auto it=stb.begin();
    if(t<n)
    {
      while((it=ste.lower_bound(ii(-b[t],-1)))!=ste.end()&&it->X+b[t]<=D)
      {
        dis[it->Y]=dis[t]+1;
        q.push(it->Y);
        ste.erase(it);
      }
    }
    else
    {
      while((it=stb.lower_bound(ii(-e[t],-1)))!=stb.end()&&it->X+e[t]<=D)
      {
        dis[it->Y]=dis[t]+1;
        q.push(it->Y);
        stb.erase(it);
      }
    }
  }
  REP(i,n)
  {
    cout<<dis[i]<<endl;
  }
  _end();
}
