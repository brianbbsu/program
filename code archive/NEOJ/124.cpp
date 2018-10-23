//{
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(ll i=0;i<n;i++)
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


const ll MAXn=2e3+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

#ifdef brian
void Report(ll a,ll b,ll c,ll d,ll e,ll f)
{
  debug(ii(a,b),ii(c,d),ii(e,f));
}
#endif
bool d[MAXn][MAXn];

void solve(int n,int x,int y,int dx=0,int dy=0,bool init=1)
{
  if(init)FILL(d,0),d[x-1][y-1]=1;
  if(n==1)return;
  ll tx,ty;
  REP(i,n)REP(j,n)if(d[i+dx][j+dy]){tx=i,ty=j;break;}
  ll tmp=n/2;
  if(tx<tmp&&ty<tmp)
  {
    Report(tmp+1+dx,tmp+dy,tmp+1+dx,tmp+1+dy,tmp+dx,tmp+1+dy);
    d[tmp+dx][tmp-1+dy]=d[tmp+dx][tmp+dy]=d[tmp-1+dx][tmp+dy]=1;
    solve(tmp,0,0,tmp+dx,dy,0);
    solve(tmp,0,0,tmp+dx,tmp+dy,0);
    solve(tmp,0,0,dx,tmp+dy,0);
    solve(tmp,0,0,dx,dy,0);
  }
  else if(tx<tmp)
  {
    Report(tmp+1+dx,tmp+dy,tmp+1+dx,tmp+1+dy,tmp+dx,tmp+dy);
    d[tmp+dx][tmp-1+dy]=d[tmp+dx][tmp+dy]=d[tmp-1+dx][tmp-1+dy]=1;
    solve(tmp,0,0,tmp+dx,dy,0);
    solve(tmp,0,0,tmp+dx,tmp+dy,0);
    solve(tmp,0,0,dx,tmp+dy,0);
    solve(tmp,0,0,dx,dy,0);
  }
  else if(ty<tmp)
  {
    Report(tmp+dx,tmp+dy,tmp+1+dx,tmp+1+dy,tmp+dx,tmp+1+dy);
    d[tmp-1+dx][tmp-1+dy]=d[tmp+dx][tmp+dy]=d[tmp-1+dx][tmp+dy]=1;
    solve(tmp,0,0,tmp+dx,dy,0);
    solve(tmp,0,0,tmp+dx,tmp+dy,0);
    solve(tmp,0,0,dx,tmp+dy,0);
    solve(tmp,0,0,dx,dy,0);
  }
  else
  {
    Report(tmp+1+dx,tmp+dy,tmp+dx,tmp+dy,tmp+dx,tmp+1+dy);
    d[tmp+dx][tmp-1+dy]=d[tmp-1+dx][tmp-1+dy]=d[tmp-1+dx][tmp+dy]=1;
    solve(tmp,0,0,tmp+dx,dy,0);
    solve(tmp,0,0,tmp+dx,tmp+dy,0);
    solve(tmp,0,0,dx,tmp+dy,0);
    solve(tmp,0,0,dx,dy,0);
  }

}

#ifdef brian
int main()
{
    IOS();
    solve(4,3,4);
}
#endif
