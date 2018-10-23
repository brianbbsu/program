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


const ll MAXn=2e5+5,MAXlg=__lg(10*MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);


#ifndef brian
#include "lib1959.h"
#endif // brian

int db[MAXn],dw[MAXn];
int preb[MAXn],prew[MAXn];
bool dp[2][MAXn][105];

void solve_puzzle(int n,char *s,int k,int *d,char *rs)
{
    FILL(db,-1);FILL(dw,-1);FILL(preb,0);FILL(prew,0);FILL(dp,0);
    REP1(i,n)
    {
      if(s[i-1]=='_')dw[i]=1,db[i]=0,prew[i]++;
      else if(s[i-1]=='X')dw[i]=0,db[i]=1,preb[i]++;
    }
    partial_sum(preb,preb+n+1,preb);
    partial_sum(prew,prew+n+1,prew);

    dp[0][0][0]=1;
    REP1(i,n)REP(j,k+1)
    {
      if(dw[i]!=0&&dp[0][i-1][j])dp[0][i][j]=1;
      if(j!=0&&db[i]!=0&&i>=d[j-1]&&prew[i]==prew[i-d[j-1]]&&dw[i-d[j-1]]!=0&&((i==d[j-1]&&j==1)||(i!=d[j-1]&&dp[0][i-d[j-1]-1][j-1])))dp[0][i][j]=1;
    }
    dp[1][n+1][k+1]=1;
    for(int i=n;i>0;i--)for(int j=k+1;j>0;j--)
    {
      if(dw[i]!=0&&dp[1][i+1][j])dp[1][i][j]=1;
      if(j!=k+1&&db[i]!=0&&n+1-i>=d[j-1]&&prew[i-1]==prew[i+d[j-1]-1]&&dw[i+d[j-1]]!=0&&((n+1-i==d[j-1]&&j==k)||(n+1-i!=d[j-1]&&dp[1][i+d[j-1]+1][j+1])))dp[1][i][j]=1;
    }

    REP1(i,n)if(dw[i]!=0)REP(j,k+1)if(dp[0][i-1][j]&&dp[1][i+1][j+1])dw[i]=1;

    REP1(i,k)
    {
      ll lt=0;
      REP1(j,n)
      {
        if(lt>=j)db[j]=1;
        if(j+d[i-1]<=n+1&&dw[j-1]!=0&&dw[j+d[i-1]]!=0&&prew[j-1]==prew[j+d[i-1]-1]
          &&((j==1&&i==1)||(j!=1&&dp[0][j-2][i-1]))&&((j+d[i-1]==n+1&&i==k)||(j+d[i-1]!=n+1&&dp[1][j+d[i-1]+1][i+1])))lt=max(lt,j+d[i-1]-1),db[j]=1;
      }
    }
    REP1(i,n)
    {
      assert(db[i]||dw[i]);
      if(db[i]==1&&dw[i]==1)rs[i-1]='?';
      else if(db[i]==1)rs[i-1]='X';
      else rs[i-1]='_';
    }
    pary(preb+1,preb+n+1);
    pary(prew+1,prew+1+n);
    pary(db+1,db+n+1);
    pary(dw+1,dw+n+1);
    rs[n]=0;
}



#ifdef brian
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    char c[201];
    char rs[201];
    int n;
    int k;
    int d[201];
    cin>>c;
    cin>>k;
    n=strlen(c);
    REP(i,k)cin>>d[i];
    solve_puzzle(n,c,k,d,rs);
    cout<<rs<<endl;
}
#endif
