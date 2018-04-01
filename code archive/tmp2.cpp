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
const ll INF=ll(2e9);

ll T,n;

namespace BCC{
  vector<ii> v[MAXn];
  ll st[MAXlg][MAXn],mx[MAXlg][MAXn],g[MAXn],dph[MAXn];
  struct BCC{
    ll root;
    vector<ll> mem;
  };
  vector<BCC> bcc;
  void add(ll rt,vector<ll> d)
  {
    BCC tmp;
    tmp.root = rt;tmp.mem = d;
    for(ll k:d)g[k]=SZ(bcc);
    bcc.pb(tmp);
  }
  void add_edge(ll a,ll b,ll c)
  {
    v[a].pb(ii(b,c));
    v[b].pb(ii(a,c));
  }
  void dfs(ll now,ii p)
  {
    st[0][now]=p.X,mx[0][now]=p.Y;
    REP1(i,MAXlg-1)
    {
      if(st[i-1][now]!=-1)st[i][now]=st[i-1][st[i-1][now]],mx[i][now]=max(mx[i-1][now],mx[i-1][st[i-1][now]]);
      else st[i][now]=-1;
    }
    for(ii k:v[now])if(k.X!=p.X)dph[k.X]=dph[now]+1,dfs(k.X,ii(now,k.Y));
  }
  void build()
  {
    for(BCC &tmp:bcc)dfs(tmp.root,ii(-1,0));
  }
  ll cal(ll a,ll b)
  {
    assert(g[a] == g[b]);
    ll rt=-INF;
    if(dph[a]<dph[b])swap(a,b);
    for(int i=MAXlg-1;i>=0;i--)if(dph[a]-(1<<i)>=dph[b])rt=max(rt,mx[i][a]),a=st[i][a];
    if(a==b)return rt;
    for(int i=MAXlg-1;i>=0;i--)if(st[i][a]!=st[i][b])rt=max({rt,mx[i][a],mx[i][b]}),a=st[i][a],b=st[i][b];
    return max({rt,mx[0][a],mx[0][b]});
  }
};

namespace Tree{
  vector<ii> v[MAXn];
  ll root,ga[MAXn],gb[MAXn],pa[MAXn],pb[MAXn],len[MAXn],totop[MAXn],eit=0;
  ll p[MAXn],sz[MAXn],mxsz[MAXn],in[MAXn],cp[MAXn],dph[MAXn],tit=0,tg[MAXn];
  void add_edge(ll a,ll b,ll c)
  {
    if(BCC::g[a]<BCC::g[b])swap(a,b);
    ga[eit] = BCC::g[a];gb[eit] = BCC::g[b];
    pa[eit] = a;pb[eit] = b;
    len[eit] = c;totop[eit] = BCC::cal(pa[eit],BCC::bcc[ga[eit]].root);
    v[ga[eit]].pb(ii(gb[eit],eit));
    v[gb[eit]].pb(ii(ga[eit],eit));
    p[gb[eit]] = eit;
    eit++;
  }
  void szdfs(ll now)
  {
    sz[now] = 1;
    mxsz[now] = -1;
    for(ii k:v[now])if(k.Y!=p[now])
    {
      dph[gb[k.Y]] = dph[now] + 1;
      szdfs(gb[k.Y]);
      sz[now] += sz[gb[k.Y]];
      if(mxsz[now] == -1 || sz[mxsz[now]] < sz[gb[k.Y]])mxsz[now] = gb[k.Y];
    }
  }
  void ch(ll a,ll b,ll c)
  {
    a=BCC::g[a],b=BCC::g[b];
    tg[a]+=c;
    if(a==b)return;
    tg[b]+=c;
    while(1)
    {
      if(dph[a]<dph[b])swap(a,b);
      len[p[a]]+=c;
      assert(dph[ga[p[a]]]==dph[a]-1);
      a=ga[p[a]];
      if(a==b)return;
      tg[a]+=c;
    }
  }
  ll cal(ll a,ll b)
  {
    ll rt = -INF;
    while(1)
    {
      ll ta = BCC::g[a],tb = BCC::g[b];
      //debug(a,b,ta,tb);
      if(ta==tb)return max(rt,BCC::cal(a,b)+tg[ta]);
      if(dph[ta]<dph[tb])swap(a,b),swap(ta,tb);
      if(a!=BCC::bcc[ta].root)rt=max(rt,BCC::cal(a,BCC::bcc[ta].root)+tg[ta]),a=BCC::bcc[ta].root;
      else if((dph[ta]==dph[tb]+1&&ga[p[ta]]==tb)||(dph[ta]==dph[tb]&&ga[p[ta]]==ga[p[tb]]))rt=max(rt,len[p[ta]]),a=pa[p[ta]];
      else rt=max({rt,len[p[ta]],totop[p[ta]]+tg[ga[p[ta]]]}),a=BCC::bcc[ga[p[ta]]].root;
    }
  }
};


