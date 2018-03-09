//{
#include<bits/stdc++.h>
using namespace std;
typedef int ll;
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

ll qr[MAXn],dph[MAXn],ct[MAXn];

priority_queue<ll,vector<ll>,greater<ll> > pq;
ll dt[MAXn];

int main()
{
    IOS();
    ll n,q;
    cin>>n>>q;
    REP(i,q)cin>>qr[i];
    dph[1]=0;ct[0]=1;
    for(int i=2;i<=n;i++)
    {
      ll t;
      cin>>t;
      dph[i]=dph[t]+1;
      ct[dph[i]]++;
    }
    ll mx=*max_element(dph+1,dph+n+1);
    for(int i=mx;i>=0;i--)
    {
      ll t=ct[i];
      while(SZ(pq)&&pq.top()<t)
      {
        ll x=pq.top();pq.pop();
        x++;t--;
        pq.push(x);
      }
      pq.push(t);
    }
    ll tt=n,ct=mx+1;
    REP1(i,1000000)
    {
      while(SZ(pq)&&pq.top()<=i)
      {
        tt-=pq.top();
        ct--;
        pq.pop();
      }
      if(tt)dt[i]=mx+1+(tt-i*ct-1)/i+1;
      else dt[i]=mx+1;
    }
    REP(i,q)cout<<dt[qr[i]]<<" \n"[i==q-1];
}
