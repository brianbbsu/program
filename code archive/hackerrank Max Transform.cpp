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


const ll MAXn=4e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007,neg2=(MOD+1)/2;
const ll INF=ll(1e15);

inline ll n2(ll x){return (x+1)*x%MOD*neg2%MOD;}
inline void sub(ll &a,ll b){
  a-=b;
  if(a<0)a+=MOD;
}
inline void add(ll &a,ll b){
  a+=b;
  if(a>=MOD)a-=MOD;
}
ll sn[MAXn];
inline ll atob(ll a,ll b){//[a,b]
  ll rt=sn[b];
  sub(rt,sn[max(a-1,0LL)]);
  return rt;
}

ll d[MAXn];
ll cal_single(ll n)
{
  ll rt=0,msum=0,cur=0;
  vector<ll> st;
  st.pb(-1);
  REP(i,n)
  {
    while(SZ(st)>1&&d[i]>=d[st.back()])
    {
      ll t=st.back();st.pop_back();
      sub(msum,(t-st.back())*d[t]%MOD);
      sub(cur,d[t]*atob(i-t,i-st.back()-1)%MOD);
    }
    add(msum,d[i]*(i-st.back())%MOD);
    add(cur,d[i]*atob(1,i-st.back()-1)%MOD);
    add(cur,msum);
    add(rt,cur);
    st.pb(i);
  }
  return rt;
}

ll cal_db(ll n)
{
  for(ll i=n-2;i>=0;i--)d[i]=max(d[i],d[i+1]);
  for(ll i=n+1;i<2*n;i++)d[i]=max(d[i],d[i-1]);
  ll rt=0;

  queue<ll> q;
  ll tt=0,cur=0;
  for(ll i=3;i<=n;i++)
  {
    ll t=n-(i-2);
    q.push(t);
    add(tt,(i-2)*d[t]%MOD);
    while(SZ(q)&&d[q.front()]<=d[n+i-1])
    {
      ll x=q.front();q.pop();
      sub(tt,d[x]*(n-x)%MOD);
      add(cur,(n-x));
    }
    add(rt,tt);
    add(rt,cur*d[n+i-1]%MOD);
  }
  while(SZ(q))q.pop();
  tt=0;cur=0;
  for(ll i=n-1;i>=0;i--)
  {
    if(i){
      ll t=n+(n-i);
      q.push(t);
      add(tt,d[t]*(n-i)%MOD);
    }
    while(SZ(q)&&d[q.front()]<=d[i])
    {
      ll x=q.front();q.pop();
      sub(tt,d[x]*(x-n)%MOD);
      add(cur,x-n);
    }
    add(rt,tt);
    add(rt,cur*d[i]%MOD);
  }
  return rt;
}

vector<ll> dt;

int main()
{
    IOS();
    sn[0]=0;
    REP1(i,MAXn-1)sn[i]=sn[i-1],add(sn[i],i);

    ll n;
    cin>>n;
    REP(i,n)cin>>d[i],d[i+n]=d[i];

    ll nnn=n2(n2(n));
    REP1(i,n)sub(nnn,(i*(i+1)/2)%MOD);
    REP1(i,n-1)sub(nnn,i*(i+1)%MOD);

    ll mx=*max_element(d,d+n);

    ll tri=nnn*mx%MOD,sig=cal_single(n),db=cal_db(n);

    cout<<(sig+db+tri)%MOD<<endl;
}
