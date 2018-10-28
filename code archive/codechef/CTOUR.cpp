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
const ll INF=ll(1e17);

vector<ii> v[MAXn];

ll pres[MAXn],p[MAXn][MAXlg],dph[MAXn],mx[MAXn],mn[MAXn];

void dfs(ll now,ll f)
{ 
    mx[now] = pres[now];
    for(ii k:v[now])if(k.X != f)
    {
        dph[k.X] = dph[now] + 1;
        pres[k.X] = pres[now] + k.Y;
        p[k.X][0] = now;
        mn[k.X] = min(mn[now],pres[k.X]);
        dfs(k.X,now);
        mx[now] = max(mx[now],mx[k.X]);
    }
}

ll lca(ll x,ll y)
{
    if(dph[x] < dph[y])swap(x,y);
    for(int j = MAXlg -1 ;j >= 0;j--)if(dph[p[x][j]] >= dph[y])x = p[x][j];
    if(x == y)return x;
    for(int j = MAXlg-1 ;j>=0;j--)if(p[x][j] != p[y][j])x = p[x][j],y = p[y][j];
    return p[x][0];
}

int main()
{
    IOS();
    ll n,q;
    cin>>n>>q;
    REP(i,n-1)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        v[a].pb(ii(b,c));
        v[b].pb(ii(a,c));
    }
    p[1][0] = 1;
    dfs(1,-1);
    REP1(j,MAXlg-1)REP1(i,n)p[i][j] = p[p[i][j-1]][j-1];
    while(q--)
    {
        ll a,b;
        cin>>a>>b;
        ll c = lca(a,b),ans = - INF;
        if(c == a)
        {
            ans = max({0LL,mx[b] - pres[b],pres[a] - mn[a]}) * 2 + pres[b] - pres[a];
        }
        else if(c == b)
        {
            ans = max({0LL,mx[a] - pres[a],pres[b] - mn[b]}) * 2 + pres[a] - pres[b];
        }
        else
        {
            ans = pres[a] - pres[c] + pres[b] - pres[c] + max(0LL,pres[c] - mn[c]) * 2;
        }
        cout<<ans<<endl;
    }
}
