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

ll sum(ll x)
{
  if(x < 10)return x;
  ll tt = 0;
  while(x)
  {
    tt += x % 10;
    x /= 10;
  }
  return tt;
}

ii cal(ll a,ll b)
{
  ll mn = 10, mnct = 0,ct = 0;
  REP(i,20)
  {
    ll tmp = a,tmpct = 0;
    while(tmp >= 10)
    {
      tmpct ++;
      tmp = sum(tmp);
    }
    //if(tmp == mn)break;
    if(ii(tmp,ct + tmpct) < ii(mn, mnct))mn = tmp,mnct = ct + tmpct;
    a += b;
    ct ++;
  }
  return ii(mn,mnct);
}

int main()
{
    IOS();
    ll T;
    cin>>T;
    while(T--)
    {
      ll a,b;
      cin>>a>>b;
      ii ans = ii(10,-1);
      REP(i,20)
      {
        ii p = cal(a,b);
        ii q = cal(sum(a),b);
        ans = min(ans,ii(p.X,p.Y + i));
        ans = min(ans,ii(q.X,q.Y + i + 1));
        a += b;
      }
      cout<<ans.X<<" "<<ans.Y<<endl;
    }
}
