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


ll ct[100];
ll md[10];

void qt(bool b)
{
  if(b)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  exit(0);
}

int main()
{
    IOS();
    ll r,c;
    cin>>r>>c;
    REP(i,r)
    {
      string s;
      cin>>s;
      REP(j,c)ct[s[j]-'a']++;
    }
    REP(i,26)md[ct[i]&3]++;

    bool tr=(r&1),tc=(c&1);

    if(!tr&&!tc)
    {
      if(md[0]!=26)qt(0);
      else qt(1);
    }
    else if(tr^tc)
    {
      ll t=(tr?c:r);
      t/=2;
      if(md[1]||md[3])qt(0);
      if(md[2]>t)qt(0);
      if((t-md[2])%2!=0)qt(0);
      else qt(1);
    }
    else
    {
      ll t=c+r-2;
      t/=2;
      if(md[1]&&md[3])qt(0);
      else if(md[1])md[0]++;
      else if(md[3])md[2]++;
      else qt(0);
      if(md[2]>t)qt(0);
      if((t-md[2])%2!=0)qt(0);
      else qt(1);

    }
}
