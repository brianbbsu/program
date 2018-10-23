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


struct node{
  ll flg;
  node *zero,*one;
  void ins(uint x,int t)
  {
    if(t==0)flg=1;
    else
    {
      if(x&(uint(1)<<(t-1)))
      {
        if(!one)one=new node{0,0,0};
        one->ins(x,t-1);
      }
      else
      {
        if(!zero)zero=new node{0,0,0};
        zero->ins(x,t-1);
      }
    }
  }
  bool qr(uint x,int t)
  {
    if(t==0||flg)return flg;
    else
    {
      if(x&(uint(1)<<(t-1)))
      {
        if(!one)return 0;
        else return one->qr(x,t-1);
      }
      else
      {
        if(!zero)return 0;
        else return zero->qr(x,t-1);
      }
    }
  }
};

uint ip(string s)
{
  uint a,b,c,d;
  sscanf(s.c_str(),"%u.%u.%u.%u",&a,&b,&c,&d);
  debug(a,b,c,d);
  return (a<<24)+(b<<16)+(c<<8)+d;
}

inline uint gmsk(ll sz)
{
  return (((uint(1)<<sz)-1)<<(32-sz));
}

ll mystoi(string s){
  stringstream ss(s);
  ll rt;ss>>rt;
  return rt;
}


node *rt=new node{0,0,0};

int main()
{
    IOS();
    ll m,n;
    cin>>m>>n;
    REP(i,m)
    {
      string s;
      cin>>s;
      REP(j,SZ(s))if(s[j]=='/')
      {
        int l=mystoi(s.substr(j+1));
        rt->ins(ip(s.substr(0,j))>>(32-l),l);
      }
    }
    REP(i,n)
    {
      string s;
      cin>>s;
      uint d=ip(s);
      if(rt->qr(d,32))cout<<"TRUE"<<endl;
      else cout<<"FALSE"<<endl;
    }
}
