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

const ll MAXn=12,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

const ll n = 10;

ll d[MAXn][MAXn];
ll vis[MAXn][MAXn];
ll dx[] = {1,-1,0,0};
ll dy[] = {0,0,1,-1};

vector<ii> v[MAXn][MAXn][MAXn][MAXn];
ll dis[MAXn][MAXn][MAXn][MAXn];

bool val(ll x,ll y)
{
    return x >= 0 && x < n && y >= 0 && y < n && d[x][y];
}

void dfs(ll x,ll y)
{
    vis[x][y] = 1;
    REP(i,4)
    {
        ll tmpx = x + dx[i],tmpy = y + dy[i];
        if(val(tmpx,tmpy) && !vis[tmpx][tmpy])dfs(tmpx,tmpy);
    }
}

int main()
{
    IOS();
    ii s,t,now;
    REP(i,n)REP(j,n)
    {
        ll x;
        cin>>x;
        d[i][j] = (x != 1);
        if(x == 2)now = {i,j};
        else if(x == 3)s = {i,j};
        else if(x == 4)t = {i,j};
    }
    REP(i,n)REP(j,n)REP(k,n)REP(l,n)if(ii(i,j) != ii(k,l) && d[i][j] && d[k][l])
    {
        d[i][j] = 0;
        FILL(vis,0);
        dfs(k,l);
        d[i][j] = 1;
        REP(p,4)
        {
            if(val(i + dx[p],j + dy[p]) && val(i - dx[p],j - dy[p]) && vis[i + dx[p]][j + dy[p]])
            {
                v[i][j][k][l].pb(ii(i - dx[p],j - dy[p]));
            }
        }
    }
    queue<pair<ii,ii> > q;
    REP(i,n)REP(j,n)REP(k,n)REP(l,n)dis[i][j][k][l] = INF;
    dis[s.X][s.Y][now.X][now.Y] = 0;
    q.push({s,now});
    while(SZ(q))
    {
        ii bx = q.front().X,pp = q.front().Y;
        q.pop();
        for(ii tmp:v[bx.X][bx.Y][pp.X][pp.Y])
        {
            if(dis[tmp.X][tmp.Y][bx.X][bx.Y] == INF)
            {
                dis[tmp.X][tmp.Y][bx.X][bx.Y] = dis[bx.X][bx.Y][pp.X][pp.Y] + 1;
                q.push({tmp,bx});
            }
        }
    }
    ll mn = INF;
    REP(i,n)REP(j,n)if(d[i][j])mn = min(mn,dis[t.X][t.Y][i][j]);
    if(mn == INF)cout<<-1<<endl;
    else cout<<mn<<endl;
}
