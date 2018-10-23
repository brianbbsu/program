//{
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<int,int> ii;
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


const ll MAXn=5e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);



int g[MAXn],sz[MAXn],c;
int ans[MAXn];
struct tg{
  int id,a,b,ltb;
  tg(int idi,int ai,int bi,int ltbi):id(idi),a(ai),b(bi),ltb(ltbi){}
};
vector<tg> st;
int fd(int a){return (g[a]==a?a:fd(g[a]));}
void mg(int id,int a,int b)
{
  a=fd(a);b=fd(b);
  if(a==b)return;
  if(sz[a]>sz[b])swap(a,b);
  st.pb(tg(id,a,b,sz[b]));
  c--;
  g[a]=b;
  sz[b]+=sz[a];
}
struct node
{
  int l,r;
  node *lc,*rc;
  int id;
  vector<ii> d;
  node(int li,int ri,node *lci,node *rci,int idi):l(li),r(ri),lc(lci),rc(rci),id(idi){}
  void clr()
  {
    d.clear();
    if(l!=r-1)lc->clr(),rc->clr();
  }
  void ins(int li,int ri,ii p)
  {
    if(li>=r||ri<=l)return;
    else if(li<=l&&ri>=r)d.pb(p);
    else lc->ins(li,ri,p),rc->ins(li,ri,p);
  }
  void dfs()
  {
    for(ii &tmp:d)
    {
      mg(id,tmp.X,tmp.Y);
    }
    if(l==r-1)ans[l]=c;
    else
    {
      lc->dfs();
      rc->dfs();
    }
    while(SZ(st)&&st.back().id==id)
    {
      tg &tmp=st.back();
      c++;
      g[tmp.a]=tmp.a;
      sz[tmp.b]=tmp.ltb;
      st.pop_back();
    }
  }
};

node *build(int l,int r)
{
  static int it=0;
  if(l==r-1)return new node(l,r,0,0,it++);
  else return new node(l,r,build(l,(l+r)/2),build((l+r)/2,r),it++);
}
struct hs
{
  size_t operator()(const ii &a)const{return (a.X<<20)|(a.Y);}
};
typedef unordered_map<ii,ii,hs> umap;
umap mp;
int n,m,q,t;
node *rt=0;



int main()
{
    IOS();
    rt=build(0,MAXn);
    ll T;
    cin>>T;
    while(T--&&cin>>n>>m>>q)
    {
      mp.clear();
      REP(i,n)g[i]=i,sz[i]=1;
      c=n;
      rt->clr();

      REP(i,m)
      {
        ll a,b;
        cin>>a>>b;
        if(a>b)swap(a,b);
        pair<umap::iterator,bool> tmp=mp.insert(make_pair(ii(a,b),ii(1,0)));
        if(!tmp.Y)tmp.X->Y.X++;
      }

      REP(i,q)
      {
        char ch;
        int a,b;
        cin>>ch>>a>>b;
        if(a>b)swap(a,b);
        if(ch=='N')
        {
          pair<umap::iterator,bool> tmp=mp.insert(make_pair(ii(a,b),ii(1,i)));
          if(!tmp.Y)tmp.X->Y.X++;
        }
        else
        {
          auto it=mp.find(ii(a,b));
          if((*it).Y.X==1)
          {
            rt->ins((*it).Y.Y,i,ii(a,b));
            mp.erase(it);
          }
          else (*it).Y.X--;
        }

      }
      for(auto &tmp:mp)rt->ins(tmp.Y.Y,q,tmp.X);
      rt->dfs();
      REP(i,q)cout<<ans[i]<<endl;
    }

}
