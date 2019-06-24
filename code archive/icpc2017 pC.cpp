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


const ll MAXn=1e2+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);


vector<ll> v[MAXn];
ll px[MAXn], py[MAXn], vy[MAXn];
bool dfs(ll x)
{
    for(ll y:v[x])if(!vy[y])
    {
        vy[y] = 1;
        if(py[y] == -1 || dfs(py[y]))
        {
            py[y] = x;
            px[x] = y;
            return 1;
        }
    }
    return 0;
}

map<ll, ll> ctr, ctc;

ll d[MAXn][MAXn], mxr[MAXn], mxc[MAXn], u[MAXn][MAXn];

int main()
{
    IOS();
    ll n, m;
    cin>>n>>m;
    REP1(i,n)REP1(j, m)cin>>d[i][j];
    REP1(i,n)REP1(j,m)if(d[i][j])u[i][j] = 1, d[i][j]--;
    ll tt = 0;
    FILL(mxr, -1);
    FILL(mxc, -1);
    REP1(i,n)REP1(j,m)if(u[i][j])mxr[i] = max(mxr[i], d[i][j]);
    REP1(i,n)REP1(j,m)if(u[i][j])mxc[j] = max(mxc[j], d[i][j]);
    REP1(i,n)REP1(j,m)tt += d[i][j];

    debug(tt);

    REP1(i,n)if(mxr[i] != -1)tt -= mxr[i];
    REP1(i,m)if(mxc[i] != -1)tt -= mxc[i];

    debug(tt);

    REP1(i,n)REP1(j,m)if(u[i][j] && mxr[i] == mxc[j])v[i].pb(j);

    REP1(i,n)debug(v[i]);

    FILL(px, -1);
    FILL(py, -1);
    REP1(i, n)
    {
        FILL(vy, 0);
        dfs(i);
    }

    REP1(i,n)debug(i, px[i], mxr[i]);

    REP1(i,n)if(px[i] != -1)tt += mxr[i];

    cout<<tt<<endl;
}
