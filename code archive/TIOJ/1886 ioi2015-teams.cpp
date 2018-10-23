//{
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<int,int> ii;
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


const ll MAXn=5e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

const ll TH=500;


struct node{
  node *lc,*rc;
  int d;
  node(node *lci,node *rci):lc(lci),rc(rci),d(0){}
  node(node *t):lc(t->lc),rc(t->rc),d(t->d){}
  node(){}

}nd[20000000],*nit,*rt[MAXn];

node* build(int l,int r)
{
  if(l==r-1)return new(nit++) node(0,0);
  else return new(nit++) node(build(l,(l+r)/2),build((l+r)/2,r));
}

void ins(node *it,int l,int r,int x)
{
  if(l==r-1)it->d++;
  else
  {
    int h=(l+r)/2;
    if(x<h)
    {
      it->lc=new(nit++) node(it->lc);
      ins(it->lc,l,h,x);
    }
    else
    {
      it->rc=new(nit++) node(it->rc);
      ins(it->rc,h,r,x);
    }
    it->d=it->lc->d+it->rc->d;
  }
}


int nqr(node *it,int l,int r,int li,int ri)
{
  if(li>=r||ri<=l)return 0;
  else if(li<=l&&ri>=r)return it->d;
  else return nqr(it->lc,l,(l+r)/2,li,ri)+nqr(it->rc,(l+r)/2,r,li,ri);
}

int n,q;
int l[MAXn],r[MAXn];
int sd[MAXn];

void read()
{
  cin>>n;
  REP(i,n)cin>>l[i]>>r[i],sd[i]=i;
  sort(sd,sd+n,[=](int a,int b){return l[a]<l[b];});
  nit=nd;
  rt[0]=build(0,n+1);
  int it=0;
  REP1(i,n)
  {
    rt[i]=new(nit++) node(rt[i-1]);
    while(it<n&&l[sd[it]]==i)
    {
      ins(rt[i],0,n+1,r[sd[it]]);
      it++;
    }
  }
  REP1(i,n)REP1(j,n)debug(i,j,nqr(rt[i],0,n+1,j,j+1));

  cin>>q;
}

priority_queue<int,vector<int>,greater<int> > pq;

int qr[MAXn];

bool solve_s(int k)
{
  while(SZ(pq))pq.pop();

  int it=0;

  REP1(i,k)
  {
    while(it<n&&l[sd[it]]<=qr[i])pq.push(r[sd[it++]]);
    int ct=qr[i];
    while(SZ(pq)&&ct)
    {
      int t=pq.top();
      pq.pop();
      if(t>=qr[i])ct--;
    }
    if(ct)return 0;
  }
  return 1;
}

ll dp[MAXn];

bool solve_l(int k)
{
  qr[0]=0;
  dp[0]=0;
  REP1(i,k)
  {
    ll ct=nqr(rt[qr[i]],0,n+1,qr[i],n+1);
    //REP(t,n)if(l[t]<=qr[i]&&r[t]>=qr[i])ct++;
    dp[i]=ct-qr[i];
    REP(j,i)
    {
      ct=0;
      ct=nqr(rt[qr[i]],0,n+1,qr[i],n+1)-nqr(rt[qr[j]],0,n+1,qr[i],n+1);
      //REP(t,n)if(l[t]>qr[j]&&l[t]<=qr[i]&&r[t]>=qr[i])ct++;
      dp[i]=min(dp[i],dp[j]+ct-qr[i]);
    }
    debug(i,dp[i]);
    if(dp[i]<0)return 0;
  }
  return 1;
}

int main()
{
    IOS();
    ll T;
    cin>>T;
    while(T--)
    {
      read();
      REP(tt,q)
      {
        ll k;
        cin>>k;
        REP1(i,k)cin>>qr[i];
        sort(qr+1,qr+k+1);
        if(k<=TH)cout<<solve_l(k)<<endl;
        else cout<<solve_s(k)<<endl;
      }
    }
}
