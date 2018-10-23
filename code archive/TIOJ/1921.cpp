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
const ll INF=ll(1e17),SINF=1e9+5;

struct seg{
  ll a,b,l,r;
  seg(ll ai,ll bi,ll li,ll ri):a(ai),b(bi),l(li),r(ri){}
  ll operator () (ll x)const{return a*x+b;}
};
bool swt=0;//0=slope 1=pos
bool operator < (const seg &a,const seg &b){
  if(swt==0)//slope
  {
    return a.a<b.a;
  }
  else//pos
  {
    debug(a,b);
    return a.r<b.l;
  }
}
set<seg> st;

struct mach{
  ll p,r,d,g;
  bool operator < (const mach &t)const{return d<t.d;}
};
#ifdef brian
ostream& operator << (ostream  &_ss,const seg &_t){return _ss<<_t.a<<"x+"<<_t.b<<":"<<ii(_t.l,_t.r);}
#endif
mach d[MAXn];
ll dp[MAXn];

int main()
{
    IOS();
    ll n,C,D;
    cin>>n>>C>>D;
    REP(i,n)cin>>d[i].d>>d[i].p>>d[i].r>>d[i].g;

    d[n].p=d[n].r=d[n].g=d[n].d=0;
    d[n+1].p=d[n+1].r=0;d[n+1].d=D+1;
    dp[0]=C;
    n+=2;
    sort(d,d+n);
    st.insert(seg(0,C,0,SINF));
    REP1(i,n-1)
    {
      debug(i,st);
      swt=1;
      seg fr=*st.lower_bound(seg(0,0,d[i].d,d[i].d));
      debug(i,fr,d[i].d,fr(d[i].d));
      dp[i]=fr(d[i].d);
      swt=0;
      if(dp[i]>=d[i].p)dp[i]+=d[i].r-d[i].p;
      else continue;
      seg tmp=seg(d[i].g,-d[i].g*(d[i].d+1)+dp[i],0,SINF);
      auto it=st.lower_bound(tmp);
      bool b=0;
      while(it!=st.end())
      {
        if((*it)(it->l)>tmp(it->l)&&(*it)(it->r)>tmp(it->r)){b=1;break;}
        else if((*it)(it->l)<=tmp(it->l)&&(*it)(it->r)<=tmp(it->r))it=st.erase(it);
        else break;
      }
      if(b)continue;
      while(it!=st.begin())
      {
        it--;
        if((*it)(it->l)<=tmp(it->l)&&(*it)(it->r)<=tmp(it->r))it=st.erase(it);
        else {it++;break;}
      }
      if(it!=st.begin())
      {
        it--;
        seg p=*it;
        it=st.erase(it);
        tmp.l=(tmp.b-p.b)/(p.a-tmp.a)+1;
        p.r=tmp.l-1;
        st.insert(p);
      }
      if(it!=st.end())
      {
        seg p=*it;
        st.erase(it);
        tmp.r=(tmp.b-p.b)/(p.a-tmp.a);
        p.l=tmp.r+1;
        st.insert(p);
      }
      st.insert(tmp);
    }
    cout<<dp[n-1]<<endl;
    pary(dp,dp+n);
}
