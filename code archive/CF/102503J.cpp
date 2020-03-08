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


const ll MAXn=2e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

struct edge{
    ll a, b, c;
};
edge e[MAXn];

struct tg{
    int *target, x;
};
vector<tg> his;
int g[MAXn], sz[MAXn];
int f(int x){return (g[x] == x ? x : f(g[x]));}
int mg(int a, int b){
    //debug(a, b);
    a = f(a), b = f(b);
    if(a == b)return 0;
    if(sz[a] > sz[b])swap(a, b);
    his.pb({&g[a], g[a]}), his.pb({&sz[b], sz[b]});
    g[a] = b, sz[b] += sz[a];
    return 1;
}
void undo(){
    reverse(ALL(his));
    for(auto &p:his)
        *(p.target) = p.x;
    his.clear();
}

vector<ll> uni, dt[MAXn];

struct qr{
    int id;
    vector<int> v;
};
vector<qr> qrs[MAXn];
int ans[MAXn];

int main()
{
    IOS();
    ll T;
    cin >> T;
    while(T--)
    {
        ll n, m;
        cin >> n >> m;
        for(int i = 1;i <= m;i ++)
            cin >> e[i].a >> e[i].b >> e[i].c, e[i].c *= -1;
        uni.clear();
        for(int i = 1;i <= m;i ++)
            uni.pb(e[i].c);
        sort(ALL(uni));
        uni.resize(unique(ALL(uni)) - uni.begin());
        for(int i = 0;i < SZ(uni);i++)
            dt[i].clear(), qrs[i].clear();
        for(int i = 1;i <= m;i ++)
            dt[lower_bound(ALL(uni), e[i].c) - uni.begin()].pb(i);
        ll q;cin >> q;
        for(int i = 1;i <= q;i ++)
            ans[i] = 0;
        for(int id = 1;id <= q;id ++){
            vector<ll> v;
            ll k;
            cin >> k;
            for(int i = 0, t;i < k;i ++)
                cin >> t, v.pb(t);
            sort(ALL(v), [](int a, int b){return e[a].c < e[b].c;});
            int t = -1;
            for(int i = 0;i < k;i ++)
            {
                if(i == 0 || e[v[i]].c != e[v[i - 1]].c){
                    t = lower_bound(ALL(uni), e[v[i]].c) - uni.begin();
                    qrs[t].pb(qr{id, vector<int>()});
                }
                qrs[t].back().v.pb(v[i]);
            }
        }
        for(int i = 1;i <= n;i ++)
            g[i] = i, sz[i] = 1;
        for(int i = 0;i < SZ(uni);i ++){
            for(auto &d:qrs[i]){
                debug(d.id, d.v);
                for(int t:d.v){
                    if(mg(e[t].a, e[t].b))
                        ans[d.id] ++;
                }
                undo();
            }
            debug(dt[i]);
            for(int t:dt[i])
                mg(e[t].a, e[t].b);
            his.clear();
        }
        for(int i = 1;i <= q;i ++)
            cout << ans[i] << endl;
    }
}
