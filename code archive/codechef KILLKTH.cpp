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


const ll MAXn=2e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);


struct rec{
  ll i,j,h,w;
};
#ifdef brian
ostream& operator << (ostream &_s,const rec &_p){return _s<<"(i="<<_p.i<<",j="<<_p.j<<",h="<<_p.h<<",w="<<_p.w<<")";}
#endif
string s;
vector<rec> dt;
vector<ll> pre;

ll sa[MAXn],tmpsa[MAXn],rk[MAXn],h[MAXn],ct[MAXn];

ll is_diff(ll i,ll j,ll k,ll n)
{
  return (rk[i]!=rk[j])||(i+k>=n)||(j+k>=n)||(rk[i+k]!=rk[j+k]);
}

void mksa()
{
  ll n=SZ(s);
  REP(i,n)rk[i]=s[i]+1;
  for(ll k=1;k<n;k<<=1)
  {
    FILL(ct,0);
    REP(i,n)ct[(i+k<n?rk[i+k]:0)]++;
    partial_sum(ct,ct+max(n,256LL)+3,ct);
    for(int i=n-1;i>=0;i--)tmpsa[--ct[(i+k<n?rk[i+k]:0)]]=i;

    FILL(ct,0);
    REP(i,n)ct[rk[i]]++;
    partial_sum(ct,ct+max(n,256LL)+3,ct);
    for(int i=n-1;i>=0;i--)sa[--ct[rk[tmpsa[i]]]]=tmpsa[i];

    tmpsa[sa[0]]=1;
    REP1(i,n-1)tmpsa[sa[i]]=tmpsa[sa[i-1]]+is_diff(sa[i],sa[i-1],k,n);
    REP(i,n)rk[i]=tmpsa[i];
  }
}


int main()
{
    IOS();
    cin>>s;
    ll n=SZ(s);/*
    REP(i,n)sa[i]=i;
    sort(sa,sa+n,[&](int a,int b){return s.substr(a)<s.substr(b);});
    REP(i,n)rk[sa[i]]=i;*/
    mksa();
    REP(i,SZ(s))rk[i]--;
    pary(sa,sa+n);
    REP(i,n)
    {
      if(rk[i]==0)continue;
      if(i!=0)h[rk[i]]=max(0LL,h[rk[i-1]]-1);
      for(;sa[rk[i]-1]+h[rk[i]]<n&&i+h[rk[i]]<n&&s[sa[rk[i]-1]+h[rk[i]]]==s[i+h[rk[i]]];h[rk[i]]++);
    }
    pary(h,h+n);
    vector<ii> st;
    st.pb(ii(0,n));
    for(int i=n-1;i>=0;i--)
    {
      assert(SZ(st));
      ll t = max(st.back().X,h[i]);
      if(t!=n-sa[i])dt.pb({i,t,n-sa[i]-t,1});
      ll lt=i;
      while(st.back().X>h[i])
      {
        lt=st.back().Y;
        t=max(h[i],st[SZ(st)-2].X);
        dt.pb({i,t,st.back().X-t,lt-i+1});
        st.pop_back();
      }
      if(st.back().X!=h[i])st.pb(ii(h[i],lt));
    }
    reverse(ALL(dt));
    debug(dt);
    for(auto &tmp:dt)
    {
      pre.pb((tmp.j+1+tmp.j+tmp.h)*tmp.h/2*tmp.w);
    }
    partial_sum(ALL(pre),pre.begin());
    debug(pre);
    ll q;
    ll tt=0;
    cin>>q;
    while(q--)
    {
      ll p,m;
      cin>>p>>m;
      ll qr = (p*tt)%m+1;
      ll t=lower_bound(ALL(pre),qr)-pre.begin();
      if(t)qr-=pre[t-1];
      auto &tmp = dt[t];
      debug(qr,t,tmp);
      ll l=tmp.j,r=tmp.j+tmp.h;
      while(l!=r-1)
      {
        ll hh=(l+r)/2;
        if((tmp.j+1+hh)*(hh-tmp.j)/2*tmp.w<qr)l=hh;
        else r=hh;
      }
      qr-=(tmp.j+1+r-1)*(r-1-tmp.j)/2*tmp.w;
      qr=(qr-1)%r;
      char c=s[sa[tmp.i]+qr];
      cout<<c<<endl;
      tt+=c;
    }
}
