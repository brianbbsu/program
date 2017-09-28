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


int main()
{
    IOS();
    string a,b;
    while(getline(cin,a)&&getline(cin,b)&&(a!="END"||b!="END"))
    {

      if(a!=b){cout<<"Password settings are not consistent."<<endl;continue;}
      if(SZ(a)<8||SZ(a)>12){cout<<"Password should contain 8 to 12 characters."<<endl;continue;}
      bool w=0,x=0,y=0,z=0;
      REP(i,SZ(a))
      {
        char c=a[i];
        if(isupper(c))w=1;
        else if(islower(c))x=1;
        else if(isdigit(c))y=1;
        else z=1;
      }
      if(!w){cout<<"Password should contain at least one upper-case alphabetical character."<<endl;continue;}
      if(!x){cout<<"Password should contain at least one lower-case alphabetical character."<<endl;continue;}
      if(!y){cout<<"Password should contain at least one number."<<endl;continue;}
      if(!z){cout<<"Password should contain at least one special character."<<endl;continue;}
      reverse(ALL(b));
      if(a==b){cout<<"Symmetric password is not allowed."<<endl;continue;}
      bool ok=1;
      for(int i=3;i<=6;i++)
      {
        string tmp=a.substr(0,i);
        bool fg=1;
        for(int j=0;j<SZ(a);j+=i)
        {
          ll t=min(i,SZ(a)-j);
          if(a.substr(j,t)!=tmp.substr(0,t))fg=0;
        }
        if(fg)ok=0;
      }
      if(!ok)cout<<"Circular password is not allowed."<<endl;
      else cout<<"Password is valid."<<endl;

    }
}
