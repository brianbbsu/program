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
const ll MOD=1000000007;
const ll INF=ll(1e15);



struct node {
    int ch[2], fa, sum, num;
    bool rv;
}tree[MAXn];
const int L=0, R=1;
#define isroot(x) (tree[tree[x].fa].ch[L] != x && tree[tree[x].fa].ch[R] != x)
void push_up(int rt) {
    tree[rt].sum = tree[rt].num;
    if( tree[rt].ch[L] ) tree[rt].sum += tree[tree[rt].ch[L]].sum;
    if( tree[rt].ch[R] ) tree[rt].sum += tree[tree[rt].ch[R]].sum;
}
void push_down(int rt) {
    if( tree[rt].rv ) {
        tree[tree[rt].ch[L]].rv ^= 1;
        tree[tree[rt].ch[R]].rv ^= 1;
        swap(tree[rt].ch[L], tree[rt].ch[R]);
        tree[rt].rv = 0;
    }
}
void rotate(int rt) {
    int p = tree[rt].fa;
    int a = tree[p].fa;
    int v = tree[p].ch[R] == rt;
    if( !isroot(p) ) tree[a].ch[tree[a].ch[R] == p] = rt;
    tree[p].ch[v] = tree[rt].ch[v^1], tree[tree[p].ch[v]].fa = p;
    tree[rt].ch[v^1] = p, tree[p].fa = rt, tree[rt].fa = a;
    push_up(p), push_up(rt), push_up(a);
}
void splay(int rt, int y){
    int des = tree[y].fa;
    while( tree[rt].fa != des ){
        int p = tree[rt].fa, a = tree[p].fa;
        push_down(a), push_down(p), push_down(rt);
        if( p != y )
            if( (tree[a].ch[R] == p) ^ (tree[p].ch[R] == rt) )    rotate(rt);
            else rotate(p);
        rotate(rt);
    }
}
int find_root(int now){
    int u;for(u = now; !isroot(u); u = tree[u].fa);
    return u;
}
void change(int rt, int ch){
    int u = find_root(rt);
    splay(rt, u), push_down(rt);
    tree[rt].ch[R] = ch;
    push_up(rt);
}
int access(int rt){
    for(change(rt,0); tree[rt].fa; rt = tree[rt].fa)
            change(tree[rt].fa, rt);
    int u = rt;
    while( push_down(u), tree[u].ch[L] )    u = tree[u].ch[L];
    return splay(u, rt), u;
}
#define makeroot(x) (tree[access(x)].rv ^= 1)
#define link(a, b) (tree[b = access(b)].rv ^= 1, tree[b].fa = a)
#define cut(a, b) (change(a, 0), change(b, 0), tree[a].fa == b ? tree[a].fa = 0 : tree[b].fa  = 0)

int query(int a, int b,int c){
	makeroot(a);
  a=access(b);
  splay(b,a);
  if(tree[b].sum<c)return -1;
  ll now = b;
  while(1)
  {
    push_down(now);
    if(tree[now].ch[L])
    {
      ll t = tree[tree[now].ch[L]].sum;
      if(t < c)c-=t;
      else
      {
        now = tree[now].ch[L];
        continue;
      }
    }
    if(c==1&&tree[now].num)
    {
      splay(now,b);
      return now;
    }
    c -= tree[now].num;
    now = tree[now].ch[R];
  }
}
ll p[MAXn];
int main()
{
    IOS();
    ll n,q;
    cin>>n>>q;
    REP1(i,n)cin>>tree[i].num,tree[i].sum=tree[i].num;

    for(int i=2;i<=n;i++)
    {
      cin>>p[i];
      link(p[i],i);
    }
    while(q--)
    {
      char tp;
      cin>>tp;
      if(tp=='T')
      {
        ll t;
        cin>>t;
        splay(t,find_root(t));
        tree[t].num ^= 1;
        push_up(t);
      }
      else if(tp == 'C')
      {
        ll a,b;
        cin>>a>>b;
        makeroot(1);
        cut(a,p[a]);
        p[a] = b;
        link(p[a],a);
      }
      else
      {
        ll a,b,k;
        cin>>a>>b>>k;
        cout<<query(a,b,k)<<endl;
      }
    }
}
