//{
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(ll i=0;i<n;i++)
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

struct node{
  int d,tg,pri,sz,mx;
  node *l,*r;
  node(int di):d(di),tg(0),pri(rand()),sz(1),mx(di),l(0),r(0){}
};
int gsz(node *a){return (a?a->sz:0);}
void push(node *a)
{
  if(!a||!a->tg)return;
  a->d+=a->tg;
  if(a->l)a->l->tg+=a->tg;
  if(a->r)a->r->tg+=a->tg;
  a->tg=0;
}
void pull(node *a)
{
  if(!a)return;
  a->sz=gsz(a->l)+gsz(a->r)+1;
  a->mx=max({a->d,(a->l?a->l->mx+a->l->tg:-1),(a->r?a->r->mx+a->r->tg:-1)});
}

node *mg(node *a,node *b)
{
  if(!a||!b)return (a?a:b);
  if(a->pri>b->pri)
  {
    push(a);
    a->r=mg(a->r,b);
    pull(a);
    return a;
  }
  push(b);
  b->l=mg(a,b->l);
  pull(b);
  return b;
}
void spltSz(node *a,node *&b,node *&c,int s)
{
  if(!a)b=c=0;
  else
  {
    push(a);
    if(gsz(a->l)>=s)
    {
      c=a;
      spltSz(a->l,b,c->l,s);
      pull(c);
    }
    else
    {
      b=a;
      spltSz(a->r,b->r,c,s-gsz(a->l)-1);
      pull(b);
    }
  }
}
void spltDt(node *a,node *&b,node *&c,int s)
{
  if(!a)b=c=0;
  else
  {
    push(a);
    if(a->d>=s)
    {
      c=a;
      spltDt(a->l,b,c->l,s);
      pull(c);
    }
    else
    {
      b=a;
      spltDt(a->r,b->r,c,s);
      pull(b);
    }
  }
}
vector<ll> dfstmp;
void dfs(node *a)
{
  if(!a)return;
  push(a);
  dfs(a->l);
  dfstmp.pb(a->d);
  dfs(a->r);
}

vector<ii> d;
ii d2[MAXn];
node *rt=0;

int main()
{
    IOS();
    srand(time(NULL));

    ll n,m;
    cin>>n;
    ll mxt=0;
    REP(i,n)
    {
        ll l,r;
        cin>>l>>r;
        d.pb(ii(l,1));
        d.pb(ii(r+1,-1));
        mxt=max(mxt,r+1);
    }
    sort(ALL(d));

    cin>>m;
    REP(i,m)cin>>d2[i].Y>>d2[i].X,mxt=max(mxt,d2[i].X);
    sort(d2,d2+m);

    ll tt=0;
    ll it=0,it2=0;

    for(int i=1;i<=mxt;i++)
    {
        while(it<SZ(d)&&d[it].X==i)tt+=d[it++].Y;
        node *a,*b,*c,*tmp;
        spltDt(rt,a,b,tt);
        b=mg(new node(tt),b);
        rt=mg(a,b);
        while(it2<m&&d2[it2].X==i)
        {
          spltSz(rt,a,b,d2[it2++].Y);
          if(a)a->tg++;
          int g=(a?a->mx+a->tg:-1);
          spltDt(a,rt,c,g);
          spltDt(b,a,tmp,g);
          rt=mg(rt,a);
          rt=mg(rt,c);
          rt=mg(rt,tmp);
        }
    }
    cout<<(rt?rt->mx+rt->tg:0)<<endl;
}
