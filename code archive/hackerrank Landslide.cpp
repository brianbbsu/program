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

map<ll,ll> v[MAXn];

ll bit[MAXn];
void add(ll x,ll k){
  while(x<MAXn)
  {
    bit[x]+=k;
    x+=x&-x;
  }
}
ll qr(ll x){
  ll rt=0;
  while(x)rt+=bit[x],x-=x&-x;
  return rt;
}

ll ask(ll a,ll b)
{
  if(a>b)swap(a,b);
  return qr(b) - qr(a-1);
}

ll dph[MAXn],sz[MAXn],mxsz[MAXn],cp[MAXn],p[MAXn],in[MAXn],tit=0;

void predfs(ll now,ll pi)
{
  p[now] = pi;
  sz[now] = 1;
  mxsz[now] = -1;
  for(ii k:v[now])if(k.X!=pi)
  {
    dph[k.X] = dph[now] + 1;
    predfs(k.X,now);
    sz[now] += sz[k.X];
    if(mxsz[now] == -1 || sz[k.X] > sz[mxsz[now]])mxsz[now] = k.X;
  }
}
void build(ll now,ll pi)
{
  in[now] = ++tit;
  if(mxsz[now]!=-1)
  {
    ll t = mxsz[now];
    cp[t] = cp[now];
    build(t,now);
  }
  for(ii k:v[now])if(k.X!=pi&&k.X!=mxsz[now])
  {
    cp[k.X] = k.X;
    build(k.X,now);
  }
}
int main()
{
    IOS();
    ll n,q;
    cin>>n;
    REP(i,n-1)
    {
      ll a,b;
      cin>>a>>b;
      v[a][b] = 0;
      v[b][a] = 0;
    }
    predfs(1,-1);
    cp[1] = 1;
    build(1,-1);
    debug(123);
    cin>>q;
    while(q--)
    {
      debug(q);
      char tp;
      ll x,y;
      cin>>tp>>x>>y;
      debug(x,y);
      if(tp=='d')
      {
        if(dph[x] < dph[y])swap(x,y);
        auto it = v[x].find(y);
        if(it == v[x].end() || it->Y == 1)continue;
        it->Y = 1;
        add(in[x],1);
      }
      else if(tp == 'c')
      {
        if(dph[x] < dph[y])swap(x,y);
        auto it = v[x].find(y);
        if(it == v[x].end() || it->Y == 0)continue;
        it->Y = 0;
        add(in[x],-1);
      }
      else
      {
        ll tt=0;
        while(1)
        {
          debug(x,y,cp[x],cp[y]);
          if(cp[x] == cp[y])
          {
            if(x==y)break;
            if(dph[x] < dph[y])swap(x,y);
            ll t = ask(in[x],in[y] + 1);
            if(t)tt=-1;
            else tt += dph[x] - dph[y];
            break;
          }
          else
          {
            if(dph[cp[x]] < dph[cp[y]])swap(x,y);
            ll t = ask(in[x],in[cp[x]]);
            if(t)
            {
              tt = -1;
              break;
            }
            else tt+=dph[x] - dph[cp[x]] + 1,x = p[cp[x]];
          }
        }
        if(tt == -1)cout<<"Impossible"<<endl;
        else cout<<tt<<endl;
      }
    }
}
