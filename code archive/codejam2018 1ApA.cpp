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


const ll MAXn=1e2+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll d[MAXn][MAXn],dt[MAXn],g[MAXn][MAXn],tmp2[MAXn];

int main()
{
    IOS();
    ll T;cin>>T;
    ll kz=0;
    while(T--)
    {
      kz++;
      cout<<"Case #"<< kz <<": ";
      ll r,c,h,v;
      cin>>r>>c>>h>>v;
      ll tt=0;
      REP(i,r)
      {
        string s;
        cin>>s;
        REP(j,c)d[i][j] = (s[j] == '@');
      }
      REP(i,r)REP(j,c)tt+=d[i][j];
      if(tt%((h+1)*(v+1))!=0)
      {
        cout<<"IMPOSSIBLE"<<endl;
        continue;
      }
      tt /= ((h+1)*(v+1));
      bool fg=1;
      ll tmptt=0,itr=0;
      REP(i,c)dt[i]=0;
      REP(i,r)
      {
        REP(j,c)dt[j]+=d[i][j],tmptt+=d[i][j];
        if(tmptt>tt*(v+1))
        {
          fg=0;
          break;
        }
        if(tmptt == tt*(v+1))
        {
          REP(j,c)g[itr][j] = dt[j],dt[j]=0;
          itr++;tmptt=0;
        }
      }
      if(fg)
      {
        REP(i,h+1)tmp2[i]=0;
        REP(i,c)
        {
          REP(j,h+1)tmp2[j] += g[j][i];
          bool ok=1;
          REP(j,h+1)
          {
            if(tmp2[j]<tt)ok=0;
            if(tmp2[j]>tt)fg=0;
          }
          if(ok)REP(j,h+1)tmp2[j]=0;
        }
      }
      if(fg)cout<<"POSSIBLE"<<endl;
      else cout<<"IMPOSSIBLE"<<endl;
    }
}
