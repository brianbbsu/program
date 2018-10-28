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

vector<ll> v[MAXn];
ll p[MAXn][MAXlg],dph[MAXn],tl[MAXn],tr[MAXn],tit = 0;

ll dfs(ll now,ll f)
{
    tl[now] = tit++;
    for(ll k:v[now])if(k != f)
    {
        p[k][0] = now;
        dph[k] = dph[now] + 1;
        dfs(k,now);
    }
    tr[now] = tit;
}

ll lca(ll a,ll b)
{
    if(dph[a] < dph[b])swap(a,b);
    for(int j = MAXlg - 1;j >= 0;j--)if(dph[p[a][j]] >= dph[b])a = p[a][j];
    if(a == b)return a;
    for(int j = MAXlg - 1;j >= 0;j--)if(p[a][j] != p[b][j])a = p[a][j],b = p[b][j];
    return p[a][0];
}


inline ll la(ll a,ll b) // a is top of b
{
    return tl[a] <= tl[b] && tr[a] >= tr[b];
}

ll up(ll a,ll c)
{
    for(int j = MAXlg - 1;j >= 0;j--)if((1<<j) <= c)a = p[a][j],c -= (1<<j);
    return a;
}

ll run(ll a,ll b,ll c)
{
    if(dph[b] > dph[a])
    {
        c = dph[b] - dph[a] - c;
        return up(b,c);
    }
    else
    {
        return up(a,c);
    }
}

ll cal(ll a,ll b,ll c,ll d)
{
    if((dph[a] < dph[b]) ^ (dph[c] < dph[d])){// diff
        if(dph[b] > dph[a])swap(a,b),swap(c,d);
        if((dph[a] - dph[c]) % 2 != 0)return 0;
        ll x = (dph[a] - dph[c]) / 2;
        if(x < 0)return 0;
        a = up(a,x);
        d = up(d,dph[d] - dph[c] - x);
        return a==d;
    }
    else //same
    {
        if(dph[b] > dph[a])swap(a,b),swap(c,d);
        if(dph[a] != dph[c])return 0;
        ll x = lca(a,c);
        return max(0LL,dph[x] - dph[b] + 1);
    }
}

int main()
{
    IOS();
    ll T;
    cin>>T;
    while(T--)
    {
        ll n,a,b;
        cin>>n>>a>>b;
        tit = 0;
        REP1(i,n)v[i].clear();
        REP(i,n-1)
        {
            ll a,b;
            cin>>a>>b;
            v[a].pb(b);
            v[b].pb(a);
        }
        p[1][0] = 1;
        dfs(1,-1);
        REP1(j,MAXlg-1)REP1(i,n)p[i][j] = p[p[i][j-1]][j-1];
        vector<ll> d1,d2;
        {
            ll lst;
            cin>>lst;
            d1.pb(lst);
            REP(i,a-1)
            {
                ll x;
                cin>>x;
                ll c = lca(x,lst);
                if(c != d1.back())d1.pb(c);
                if(x != d1.back())d1.pb(x);
                lst = x;
            }
        }
        {
            ll lst;
            cin>>lst;
            d2.pb(lst);
            REP(i,b-1)
            {
                ll x;
                cin>>x;
                ll c = lca(x,lst);
                if(c != d2.back())d2.pb(c);
                if(x != d2.back())d2.pb(x);
                lst = x;
            }
        }
        ll tt = 0;
        ll x = d1[0],y = d2[0],ita = 1,itb = 1;
        if(x == y)tt++;
        debug(d1,d2);
        while(ita != SZ(d1) && itb != SZ(d2))
        {
            if(x==y)tt--;
            ll da = abs(dph[x] - dph[d1[ita]]);
            ll db = abs(dph[y] - dph[d2[itb]]);
            ll d = min(da,db);
            ll ga = run(x,d1[ita],d);
            ll gb = run(y,d2[itb],d);
            tt += cal(x,ga,y,gb);
            x = ga,y = gb;
            if(x == d1[ita])ita++;
            if(y == d2[itb])itb++;
            debug(x,y,tt);
        }

        cout<<tt<<endl;
        
    }
}
