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
const ll MOD=888888888919;
const ll INF=ll(1e15);



ll myrand()
{
  ll rt=0;
  REP(i,13)rt=rt*10+((ll)rand()>>5)%10;
  return rt%MOD;
}

ll sed[MAXn];

ll bit[3000][3000];

ll cal(ll x,ll y)
{
  ll rt=0;
  while(x>0)
  {
    ll tp=y;
    while(tp>0)
    {
      rt+=bit[x][tp];
      tp-=tp&-tp;
    }
    x-=x&-x;
  }
  return rt%MOD;
}

const ll MAXc=3000;

void ins(ll x,ll y,ll t)
{
  t=(t+MOD)%MOD;
  while(x<MAXc)
  {
    ll tp=y;
    while(tp<MAXc)
    {
      bit[x][tp]=bit[x][tp]+t;
      if(bit[x][tp]>=MOD)bit[x][tp]-=MOD;
      tp+=tp&-tp;
    }
    x+=x&-x;
  }
}
map<ll,ll> mp;
ll hs(ll a,ll b,ll c,ll d)
{
  return a*MAXc*MAXc*MAXc+b*MAXc*MAXc+c*MAXc+d;
}


int main()
{
    IOS();
    srand(time(NULL));
    ll n,m,q;
    cin>>n>>m>>q;
    debug(RAND_MAX);
    REP(i,q)sed[i]=myrand();
    FILL(bit,0);

    REP(i,q)
    {
      ll tp;
      ll r1,c1,r2,c2;
      cin>>tp>>r1>>c1>>r2>>c2;
      if(tp==3)
      {
        ll a=cal(r1,c1),b=cal(r2,c2);
        if(a==b)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
      }
      else if(tp==1)//add
      {
        ll h=hs(r1,c1,r2,c2);
        mp[h]=i;
        ins(r1,c1,sed[i]);
        ins(r2+1,c2+1,sed[i]);
        ins(r1,c2+1,-sed[i]);
        ins(r2+1,c1,-sed[i]);
      }
      else //rm
      {
        ll h=hs(r1,c1,r2,c2);
        ll it=mp[h];
        mp.erase(h);
        ins(r1,c1,-sed[it]);
        ins(r2+1,c2+1,-sed[it]);
        ins(r1,c2+1,sed[it]);
        ins(r2+1,c1,sed[it]);
      }
    }
}
