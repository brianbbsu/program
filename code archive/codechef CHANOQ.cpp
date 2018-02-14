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

const ll K=77;
ll sl[MAXn],sr[MAXn],p[MAXn],dt[MAXn];

ll ans[MAXn],srt[MAXn];

struct tg{ll x,tp,id;};
#ifdef brian
ostream& operator << (ostream &_s,const tg &_p){return _s<<"(x= "<<_p.x<<", tp= "<<_p.tp<<", id= "<<_p.id<<")";}
#endif
vector<tg> v[MAXn];

int bit[MAXn];

void ins(int x,int n)
{
  while(x<=n)bit[x]++,x+=x&-x;
}
inline int qr(int x)
{
  int rt=0;
  while(x)rt+=bit[x],x-=x&-x;
  return rt;
}

int main()
{
    IOS();
    ll T;
    cin>>T;
    while(T--)
    {
      ll n;
      cin>>n;
      REP(i,n)cin>>sl[i]>>sr[i];
      REP(i,n)srt[i]=i;
      REP1(i,n)v[i].clear(),v[i].shrink_to_fit(),bit[i]=0;
      ll q;
      cin>>q;
      REP(i,q)ans[i]=0;
      REP(Q,q)
      {
        ll k;
        cin>>k;
        REP(i,k)cin>>p[i];
        sort(p,p+k);
        if(k<K)
        {
          REP(j,k)REP(i,j+1)
          {
            if((j-i+1)==1)v[p[j]].pb({p[i],1,Q});
            else if((j-i+1)&1)v[p[j]].pb({p[i],2,Q});
            else v[p[j]].pb({p[i],-2,Q});
          }
        }
        else
        {
          REP(i,n+2)dt[i]=0;
          REP(i,k)dt[p[i]]++;
          REP1(i,n)dt[i]+=dt[i-1];
          ll tt=0;
          REP(i,n)if((dt[sr[i]]-dt[sl[i]-1])%2==1)tt++;
          ans[Q]=tt;
        }
      }
      sort(srt,srt+n,[&](int a,int b){return sr[a]>sr[b];});
      //REP1(i,n)debug(i,v[i]);
      ll it=0;
      for(int i=n;i>0;i--)
      {
        while(it<n&&sr[srt[it]]>=i)ins(sl[srt[it++]],n);
        for(auto &tmp:v[i])ans[tmp.id]+=tmp.tp*qr(tmp.x);
      }
      REP(i,q)cout<<ans[i]<<endl;
    }
}
