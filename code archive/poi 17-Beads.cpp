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
const ll MOD=1000000087,bs=880301,ibs=728591761;
const ll INF=ll(1e15);

ll d[MAXn],pw[MAXn],ipw[MAXn],hs[MAXn],rhs[MAXn];

set<ll> st;
vector<ll> mxdt;
ll mx=0;

int main()
{
    IOS();
    //for(ll i=1;i<MOD;i++)if(i*bs%MOD==1)debug(i);
    pw[0]=ipw[0]=1;
    REP1(i,MAXn-1)pw[i]=pw[i-1]*bs%MOD;//,ipw[i]=ipw[i-1]*ibs%MOD,assert(pw[i]*ipw[i]%MOD==1);
    ll n;cin>>n;
    REP1(i,n)cin>>d[i];
    hs[0]=0;
    REP1(i,n)hs[i]=(hs[i-1]*bs+d[i])%MOD;
    for(int i=n;i>0;i--)rhs[i]=(rhs[i+1]*bs+d[i])%MOD;
    REP1(i,n)
    {
      ll tt=0;
      st.clear();
      for(int j=0;(j+1)*i<=n;j++)
      {
        ll t=(i*j+1);
        ll tmp=(hs[t+i-1]-hs[t-1]*pw[i]%MOD)%MOD,rtmp=(rhs[t]-rhs[t+i]*pw[i]%MOD)%MOD;
        tmp=(tmp+MOD)%MOD;rtmp=(rtmp+MOD)%MOD;
        bool a=st.insert(tmp).Y,b=st.insert(rtmp).Y;
        if(a||b)tt++;
      }
      if(tt>mx)
      {
        mx=tt;mxdt.clear();
      }
      if(tt>=mx)mxdt.pb(i);
      debug(st);
    }
    cout<<mx<<" "<<SZ(mxdt)<<endl;
    REP(i,SZ(mxdt))cout<<mxdt[i]<<" \n"[i==SZ(mxdt)-1];
}
