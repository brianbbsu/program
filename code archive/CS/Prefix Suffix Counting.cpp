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


const ll MAXn=1e6+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll d[MAXn];

void build_z(string s)
{
  ll n=SZ(s);

  ll t=-1,l=-1;
  for(int i=1;i<n;i++)
  {
    if(l<i)
    for(d[i]=0;d[i]+i<n&&s[d[i]]==s[d[i]+i];d[i]++);
    else if(d[i-t]>=l-i+1)
    for(d[i]=l-i+1;d[i]+i<n&&s[d[i]]==s[d[i]+i];d[i]++);
    else
    d[i]=d[i-t];
    if(i+d[i]-1>l)t=i,l=i+d[i]-1;
  }
}

int main()
{
    IOS();
    string n,m;
    cin>>n>>m;
    ll a=SZ(n),b=SZ(m);
    build_z(m);
    d[0]=b;
    if(a<b){cout<<0<<endl;return 0;}
    if(a<=2*b)
    {
      ll tt=0;
      REP(i,a-b+1)
      {
        if(d[i]!=b-i)continue;
        if(i!=a-b)tt++;
        else
        {
          string tmp=m+m.substr(b-i);
          if(tmp<=n)tt++;
          debug(tmp,n);
        }
      }
      cout<<tt<<endl;
      return 0;
    }
    ll tt=0;
    REP(i,b)
    {
      if(d[i]!=b-i)continue;
      tt++;
    }
    ll lt=a-2*b;
    ll nw=1;
    REP(i,lt)
    {
      tt+=nw;
      if(tt>=MOD)tt-=MOD;
      nw=nw*10%MOD;
    }
    if(n.substr(0,b)>m)
    {
      tt+=nw;
      if(tt>=MOD)tt-=MOD;
    }
    else if(n.substr(0,b)==m)
    {
      string q=n.substr(b,lt);
      ll tmp=0;
      for(char c:q)
      {
        tmp=tmp*10%MOD;
        tmp+=c-'0';
        if(tmp>=MOD)tmp-=MOD;
      }
      tmp++;
      if(n.substr(b+lt)<m)tmp--;
      if(tmp<0)tmp+=MOD;
      else if(tmp>=MOD)tmp-=MOD;
      tt+=tmp;
      if(tt>=MOD)tt-=MOD;
    }
    cout<<tt<<endl;

}
