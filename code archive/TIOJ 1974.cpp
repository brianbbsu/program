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

struct box{ll l,r,d,u,w;} d[MAXn];
vector<ll> unix,uniy;

struct node{
  ll l,r;
  node *lc,*rc;
  ll mx,tt;
  void pull(){mx=max(lc->mx+lc->tt,rc->mx+rc->tt);}
  void ins(ll li,ll ri,ll k)
  {
    if(li>=r||ri<=l)return;
    else if(li<=l&&ri>=r)tt+=k;
    else
    {
      lc->ins(li,ri,k);rc->ins(li,ri,k);
      pull();
    }
    //debug(l,r,tt,mx);
  }
};
node *build(ll l,ll r)
{
  if(l==r-1)return new node{l,r,0,0,0,0};
  else return new node{l,r,build(l,(l+r)/2),build((l+r)/2,r),0,0};
}
node *rt;
struct tg{ll x,id,tp;};
vector<tg> dt;

int main()
{
    IOS();
    ll n;
    cin>>n;
    REP(i,n)
    {
      cin>>d[i].l>>d[i].d>>d[i].r>>d[i].u>>d[i].w;
      d[i].r++;d[i].u++;
      unix.pb(d[i].l);unix.pb(d[i].r);
      uniy.pb(d[i].d);uniy.pb(d[i].u);
    }

    sort(ALL(unix));
    unix.resize(unique(ALL(unix))-unix.begin());
    REP(i,n)d[i].l=lower_bound(ALL(unix),d[i].l)-unix.begin(),
              d[i].r=lower_bound(ALL(unix),d[i].r)-unix.begin();

    sort(ALL(uniy));
    uniy.resize(unique(ALL(uniy))-uniy.begin());
    REP(i,n)d[i].d=lower_bound(ALL(uniy),d[i].d)-uniy.begin(),
              d[i].u=lower_bound(ALL(uniy),d[i].u)-uniy.begin();

    rt=build(0,SZ(uniy)+2);
    REP(i,n)rt->ins(d[i].d,d[i].u,d[i].w);
    REP(i,n)dt.pb({d[i].l,i,1}),dt.pb({d[i].r,i,-1});
    sort(ALL(dt),[](tg a,tg b){return a.x<b.x;});

    debug(rt->tt+rt->mx);

    ll it=0,mx=0,tmp=0;
    while(it<SZ(dt))
    {
      ll x=dt[it].x;
      while(it<SZ(dt)&&dt[it].x==x)
      {
        auto t=dt[it];
        rt->ins(d[t.id].d,d[t.id].u,t.tp*-1*d[t.id].w);
        tmp+=t.tp*d[t.id].w;
        it++;
      }
      debug(x,rt->tt+rt->mx,tmp);
      mx=max(mx,rt->tt+rt->mx+tmp);
    }
    cout<<mx<<endl;
}
