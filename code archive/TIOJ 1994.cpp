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
const ll INF=ll(1e15);

int ans[(1<<11)][1<<11];



void dfs(ii a,int l,int r,int rt,int L,bool inv)
{
  //debug(a,l,r,rt,L,inv);
  if(l==r-1)
  {
    ans[a.X][a.Y]=l;
    return;
  }
  if(!inv)
  {
    ll now=rt,dt=((r-l)>>2),t=l;
    int tr[]={0,1,3,2},drt[]={1,0,0,3};
    REP(i,4)
    {
      ii b;
      if(tr[now]&1)b.X=a.X+L;
      else b.X=a.X;
      if(tr[now]&2)b.Y=a.Y+L;
      else b.Y=a.Y;
      dfs(b,t,t+dt,(rt+drt[i])&3,L>>1,(i==0||i==3));
      t+=dt;
      now=(now+1)&3;
    }
  }
  else
  {
    ll now=(rt+3)&3,dt=((r-l)>>2),t=l;
    int tr[]={0,1,3,2},drt[]={3,0,0,1};
    REP(i,4)
    {
      ii b;
      if(tr[now]&1)b.X=a.X+L;
      else b.X=a.X;
      if(tr[now]&2)b.Y=a.Y+L;
      else b.Y=a.Y;
      dfs(b,t,t+dt,(rt+drt[i])&3,L>>1,(i==1||i==2));
      t+=dt;
      now=(now+3)&3;
    }
  }
}


int main()
{
    IOS();
    ll n;
    cin>>n;
    dfs(ii(0,0),0,(1<<(2*n)),0,(1<<(n-1)),0);
    REP(i,(1<<n))
    {
      REP(j,(1<<n))cout<<(j?" ":"")<<ans[i][j];
      cout<<endl;
    }
}
