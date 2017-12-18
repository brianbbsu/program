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

string _taskname;
void _init()
{
  #ifndef brian
      freopen((_taskname+".in").c_str(), "r", stdin);
      freopen((_taskname+".out").c_str(),"w",stdout);
  #endif
}
void _end()
{
  #ifndef brian
      fclose( stdin);
      fclose(stdout);
  #endif
}




string d[MAXn],s="";
ll sa[MAXn],tmpsa[MAXn],rk[MAXn],h[MAXn],ct[MAXn];
ll pre[MAXn],dt[MAXn],ans[MAXn];

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
  _taskname = "standingout";
  _init();
  ll n;
  cin>>n;
  REP(i,n)cin>>d[i],d[i].pb('@'),s+=d[i];

  mksa();
  debug(s);

  pary(sa,sa+SZ(s));

  REP(i,SZ(s))rk[i]--;
  REP(i,SZ(s))
  {
    if(rk[i])
    {
      if(i)h[rk[i]]=max(0LL,h[rk[i-1]]-1);
      for(;h[rk[i]]+i<SZ(s)&&s[i+h[rk[i]]]==s[sa[rk[i]-1]+h[rk[i]]];h[rk[i]]++);
    }
  }

  REP(i,n)pre[i+1]=SZ(d[i]);
  partial_sum(pre,pre+n,pre);

  REP(i,n)REP(j,SZ(d[i]))dt[pre[i]+j]=i;
  deque<ll> dq;ll it=0;dt[SZ(s)]=n;sa[SZ(s)]=SZ(s);
  REP(i,SZ(s))
  {
    if(it==i)
    {
      dq.clear();
      do{
        it++;
        while(SZ(dq)&&h[dq.back()]>=h[it])dq.pop_back();
        dq.pb(it);
      }while(dt[sa[it]]==dt[sa[i]]);
    }
    while(dq.front()<=i)dq.pop_front();
    ll t=sa[i],th=max(h[i],h[dq.front()]),id=dt[t],l=pre[id]+SZ(d[id])-t-1;
    ans[id]+=max(0LL,l-th);
  }
  REP(i,n)cout<<ans[i]<<endl;
  _end();
}
