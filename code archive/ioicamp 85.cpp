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


int rk[MAXn],sa[MAXn],dt[MAXn],cnt[MAXn],ork[MAXn],h[MAXn];

bool eq(ll a,ll b,ll t,ll n)
{
  return !(ork[a]!=ork[b]||a+t>=n||b+t>=n||ork[a+t]!=ork[b+t]);
}

int main()
{
    IOS();
    ll T;
    cin>>T;
    while(T--)
    {
      string s;
      cin>>s;
      ll n=SZ(s);
      REP(i,n)rk[i]=s[i]-'a';

      for(int k=1;k<n;k*=2)
      {
        REP(i,n)cnt[i]=0;
        cnt[0]=k;
        REP(i,n-k)cnt[rk[i+k]]++;
        partial_sum(cnt,cnt+n,cnt);
        REP(i,n-k)dt[--cnt[rk[i+k]]]=i;
        REP(i,k)dt[i]=n-i-1;

        REP(i,n)cnt[i]=0;
        REP(i,n)cnt[rk[i]]++;
        partial_sum(cnt,cnt+n,cnt);
        for(int i=n-1;i>=0;i--)sa[--cnt[rk[dt[i]]]]=dt[i];
        REP(i,n)ork[i]=rk[i];
        rk[sa[0]]=0;
        REP1(i,n-1)if(eq(sa[i],sa[i-1],k,n))rk[sa[i]]=rk[sa[i-1]];else rk[sa[i]]=rk[sa[i-1]]+1;
        pary(sa,sa+n);
        pary(rk,rk+n);
      }
      debug(123);
      h[0]=0;
      for(int j=0,k=0;j<n;j++)
      {
        if(rk[j])
        {
          while(k<min(n-j,n-sa[rk[j]-1])&&s[sa[rk[j]-1]+k]==s[j+k])k++;
        }
        h[rk[j]]=k;
        k=max(k-1,0);
      }
      REP(i,n)debug(i,s.substr(sa[i]));
      pary(h,h+n);
      ll tt=0;
      REP(i,n)tt+=(n-sa[i]-h[i]);
      cout<<tt<<endl;
    }
}
