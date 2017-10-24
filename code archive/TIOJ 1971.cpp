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


const ll MAXn=1e8+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);


bitset<MAXn> b;
ll d[100];
ll vis[(1<<20)];


int main()
{
    IOS();
    ll m,n;
    cin>>m>>n;
    REP(i,n)cin>>d[i];
    if(m<=100000000)
    {
      b.reset();
      ll tt=0;
      REP(i,m+1)
      {
        if(b[i])tt++;
        else REP(j,n)if(i+d[j]<=m)b[i+d[j]]=1;
      }
      cout<<tt<<endl;
    }
    else
    {
      FILL(vis,-1);
      REP(i,20)REP(j,n)if(i-d[j]>=0&&!b[i-d[j]])b[i]=1;
      ll l,r;
      for(int i=20;;i++)
      {
        ll t=0;
        REP1(j,20)
        {
          t<<=1;
          t+=b[i-j];
        }
        debug(i,bitset<20>(t));
        if(vis[t]!=-1)
        {
          r=i;l=vis[t];
          break;
        }
        else vis[t]=i;
        REP(j,n)if(!b[i-d[j]])b[i]=1;
      }
      debug(l,r);
      if(m<l)
      {
        ll tt=0;
        REP(i,m+1)if(b[i])tt++;
        cout<<tt<<endl;
      }
      else
      {
        ll c=(m+1-l)/(r-l),x=(m+1-l)%(r-l);
        ll tt=0;
        for(int i=l;i<r;i++)tt+=b[i];
        tt*=c;
        REP(i,x)tt+=b[l+i];
        REP(i,l)if(b[i])tt++;
        cout<<tt<<endl;
      }
    }
}
