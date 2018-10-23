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
template<typename _a> ostream &operator << (ostream &_s,multiset<_a> &_c){return _OUTC(_s,ALL(_c));}
template<typename _a> ostream &operator << (ostream &_s,multiset<_a,greater<_a> > &_c){return _OUTC(_s,ALL(_c));}
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
const ll MOD=1000000007;
const ll INF=ll(1e15);

struct tg{ll x,id,tp;};

ll n,m;
ll l[MAXn],r[MAXn];
ii dt[MAXn][2];

vector<tg> v;
multiset<ll> pre;
multiset<ll,greater<ll> > bak;

ll cal_odd(ll x)
{
  REP(i,n)
  {
    ll a=(l[i]&1),b=(r[i]&1),c=((r[i]-l[i]+1)&1);
    if(a!=x&&c==0)dt[i][0]==ii(l[i]-1,m+1);
    else if(a!=x&&c==1)dt[i][0]=ii(l[i]-1,r[i]+1);
    else if(a==x&&c==0)dt[i][0]=ii(r[i],m+1);
    else dt[i][0]=ii(m,1);

    if(b==x)dt[i][1]=ii(0,r[i]+1);
    else dt[i][1]=ii(0,m+1);
  }
  v.clear();pre.clear();bak.clear();
  REP(i,n)
  {
    v.pb((tg){l[i],i,0});
    v.pb((tg){r[i]+1,i,1});
    pre.insert(dt[i][0].X);
    bak.insert(dt[i][0].Y);
  }
  sort(ALL(v),[](tg &a,tg &b){return a.x<b.x;});
  ll it=0,rt=0;
  REP1(i,m)
  {
    while(it<SZ(v)&&v[it].x==i)
    {
      tg a=v[it];
      pre.erase(dt[a.id][a.tp].X);
      bak.erase(dt[a.id][a.tp].Y);
      if(a.tp==0)pre.insert(dt[a.id][1].X),bak.insert(dt[a.id][1].Y);
      it++;
    }
    if((i&1)!=x)continue;
    debug(x,i,pre,bak);
    ll tl,tr;
    if(SZ(pre))tl=*pre.begin();
    else tl=m;
    if(SZ(bak))tr=*bak.begin();
    else tr=1;

    tr=max(tr,i);
    tl=min(tl,tr-1);
    rt+=(1+tl-i+1)*(tl-i+1)/2;
    rt+=(tr-i+1+m-i+1)*(m-tr+1)/2;
  }
  return rt;
}
ll cal_even(ll x)
{
  REP(i,n)
  {
    ll a=(l[i]&1),b=(r[i]&1),c=((r[i]-l[i]+1)&1);
    if(a==x&&c==0)dt[i][0]==ii(l[i]-1,m+1);
    else if(a!=x&&c==1)dt[i][0]=ii(l[i]-1,r[i]+1);
    else if(a==x&&c==0)dt[i][0]=ii(r[i],m+1);
    else dt[i][0]=ii(m,1);

    if(b==x)dt[i][1]=ii(0,r[i]+1);
    else dt[i][1]=ii(0,m+1);
  }
  v.clear();pre.clear();bak.clear();
  REP(i,n)
  {
    v.pb((tg){l[i],i,0});
    v.pb((tg){r[i]+1,i,1});
    pre.insert(dt[i][0].X);
    bak.insert(dt[i][0].Y);
  }
  sort(ALL(v),[](tg &a,tg &b){return a.x<b.x;});
  ll it=0,rt=0;
  REP1(i,m)
  {
    while(it<SZ(v)&&v[it].x==i)
    {
      tg a=v[it];
      pre.erase(dt[a.id][a.tp].X);
      bak.erase(dt[a.id][a.tp].Y);
      if(a.tp==0)pre.insert(dt[a.id][1].X),bak.insert(dt[a.id][1].Y);
      it++;
    }
    if((i&1)!=x)continue;
    debug(x,i,pre,bak);
    ll tl,tr;
    if(SZ(pre))tl=*pre.begin();
    else tl=m;
    if(SZ(bak))tr=*bak.begin();
    else tr=1;

    tr=max(tr,i);
    tl=min(tl,tr-1);
    rt+=(1+tl-i+1)*(tl-i+1)/2;
    rt+=(tr-i+1+m-i+1)*(m-tr+1)/2;
  }
  return rt;
}

int main()
{
    IOS();
    cin>>n>>m;
    REP(i,n)cin>>l[i]>>r[i];
    ll tt=cal(0)+cal(1);
    debug(tt);
}
