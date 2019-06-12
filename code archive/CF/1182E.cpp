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

vector<vector<ll>> pat = {
    {1, 1, 1}, 
    {1, 0, 0},
    {0, 1, 0}
};

void add(ll &a, ll b, ll M){
    a = (a + b) % M;
}

vector<vector<ll>> pw(ll k, ll M){
    if(k == 0){
        vector<vector<ll>> ret(3, vector<ll>(3, 0));
        ret[0][0] = ret[1][1] = ret[2][2] = 1;
        return ret;
    }
    auto a = pw(k / 2, M);
    vector<vector<ll>> b(3, vector<ll>(3, 0));
    REP(i, 3)REP(j, 3)REP(k, 3)add(b[i][j], a[i][k] * a[k][j], M);
    if(k & 1){
        vector<vector<ll>> ret(3, vector<ll>(3, 0));
        REP(i, 3)REP(j, 3)REP(k, 3)add(ret[i][j], pat[i][k] * b[k][j], M);
        return ret;
    }
    return b;
}

ll pw(ll x,ll k, ll M){
    if(!k)return 1;
    ll a = pw(x, k / 2, M);
    a = a * a % M;
    if(k & 1)return a * x % M;
    else return a;
}

int main(){
    IOS();
    ll n, f1, f2, f3, c;
    cin>>n>>f1>>f2>>f3>>c;
    auto p = pw(n - 3, MOD - 1);
    ll ans = pw(c, ((3 * p[0][0] + 2 * p[0][1] + p[0][2] - n) % (MOD - 1) + MOD - 1) % (MOD - 1), MOD);
    ans = ans * pw(f1, p[0][2], MOD) % MOD;
    ans = ans * pw(f2, p[0][1], MOD) % MOD;
    ans = ans * pw(f3, p[0][0], MOD) % MOD;
    cout<<ans<<endl;
} 
