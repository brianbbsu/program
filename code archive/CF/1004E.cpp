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

vector<ii> v[MAXn];
ll h[MAXn][2],mxdis[MAXn],mn,dg[MAXn],tp[MAXn];
priority_queue<ii,vector<ii>,greater<ii> > pq;

void hdfs(ll now,ll f)
{
  h[now][0] = h[now][1] = 0;
  for(ii k:v[now])if(k.X != f)
  {
    tp[k.X] = k.Y;
    hdfs(k.X,now);
    ll x = h[k.X][0] + k.Y;
    if(x > h[now][0])h[now][1] = h[now][0],h[now][0] = x;
    else if(x>h[now][1])h[now][1] = x;
  }
}

void disdfs(ll now,ll f,ll top)
{
  mxdis[now] = max(top,h[now][0]);
  for(ii k:v[now])if(k.X != f)
  {
    disdfs(k.X,now,max(top,(h[k.X][0] + k.Y == h[now][0]?h[now][1]:h[now][0])) + k.Y);
  }
  mn = min(mn,mxdis[now]);
}


int main()
{
    IOS();
    ll n,k;
    cin>>n>>k;
    REP(i,n-1)
    {
      ll a,b,c;
      cin>>a>>b>>c;
      v[a].pb({b,c});
      v[b].pb({a,c});
      dg[a]++;
      dg[b]++;
    }
    hdfs(1,-1);
    mn=INF;
    disdfs(1,-1,0);
    ll rt=-1;
    REP1(i,n)if(mxdis[i] == mn)
    {
      rt = i;
      break;
    }
    tp[rt] = 0;
    hdfs(rt,-1);
    ll tt = n,mx=0;
    REP1(i,n)if(dg[i] == 1)pq.push({h[i][0] + tp[i],i});
    while(SZ(pq) > 2 || tt > k)
    {
      tt -- ;
      ll x = pq.top().Y;
      mx = max(mx,pq.top().X);
      pq.pop();
      for(ii p:v[x])
      {
        dg[p.X]--;
        if(dg[p.X] == 1)pq.push({h[p.X][0] + tp[p.X],p.X});
      }
    }
    cout<<mx<<endl;
}
