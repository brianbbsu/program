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


const ll MAXn=1e4+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);
const ll M=26;

int tri[MAXn][M],triit=0,p[MAXn],pc[MAXn],f[MAXn],fg[MAXn],dp[105][MAXn],rt;
int gt(int pi,int pci)
{
  int t=triit++;
  REP(i,M)tri[t][i]=-1;
  p[t]=pi;pc[t]=pci;fg[t]=0;f[t]=0;
  return t;
}

void dfs(ll now)
{
  debug(now,p[now],(char)(pc[now]+'a'),f[now],fg[now]);
  REP(i,M)if(tri[now][i]!=-1)dfs(tri[now][i]);
  debug("exit",now);
}
 void add(int &a,int b)
{
  a+=b;
  if(a>=MOD)a-=MOD;
}

int main()
{
    IOS();
    ll T;
    cin>>T;
    while(T--)
    {
      ll n,m;
      cin>>n>>m;
      triit=0;
      rt=gt(0,-1);
      REP(i,m)
      {
        string s;
        cin>>s;
        for(char &c:s)c-='a';
        int now=rt;
        for(char c:s)
        {
          if(tri[now][c]==-1)tri[now][c]=gt(now,c);
          now=tri[now][c];
        }
        fg[now]=1;
      }
      queue<ll> q;
      q.push(rt);
      while(SZ(q))
      {
        ll t=q.front();q.pop();
        ll now=p[t];
        while(now!=0)
        {
          now=f[now];
          if(tri[now][pc[t]]!=-1)
          {
            f[t]=tri[now][pc[t]];
            break;
          }
        }
        if(fg[f[t]])fg[t]=1;
        REP(i,M)
        {
          if(tri[t][i]!=-1){
            q.push(tri[t][i]);
            if(fg[t])fg[tri[t][i]]=1;
          }
          else tri[t][i]=tri[f[t]][i];
          if(tri[t][i]==-1)tri[t][i]=0;
        }
      }
      REP(j,n+1)REP(i,triit)dp[j][i]=0;
      dp[0][0]=1;
      REP(i,n)REP(j,triit)if(!fg[j])REP(k,M)add(dp[i+1][tri[j][k]],dp[i][j]);
      int tt=0;
      REP(i,triit)if(!fg[i])add(tt,dp[n][i]);
      cout<<tt<<endl;
    }
}
