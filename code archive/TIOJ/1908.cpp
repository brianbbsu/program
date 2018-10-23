//{
#include<bits/stdc++.h>
using namespace std;
typedef int ll;
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

ll dp[2][(1<<22)];
bool b[(1<<22)];
ll ct[(1<<22)];
ll d[30][30];
ll lg[(1<<22)];

int main()
{
    IOS();


    ll n;
    cin>>n;
    REP(i,n)REP(j,n)cin>>d[i][j];
    REP(I,(1<<n))
    {
      b[I]=1;
      for(int j=0,J=1;j<22;j++,J<<=1)
      {
        if(J&I)if((I&(J<<1)))
        {
          b[I]=0;
          break;
        }
      }
    }
    REP(i,n)lg[(1<<i)]=i;
    bool fg=0;
    REP(i,n)
    {
      fg=!fg;
      REP(I,(1<<n))dp[fg][I]=0;

      REP(I,(1<<n))
      {
        if(!b[I])continue;
        ll T=(1<<n)-1,tt=0;
        ll tmp=I;
        while(tmp)
        {
          ll J=tmp&-tmp;
          tt+=d[i][lg[J]];
          T=((T<<1)&(~(7<<lg[J])))>>1;
          tmp-=J;
          //else tmp.pb(J);
        }
        //debug(bitset<3>(I),bitset<3>(T));
        dp[fg][I]=dp[!fg][T]+tt;
        /*for(int j=0,J=1;j<n;j++,J<<=1)
        {
          if(!(J&I))dp[fg][J|I]=max(dp[fg][J|I],dp[fg][I]);
        }*/
        //for(ll k:tmp)dp[fg][I|k]=max(dp[fg][I|k],dp[fg][I]);
      }

      //REP(I,(1<<n))debug(i,bitset<3>(I),dp[fg][I]);
      REP(I,(1<<n))
      {
          ll tmp=I;
          while(tmp)
          {
            ll J=tmp&-tmp;
            dp[fg][I]=max(dp[fg][I],dp[fg][I-J]);
            tmp-=J;
          }

      }
    }
    cout<<dp[fg][(1<<n)-1]<<endl;
}
