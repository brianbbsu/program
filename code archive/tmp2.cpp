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

ll d[MAXn],pre[3][MAXn],ans[MAXn];

int main()
{
    IOS();
    ll T;
    cin>>T;
    while(T--)
    {
      ll n;
      cin>>n;
      REP1(i,n)cin>>d[i];
      REP1(i,n+2)REP(j,3)pre[j][i] = 0;
      REP1(i,n)if(d[i] < 0)pre[0][i] += d[i],pre[1][i] += i * d[i],pre[2][i] += (n-i) * d[i];
      REP1(i,n)REP(j,3)pre[j][i] += pre[j][i-1];
      REP1(i,n)if(d[i]>0)
      {
        ll l = 0,r = 10000000;
        while(l != r-1)
        {
          ll h = (l+r)/2;
          ll efl = max(1LL,i - h),efr = min(n, i + h);
          ll tmp = (pre[0][efr] - pre[0][efl - 1]) * h;
          tmp -= (pre[2][i] - pre[2][efl - 1] - (n-(i-1)) * (pre[0][i] - pre[0][efl-1]));
          tmp -= (pre[1][efr] - pre[1][i] - (i+1) * (pre[0][efr] - pre[0][i]));
          if(tmp + d[i] > 0)l = h;
          else r = h;
        }
        ans[i] = l;
      }else ans[i] = -1;
      ll mx = 0,ct = 0;
      REP1(i,n)mx = max(mx,ans[i]);
      REP1(i,n)if(mx == ans[i])ct++;
      cout<<ct;
      REP1(i,n)if(mx == ans[i])cout<<" "<<i;
      cout<<endl;
    }
}
