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


struct val{
  ll d,md;
  bool fg;
  val(ll di=0):d(di),md(di),fg(0){}
};
val operator * (const val &a,const val &b)
{
  val rt;
  rt.md=a.md*b.md%MOD;
  if(a.fg||b.fg)rt.fg=1;
  else rt.d=a.d*b.d;
  if(rt.d>1000000000)rt.fg=1;
  return rt;
}
bool operator < (const val &a,const val &b)
{
  if(b.fg)return 1;
  else return a.d<b.d;
}

struct tg{
  val tt,ans,bk,ansy;
  tg(ll xi=1,ll yi=1):tt(xi),bk(1),ansy(yi){ans=val(xi)*val(yi);}
};

tg operator + (const tg &a,const tg &b)
{
  tg rt;
  rt.tt=a.tt*b.tt;
  if(a.ansy<a.bk*b.ans)
  {
    rt.ans=a.tt*b.ans;
    rt.ansy=b.ansy;
    rt.bk=b.bk;
  }
  else
  {
    rt.ans=a.ans;
    rt.ansy=a.ansy;
    rt.bk=a.bk*b.tt;
  }
  return rt;
}

tg seg[4*MAXn];

ll d[2][MAXn];

void build(int id,int l,int r)
{
  if(l==r-1)
  {
    seg[id]=tg(d[0][l],d[1][l]);
  }
  else
  {
    build(id<<1,l,(l+r)>>1);
    build((id<<1)+1,(l+r)>>1,r);
    seg[id]=seg[id<<1]+seg[(id<<1)+1];
  }
}
void ins(int id,int l,int r,int x)
{
  if(l==r-1)seg[id]=tg(d[0][l],d[1][l]);
  else
  {
    if(x<((l+r)>>1))ins(id<<1,l,(l+r)>>1,x);
    else ins((id<<1)+1,(l+r)>>1,r,x);
    seg[id]=seg[id<<1]+seg[(id<<1)+1];
  }
}

int main()
{
    IOS();
    int T;
    cin>>T;
    while(T--)
    {
      ll n;
      cin>>n;
      REP(i,n)cin>>d[0][i];
      REP(i,n)cin>>d[1][i];
      build(1,0,n);
      cout<<seg[1].ans.md<<endl;
      int q;
      cin>>q;
      while(q--)
      {
        int k,p,v;
        cin>>k>>p>>v;
        k--;
        d[k][p]=v;
        ins(1,0,n,p);
        cout<<seg[1].ans.md<<endl;
      }
    }
}
