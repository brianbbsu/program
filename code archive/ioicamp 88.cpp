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

const ll bs[2]={880301,876543};

ll pw[2][MAXn];

struct h{
  ll h[2],l;
};
struct hs{
  size_t operator () (const h &a)const{
      return a.h[0];
  }
};
h operator -  (const h &a,const h &b)
{
  h rt={0,0,a.l-b.l};
  REP(i,1)rt.h[i]=(a.h[i]-b.h[i]*pw[i][rt.l]%MOD+MOD)%MOD;
  return rt;
}
h operator +  (const h &a,char c)
{
  h rt={0,0,a.l+1};
  REP(i,1)rt.h[i]=(a.h[i]*bs[i]+c)%MOD;
  return rt;
}
bool operator == (const h &a,const h &b)
{
  REP(i,1)if(a.h[i]!=b.h[i])return 0;
  return a.l==b.l;
}

h d[2][MAXn],rd[2][MAXn];

h grd(ll i,ll n,ll s,ll l)//idx1
{
  return rd[i][n-s+1]-rd[i][n-s-l+1];
}

int main()
{
    IOS();
    REP(i,2)
    {
      pw[i][0]=1;
      REP1(j,MAXn-1)pw[i][j]=pw[i][j-1]*bs[i]%MOD;
    }
    string s[2];
    ll T;
    cin>>T;
    while(T--&&cin>>s[0]>>s[1])
    {
      REP(i,2)
      {
        d[i][0]=rd[i][0]=(h){0,0,0};
        REP1(j,SZ(s[i]))d[i][j]=d[i][j-1]+s[i][j-1],rd[i][j]=rd[i][j-1]+s[i][SZ(s[i])-j];
      }/*
      REP(i,2)
      {
        REP1(k,SZ(s[i]))REP(j,k)
        {
          if(d[i][k]-d[i][j]==grd(i,SZ(s[i]),j+1,k-j))debug(s[i].substr(j,k-j));
        }
      }*/
      ll mx[2],l,r;
      l=0,r=min(SZ(s[0]),SZ(s[1]))/2+1;
      while(l!=r-1)
      {
        ll t=2*((l+r)/2);
        unordered_set<h,hs> st;
        st.reserve(SZ(s[0]));
        REP(i,SZ(s[0])-t+1)
        {
          h a=d[0][i+t]-d[0][i],b=grd(0,SZ(s[0]),i+1,t);
          if(a==b)st.insert(a);
        }
        bool ok=0;
        REP(i,SZ(s[1])-t+1)
        {
          h a=d[1][i+t]-d[1][i],b=grd(1,SZ(s[1]),i+1,t);
          if(a==b&&st.count(a))ok=1;
        }
        if(ok)l=(l+r)/2;
        else r=(l+r)/2;
      }
      debug(l*2);
      mx[0]=l*2;
      l=0,r=min(SZ(s[0]),SZ(s[1]))/2+1;
      while(l!=r-1)
      {
        ll t=2*((l+r)/2)-1;
        unordered_set<h,hs> st;
        st.reserve(SZ(s[0]));
        REP(i,SZ(s[0])-t+1)
        {
          h a=d[0][i+t]-d[0][i],b=grd(0,SZ(s[0]),i+1,t);
          if(a==b)st.insert(a);
        }
        bool ok=0;
        REP(i,SZ(s[1])-t+1)
        {
          h a=d[1][i+t]-d[1][i],b=grd(1,SZ(s[1]),i+1,t);
          if(a==b&&st.count(a))ok=1;
        }
        if(ok)l=(l+r)/2;
        else r=(l+r)/2;
      }
      debug(2*l-1);
      mx[1]=2*l-1;
      cout<<max(mx[0],mx[1])<<endl;
    }
}
