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


int main()
{
    IOS();/*
    const ll n = 15;
    ll mn=INF,mndt;
    REP(I,(1<<n))
    {
      string s=bitset<n>(I).to_string();
      unordered_set<string> st;
      REP(i,n)REP(j,i+1)
      {
        string tmp,rtmp;
        tmp=rtmp=s.substr(j,i-j+1);
        reverse(ALL(rtmp));
        if(tmp==rtmp)st.insert(tmp);
      }
      if(SZ(st)<mn)mn=SZ(st),mndt=I;
    }
    debug(mn,bitset<n>(mndt));*/
    ll n;
    cin>>n;
    if(n<=7)cout<<n<<endl<<string(n,'1')<<endl;
    else
    {
      if(n==8)cout<<7<<endl;
      else cout<<8<<endl;
      n-=2;
      cout<<"00";
      while(n)
      {
        REP(i,6)
        {
          cout<<"101100"[i];
          n--;
          if(!n)break;
        }
      }
      cout<<endl;
    }
}