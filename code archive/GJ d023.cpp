//{
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<string>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<sstream>
#include<cmath>

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


inline char p(char c){return !(c-'0')+'0';}

string p1(string a)
{
  REP(i,SZ(a))a[i]=p(a[i]);
  return a;
}
string p2(string a)
{
  REP(i,SZ(a))if((i+1)%2==1)a[i]=p(a[i]);
  return a;
}
string p3(string a)
{
  REP(i,SZ(a))if((i+1)%2==0)a[i]=p(a[i]);
  return a;
}
string p4(string a)
{
  REP(i,SZ(a))if((i+1)%3==1)a[i]=p(a[i]);
  return a;
}
int main()
{
    IOS();
    char c;
    string s,t;
    ll n;
    cin>>c>>c>>n;
    cin>>s>>t;
    s=s.substr(2);
    t=t.substr(2);
    ll ct=INF,ans;
    REP(i,(1<<4))
    {
      string tmp=s;
      ll tct=0;
      if(i&1)
      {
        tct++;
        tmp=p4(tmp);
      }
      if(i&2)
      {
        tct++;
        tmp=p1(tmp);
      }
      if(i&4)
      {
        tct++;
        tmp=p2(tmp);
      }
      if(i&8)
      {
        tct++;
        tmp=p3(tmp);
      }
      if(tmp==t)
      {
        if(tct<ct)ans=i,ct=tct;
      }
    }
    if(ct==INF){
      cout<<"無解"<<endl;
      return 0;
    }
    if(ans&1)
    {
      s=p4(s);
      cout<<"P4:"<<s<<endl;
    }
    if(ans&2)
    {
      s=p1(s);
      cout<<"P1:"<<s<<endl;
    }
    if(ans&4)
    {
      s=p2(s);
      cout<<"P2:"<<s<<endl;
    }
    if(ans&8)
    {
      s=p3(s);
      cout<<"P3:"<<s<<endl;
    }
}
