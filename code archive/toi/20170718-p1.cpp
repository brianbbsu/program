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


const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);


vector<ii> dt[2];

ll dis(ii a,ii b)
{
  return (a.X-b.X)*(a.X-b.X)+(a.Y-b.Y)*(a.Y-b.Y);
}

ii vec(ii a,ii b)
{
  return ii(b.X-a.X,b.Y-a.Y);
}

ll cross(ii a,ii b)
{
  return a.X*b.Y-a.Y*b.X;
}

vector<ii> cv[2];
vector<ii> st;

void cal_cv(ll t)
{
  cv[t].clear();
  vector<ii> &tmp=dt[t];

  st.clear();
  for(ii &k:tmp)
  {
    while(SZ(st)>=2)
    {
      ll crs=cross(vec(st[SZ(st)-2],st.back()),vec(st[SZ(st)-2],k));
      if(crs<0||(crs==0&&dis(st[SZ(st)-2],st.back())<=dis(st[SZ(st)-2],k)))st.pop_back();
      else break;
    }
    st.pb(k);
  }
  //debug(st);
  cv[t]=st;

  st.clear();

  for(int i=SZ(tmp)-1;i>=0;i--)
  {
    ii &k=tmp[i];
    while(SZ(st)>=2)
    {
      ll crs=cross(vec(st[SZ(st)-2],st.back()),vec(st[SZ(st)-2],k));
      if(crs<0||(crs==0&&dis(st[SZ(st)-2],st.back())<=dis(st[SZ(st)-2],k)))st.pop_back();
      else break;
    }
    st.pb(k);
  }

  for(int i=1;i<SZ(st);i++)cv[t].pb(st[i]);

}

bool cal(ll a,ll b)
{

    REP(i,SZ(cv[b])-1)
    {
      bool ok=0;
      REP(j,SZ(cv[a])-1)
      {
        if(cross(vec(cv[a][j],cv[a][j+1]),vec(cv[a][j],cv[b][i]))<0){ok=1;break;}
      }
      if(!ok)return 0;
    }

    REP(i,SZ(cv[a])-1)
    {
      REP(j,SZ(cv[b])-1)
      if(cross(vec(cv[a][i],cv[a][i+1]),vec(cv[a][i],cv[b][j]))*cross(vec(cv[a][i],cv[a][i+1]),vec(cv[a][i],cv[b][j+1]))<0&&
         cross(vec(cv[b][j],cv[b][j+1]),vec(cv[b][j],cv[a][i]))*cross(vec(cv[b][j],cv[b][j+1]),vec(cv[b][j],cv[a][i+1]))<0)return 0;
    }


    return 1;
}

bool solve()
{
  ll n;
  cin>>n;
  dt[0].clear();
  dt[1].clear();

  REP(i,n)
  {
    ll x,y,t;
    cin>>x>>y>>t;
    dt[t].pb(ii(x,y));
  }
  if(!SZ(dt[0])||!SZ(dt[1]))return 1;


  REP(k,2)sort(ALL(dt[k]));

  cal_cv(0);
  cal_cv(1);
  //debug(cv[0],cv[1]);

  return cal(0,1)&&cal(1,0);

}

int main()
{
    IOS();
    ll T;
    cin>>T;
    while(T--)
    {
      cout<<solve()<<endl;
    }
}
