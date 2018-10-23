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


const ll MAXn=2e7+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll n;
ll cnt[MAXn];
ll pdt[MAXn];
ll dt[MAXn];//dt[2][MAXn];
ll rk[MAXn],tmprk[MAXn];
ll ans[MAXn];


inline bool diff(ll a,ll b,ll l)
{
  return (rk[a]!=rk[b]||a+l>=n||b+l>=n||rk[a+l]!=rk[b+l]);
}

char s[MAXn];
int main()
{
    //IOS();

    fgets(s,MAXn,stdin);
    //s.append(0);
    n=strlen(s)-1;
    REP(i,n)rk[i]=s[i];
    int sigma=128;

    for(int l=1;l<n;l*=2)
    {
      memset(cnt,0,sizeof(int)*sigma);
      REP(i,n-l)cnt[rk[i+l]]++;
                cnt[0]+=l;
      partial_sum(cnt,cnt+sigma,cnt);
      REP(i,n-l)pdt[--cnt[rk[i+l]]]=i;
      REP(i,l)pdt[i]=n-l+i;

      memset(cnt,0,sizeof(int)*sigma);
      REP(i,n)cnt[rk[i]]++;
      partial_sum(cnt,cnt+sigma,cnt);
      for(int i=n-1;i>=0;i--)dt[--cnt[rk[pdt[i]]]]=pdt[i];
      tmprk[0]=0;
      REP1(i,n-1)tmprk[i]=tmprk[i-1]+diff(dt[i-1],dt[i],l);
      REP(i,n)rk[dt[i]]=tmprk[i];
      sigma=tmprk[n-1]+1;
      if(sigma==n)break;
    }

    REP(i,n)ans[rk[i]]=i;
    REP(i,n)printf("%d\n",ans[i]);
}
