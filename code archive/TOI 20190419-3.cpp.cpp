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


const ll MAXn=1e3+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

struct {
    struct edge{ll to, cap, rev;};
    vector<edge> v[300000];
    ll dis[300000], iter[300000], s, t;
    void add_edge(ll a, ll b,ll c)
    {
        v[a].pb({b, c, SZ(v[b])});
        v[b].pb({a, c, SZ(v[a]) - 1});
    }
    void bfs()
    {
        queue<ll> q;
        FILL(dis, -1);
        dis[s] = 0;
        q.push(s);
        while(SZ(q))
        {
            ll t = q.front();q.pop();
            for(auto e:v[t])if(e.cap && dis[e.to] == -1)
            {
                dis[e.to] = dis[t] + 1;
                q.push(e.to);
            }
        }
    }
    ll dfs(ll now,ll cap)
    {
        if(now == t)return cap;
        for(auto &i = iter[now];i < SZ(v[now]);i ++)
        {
            auto &e = v[now][i];
            if(e.cap != 0 && dis[e.to] == dis[now] + 1){
                ll d = dfs(e.to, min(cap, e.cap));
                if(d > 0)
                {
                    e.cap -= d;
                    v[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
    ll flow(ll S,ll T)
    {
        s = S, t = T;
        ll tt = 0;
        while(1)
        {
            bfs();
            if(dis[t] == -1)return tt;
            FILL(iter, 0);
            ll d;
            while((d = dfs(s, INF)) > 0)tt += d;
        }
    }
} dinic;

ll d[500][500];

ll h(ll x,ll y){return x * 400 + y;}

int main()
{
    IOS();
    ll n, m;
    cin>>n>>m;
    REP1(i, n)REP1(j, m)cin>>d[i][j];
    ll S = 0, T = 1;
    REP1(i,n)REP1(j,m)if(d[i][j] == 0)dinic.add_edge(S, h(i, j), 2);
    REP1(i,n)REP1(j,m)if(d[i][j] == 1)dinic.add_edge(T, h(i, j), 2);
    ll dx[] = {1, -1, 0 , 0};
    ll dy[] = {0, 0, 1 , -1};
    REP1(i,n)REP1(j,m)
    {
        REP(k, 4)
        {
            ll x = i + dx[k], y = j + dy[k];
            if(x > 0 && x <= n && y > 0 && y <= m && i <= x && j <= y)dinic.add_edge(h(i, j), h(x, y), 1);
        }
    }
    cout<<dinic.flow(S, T)<<endl;
}
