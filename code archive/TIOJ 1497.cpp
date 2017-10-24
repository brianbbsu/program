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

ll d[MAXn];
ll n;
ll cnt[MAXn];
ll dt[2][MAXn];
ll rk[MAXn],tmprk[MAXn];
ll ans[MAXn];


bool diff(ll a,ll b,ll l)
{
  return (rk[a]!=rk[b]||a+l>=n||b+l>=n||rk[a+l]!=rk[b+l]);
}

int main()
{
    IOS();
    vector<char> uni;
    string s;
    getline(cin,s);
    n=SZ(s);
    REP(i,n)uni.pb(s[i]);
    sort(ALL(uni));
    uni.resize(unique(ALL(uni))-uni.begin());
    REP(i,n)d[i]=lower_bound(ALL(uni),s[i])-uni.begin()+1;
    REP(i,n)rk[i]=d[i];
    for(int l=1;l<n;l*=2)
    {
      REP(i,n+1)cnt[i]=0;
      REP(i,n)cnt[(i+l<n?rk[i+l]:0)]++;
      partial_sum(cnt,cnt+n+1,cnt);
      REP(i,n)dt[0][--cnt[(i+l<n?rk[i+l]:0)]]=i;

      REP(i,n+1)cnt[i]=0;
      REP(i,n)cnt[rk[i]]++;
      partial_sum(cnt,cnt+n+1,cnt);
      for(int i=n-1;i>=0;i--)dt[1][--cnt[rk[dt[0][i]]]]=dt[0][i];
      tmprk[0]=1;
      REP1(i,n-1)tmprk[i]=tmprk[i-1]+diff(dt[1][i-1],dt[1][i],l);
      REP(i,n)rk[dt[1][i]]=tmprk[i];
    }

    REP(i,n)ans[rk[i]-1]=i;
    REP(i,n)cout<<ans[i]<<endl;
}
