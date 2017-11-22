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


const ll MAXn=1e5+5,MAXlg=32;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll srt,dt;

struct node;
node *crt();


struct node{
  ll cnt,sum;
  node *zero,*one;
  ll *btcnt;
  void ins(ll x,ll dph)
  {
    sum+=x;
    cnt++;
    if(dph<0)return;
    if(x&(1LL<<dph))
    {
      if(!one)one=crt();
      one->ins(x,dph-1);
      btcnt[dph]++;
    }
    else
    {
      if(!zero)zero=crt();
      zero->ins(x,dph-1);
      btcnt[dph]--;
    }
  }
  void dfs(ll dph)
  {
    if(zero)
    {
      zero->dfs(dph-1);
      for(int i=0;i<dph;i++)btcnt[i]+=zero->btcnt[i];
    }
    if(one)
    {
      one->dfs(dph-1);
      for(int i=0;i<dph;i++)btcnt[i]+=one->btcnt[i];
    }
  }
  ll cal(ll l,ll r,ll dph);
};
node *crt()
{
  node *tmp=new node{0,0,0,0,(new ll[MAXlg])};
  //FILL(tmp->btcnt,0);
  return tmp;
}
inline ll gcnt(node *a){return (a?a->cnt:0);}

ll mod(ll cnt,ll dph,ll bt)
{

  ll I=(1LL<<dph);
  //debug(cnt,dph,bt);
  if(I&dt)
  {
    if(bt)return -cnt*I;
    else return cnt*I;
  }
  else return 0;
}

ll node::cal(ll l,ll r,ll dph)
{
  if(r-l+1==cnt)
  {
    ll tt=sum;
    for(int i=0;i<dph;i++)tt+=mod(btcnt[i],i,1);
    return tt;
  }
  if(dph<0)return sum/cnt*(r-l+1);
  node *low,*high;ll lowbl;
  if((1LL<<dph)&srt)//1...0
  {
    low=one;high=zero;
    lowbl=1;
  }
  else //0...1
  {
    low=zero;high=one;
    lowbl=0;
  }
  ll tt=0,dd=gcnt(low);
  if(dd<l)
  {
    tt+=high->cal(l-dd,r-dd,dph-1);
    tt+=mod(r-l+1,dph,!lowbl);
  }
  else if(dd>=r)
  {
    tt+=low->cal(l,r,dph-1);
    tt+=mod(r-l+1,dph,lowbl);
  }
  else
  {
    tt+=low->cal(l,dd,dph-1)+high->cal(1,r-dd,dph-1);
    tt+=mod(dd-l+1,dph,lowbl)+mod(r-dd,dph,!lowbl);
  }
  //debug(dph,tt,sum,cnt);
  return tt;
}
node *rt=0;

int main()
{
    IOS();
    rt = crt();
    ll n,q;
    cin>>n>>q;
    REP(i,n)
    {
      ll t;
      cin>>t;
      rt->ins(t,MAXlg-1);
    }
    rt->dfs(MAXlg-1);
    REP(i,q)
    {
      ll t,a,b;
      cin>>t;
      if(t==1)
      {
        cin>>a;
        dt ^= a;
        continue;
      }
      else if(t==3)
      {
        srt = dt;
        continue;
      }
      cin>>a>>b;
      cout<<rt->cal(a,b,MAXlg-1)<<endl;
    }
}
