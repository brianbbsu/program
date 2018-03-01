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


const ll MAXn=1e6+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

int d[MAXn];
int dp[2][MAXn];

priority_queue<ii> pq;
int lg[MAXn];
int st[MAXn][MAXlg];

int main()
{
    IOS();
    lg[0]=0;
    REP1(i,MAXn-1)if((1<<(lg[i-1]+1))==i)lg[i]=lg[i-1]+1;else lg[i]=lg[i-1];
    ll n;
    cin>>n;
    string s;
    cin>>s;
    REP1(i,n)if(s[i-1]=='p')d[i]=1;
    partial_sum(d,d+n+1,d);

    REP1(i,n)
    {
      pq.push(ii(2*d[i-1]-(i-1),i));
      ll t=2*d[i]-i;
      while(SZ(pq)&&pq.top().X>t)dp[0][pq.top().Y]=i-1,pq.pop();
    }
    while(SZ(pq))dp[0][pq.top().Y]=n,pq.pop();
    for(int i=n;i>0;i--)
    {
      pq.push(ii(i-2*d[i],i));
      ll t=(i-1)-2*d[i-1];
      while(SZ(pq)&&pq.top().X>t)dp[1][pq.top().Y]=i+1,pq.pop();
    }
    while(SZ(pq))dp[1][pq.top().Y]=1,pq.pop();

    REP1(i,n)st[i][0]=dp[1][i];
    REP1(j,MAXlg-1)REP1(i,n)if(i+(1<<j)-1<=n)st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);

    pary(dp[1]+1,dp[1]+1+n);
    REP(j,MAXlg)REP1(i,n)debug(j,i,st[i][j]);

    ll ans=0;
    REP1(i,n)
    {
      ll l=i-1,r=dp[0][i]+1;
      while(l!=r-1)
      {
        ll h=(l+r)/2,len=dp[0][i]-h+1,llg=lg[len];
        ll t=min(st[h][llg],st[dp[0][i]-(1<<llg)+1][llg]);
        if(t<=i)l=h;
        else r=h;
      }
      debug(i,l);
      ans=max(ans,l-i+1);
    }
    cout<<ans<<endl;
}
