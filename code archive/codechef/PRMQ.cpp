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


const ll MAXn=2e5+5,MAXc=1e6+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

vector<ll> pm;
ll ispm[MAXc];
vector<ii> dt;

struct tg{
  ll l,r,x,id,t;
};
tg qrs[MAXn];
vector<ll> qr;
ll ans[MAXn];

ll bit[MAXn];
ll n;
void ad(int x)
{
    while(x<=n)bit[x]++,x+=x&-x;
}
ll qra(ll x)
{
  ll rt=0;
  while(x>0)rt+=bit[x],x-=x&-x;
  return rt;
}

int main()
{
    IOS();
    for(int i=2;i<MAXc;i++)
    {
      if(!ispm[i])pm.pb(i),ispm[i]=SZ(pm);
      for(int j=0;i*pm[j]<MAXc;j++)
      {
        ispm[i*pm[j]]=j+1;
        if(i%pm[j]==0)break;
      }
    }
    //REP1(i,20)debug(i,ispm[i]);
    cin>>n;

    REP(k,n)
    {
      ll t;
      cin>>t;
      while(t>1)
      {
          dt.pb(ii(ispm[t]-1,k));
          t/=pm[ispm[t]-1];
      }
    }


    sort(ALL(dt));
    ll q;
    cin>>q;
    ll qrit=0;
    REP(i,q)
    {
      ll l,r,x,y;
      cin>>l>>r>>x>>y;
      l--;
      qrs[qrit].l=qrs[qrit+1].l=l;
      qrs[qrit].r=qrs[qrit+1].r=r;
      qrs[qrit].id=qrs[qrit+1].id=i;
      qrs[qrit].x=lower_bound(ALL(pm),x)-pm.begin();
      qrs[qrit+1].x=upper_bound(ALL(pm),y)-pm.begin();
      qrs[qrit].t=-1;
      qrs[qrit+1].t=1;
      qrit+=2;
    }
    REP(i,qrit)qr.pb(i);
    sort(ALL(qr),[](int a,int b){return qrs[a].x<qrs[b].x;});

    ll it=0;
    REP(i,qrit)
    {
      auto &t=qrs[qr[i]];
      while(it<SZ(dt)&&dt[it].X<t.x)ad(dt[it++].Y+1);
      ans[t.id]+=(qra(t.r)-qra(t.l))*t.t;
    }
    REP(i,q)cout<<ans[i]<<endl;
    
}
