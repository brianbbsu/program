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


const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(2e9);

vector<ll> his;
vector<ii> v[MAXn];
ll h[MAXn][2], far[MAXn];
bool vis[MAXn];

void dfs1(ll now,ll f)
{
    h[now][0] = h[now][1] = 0;
    vis[now] = 1;
    his.pb(now);
    for(ii k:v[now])if(k.X!=f)
    {
        dfs1(k.X,now);
        if(h[k.X][0] + k.Y >= h[now][0])h[now][1] = h[now][0], h[now][0] = h[k.X][0] + k.Y;
        else if(h[k.X][0] + k.Y >= h[now][1])h[now][1] = h[k.X][0] + k.Y;
    }
}
void dfs2(ll now,ll f,ll tp)
{
    far[now] = max(tp,h[now][0]);
    for(ii k:v[now])if(k.X!=f)
    {
        if(h[k.X][0] + k.Y == h[now][0])dfs2(k.X,now, max(tp,h[now][1]) + k.Y);
        else dfs2(k.X, now, max(tp, h[now][0]) + k.Y);
    }
}

int main()
{
    IOS();
    ll n,m,l;
    while(cin>>n>>m>>l)
    {
        REP(i,n)v[i].clear();
        REP(i,m)
        {
            ll a,b,c;
            cin>>a>>b>>c;
            v[a].pb({b,c});
            v[b].pb({a,c});
        }
        ll ans = 0;
        REP(i,n)vis[i] = 0;
        ll dt[] = {-1,-1,-1};
        ll ct = 0;
        REP(i,n)if(!vis[i])
        {
            his.clear();
            dfs1(i,-1);
            dfs2(i,-1,0);
            ll mn = INF;
            for(ll x:his)
            {
                mn = min(mn,far[x]);
                ans = max(ans, far[x]);
            }
            if(mn >= dt[0])dt[2] = dt[1], dt[1] = dt[0], dt[0] = mn;
            else if(mn >= dt[1])dt[2] = dt[1], dt[1] = mn;
            else if(mn >= dt[2])dt[2] = mn;
            ct++;
        }
        debug(dt,ans);
        if(ct > 1)ans = max(ans, dt[0] + dt[1] + l);
        if(ct > 2)ans = max(ans, dt[1] + 2*l + dt[2]);
        cout<<ans<<endl;
        
    }
}
