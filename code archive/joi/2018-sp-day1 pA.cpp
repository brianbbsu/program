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
template<typename _a> ostream &operator << (ostream &_s,deque<_a> &_c){return _OUTC(_s,ALL(_c));}
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

ll d[MAXn],qr[MAXn],p[MAXn];
vector<ll> v[MAXn];
ll sz[MAXn],mxid[MAXn],cid[MAXn],cp[MAXn],dph[MAXn],bit[MAXn],cit=0;

deque<ii> stk[MAXn];
vector<ii> his;

void ins(ll x,ll k)
{
  while(x<MAXn)bit[x]+=k,x+=x&-x;
}
ll bqr(ll x)
{
  ll rt=0;
  while(x)rt+=bit[x],x-=x&-x;
  return rt;
}

ll cal(vector<ii> dt)
{
  vector<ll> uni;
  his.clear();
  for(ii tmp:dt)uni.pb(tmp.X);
  sort(ALL(uni));
  uni.resize(unique(ALL(uni))-uni.begin());
  ll tt=0;
  for(ii tmp:dt)
  {
    ll t=lower_bound(ALL(uni),tmp.X)-uni.begin()+1;
    tt+=tmp.Y*bqr(t-1);
    ins(t,tmp.Y);
    his.pb(ii(t,tmp.Y));
  }
  for(ii tmp:his)ins(tmp.X,-tmp.Y);
  return tt;
}

void predfs(int now)
{
  sz[now]=1;mxid[now]=-1;
  for(ll k:v[now])
  {
    dph[k]=dph[now]+1;
    predfs(k);
    sz[now]+=sz[k];
    if(mxid[now]==-1||sz[mxid[now]]<sz[k])mxid[now]=k;
  }
}
void build(int now,int c)
{
  cid[now]=c;
  if(mxid[now]!=-1)
  {
    ll t=mxid[now];
    cp[t]=cp[now];
    build(t,c);
  }
  for(ll k:v[now])if(k!=mxid[now])
  {
    cp[k]=now;
    build(k,cit++);
  }
}

int main()
{
    IOS();
    ll n;
    cin>>n;
    REP1(i,n)cin>>d[i];
    REP(i,n-1)
    {
      ll a,b;
      cin>>a>>b;
      v[a].pb(b);
      p[b]=a;
      qr[i]=b;
    }
    dph[1]=1;
    predfs(1);
    build(1,cit++);
    REP1(i,n)debug(i,cid[i]);
    stk[cid[1]].pb(ii(d[1],1));

    REP(q,n-1)
    {
      ll t=qr[q];
      stk[cid[t]].pb(ii(d[t],1));
      vector<ii> dt;
      int now=p[t];
      while(now)
      {
        ll ct=dph[now]-dph[cp[now]];
        //debug(q,now,ct);
        vector<ii> tmp;
        deque<ii> &dq = stk[cid[now]];
        while(ct)
        {
          if(ct>=dq.front().Y){
            tmp.pb(dq.front());
            dq.pop_front();
          }
          else
          {
            tmp.pb(ii(dq.front().X,ct));
            dq.front().Y-=ct;
          }
          ct-=tmp.back().Y;
        }
        dq.push_front(ii(d[t],dph[now]-dph[cp[now]]));
        reverse(ALL(tmp));
        for(ii k:tmp)dt.pb(k);
        now=cp[now];
      }
      //reverse(ALL(dt));
      //debug(t,d[t],dt);
      //debug(qr[q],p[qr[q]]);
      //REP(i,cit)debug(i,stk[i]);
      cout<<cal(dt)<<endl;
    }
}
