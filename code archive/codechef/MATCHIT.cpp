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


const ll MAXn=2e3+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ii dt[MAXn], p[MAXn][MAXn];
ll d[MAXn][MAXn], dis[MAXn][MAXn], u[MAXn][MAXn];
ll dx[] = {1, -1, 0 , 0}, dy[] = {0 , 0, 1, -1};

vector<vector<ii>> ans;

ll n, m;

void safe()
{
    sort(dt, dt+2*m, [](ii a,ii b){
        if(a.X&1)a.Y = -a.Y;
        if(b.X&1)b.Y = -b.Y;
        return a < b;
    });
    ans.clear();
    FILL(u, 0);
    REP(i, 2 * m)u[dt[i].X][dt[i].Y] = -1;
    for(int i = 0;i < 2*m;i += 2)
    {
        ll l = max(dt[i].X, 1LL), r = min(dt[i|1].X, n);
        queue<ii> q;
        for(int j = l;j <= r;j++)REP1(k, n)dis[j][k] = -1;
        dis[dt[i].X][dt[i].Y] = 0;
        u[dt[i|1].X][dt[i|1].Y] = 0;
        q.push(dt[i]);
        while(SZ(q))
        {
            ii t = q.front();
            q.pop();
            ll x = t.X, y = t.Y;
            if(t == dt[i|1])break;
            REP(j, 4)
            {
                ll xx = x + dx[j], yy = y + dy[j];
                if(xx >= l && xx <= r && yy > 0 && yy <= n && dis[xx][yy] == -1 && u[xx][yy] == 0)
                {
                    dis[xx][yy] = dis[x][y] + 1;
                    p[xx][yy] = ii(x,y);
                    q.push(ii(xx, yy));
                }
            }
        }
        assert(dis[dt[i|1].X][dt[i|1].Y] != -1);
        vector<ii> v;
        ii now = dt[i|1];
        while(now != dt[i])
        {
            v.pb(now);
            now = p[now.X][now.Y];   
        }
        v.pb(now);
        ans.pb(v);
        for(ii x:v)u[x.X][x.Y] = 1;
    }
}

inline ll G(ii x){return x.X * n + x.Y;}

ll g[MAXn * MAXn];
ll f(ll x){return g[x] = (g[x] == x?x:f(g[x]));}
void mg(ll a,ll b){
    a = f(a), b = f(b);
    g[a] = b;
}

bool bts()
{
    sort(dt, dt+2*m, [](ii a,ii b){
        if(a.X&1)a.Y = -a.Y;
        if(b.X&1)b.Y = -b.Y;
        return a < b;
    });
    ans.clear();
    FILL(u, 0);
    REP(i, 2 * m)u[dt[i].X][dt[i].Y] = -1;
    for(int i = 0;i < 2*m;i += 2)
    {
        ll l = max(dt[i].X, 1LL), r = min(dt[i|1].X, n);

        vector<pair<ll, ii>> s;
        for(int j = l;j <= r;j++)REP1(k, n)if(u[j][k] == 0)s.pb({d[j][k], ii(j, k)}), g[G(ii(j,k))] = G(ii(j,k));
        sort(ALL(s));
        s.pb({d[dt[i].X][dt[i].Y], dt[i]});
        s.pb({d[dt[i|1].X][dt[i|1].Y], dt[i|1]});
        g[G(dt[i])] = G(dt[i]);
        g[G(dt[i|1])] = G(dt[i|1]);
        reverse(ALL(s));

        for(auto t:s)
        {
            ll x = t.Y.X, y = t.Y.Y;
            u[x][y] = 2;
            REP(j, 4)
            {
                ll xx = x + dx[j], yy = y + dy[j];
                if(xx >= l && xx <= r && yy > 0 && yy <= n && u[xx][yy] == 2)mg(G(ii(x,y)), G(ii(xx,yy)));
            }
            if(f(G(dt[i])) == f(G(dt[i|1])))break;
        }
        if(f(G(dt[i])) != f(G(dt[i|1])))assert(0);
        
        queue<ii> q;
        for(int j = l;j <= r;j++)REP1(k, n)dis[j][k] = -1;
        dis[dt[i].X][dt[i].Y] = 0;
        q.push(dt[i]);
        while(SZ(q))
        {
            ii t = q.front();
            q.pop();
            ll x = t.X, y = t.Y;
            if(t == dt[i|1])break;
            REP(j, 4)
            {
                ll xx = x + dx[j], yy = y + dy[j];
                if(xx >= l && xx <= r && yy > 0 && yy <= n && dis[xx][yy] == -1 && u[xx][yy] == 2)
                {
                    dis[xx][yy] = dis[x][y] + 1;
                    p[xx][yy] = ii(x,y);
                    q.push(ii(xx, yy));
                }
            }
        }
        assert(dis[dt[i|1].X][dt[i|1].Y] != -1);
        vector<ii> v;
        ii now = dt[i|1];
        while(now != dt[i])
        {
            v.pb(now);
            now = p[now.X][now.Y];   
        }
        v.pb(now);
        ans.pb(v);
        for(ii x:v)u[x.X][x.Y] = 1;
        for(int j = l;j <= r;j++)REP1(k, n)if(u[j][k] == 2)u[j][k] = 0;
    }
    return 1;
}

int main()
{
    IOS();
    cin>>n>>m;
    REP(i,2 * m)cin>>dt[i].X>>dt[i].Y, u[dt[i].X][dt[i].Y] = -1;
    REP1(i,n)REP1(j,n)cin>>d[i][j];
    if(!bts())safe();
    for(auto &vv:ans)
    {
        cout<<SZ(vv);
        for(ii x:vv)cout<<" "<<x.X<<" "<<x.Y;
        cout<<endl;
    }
}
