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


const ll MAXn=1e6+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

//priority_queue<ii> pq;
vector<ii> qu;
ll d[MAXn];
vector<ll> ans;
ll k,p,q;

inline void add(ll x)
{
  if(d[x]==0)return;
  if(x==q)qu.pb(ii(d[x],x+k));
  else qu.pb(ii(d[x],x));
  push_heap(ALL(qu));
}



int main()
{
    //IOS();
    qu.reserve(MAXn);
    ans.reserve(MAXn);
    scanf("%d%d%d",&k,&p,&q);
    REP1(i,k)scanf("%d",d+i);
    ll tt=0;
    REP1(i,k)tt+=d[i];
    if(tt==1)
    {
      if(p==q&&d[p]==1)printf("%d",p);
      else puts("0");
      return 0;
    }
    REP1(i,k)if(2*d[i]-1>tt){puts("0");return 0;}
    d[p]--,d[q]--;
    if(d[p]<0||d[q]<0)
    {
      puts("0");
      return 0;
    }
    ans.pb(p);
    REP1(i,k)if(i!=p)add(i);
    while(1)
    {
      if(SZ(ans)>=2)add(ans[SZ(ans)-2]);
      if(!SZ(qu))break;
      pop_heap(ALL(qu));
      ii a=qu.back();qu.pop_back();
      if(a.Y>k)a.Y-=k;
      ans.pb(a.Y);
      d[a.Y]--;
    }
    if(ans.back()==q)
    {
      puts("0");
      return 0;
    }
    ans.pb(q);
    if(SZ(ans)!=tt)puts("0");
    else for(ll k:ans)printf("%d ",k);
}
