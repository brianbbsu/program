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


ll a[MAXn],b[MAXn],c[MAXn];
ll p,q,r;
ll prec[MAXn],cb[MAXn],suby[MAXn],ss[MAXn];

int main()
{
    IOS();
    ll T;
    cin>>T;
    while(T--&&cin>>p>>q>>r)
    {
      REP(i,p)cin>>a[i];
      REP(i,q)cin>>b[i];
      REP(i,r)cin>>c[i];
      FILL(prec,0);
      FILL(cb,0);
      FILL(suby,0);
      FILL(ss,0);

      sort(a,a+p);
      sort(b,b+q);
      sort(c,c+r);
      prec[0]=c[0];
      REP1(i,r-1)prec[i]=(prec[i-1]+c[i])%MOD;
      for(int i=q-1;i>=0;i--)
      {
        cb[i]=(upper_bound(c,c+r,b[i])-c);
        if(cb[i]>0)ss[i]=(b[i]*cb[i]+prec[cb[i]-1])%MOD;
        suby[i]=(ss[i]*b[i]+suby[i+1])%MOD;
        cb[i]=(cb[i]+cb[i+1])%MOD;
        ss[i]=(ss[i]+ss[i+1])%MOD;
      }
      ll ans=0;
      REP(i,p)
      {
        ll t=lower_bound(b,b+q,a[i])-b;
        ans=(ans+suby[t]+a[i]%MOD*ss[t])%MOD;
        debug(ans);
      }
      pary(cb,cb+q);
      pary(suby,suby+q);
      pary(ss,ss+q);
      cout<<ans<<endl;
    }
}
