#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
#define REP(i,n) for(ll i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define X first
#define Y second
#define SZ(_a) (int)_a.size()
#define ALL(_a) _a.begin(),_a.end()
#define pb push_back

#define debug(...)
#define pary(...)
#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);

const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll INF=ll(2e9);

ll T,n;

namespace BCC{
  vector<ii> v[MAXn];
  ll st[MAXlg][MAXn],mx[MAXlg][MAXn],g[MAXn],dph[MAXn],root[MAXn],bit=0;
  void add(ll rt,vector<ll> d)
  {
    for(ll k:d)g[k]=bit;
    root[bit++]=rt;
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
    REP(i,bit)dfs(root[i],ii(-1,0));
  }
  ll cal(ll a,ll b)
  {
    ll rt=-INF;
    if(dph[a]<dph[b])swap(a,b);
    for(int i=MAXlg-1;i>=0;i--)if(dph[a]-(1<<i)>=dph[b])rt=max(rt,mx[i][a]),a=st[i][a];
    if(a==b)return rt;
    for(int i=MAXlg-1;i>=0;i--)if(st[i][a]!=st[i][b])rt=max({rt,mx[i][a],mx[i][b]}),a=st[i][a],b=st[i][b];
    return max({rt,mx[0][a],mx[0][b]});
  }
};

namespace Seg{
  struct node{
    ll l,r;
    node *lc,*rc;
    ll mx,tg;
    node(ll li,ll ri,node *lci=0,node *rci=0):l(li),r(ri),lc(lci),rc(rci),mx(0),tg(0){}
    ll dt(){return mx+tg;}
    void st(ll x,ll d)
    {
      if(l==r-1)mx=d;
      else
      {
        if(x<(l+r)/2)lc->st(x,d);
        else rc->st(x,d);
        mx=max(lc->dt(),rc->dt());
      }
    }
    void ins(ll li,ll ri,ll c)
    {
      if(li>=r||ri<=l)return;
      else if(li<=l&&ri>=r)tg+=c;
      else lc->ins(li,ri,c),rc->ins(li,ri,c),mx=max(lc->dt(),rc->dt());
    }
    ll qr(ll li,ll ri,bool bs=true)
    {
      if(li>=r||ri<=l)return -INF;
      else if(li<=l&&ri>=r)return (bs?this->dt():tg);
      else return max(lc->qr(li,ri,bs),rc->qr(li,ri,bs))+tg;
    }
  };
  node *build(ll l,ll r)
  {
    if(l==r-1)return new node(l,r);
    else return new node(l,r,build(l,(l+r)/2),build((l+r)/2,r));
  }
  node *rt,*rtw;
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
    len[eit] = c;totop[eit] = BCC::cal(pa[eit],BCC::root[ga[eit]]);
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
  void build(ll now)
  {
    in[now] = tit++;
    debug(now,in[now],BCC::bcc[now].mem,BCC::root[now],dph[now],max(totop[p[mxsz[now]]],len[p[mxsz[now]]]));
    if(mxsz[now]!=-1)
    {
      cp[mxsz[now]] = cp[now];
      build(mxsz[now]);
    }
    for(ii k:v[now])if(k.Y!=p[now]&&gb[k.Y]!=mxsz[now])
    {
      cp[gb[k.Y]] = gb[k.Y];
      build(gb[k.Y]);
    }
  }
  void init_chain()
  {
    REP(i,tit)if(cp[i]!=i)Seg::rt->st(in[ga[p[i]]],len[p[i]]),Seg::rtw->st(in[ga[p[i]]],totop[p[i]]);
  }
  void ch(ll a,ll b,ll c)
  {
    a=BCC::g[a],b=BCC::g[b];
    while(1)
    {
      if(dph[a]<dph[b])swap(a,b);
      if(cp[a]==cp[b])
      {
        Seg::rt->ins(in[b],in[a],c);
        Seg::rtw->ins(in[b],in[a]+1,c);
        return;
      }
      if(dph[cp[a]]<dph[cp[b]])swap(a,b);
      Seg::rt->ins(in[cp[a]],in[a],c);
      Seg::rtw->ins(in[cp[a]],in[a]+1,c);
      len[p[cp[a]]]+=c;
      a=ga[p[cp[a]]];
    }
  }
  ll cal(ll a,ll b)
  {
    ll rt = -INF;
    while(1)
    {
      ll ta = BCC::g[a],tb = BCC::g[b];
      if(ta==tb)return max(rt,BCC::cal(a,b)+Seg::rtw->qr(in[ta],in[ta]+1,false));
      if(dph[ta]<dph[tb])swap(a,b),swap(ta,tb);
      debug(a,b,ta,tb,cp[ta],cp[tb]);
      if(a!=BCC::root[ta])rt=max(rt,BCC::cal(a,BCC::root[ta])+Seg::rtw->qr(in[ta],in[ta]+1,false)),a=BCC::root[ta];
      else if(cp[ta]==cp[tb])rt=max({rt,Seg::rtw->qr(in[tb]+1,in[ta]),Seg::rt->qr(in[tb],in[ta])}),a=pa[p[mxsz[tb]]];
      else
      {
          if(dph[cp[ta]]<dph[cp[tb]])swap(a,b),swap(ta,tb);
          if(a!=BCC::root[ta])rt=max(rt,BCC::cal(a,BCC::root[ta])+Seg::rtw->qr(in[ta],in[ta]+1,false)),a=BCC::root[ta];
          else rt = max({rt,Seg::rt->qr(in[cp[ta]],in[ta]),Seg::rtw->qr(in[cp[ta]],in[ta]),len[p[cp[ta]]]}),a=pa[p[cp[ta]]];
      }
      debug(a,b,rt);
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
  void dfs(ll now,ii pi)
  {
    stk.pb(now);
    vis[now] = 1;in[now] = tit++;
    mn[now] = in[now];
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
    for(edge &edg:mste)if(BCC::g[edg.a]==BCC::g[edg.b])BCC::add_edge(edg.a, edg.b, edg.c);
    BCC::build();
    for(edge &edg:mste)if(BCC::g[edg.a]!=BCC::g[edg.b])Tree::add_edge(edg.a, edg.b, edg.c);
    Tree::root = BCC::g[0];
    Tree::p[Tree::root] = -1;
    Tree::szdfs(Tree::root);
    Tree::cp[Tree::root] = Tree::root;
    Tree::build(Tree::root);

    Seg::rt = Seg::build(0,Tree::tit);
    Seg::rtw = Seg::build(0,Tree::tit);
    Tree::init_chain();

    while(q--)
    {
      ll tp;
      cin>>tp;
      if(tp==0){
        ll a,b,c;cin>>a>>b>>c;
        Tree::ch(a,b,c);
      }
      else{
        ll a,b;cin>>a>>b;
        ll ans = Tree::cal(a,b);
        cout<<ans<<endl;
      }
    }


}
