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


const ll MAXn=2e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);



ll n,m;

ll d[MAXn],tmpd[MAXn];
ii op[3*MAXn];
bool vis[MAXn];

bool chk(int k)
{
  REP(i,n)tmpd[i]=d[i];
  REP(i,k)swap(tmpd[op[i].X],tmpd[op[i].Y]);
  memset(vis,0,sizeof(bool)*n);
  ll cnt=0;
  REP(i,n)
  {
    if(!vis[i])
    {
      int now=i;
      vis[now]=1;
      while(!vis[tmpd[now]])
      {
        now=tmpd[now];
        vis[now]=1;
        cnt++;
      }
    }
  }
  debug(k,cnt);
  return cnt<=k;
}

vector<ii> sp;

int p[MAXn];



int main()
{
    IOS();
    ll T;
    cin>>T;
    while(T--)
    {
      cin>>n;
      REP(i,n)cin>>d[i];
      cin>>m;
      REP(i,m)cin>>op[i].X>>op[i].Y;
      ll l=-1,r=m;
      while(l!=r-1)
      {
        ll h=(l+r)/2;
        if(chk(h))r=h;
        else l=h;
      }
      debug(r);
      REP(i,n)tmpd[i]=d[i];
      REP(i,r)swap(tmpd[op[i].X],tmpd[op[i].Y]);
      sp.clear();
      memset(vis,0,sizeof(bool)*n);
      REP(i,n)
      {
        if(!vis[i])
        {
          int now=i;
          vis[now]=1;
          while(!vis[tmpd[now]])
          {
            sp.pb(ii(now,tmpd[now]));
            now=tmpd[now];
            vis[now]=1;
          }
        }
      }
      while(SZ(sp)<r)sp.pb(ii(0,0));
      debug(sp);
      REP(i,n)p[d[i]]=i;
      cout<<r<<endl;
      REP(i,r)
      {
        swap(p[d[op[i].X]],p[d[op[i].Y]]);
        swap(d[op[i].X],d[op[i].Y]);
        cout<<p[sp[i].X]<<" "<<p[sp[i].Y]<<endl;
        swap(p[sp[i].X],p[sp[i].Y]);
        swap(d[p[sp[i].X]],d[p[sp[i].Y]]);
      }
    }
}
