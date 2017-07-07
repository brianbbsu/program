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


const ll MAXn=3e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e9);

vector<ll> v[MAXn];

int n;
int d[MAXn];

struct tg{
  int dis,id;
  tg(int disi=0,int idi=0):dis(disi),id(idi){}
  const bool operator < (const tg &t)const {return ii(d[id]-dis,-id)<ii(d[t.id]-t.dis,-t.id);}
  const bool operator > (const tg &t)const {return t<(*this);}
  const bool operator == (const tg &t){return (dis==t.dis&&id==t.id);}
  tg operator + (int a){return tg(dis+a,id);}
};
//ostream &operator << (ostream &_ss,tg &t){return _ss<<ii(t.dis,t.id);}

tg mx[MAXn][2],dp[MAXn];

#define max(_a,_b) ((_a)<(_b)?(_b):(_a))
#define min(_a,_b) ((_a)<(_b)?(_a):(_b))

void dfs1(int now,int f)
{
  for(int k:v[now])
  {
    if(k==f)continue;
    dfs1(k,now);
    tg tmp=max(mx[k][0],tg(0,k))+1;
    debug(tmp);
    if(tmp>mx[now][0])mx[now][1]=mx[now][0],mx[now][0]=tmp;
    else if(tmp>mx[now][1])mx[now][1]=tmp;
  }
}
void dfs2(int now,int f,tg bst)
{
    debug(now,bst);
    dp[now]=max(mx[now][0],bst);
    for(int k:v[now])
    {
      if(k==f)continue;
      tg tmp=max(mx[k][0],tg(0,k))+1;
      debug(tmp);
      if(tmp==mx[now][0])tmp=max(max(bst,mx[now][1]),tg(0,now))+1;
      else tmp=max(max(bst,mx[now][0]),tg(0,now))+1;
      dfs2(k,now,tmp);
    }
}
int dt[MAXn],stp[MAXn],tit=-1;
vector<int> st;
int dfs3(int now)
{
  stp[now]=++tit;
  st.pb(now);
  if(stp[dt[now]]==-1)return dfs3(dt[now]);
  else return stp[now]-stp[dt[now]]+1;
}
int main()
{
    IOS();
    ll k;
    cin>>n>>k;
    REP(i,n)cin>>d[i];
    REP(i,n-1)
    {
      ll a,b;
      cin>>a>>b;
      a--;b--;
      v[a].pb(b);
      v[b].pb(a);
    }
    d[n]=0;
    REP(i,n)REP(j,2)mx[i][j]=tg(INF,n);
    dfs1(0,-1);
    dfs2(0,-1,tg(INF,n));
    FILL(stp,-1);
    REP(i,n)dt[i]=dp[i].id;
    pary(dt,dt+n);
    REP(i,n)debug(mx[i][0].id);
    ll tmp=dfs3(0);
    if(k<SZ(st)){cout<<st[k]+1<<endl;return 0;}
    else
    {
      ll p=SZ(st)-tmp;
      k=(k-p)%tmp+p;
      cout<<st[k]+1<<endl;
    }
    debug(st,tmp);
}
