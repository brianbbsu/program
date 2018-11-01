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


const ll MAXn=5e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);


struct node{
  ll l,r;
  node *lc,*rc;
  ll tg;
  node(ll l,ll r):l(l),r(r),lc(0),rc(0),tg(0){}
  void ins(ll li,ll ri,ll k)
  {
    if(li >= r || ri <= l)return;
    if(li <= l && ri >= r)tg += k;
    else 
    {
      ll h = (l+r)/2;
      if(li < h){
        if(!lc)lc = new node(l,h);
        lc->ins(li,ri,k);
      }
      if(ri > h){
        if(!rc)rc = new node(h,r);
        rc->ins(li,ri,k); 
      }
    }
  }
  ll qr(ll x)
  {
    if(l == r-1)return tg;
    else if(x < (l+r)/2 && lc)return tg + lc->qr(x);
    else if(x >= (l+r)/2 && rc)return tg + rc->qr(x);
    else return tg;
  }
  void clr()
  {
    tg = 0;
    if(lc)
    {
      lc->clr();
      lc = 0;
    }
    if(rc)
    {
      rc->clr();
      rc = 0;
    }
  }
};

vector<ll> v[MAXn];
ll l[MAXn],r[MAXn],tit,c[MAXn],p[MAXn];

void predfs(ll now)
{
  l[now] = tit++;
  for(ll k:v[now])predfs(k);
  r[now] = tit;
}

node *rt[MAXn];
vector<ll> dt[MAXn],pre[MAXn];

ll tt = 0;

ll cal(ll x,ll k)
{
  ll tp = rt[k]->qr(l[x]);
  int itl = upper_bound(ALL(dt[k]),l[x]) - dt[k].begin();
  int itr = lower_bound(ALL(dt[k]),r[x]) - dt[k].begin();
  ll b1 = itr - itl;
  
  ll b2 = pre[k][itr - 1] - pre[k][itl - 1];
  ll ret = 0;
  ret += tp * (tp-1) / 2;
  ret += tp * b1;
  ret += b2;
  return ret;
}


int main()
{
  IOS();
  ll n,q;
  cin>>n>>q;
  REP1(i,n-1)
  {
    ll x;
    cin>>x;
    v[x].pb(i);
  }
  predfs(0);
  REP(i,n)p[l[i]] = i;
  REP(i,n)cin>>c[i];
  
  REP(i,n)rt[i] = new node(0,n);

  REP(i,n)
  {
    ll tmp = rt[c[i]]->qr(l[i]);
    tt += tmp * (tmp-1) / 2;
    rt[c[i]]->ins(l[i] + 1,r[i],1);
  }
  ll lst = tt;
  cout<<tt<<endl;
  REP(K,q)
  {
    ll x,k;
    cin>>k;
    x = K % n;
    if(x == 0)
    {
      REP(i,n)rt[i]->clr(),dt[i].clear(),pre[i].clear();
      tt = 0;
      REP(i,n)
      {
        ll tmp = rt[c[i]]->qr(l[i]);
        tt += tmp * (tmp-1) / 2;
        rt[c[i]]->ins(l[i] + 1,r[i],1);
        dt[c[i]].pb(l[i]);
      }
      REP(i,n)
      {
        dt[i].pb(-1);
        pre[i].pb(0);
        sort(ALL(dt[i]));
        REP1(j,SZ(dt[i]) - 1)
        {
          ll tmp = (lower_bound(ALL(dt[i]),r[p[dt[i][j]]]) - dt[i].begin()) - j - 1;
          pre[i].pb(pre[i].back() + tmp);
        }
      }
    }
    k = (k+lst)%n;
    tt -= cal(x,c[x]);
    tt += cal(x,k);
    rt[c[x]]->ins(l[x] + 1,r[x],-1);
    rt[k]->ins(l[x] + 1,r[x],1);
    c[x] = k;
    cout<<tt<<endl;
    lst = tt;
  }
}
