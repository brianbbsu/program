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

ii edg[]={ii(0,3),ii(1,4),ii(2,3),ii(3,4),ii(4,5),ii(3,7),ii(4,8),ii(6,7),ii(7,8),ii(8,9),ii(7,10),ii(8,11)};
const ll N=12;

bool dp[(1<<N)];

int main()
{
    IOS();
    dp[0]=1;
    REP1(I,(1<<N)-1)
    {
      bool tmp=0;
      REP(j,N)if((I&(1<<j))&&dp[(I&(~(1<<j)))]==0)tmp=1;
      REP(k,N)if((I&(1<<edg[k].X))&&(I&(1<<edg[k].Y))&&dp[(I&(~(1<<edg[k].X))&(~(1<<edg[k].Y)))]==0)tmp=1;
      dp[I]=tmp;
    }
    debug("fin");
    ll T;
    cin>>T;
    while(T--)
    {
      string s;
      cin>>s;
      ll tmp=0;
      REP(i,N)if(s[i]=='1')tmp+=(1<<i);
      cout<<dp[tmp];
    }
    cout<<endl;
}
