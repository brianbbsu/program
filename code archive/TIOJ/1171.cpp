//{
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<int,int> ii;
#define REP(i,n) for(int i=0;i<n;i++)
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

inline int input()
{
    char c;
    int x=0;
    do{
        c = getchar();
    }while(c<'0' || c>'9');
    do{
      x = x*10+c-'0';
        c = getchar();
    }while(c>='0' && c<='9');
    return x;
}

vector<ii> v[MAXn];
bool vis[MAXn],dt[MAXn];
int sz[MAXn],lv[MAXn],p[MAXn],cnt[MAXn];
ll dis[MAXn][MAXlg],tt[MAXn];

int fdcentro(int now,int f,ll disi,int szi,int pi,int lvi)
{
  p[now]=pi;
  dis[now][lvi]=disi;
  int rt=-1,mxsz=0;
  sz[now]=1;
  for(ii &k:v[now])
  {
    if(k.X==f||vis[k.X])continue;
    int t=fdcentro(k.X,now,disi+k.Y,szi,pi,lvi);
    sz[now]+=sz[k.X];
    mxsz=max(mxsz,sz[k.X]);
    if(t!=-1)rt=t;
  }
  mxsz=max(mxsz,szi-sz[now]);
  if(mxsz*2<=szi)rt=now;
  return rt;
}
int szdfs(int now,int f){
  int rt=1;
  for(ii &k:v[now])if(!vis[k.X]&&k.X!=f)rt+=szdfs(k.X,now);
  return rt;
}
void centro_decompose(int now,int lvi)
{
  lv[now]=lvi;vis[now]=1;
  for(ii &k:v[now])if(!vis[k.X])centro_decompose(fdcentro(k.X,now,k.Y,szdfs(k.X,now),now,lvi),lvi+1);
}
void ins(int x)
{
  if(dt[x])return;else dt[x]=1;
  for(int i=lv[x],now=x;i>=0;i--,now=p[now]){cnt[now]++,tt[now]+=dis[x][i];if(i!=0)tt[now]-=dis[x][i-1];}
}
ll qr(int x)
{
  ll rt=0,dcnt=0;
  for(int i=lv[x],now=x;i>=0;i--,now=p[now]){rt+=tt[now]+(cnt[now]-dcnt)*dis[x][i];dcnt=cnt[now];}
  return rt;
}
int main()
{
    IOS();
    int n,q;
    n=input();
    q=input();

    REP(i,n-1)
    {
      int a,b,c;
      a=input();
      b=input();
      c=input();
      v[a].pb(ii(b,c));
      v[b].pb(ii(a,c));
    }
    int st=fdcentro(0,-1,0,n,-1,0);
    dis[st][0]=0;
    centro_decompose(st,0);
    #ifdef brian
    pary(lv,lv+n);
    pary(p,p+n);
    REP(i,n)
    {
      debug(i);
      pary(dis[i],dis[i]+__lg(n)+1);
    }
    #endif
    REP(i,q)
    {
      int t,x;
      t=input();
      x=input();
      if(t==1)ins(x);
      else cout<<qr(x)<<endl;
    }
}
