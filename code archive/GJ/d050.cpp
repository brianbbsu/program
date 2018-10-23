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

ll tt[5][200],ct[5][200];

int main()
{
    IOS();
    ll T,r,c;
    cin>>T;
    while(T--&&cin>>r>>c)
    {
      FILL(tt,0);FILL(ct,0);
      REP1(i,r)REP1(j,c)
      {
        ll t;
        cin>>t;
        ct[0][i]+=t;
        ct[1][j]+=t;
      }

      REP1(i,r)tt[0][i]=ct[0][i]*i+tt[0][i-1];
      REP1(i,c)tt[1][i]=ct[1][i]*i+tt[1][i-1];
      REP1(i,r)ct[0][i]+=ct[0][i-1];
      REP1(i,c)ct[1][i]+=ct[1][i-1];
      ll x=-1,y=-1,tx=INF,ty=INF;
      REP1(i,r)
      {
        ll tmp=(tt[0][r]-tt[0][i])-(ct[0][r]-ct[0][i])*i+i*ct[0][i-1]-tt[0][i-1];
        if(tmp<tx)tx=tmp,x=i;
      }
      REP1(i,c)
      {
        ll tmp=(tt[1][c]-tt[1][i])-(ct[1][c]-ct[1][i])*i+i*ct[1][i-1]-tt[1][i-1];
        if(tmp<ty)ty=tmp,y=i;
      }
      cout<<x<<" "<<y<<endl<<(tx+ty)*100<<endl;
    }
}
