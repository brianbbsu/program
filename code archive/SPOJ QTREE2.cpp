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

vector<ii> v[MAXn];
ll st[MAXn][MAXlg],dis[MAXn][MAXlg],dph[MAXn];

void dfs(ll now,ll f)
{
  for(ii k:v[now])if(k.X!=f)
  {
    st[k.X][0]=now;
    dis[k.X][0]=k.Y;
    dph[k.X]=dph[now]+1;
    dfs(k.X,now);
  }
}

ii lca(ll a,ll b)// pair(lca,dis)
{
  if(dph[a]<dph[b])swap(a,b);
  ll tt=0;
  for(ll i=MAXlg-1;i>=0;i--)if(dph[st[a][i]]>=dph[b])tt+=dis[a][i],a=st[a][i];
  if(a==b)return ii(a,tt);
  for(ll i=MAXlg-1;i>=0;i--)if(st[a][i]!=st[b][i])tt+=dis[a][i]+dis[b][i],a=st[a][i],b=st[b][i];
  return ii(st[a][0],tt+dis[a][0]+dis[b][0]);

}

int main()
{
    IOS();
    ll T;
    cin>>T;
    while(T--)
    {
      ll n;
      cin>>n;
      REP1(i,n)v[i].clear();
      REP(i,n-1)
      {
        ll a,b,c;
        cin>>a>>b>>c;
        v[a].pb(ii(b,c));
        v[b].pb(ii(a,c));
      }
      dph[1]=0;
      dis[1][0]=0;
      st[1][0]=1;
      dfs(1,-1);
      REP1(j,MAXlg-1)REP1(i,n)st[i][j]=st[st[i][j-1]][j-1],dis[i][j]=dis[i][j-1]+dis[st[i][j-1]][j-1];
      string s;
      while(cin>>s)
      {
        if(s=="DONE")break;
        else if(s=="DIST")
        {
          ll a,b;
          cin>>a>>b;
          ii tmp=lca(a,b);
          cout<<tmp.Y<<endl;
        }
        else
        {
          ll a,b,k;
          cin>>a>>b>>k;
          ii tmp=lca(a,b);
          if(dph[a]-dph[tmp.X]+1>=k)
          {
            k--;
            REP(i,MAXlg)if((1<<i)&k)a=st[a][i];
            cout<<a<<endl;
          }
          else
          {
            k=k-(dph[a]-dph[tmp.X]+1);
            k=(dph[b]-dph[tmp.X])-k;
            REP(i,MAXlg)if((1<<i)&k)b=st[b][i];
            cout<<b<<endl;
          }
        }
      }
      cout<<endl;
    }

}
