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


const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll run(ll l1,ll r1,ll l2,ll r2,ll da,ll db,ll dis)
{
    ll a = 0,b = 0;
    ll ct = 0;
    while(1)
    {
        if(a == -l1)da = 1;
        else if(a == r1)da = -1;
        if(b == -l2)db = 1;
        else if(b == r2)db = -1;
        a += da;
        b += db;
        if(l1 == 0 && r1 == 0)a = 0;
        if(l2 == 0 && r2 == 0)b = 0;
        if(a == dis + b){
            return 1;
        }
        if(a == 0 && b == 0)ct++;
        if(ct == 4)break;
    }
    return 0;
}

ll f[10][10][2][2][25];

ll d[MAXn],g[MAXn],vis[MAXn],git;
vector<ll> v[MAXn],vr[MAXn],tp;


void dfs1(ll now)
{
    vis[now] = 1;
    for(ll k:vr[now])if(!vis[k])dfs1(k);
    tp.pb(now);
}
void dfs2(ll now)
{
    vis[now] = 1;
    g[now] = git;
    for(ll k:v[now])if(!vis[k])dfs2(k);
}

int main()
{
    IOS();
    debug(run(0,1,2,2,1,1,2));
    REP(i,10)REP(j,10)REP(k,2)REP(l,2)REP1(d,20)
    {
        ll a = 0,b = 0,da,db;
        if(!k)da = -1;
        else da = 1;
        if(!l)db = -1;
        else db = 1;/*
        while(1)
        {
            if(a == -i)da = 1;
            else if(a == i)da = -1;
            if(b == -j)db = 1;
            else if(b == j)db = -1;
            a += da;
            b += db;
            if(!i)a = 0;
            if(!j)b = 0;
            if(a == d + b){
                f[i][j][k][l][d] = 1;
                break;
            }
            if(a == 0 && b == 0)break;
        }*/
        f[i][j][k][l][d] = run(i,i,j,j,da,db,d);
    }
    ll T;
    cin>>T;
    while(T--)
    {
        ll n;
        string s;
        cin>>s;
        n = SZ(s);
        REP(i,n)
        {
            if(s[i] == '.')d[i] = -1;
            else d[i] = s[i] - '0';
        }
        REP(i,2 * n)v[i].clear(),vr[i].clear();
        git = 0;
        REP(i,n)if(d[i] != -1)REP1(j,20)if(i + j < n && d[i+j] != -1)
        {
            ll t = i + j;
            if(i - 9 < 0 || t + 9 >= n)
            {
                if(run(min(i,d[i]),min(n-i-1,d[i]),min(t,d[t]),min(n-t-1,d[t]),-1,-1,j))v[i].pb(t+n),v[t].pb(i+n);
                if(run(min(i,d[i]),min(n-i-1,d[i]),min(t,d[t]),min(n-t-1,d[t]), 1,-1,j))v[i+n].pb(t+n),v[t].pb(i);
                if(run(min(i,d[i]),min(n-i-1,d[i]),min(t,d[t]),min(n-t-1,d[t]),-1, 1,j))v[i].pb(t),v[t+n].pb(i+n);
                if(run(min(i,d[i]),min(n-i-1,d[i]),min(t,d[t]),min(n-t-1,d[t]), 1, 1,j))v[i+n].pb(t),v[t+n].pb(i);
            }
            else
            {
                if(f[d[i]][d[t]][0][0][j])v[i].pb(t+n),v[t].pb(i+n);
                if(f[d[i]][d[t]][1][0][j])v[i+n].pb(t+n),v[t].pb(i);
                if(f[d[i]][d[t]][0][1][j])v[i].pb(t),v[t+n].pb(i+n);
                if(f[d[i]][d[t]][1][1][j])v[i+n].pb(t),v[t+n].pb(i);
            }
        }
        REP(i,2 * n)for(ll x:v[i])vr[x].pb(i);
        tp.clear();
        REP(i,2*n)vis[i] = 0;
        REP(i,2 * n)if(!vis[i])dfs1(i);
        reverse(ALL(tp));
        REP(i,2*n)vis[i] = 0;
        for(ll x:tp)if(!vis[x])
        {
            dfs2(x);
            git ++;
        }
        bool fg = 0;
        REP(i,n)if(g[i] == g[i + n])fg = 1;
        if(fg)cout<<"unsafe"<<endl;
        else cout<<"safe"<<endl;
    }
}
