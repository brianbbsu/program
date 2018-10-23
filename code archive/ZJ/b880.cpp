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


const ll MAXn=1e6+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

const ll MAXs=3*MAXn;

//#define max(_a,_b) ((_a) < (_b) ? (_a) : (_b))

ll x[MAXn],y[MAXn];


struct segt
{
  ll l[MAXs],r[MAXs],lc[MAXs],rc[MAXs],mny[MAXs],tg[MAXs],d[MAXs];
  ll nit=0;
  ll crt(ll li,ll ri,ll lci=-1,ll rci=-1)
  {
    ll t=nit++;
    l[t]=li;r[t]=ri;
    lc[t]=lci;rc[t]=rci;
    tg[t]=INF;
    if(li==ri-1)mny[t]=y[li],d[t]=x[li]+y[li];
    else mny[t]=min(mny[lc[t]],mny[rc[t]]),d[t]=min(d[lc[t]],d[rc[t]]);
    return t;
  }
  ll build(ll li,ll ri)
  {
    if(li==ri-1)return crt(li,ri);
    else return crt(li,ri,build(li,(li+ri)/2),build((li+ri)/2,ri));
  }
  void ins(ll id,ll li,ll ri,ll k)
  {
    if(li>=r[id]||ri<=l[id])return;
    else if(li<=l[id]&&ri>=r[id])tg[id]=min(tg[id],k),d[id]=min(d[id],tg[id]+mny[id]);
    else
    {
      ins(lc[id],li,ri,k);
      ins(rc[id],li,ri,k);
      d[id]=min({d[id],d[lc[id]],d[rc[id]]});
    }
  }
  ll qr(ll id,ll li,ll ri,ll tt=INF)
  {
    if(li>=r[id]||ri<=l[id])return INF;
    else if(li<=l[id]&&ri>=r[id])return min(d[id],mny[id]+tt);
    else return min(qr(lc[id],li,ri,min(tt,tg[id])),qr(rc[id],li,ri,min(tt,tg[id])));
  }
}seg;
ll rt=0;
int main()
{
    IOS();
    ll n,q;
    cin>>n;
    REP(i,n)cin>>x[i];
    REP(i,n)cin>>y[i];
    cin>>q;
    rt=seg.build(0,n);

    REP(i,q)
    {
      char c;
      cin>>c;
      if(c=='c')
      {
        ll l,r,k;
        cin>>l>>r>>k;
        seg.ins(rt,l-1,r,k);
      }
      else
      {
        ll l,r;
        cin>>l>>r;
        cout<<seg.qr(rt,l-1,r)<<endl;
      }

    }

}
