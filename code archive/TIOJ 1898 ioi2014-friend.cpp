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

#ifndef brian
#include "lib1898.h"
#endif


int dp[MAXn][2];

int findSample(int n, int d[], int  h[], int prt[])
{
    FILL(dp,0);
    REP(i,n)dp[i][1]=d[i];
    for(int i=n-1;i>0;i--)
    {
      int a=h[i],b=i;
      if(prt[i]==0)
      {
        dp[a][0]+=max(dp[b][1],dp[b][0]);
        dp[a][1]+=dp[b][0];
      }
      else if(prt[i]==1)
      {
        dp[a][1]=max({dp[a][0]+dp[b][1],dp[a][1]+dp[b][0],dp[a][1]+dp[b][1]});
        dp[a][0]+=dp[b][0];
      }
      else
      {
        dp[a][1]=max(dp[a][0]+dp[b][1],dp[a][1]+dp[b][0]);
        dp[a][0]+=dp[b][0];
      }
      //REP(j,6)debug(j,dp[j][0],dp[j][1]);
      //cerr<<endl;
    }
    return max(dp[0][0],dp[0][1]);
}

#ifdef brian
int main()
{
    IOS();
    int d[]={13,3,6,20,10,15},h[]={0,0,0,1,2,0},tp[]={0,0,1,2,1,0};
    debug(findSample(6,d,h,tp));
}
#endif
