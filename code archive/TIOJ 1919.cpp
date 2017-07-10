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

ll n,m,q;
namespace bit{
  ll bit[MAXn];
  void ins(ll x,ll k)
  {
    x++;
    while(x<=m)bit[x]+=k,x+=x&-x;
  }
  ll qr(ll x)
  {
    ll rt=0;
    x++;
    while(x>0)rt+=bit[x],x-=x&-x;
    return rt;
  }
}

struct tg{
  int l,r,c;
};
tg qr[MAXn];
int dt[MAXn],tmpdt[MAXn];
int d[MAXn],lt[MAXn],p[MAXn],g[MAXn],ans[MAXn];
ll tmpg[MAXn];

struct ch{
  int x,tp,id;
  ch(int xi,int tpi,int idi):x(xi),tp(tpi),id(idi){}
};
bool operator < (const ch &a,const ch &b){return make_pair(a.x,a.tp)>make_pair(b.x,b.tp);}
vector<ch> tmpch;

void cal(int l,int r,int qrl,int qrr)
{
  if(l==r)return;
  if(qrl==qrr-1)//base case
  {
    for(int i=l;i<r;i++)ans[dt[i]]=qrl;
    return;
  }

  ll qrh=(qrl+qrr)/2;

  tmpch.clear();
  for(int i=l;i<r;i++)
  {
    int it=lt[dt[i]];
    while(it!=-1)tmpch.pb(ch(it,1,dt[i])),it=p[it];
    tmpg[dt[i]]=0;
  }
  for(int i=qrl;i<qrh;i++)tmpch.pb(ch(qr[i].r,0,i));

  sort(ALL(tmpch));

  for(auto &tmp:tmpch)
  {
    if(tmp.tp==0)bit::ins(qr[tmp.id].l,qr[tmp.id].c);
    else tmpg[tmp.id]+=bit::qr(tmp.x)-bit::qr(p[tmp.x]);
    debug(l,r,qrl,qrr,tmp.x,tmp.id,tmp.tp);
  }

  for(int i=qrl;i<qrh;i++)bit::ins(qr[i].l,-qr[i].c);
  int itl=l,itr=r;
  for(int i=l;i<r;i++)
  {
    debug(qrl,qrh,qrr,dt[i],tmpg[dt[i]]);
    if(tmpg[dt[i]]>=g[dt[i]])tmpdt[itl++]=dt[i];
    else tmpdt[--itr]=dt[i],g[dt[i]]-=tmpg[dt[i]];
  }
  for(int i=l;i<r;i++)dt[i]=tmpdt[i];

  cal(l,itr,qrl,qrh);
  cal(itr,r,qrh,qrr);
}


int main()
{
    IOS();
    cin>>n>>m>>q;
    REP(i,m)cin>>d[i],d[i]--,p[i]=-1;
    REP(i,n)cin>>g[i],dt[i]=i,lt[i]=-1,ans[i]=q;
    REP(i,q)cin>>qr[i].l>>qr[i].r>>qr[i].c,qr[i].l--;
    REP(i,m)p[i]=lt[d[i]],lt[d[i]]=i;
    pary(p,p+m);
    cal(0,n,0,q+1);
    REP(i,n)cout<<(ans[i]==q?-1:ans[i]+1)<<endl;
}
