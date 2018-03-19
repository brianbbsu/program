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

int st[MAXn],ct[MAXn];

int d[MAXn],inp[MAXn],dt[MAXn],p[MAXn],dtit=0;

int main()
{
    IOS();
    ll n;
    cin>>n;
    REP(i,n)cin>>d[i];
    FILL(st,-1);
    REP(i,n)p[i]=i;
    sort(p,p+n,[](int a,int b){return ii(d[a],a)<ii(d[b],b);});
    REP(i,n)
    {
      ll t=d[p[i]];
      if(st[t]==-1)st[t]=dtit;
      ct[t]++;
      dt[dtit++]=p[i];
    }
    ll q;
    cin>>q;
    while(q--)
    {
      ll l;
      cin>>l;
      REP(i,l)cin>>inp[i];
      ll now=-1,ok=1;
      REP(i,l)
      {
        ll bl=st[inp[i]]-1,br=st[inp[i]]+ct[inp[i]];
        while(bl!=br-1)
        {
          ll h=(bl+br)/2;
          if(dt[h]>now)br=h;
          else bl=h;
        }
        if(st[inp[i]]+ct[inp[i]]>br)now=dt[br];
        else {ok=0;break;}
      }
      if(ok)cout<<"TAK"<<endl;
      else cout<<"NIE"<<endl;
    }
}
