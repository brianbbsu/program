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


const ll MAXn=5e4+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll d[MAXn];

struct chtg{ll t,id,x,y;};

vector<chtg> ch;

int l[MAXn],r[MAXn],ct[1000005],tt=0,ans[MAXn];
vector<ll> dt;

void ins(ll x)
{
  x=d[x];
  debug("ins",x);
  if(ct[x]==0)tt++;
  ct[x]++;
}
void rm(ll x)
{
  x=d[x];
  debug("rm",x);
  if(ct[x]==1)tt--;
  ct[x]--;
}

int main()
{
    IOS();
    ll n,q;
    cin>>n>>q;
    REP(i,n)cin>>d[i];
    REP(i,q)
    {
      char tp;
      ll a,b;
      cin>>tp>>a>>b;
      if(tp=='Q')l[i]=a,r[i]=b,dt.pb(i);
      else ch.pb((chtg){i,a,d[a],b}),d[a]=b;
    }
    for(auto tmp:ch)debug(tmp.t,tmp.id,tmp.x,tmp.y);
    ll K = max((int)pow(n,0.6666),1);
    auto crt = [=](int x){return make_tuple(l[x]/K,r[x]/K,x);};
    sort(ALL(dt),[=](int a,int b){return crt(a)<crt(b);});
    int itl=0,itr=0,itt=SZ(ch);
    debug(itt);
    for(ll t:dt)
    {
      while(itr<r[t])ins(itr++);
      while(itr>r[t])rm(--itr);
      while(itl<l[t])rm(itl++);
      while(itl>l[t])ins(--itl);
      while(itt<SZ(ch)&&ch[itt].t<t)
      {
        chtg &c=ch[itt];
        if(c.id>=l[t]&&c.id<r[t])rm(c.id),d[c.id]=c.y,ins(c.id);
        else d[c.id]=c.y;
        itt++;
      }
      while(itt&&ch[itt-1].t>t)
      {
        chtg &c=ch[itt-1];
        if(c.id>=l[t]&&c.id<r[t])rm(c.id),d[c.id]=c.x,ins(c.id);
        else d[c.id]=c.x;
        itt--;
      }
      debug(t,tt,itl,itr,itt);
      pary(d+1,d+1+n);
      ans[t]=tt;
    }
    sort(ALL(dt));
    for(ll t:dt)cout<<ans[t]<<endl;
}
