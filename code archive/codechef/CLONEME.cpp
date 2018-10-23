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
const ll MOD=1000000009;
const ll INF=ll(1e15);

const ll bs=880301;
ll pw[MAXn];

struct node{
  ll l,r;
  node *lc,*rc;
  ll d,ct,h;
  node(ll li,ll ri,node *lci=0,node *rci=0,ll cti=0,ll di=0):l(li),r(ri),lc(lci),rc(rci),d(di),ct(cti),h((l+r)/2){}
  void ins(ll x,ll k)
  {
    if(l==r-1)ct++,d+=pw[k];
    else
    {
      if(x<h)
      {
        lc=new node(l,h,lc->lc,lc->rc,lc->ct,lc->d);
        lc->ins(x,k);
      }
      else
      {
        rc=new node(h,r,rc->lc,rc->rc,rc->ct,rc->d);
        rc->ins(x,k);
      }
      ct=lc->ct+rc->ct;
      d=lc->d+rc->d;
    }
  }
  ll qrdt(ll li,ll ri)
  {
    if(li>=r||ri<=l)return 0;
    else if(li<=l&&ri>=r)return d;
    else return lc->qrdt(li,ri)+rc->qrdt(li,ri);
  }
};


node *build(ll l,ll r)
{
  if(l==r-1)return new node(l,r);
  else return new node(l,r,build(l,(l+r)/2),build((l+r)/2,r));
}

node *rt[MAXn];
vector<ii> dt;
ll d[MAXn];
ll T,n,q;

ll prek(ll li,ll ri,ll k)
{

  node *a=rt[li],*b=rt[ri];
  while(1)
  {
    if(b->l==b->r-1)return b->l;
    else if(b->lc->ct-a->lc->ct>=k)a=a->lc,b=b->lc;
    else k-=b->lc->ct-a->lc->ct,a=a->rc,b=b->rc;
  }
}



int main()
{
    IOS();
    pw[0]=1;
    REP1(i,MAXn-1)pw[i]=pw[i-1]*bs%MOD;


    cin>>T;
    while(T--&&cin>>n>>q)
    {
      FILL(rt,0);
      dt.clear();

      REP(i,n)
      {
        ll t;
        cin>>t;
        dt.pb(ii(t,i));
      }
      //sort(ALL(dt));
      //REP(i,n)d[dt[i].Y]=i;

      rt[0]=build(0,MAXn);
      REP(i,n)
      {
        rt[i+1]=new node(0,MAXn,rt[i]->lc,rt[i]->rc,rt[i]->ct,rt[i]->d);
        rt[i+1]->ins(dt[i].X,dt[i].X);
      }
      //debug(123);
      REP1(i,n)debug(i,rt[i]->ct);
      REP(i,q)
      {
        ll la,ra,lb,rb;
        cin>>la>>ra>>lb>>rb;
        la--;lb--;

        node *a[4];
        a[0]=rt[la];a[1]=rt[ra];a[2]=rt[lb];a[3]=rt[rb];
        ll t=0;
        while(1)
        {
          REP(j,4)debug(j,a[j]->l,a[j]->r,a[j]->ct,a[j]->d);
          if(a[0]->l==a[0]->r-1){t+=min((a[1]->ct-a[0]->ct),(a[3]->ct-a[2]->ct));debug(a[0]->l);break;}
          else if(a[1]->lc->d-a[0]->lc->d==a[3]->lc->d-a[2]->lc->d)
          {
            t+=a[1]->lc->ct-a[0]->lc->ct;
            REP(k,4)a[k]=a[k]->rc;
          }
          else REP(k,4)a[k]=a[k]->lc;
        }
        ll u=0;
        a[0]=rt[la];a[1]=rt[ra];a[2]=rt[lb];a[3]=rt[rb];
        while(1)
        {
          if(a[0]->l==a[0]->r-1){u+=min((a[1]->ct-a[0]->ct),(a[3]->ct-a[2]->ct));debug(a[0]->l);break;}
          else if(a[1]->rc->d-a[0]->rc->d==a[3]->rc->d-a[2]->rc->d)
          {
            u+=a[1]->rc->ct-a[0]->rc->ct;
            REP(k,4)a[k]=a[k]->lc;
          }
          else REP(k,4)a[k]=a[k]->rc;
        }
        debug(t,u);
        if(t+u>=ra-la-1){cout<<"YES"<<endl;continue;}
        else cout<<"NO"<<endl;

      }

    }

}
