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


const ll MAXn=5e2+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll d[MAXn][MAXn], p[MAXn][MAXn];

ll ok[MAXn], ct[MAXn], u[MAXn];

int main()
{
    IOS();
    ll n;
    cin>>n;
    REP1(i,n)REP1(j,n)cin>>d[i][j], p[i][d[i][j]] = j;
    ll tp;
    cin>>tp;
    if(tp == 1)
    {
        vector<ll> ans;
        REP1(i,n)if(d[i][1] == i)ans.pb(i);
        cout<<SZ(ans)<<endl;
        for(ll x:ans)cout<<x<<" ";
        exit(0);
    }
    REP1(i,n)
    {
        FILL(ct, 0);
        FILL(u, 0);
        for(int j = 1;j <= n && p[i][i] >= j;j++)
        {
            bool fg = 1;
            REP1(k, n)if(u[k] && ct[k] == p[k][k] - 1)fg = 0;
            if(fg)ok[d[i][j]] = 1;
            u[d[i][j]] = 1;
            REP1(k, n)if(p[k][d[i][j]] < p[k][k])ct[k]++;
        }
    }
    vector<ll> ans;
    REP1(i,n)if(ok[i])ans.pb(i);
    cout<<SZ(ans)<<endl;
    for(ll x:ans)cout<<x<<" ";
    cout<<endl;
}
