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

char ans[MAXn];

struct node{
  ll l,r;
  node *lc,*rc;
  ll tg,tt;
  void push();
  void ins(ll,ll,ll);
  ll qr(ll,ll);
  void dfs(char);
};
void node::push()
{
  if(tg!=-1)
  {
    lc->tg=rc->tg=tg;
    lc->tt=(tg?lc->r-lc->l:0);
    rc->tt=(tg?rc->r-rc->l:0);
    tg=-1;
  }
}
void node::ins(ll li,ll ri,ll x)
{
  if(li>=r||ri<=l)return;
  if(li<=l&&ri>=r)tg=x,tt=(x?r-l:0);
  else
  {
    push();
    lc->ins(li,ri,x);rc->ins(li,ri,x);
    tt=lc->tt+rc->tt;
  }
}
ll node::qr(ll li,ll ri)
{
  if(li>=r||ri<=l)return 0;
  if(li<=l&&ri>=r)return tt;
  else
  {
    push();
    return lc->qr(li,ri)+rc->qr(li,ri);
  }
}
void node::dfs(char c)
{
  if(l==r-1)
  {
    if(tt)ans[l]=c;return;
  }
  push();
  lc->dfs(c);rc->dfs(c);
}

node *build(ll l,ll r)
{
  if(l==r-1)return new node{l,r,0,0,-1,0};
  else return new node{l,r,build(l,(l+r)/2),build((l+r)/2,r),-1,0};
}

node *rt[30];

int main()
{
    IOS();
    ll n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    REP(i,26)rt[i]=build(0,n);
    REP(i,n)
    {
      rt[s[i]-'a']->ins(i,i+1,1);
    }
    REP(T,q)
    {
      ll l,r,tp;
      cin>>l>>r>>tp;
      l--;
      ll tt=0;
      for(int i=(tp?0:25);(tp?i<26:i>=0);i+=(tp?1:-1))
      {
        ll tmp=rt[i]->qr(l,r);
        rt[i]->ins(l,r,0);
        rt[i]->ins(l+tt,l+tt+tmp,1);
        tt+=tmp;
      }
    }
    REP(i,26)rt[i]->dfs('a'+i);
    REP(i,SZ(s))cout<<ans[i];
    cout<<endl;
}
