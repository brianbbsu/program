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
#include<queue>
#include<stack>

using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(ll i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define FILL(i,n) memset(i,n,sizeof i)
#define MEM(i,n) memset(i,n,sizeof i)
#define X first
#define Y second
#define SZ(_a) (int)_a.size()
#define ALL(_a) _a.begin(),_a.end()
#define pb push_back
#define eb emplace_back
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

#define MAXN MAXn

const ll MAXn=304,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll n,m,k;
char a[MAXN],b[MAXN][MAXN];
bool vis[MAXn][MAXn];

ll dx[4] = {0,0,1,-1};
ll dy[4] = {1,-1,0,0};
bool valid(ll px,ll py,ll pd){
    if(px+dx[pd] >= 0 && px+dx[pd]<n && py+dy[pd] >= 0 && py+dy[pd] < m)return true;
    else return false;
    return true;
}

bool dfs(ll x,ll y,ll p)
{
    if(p == k-1)return 1;
    vis[x][y] = 1;
    REP(i,4)
    {
        ll tmpx = x + dx[i],tmpy = y + dy[i];
        if(!valid(x,y,i) || vis[tmpx][tmpy] || a[p+1] != b[tmpx][tmpy])continue;
        if(dfs(tmpx,tmpy,p+1))return 1;
    }
    vis[x][y] = 0;
    return 0;
}

int main()
{
    IOS();
    cin>>k;
    REP(i,k)cin>>a[i];
    cin>>n>>m;
    REP(i,n)REP(j,m)cin>>b[i][j];
    REP(i,n)REP(j,m)if(b[i][j] == a[0])
    {
        if(dfs(i,j,0))
        {
            cout<<"True"<<endl;
            return 0;
        }
    }
    cout<<"False"<<endl;
    
}
