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


const ll MAXn=2e4+5, MAXp = 3e3 + 5, MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ii operator - (ii a, ii b){return ii(a.X - b.X, a.Y - b.Y);}
ll cros(ii a, ii b){return a.X * b.Y - a.Y * b.X;}

struct edge{
    ll a, b, c;
};

ii e[MAXn], p[MAXn];
ll h[MAXn], eh[MAXn];
ll ev[MAXp][MAXp];
vector<ll> ue[MAXn];

vector<edge> v;

ll trans(string &s)
{
    ll tt = 0;
    if(isupper(s[0]))tt += s[0] - 'A' + 26;
    else tt += s[0] - 'a';
    tt *= 52;
    if(isupper(s[1]))tt += s[1] - 'A' + 26;
    else tt += s[1] - 'a';
    return tt;
}

ll g[MAXn], mnh[MAXn];
vector<ll> gv[MAXn];
ll f(ll x){return g[x] = (g[x] == x ? x : f(g[x]));}
void mg(ll a,ll b, ll c)
{
    a = f(a), b = f(b);
    if(a == b)return;
    if(SZ(gv[a]) > SZ(gv[b]))swap(a, b);
    g[a] = b;
    for(ll x:gv[a])gv[b].pb(x);
    gv[a].clear();gv[a].shrink_to_fit();
    mnh[b] = min({mnh[a], mnh[b], c});
}

ll wh[MAXn];

int main()
{
    IOS();
    ll n, m, kz = 0;
    while(cin>>n>>m&&(n||m))
    {
        kz ++;
        cout<<"Case "<<kz<<":"<<endl;
        REP1(i, n)
        {
            string s;
            cin>>s;
            ll t = trans(s);
            cin>>p[t].X>>p[t].Y>>h[t];
        }
        REP1(i, m)
        {
            string sa, sb;
            ll a, b;
            cin>>sa>>sb;
            a = trans(sa), b = trans(sb);
            if(a > b)swap(a, b);
            e[i] = ii(a, b);
            eh[i] = min(h[a], h[b]);
            ev[a][b] = ev[b][a] = i;
            debug(p[a], p[b]);
        }
        ll tct = 0;
        REP1(i, m)
        {
            ll bst = -1;
            ii vi = p[e[i].Y] - p[e[i].X], vbst;
            REP1(j, m)if(j != i && (e[j].X == e[i].X || e[j].Y == e[i].X))
            {
                ii vj = (e[j].X == e[i].X ? p[e[j].Y] - p[e[j].X] : p[e[j].X] - p[e[j].Y]);
                if(cros(vi, vj) <= 0)continue;
                if(bst == -1 || cros(vj, vbst) > 0)
                {
                    bst = j;
                    vbst = vj;
                }
            }
            if(bst != -1 && e[bst].X == e[i].X && ev[e[i].Y][e[bst].Y])
            {
                tct ++;
                ue[i].pb(tct);ue[bst].pb(tct);ue[ev[e[i].Y][e[bst].Y]].pb(tct);
                debug(p[e[i].X], p[e[i].Y], p[e[bst].Y]);
            }
        }
        debug(tct);
        REP1(i, m)
        {
            if(SZ(ue[i]) == 1)v.pb({0, ue[i][0], eh[i]});
            else if(SZ(ue[i]) == 2)v.pb({ue[i][0], ue[i][1], eh[i]});
        }
        sort(ALL(v), [](edge &a, edge &b){return a.c < b.c;});
        for(int i = 0;i <= tct;i ++)g[i] = i, gv[i].pb(i), mnh[i] = INF;
        REP1(i, tct)wh[i] = -1;
        for(auto &d:v)debug(d.a, d.b, d.c);
        vector<ll> ans;
        for(auto &t:v)
        { 
            if(f(t.a) == f(t.b))continue;
            if(f(t.a) == f(0))swap(t.a, t.b);
            if(f(t.b) == f(0) && mnh[f(t.a)] < t.c)for(ll k:gv[f(t.a)])wh[k] = t.c;
            mg(t.a, t.b, t.c);
        }
        REP1(i, tct)g[i] = i, mnh[i] = INF;
        for(auto &t:v)
        {
            if(f(t.a) == f(t.b))continue;
            if(wh[f(t.a)] == wh[f(t.b)] && t.c < wh[f(t.a)])mnh[f(t.b)] = min({mnh[f(t.a)], mnh[f(t.b)], t.c}), g[f(t.a)] = f(t.b);
        }
        REP1(i, tct)if(f(i) == i && wh[i] != -1 && mnh[i] < wh[i])ans.pb(wh[i]);
        if(!SZ(ans))cout<<"  0"<<endl;
        else
        {
            sort(ALL(ans));
            for(ll x:ans)cout<<"  "<<x<<endl;
        }
        //clean
        REP1(i, m)
        {
            ev[e[i].X][e[i].Y] = ev[e[i].Y][e[i].X] = 0;
            ue[i].clear();
        }
        v.clear();
        for(int i = 0;i <= tct;i ++)gv[i].clear(), gv[i].shrink_to_fit();
    }
}
