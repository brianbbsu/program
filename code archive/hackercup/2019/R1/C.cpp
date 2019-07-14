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
#else
#define debug(...)
#define pary(...)
#endif // brian
//}

#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);

const ll MAXn=3e3+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

struct dinic{
    struct edge{
        ll to, cap, rev;
    };
    vector<edge> v[MAXn];
    ll dis[MAXn], iter[MAXn];
    void add_edge(ll from, ll to, ll cap){
        v[from].pb({to, cap, SZ(v[to])});
        v[to].pb({from, cap, SZ(v[from]) - 1});
    }
    ll dfs(ll now,ll t, ll k){
        if(now == t)return k;
        for(ll &i = iter[now];i < SZ(v[now]);i ++){
            edge &e = v[now][i];
            if(e.cap && dis[e.to] == dis[now] + 1)
            {
                ll ret = dfs(e.to, t, min(k, e.cap));
                if(ret){
                    e.cap -= ret;
                    v[e.to][e.rev].cap += ret;
                    return ret;
                }
            }
        }
        return 0;
    }
    void bfs(ll s){
        dis[s] = 0;
        queue<ll> q;
        q.push(s);
        while(SZ(q)){
            ll t = q.front();
            q.pop();
            for(edge &e:v[t])if(e.cap && dis[e.to] == -1){
                dis[e.to] = dis[t] + 1;
                q.push(e.to);
            }
        }
    }
    ll flow(ll s,ll t){
        ll tt = 0;
        while(1){
            FILL(dis, -1);
            FILL(iter, 0);
            bfs(s);
            if(dis[t] == -1)return tt;
            ll d;
            while((d = dfs(s, t, INF)) != 0){
                tt += d;
            }
        }
    }
};

struct seg{
    ll x, a, b;
};


vector<seg> d;
ll bs[MAXn], bit;

vector<ll> v[MAXn];

int main()
{
    IOS();
    ll T;
    cin>>T;
    ll kz = 0;
    while(T--)
    {
        kz ++;
        cout<<"Case #"<<kz<<": ";
        ll n, h;
        cin>>n>>h;
        d.clear();
        REP(i, n)
        {
            ll x, a, b;
            cin>>x>>a>>b;
            d.pb({x, a, b});
        }
        sort(ALL(d), [](auto &a, auto &b){return a.x < b.x;});
        vector<ll> uni;
        uni.pb(0);
        uni.pb(h);
        REP(i, n)uni.pb(d[i].a), uni.pb(d[i].b);
        sort(ALL(uni));
        uni.resize(unique(ALL(uni)) - uni.begin());
        REP(i, n)d[i].a = lower_bound(ALL(uni), d[i].a) - uni.begin(), d[i].b = lower_bound(ALL(uni), d[i].b) - uni.begin();
        bit = 2; // 0 -> source, 1 -> sink
        REP(i, n)bs[i] = bit, bit += d[i].b - d[i].a;
        dinic dc;
        REP(i, n)if(d[i].a == 0)dc.add_edge(0, bs[i], INF);
        h = SZ(uni) - 1;
        REP(i, n)if(d[i].b == h)dc.add_edge(bs[i] + (d[i].b - d[i].a - 1), 1, INF);
        REP(i, SZ(uni))v[i].clear();
        REP(i, n)REP(j, d[i].b - d[i].a)
        {
            ll t = d[i].a + j, id = bs[i] + j;
            if(SZ(v[t]))dc.add_edge(id, v[t].back(), uni[t + 1] - uni[t]);
            v[t].pb(id);
            if(t != d[i].b - 1)dc.add_edge(id, id + 1, INF);
        }
        ll t = dc.flow(0, 1);
        if(t >= INF)cout<<-1<<endl;
        else cout<<t<<endl;
    }
}
