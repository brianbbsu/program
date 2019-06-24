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


const ll MAXn=4e4+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e9);
const int N = 205;

const lf EPS = 5e-5;

struct {
    struct edge{
        ll to, rev, id;lf cap;
    };
    vector<edge> v[N];
    int dis[N], iter[N];
    void add_edge(int a, int b, int id, lf c, lf rc){
        v[a].pb({b, SZ(v[b]), id, c});
        v[b].pb({a, SZ(v[a]) - 1, -1, rc});
    }
    void clear(){
        REP(i, N)v[i].clear();
    }
    void bfs(int s){
        FILL(dis, -1);
        queue<ll> q;
        dis[s] = 0;q.push(s);
        while(SZ(q)){
            ll t = q.front();q.pop();
            for(auto &e:v[t])if(e.cap >= EPS && dis[e.to] == -1){
                dis[e.to] = dis[t] + 1;
                q.push(e.to);
            }
        }
    }
    lf dfs(int now, int t, lf f){
        if(now == t)return f;
        for(auto &i = iter[now];i < SZ(v[now]);i ++){
            auto &e = v[now][i];
            if(e.cap >= EPS && dis[e.to] == dis[now] + 1){
                lf d = dfs(e.to, t, min(f, e.cap));
                if(d >= EPS){
                    e.cap -= d;v[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
    lf flow(int s, int t){
        lf tt = 0, d;
        while(bfs(s), dis[t] != -1){
            FILL(iter, 0); 
            while((d = dfs(s, t, INF)) >= EPS)tt += d;
        }
        return tt;
    }
} dinic;

ii e[MAXn];
lf c[MAXn], u[MAXn], uf[MAXn], uw[MAXn];
int r[MAXn];

int main()
{
    IOS();
    ll n, m;
    lf v, a;
    cin>>n>>m>>v>>a;
    REP1(i, m)cin>>e[i].X>>e[i].Y>>c[i];

    lf T, F, W;

    dinic.clear();
    REP1(i, m)dinic.add_edge(e[i].X, e[i].Y, i, c[i], c[i]);
    dinic.add_edge(0, 1, -1, INF, 0);
    dinic.add_edge(0, 2, -1, INF, 0);
    T = dinic.flow(0, 3);
    
    dinic.clear();
    REP1(i, m)dinic.add_edge(e[i].X, e[i].Y, i, c[i], c[i]);
    F = dinic.flow(1, 3);
    
    dinic.clear();
    REP1(i, m)dinic.add_edge(e[i].X, e[i].Y, i, c[i], c[i]);
    W = dinic.flow(2, 3);

    debug(T, F, W);

    if(a * T > F)W = T - F;
    else if((1 - a) * T > W)F = T - W;
    else F = T * a, W = T * (1 - a);

    lf ans = pow(F / v, a) * pow(W, 1 - a);

    debug(F, W, ans);

    dinic.clear();
    REP1(i, m)dinic.add_edge(e[i].X, e[i].Y, i, c[i], c[i]);
    dinic.add_edge(0, 1, -1, F, 0);
    dinic.add_edge(0, 2, -1, W, 0);
    lf TT = dinic.flow(0, 3);
    assert(fabs(TT - T) <= EPS);

    REP(i, n + 1)for(auto &p:dinic.v[i])if(p.id != -1)
    {
        ll t = p.id;
        if(p.cap > c[t])r[t] = 1, u[t] = p.cap - c[t];
        else u[t] = c[t] - p.cap;
    }

    dinic.clear();
    REP1(i, m)
    {
        if(r[i])dinic.add_edge(e[i].Y, e[i].X, i, u[i], 0);
        else dinic.add_edge(e[i].X, e[i].Y, i, u[i], 0);
    }
    dinic.add_edge(0, 1, -1, F, 0);
    lf FF = dinic.flow(0, 3);
    assert(fabs(FF - F) <= EPS);

    REP(i, n + 1)for(auto &p:dinic.v[i])if(p.id != -1)uf[p.id] = u[p.id] - p.cap, uw[p.id] = p.cap;

    REP1(i, m)
    {
        cout<<fixed<<setprecision(10);
        if(r[i])cout<<-uf[i] / v;
        else cout<<uf[i] / v;
        cout<<" "<<fixed<<setprecision(10);
        if(r[i])cout<<-uw[i];
        else cout<<uw[i];
        cout<<endl;
    }
    cout<<fixed<<setprecision(10)<<ans<<endl;
}

