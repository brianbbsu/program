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


const ll MAXn=(1<<17),MAXq=(1<<19)+5,MAXlg=20;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll tit=0;

struct node{
  ll l,r,lt;
  node *lc,*rc;
  ll *d,*dt,dit;
  node(ll li,ll ri,node *lci=0,node *rci=0):l(li),r(ri),lt(-1),lc(lci),rc(rci){
    d=new ll[r-l];dt=new ll[r-l];
    REP(i,r-l)d[i]=0;dit=0;
  }
  void chk()
  {
    if(lt!=tit)
    {
      lt=tit;
      REP(k,dit)d[dt[k]]=0;
      dit=0;
    }
  }
  void ins(int x,ll k){
    chk();
    if(!d[x])dt[dit++]=x;
    d[x]+=k;
  }
  void push()
  {
    REP(i,dit)
    {
      ll x=dt[i];
      if(x&1)rc->ins(x/2,d[x]);
      lc->ins(x/2,d[x]);
      d[x]=0;
    }
    dit=0;
  }
  ll qr(ll x)
  {
    chk();
    if(l==r-1)return d[0];
    else{
      push();
      if(x&1)return rc->qr(x/2);
      else return lc->qr(x/2);
    }
  }
};
node *build(ll l,ll r){
  if(l==r-1)return new node(l,r);
  else return new node(l,r,build(l,(l+r)/2),build((l+r)/2,r));
}
node *rt;

ll d[MAXn],ans[MAXq],qrl[MAXlg][MAXq],qrr[MAXlg][MAXq],qrx[MAXq],qrk[MAXq];
vector<int> dt[MAXlg][MAXq];

ll val[MAXn];

void cal(int l,int r)
{
  FILL(val,0);
  for(int i=l;i<=r;i++)val[qrx[i]]+=qrk[i];
  REP(i,17)REP(j,MAXn)if(j&(1<<i))val[j-(1<<i)]+=val[j];
}


int main()
{
    IOS();
    rt=build(0,MAXn);
    ll n,q;
    cin>>n;
    REP(i,n)cin>>d[i];
    cin>>q;
    REP(i,q)cin>>qrx[i]>>qrk[i];
    REP(i,q)qrx[i]&=(MAXn-1);
    //REP(i,q)rt->ins(qrx[i],qrk[i]);
    //REP(i,n)debug(i,rt->qr(i));
    srand(time(NULL));
    qrl[0][0]=-1,qrr[0][0]=q;
    REP(i,n)dt[0][0].pb(i);
    REP(i,MAXlg)
    {
      int it=0;
      REP(j,(1<<i))if(SZ(dt[i][j]))
      {
        debug(i,j,qrl[i][j],qrr[i][j],dt[i][j]);
        if(qrl[i][j]==qrr[i][j]-1)ans[qrr[i][j]]-=SZ(dt[i][j]);
        else
        {
          int L=2*j,R=2*j+1;
          tit++;
          ll h=(qrl[i][j]+qrr[i][j])/2;
          if(i>=9)for(int k=qrl[i][j]+1;k<=h;k++)rt->ins(qrx[k],qrk[k]);
          else cal(qrl[i][j]+1,h);
          //REP(k,n)debug(h,k,rt->qr(k));
          for(ll k:dt[i][j])
          {
            ll t = (i>=9?rt->qr(k):val[k]);
            if(t>=d[k])dt[i+1][L].pb(k);else dt[i+1][R].pb(k),d[k]-=t;
          }
          qrl[i+1][L]=qrl[i][j];
          qrr[i+1][L]=qrl[i+1][R]=h;
          qrr[i+1][R]=qrr[i][j];
        }
      }
    }
    ll tt=n;
    REP(i,q)
    {
      tt+=ans[i];
      cout<<tt<<endl;
    }
}
