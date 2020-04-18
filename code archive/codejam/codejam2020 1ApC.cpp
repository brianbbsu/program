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

vector<vector<int>> d;
vector<vector<int>> u;
set<int> sr[MAXn], sc[MAXn];

vector<ii> neigh(int x,int y){
    vector<ii> ret;
    auto it = sr[x].lower_bound(y);
    if(it != sr[x].begin())
        ret.pb({x, *prev(it)});
    if(next(it) != sr[x].end())
        ret.pb({x, *next(it)});
    it = sc[y].lower_bound(x);
    if(it != sc[y].begin())
        ret.pb({*prev(it), y});
    if(next(it) != sc[y].end())
        ret.pb({*next(it), y});
    return ret;
}

bool rem(int x, int y){
    auto v = neigh(x, y);
    ll tt = 0;
    for(auto p:v)
        tt += d[p.X][p.Y];
    return tt > SZ(v) * d[x][y];
}

int main()
{
    IOS();
    ll T;
    cin >> T;
    for(int kz = 1;kz <= T;kz ++){
        cout << "Case #" << kz << ": ";
        ll n, m;
        cin >> n >> m;
        d.resize(0);
        d.resize(n, vector<int>(m, 0));
        u.resize(0);
        u.resize(n, vector<int>(m, 0));
        ll ans = 0, s = 0;
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                cin >> d[i][j], s += d[i][j];
        for(int i = 0;i < n;i++){
            sr[i].clear();
            for(int j = 0;j < m;j++)
                sr[i].insert(j);
        }
        for(int i = 0;i < m;i++){
            sc[i].clear();
            for(int j = 0;j < n;j++)
                sc[i].insert(j);
        }
        vector<ii> v;
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                if(rem(i, j))v.pb({i, j}), u[i][j] = 1;
        while(1){
            ans += s;
            if(!SZ(v))break;
            vector<ii> can, ret;
            for(auto p:v){
                auto tmp = neigh(p.X, p.Y);
                for(auto pp:tmp)
                    can.pb(pp);
                sr[p.X].erase(p.Y);
                sc[p.Y].erase(p.X);
                s -= d[p.X][p.Y];
            }
            for(auto p:can)if(!u[p.X][p.Y]){
                if(rem(p.X, p.Y))
                    ret.pb({p.X, p.Y}), u[p.X][p.Y] = 1;
            }
            v = ret;
        }
        cout << ans << "\n";
    }
}
