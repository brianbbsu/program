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

struct node{
  ll l,r;
  node *lc,*rc;
  ll f[4],s[4],mn,pmxmn,nfmn,nsmn;
  node(ll li,ll ri,node *lci=0,node *rci=0):l(li),r(ri),lc(lci),rc(rci){f[0]=f[1]=INF;s[0]=s[1]=-INF;mn=pmxmn=nfmn=nsmn=INF;}

  ll calpmn(ll t,ll k);
  void pull();

  void ins(ll x,ll k)
  {
      if(l==r-1)
      {
        if(k==-1){f[0]=f[1]=INF;s[0]=s[1]=-INF;}
        else f[0]=s[0]=k;
      }
      else
      {
          if(x<(l+r)/2)lc->ins(x,k);
          else rc->ins(x,k);
          pull();
      }
  }
  void dbg()
  {
    debug(l,r,f[0],s[0],mn,pmxmn,nfmn,nsmn);
    if(l!=r-1)lc->dbg(),rc->dbg();
  }

  ii qrpmxmn()
  {
    if(l==r-1)return ii(l,f[0]);
    else
    {
      if(lc->f[0]==INF)return rc->qrpmxmn();
      else if(rc->f[0]==INF)return lc->qrpmxmn();
      else if(min(lc->calpmn(1,rc->f[0]),rc->mn)>=min(rc->calpmn(0,lc->s[0]),lc->mn))return lc->qrpmxmn();
      else return rc->qrpmxmn();
    }
  }

};

ll node::calpmn(ll t,ll k){
  ll rt=pmxmn;
  if(t==0)rt=max(rt,min(nfmn,f[1]-k));
  else rt=max(rt,min(nsmn,k-s[1]));
  return rt;
}
void node::pull()
{
  if(lc->s[0]==-INF&&rc->s[0]==-INF){f[0]=f[1]=INF;s[0]=s[1]=-INF;mn=pmxmn=nfmn=nsmn=INF;return;}
  if(lc->s[0]!=-INF&&rc->f[0]!=INF)
  {
    mn=min({rc->f[0]-lc->s[0],lc->mn,rc->mn});
    nfmn=min(rc->mn,lc->nfmn);
    if(lc->s[1]!=-INF)nfmn=min(nfmn,rc->f[0]-lc->s[0]);
    nsmn=min(rc->nsmn,lc->mn);
    if(rc->s[1]!=-INF)nsmn=min(nsmn,rc->f[0]-lc->s[0]);
  }
  else mn=min(lc->mn,rc->mn),nfmn=min(lc->nfmn,rc->nfmn),nsmn=min(lc->nsmn,rc->nsmn);

  // f
  f[0]=lc->f[0];f[1]=lc->f[1];
  f[2]=rc->f[0];f[3]=rc->f[1];
  sort(f,f+4);

  //s
  s[0]=lc->s[0];s[1]=lc->s[1];
  s[2]=rc->s[0];s[3]=rc->s[1];
  sort(s,s+4,greater<ll>());

  //pk
  if(lc->s[0]==-INF||rc->s[0]==-INF){pmxmn=min(lc->pmxmn,rc->pmxmn);return;}
  pmxmn=max(min(lc->calpmn(1,rc->f[0]),rc->mn),min(rc->calpmn(0,lc->s[0]),lc->mn));

}

node *build(ll l,ll r)
{
  if(l==r-1)return new node(l,r);
  else return new node(l,r,build(l,(l+r)/2),build((l+r)/2,r));
}
node *rt=0;


ll d[MAXn];
set<ii> st;


int main()
{
    IOS();
    ll n;
    string S;
    cin>>n>>S;
    REP(i,n)cin>>d[i];
    rt=build(0,n);
    REP(i,n)rt->ins(i,d[i]);
    rt->dbg();

    REP(i,n)st.insert(ii(i,d[i]));

    ll fg=(S=="Bob");

    REP(i,n-2)
    {
      if(fg==0)//mn->mx
      {
        ii t=rt->qrpmxmn();
        rt->ins(t.X,-1);
        debug(t.Y);
        st.erase(t);
      }
      else// mx->mn
      {
        if(prev(prev(st.end()))->Y-st.begin()->Y>prev(st.end())->Y-next(st.begin())->Y)//remove begin
        {
          debug(st.begin()->Y);
          rt->ins(st.begin()->X,-1);
          st.erase(st.begin());
        }
        else
        {
          rt->ins(prev(st.end())->X,-1);
          debug(prev(st.end())->Y);
          st.erase(prev(st.end()));
        }
      }
      fg=!fg;
    }
    cout<<next(st.begin())->Y-st.begin()->Y<<endl;
}
