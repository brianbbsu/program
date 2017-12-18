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

string _taskname;
void _init()
{
  #ifndef brian
      freopen((_taskname+".in").c_str(), "r", stdin);
      freopen((_taskname+".out").c_str(),"w",stdout);
  #endif
}
void _end()
{
  #ifndef brian
      fclose( stdin);
      fclose(stdout);
  #endif
}

struct node{
  ll l,r;
  node *lc,*rc;
  ll mx,tg;
  void ins(ll li,ll ri,ll k)
  {
    if(li>=r||ri<=l)return;
    else if(li<=l&&ri>=r)tg+=k;
    else
    {
      lc->ins(li,ri,k);
      rc->ins(li,ri,k);
      mx=max(lc->mx+lc->tg,rc->mx+rc->tg);
    }
  }
};
node *build(ll l,ll r)
{
  if(l==r-1)return new node{l,r,0,0,0,0};
  else return new node{l,r,build(l,(l+r)/2),build((l+r)/2,r),0,0};
}

ll d[MAXn];

int main()
{
  _taskname = "greedy";
  _init();
  ll n;
  cin>>n;
  node *rt=build(0,n);
  REP(i,n)rt->ins(i,i+1,-i);
  REP1(i,n)cin>>d[i];
  REP1(i,n)
  {
    rt->ins(n-d[i]-1,n,1);
    if(rt->mx+rt->tg>0)
    {
      cout<<n-i<<endl;
      return 0;
    }
  }
  _end();
}