struct edge{ll a,b,c;};
vector<edge> e;

namespace MST{
  ll g[MAXn];
  ll fd(ll x){return g[x]=(g[x]==x?x:fd(g[x]));}
  void mg(ll a,ll b){g[fd(a)]=fd(b);}
  void add(ll a,ll b,ll c){e.pb({a,b,c});}
  vector<edge> cal()
  {
    vector<edge> rt;
    REP(i,n)g[i]=i;
    sort(ALL(e),[](const edge &a,const edge &b){return a.c<b.c;});
    for(edge &edg:e)if(fd(edg.a)!=fd(edg.b))mg(edg.a,edg.b),rt.pb(edg);
    return rt;
  }
};

vector<ii> v[MAXn];

namespace pre{
  vector<ll> stk;
  ll in[MAXn],mn[MAXn],vis[MAXn],tit=0;
  ii p[MAXn];
  void dfs(ll now,ii pi)
  {
    stk.pb(now);
    vis[now] = 1;in[now] = tit++;
    mn[now] = in[now];p[now] = pi;
    for(ii k:v[now])if(k.X!=pi.X)
    {
      if(vis[k.X])mn[now]=min(mn[now],in[k.X]);
      else dfs(k.X,ii(now,k.Y)),mn[now] = min(mn[now],mn[k.X]);
    }
    if(mn[now]==in[now])
    {
      vector<ll> tmp;
      while(SZ(stk)&&in[stk.back()]>=in[now])
      {
        tmp.pb(stk.back());
        stk.pop_back();
      }
      BCC::add(now,tmp);
    }
  }
};

int main()
{
    IOS();
    ll m,q;
    cin>>T>>n>>m>>q;
    REP(i,m)
    {
      ll a,b,c;
      cin>>a>>b>>c;
      MST::add(a,b,c);
      v[a].pb(ii(b,c)),v[b].pb(ii(a,c));
    }

    vector<edge> mste = MST::cal();

    pre::dfs(0,ii(-1,0));
    //pary(BCC::g,BCC::g+n);
    for(edge &edg:mste)if(BCC::g[edg.a]==BCC::g[edg.b])BCC::add_edge(edg.a, edg.b, edg.c);
    BCC::build();
    for(edge &edg:mste)if(BCC::g[edg.a]!=BCC::g[edg.b])Tree::add_edge(edg.a, edg.b, edg.c);
    Tree::root = BCC::g[0];
    Tree::p[Tree::root] = -1;
    Tree::szdfs(Tree::root);
    //debug(SZ(BCC::bcc));

    while(q--)
    {
      ll tp;
      cin>>tp;
      if(tp==0)
      {
        ll a,b,c;
        cin>>a>>b>>c;
        Tree::ch(a,b,c);
      }
      else
      {
        ll a,b;
        cin>>a>>b;
        cout<<Tree::cal(a,b)<<endl;
      }
    }


}
