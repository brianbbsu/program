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


const ll MAXn=30+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll n, m;
ll d[MAXn][MAXn], dt[MAXn][MAXn];
ll dx[] = {-1,1,0,0};
ll dy[] = {0,0,1,-1};
bool val(ll x,ll y){
    return x >= 0 && x < n && y >= 0 && y < m;
}


bool chk(ll k, ll I)
{
    REP(i, m)
    {
        ll tt = 0;
        if(val(k, i-1))tt += ((I&(1<<(m+i-1))) > 0);
        if(val(k, i+1))tt += ((I&(1<<(m+i+1))) > 0);
        if(val(k+1, i))tt += ((I&(1<<(i))) > 0);
        if(val(k-1, i))tt += ((I&(1<<(2 * m + i))) > 0);
        if(d[k][i] != -1 && d[k][i] != tt%2)return 0;
    }
    return 1;
}

ll dp[MAXn][(1<<8)];

void add(ll &a,ll b)
{
    a += b;
    if(a >= MOD)a -= MOD;
}

int main()
{
    IOS();
    ll T;
    cin>>T;
    while(T--)
    {
        cin>>n>>m;
        REP(i,n)REP(j,m)cin>>d[i][j];
        FILL(dp, 0);
        REP(i, (1<<m))dp[0][i] = 1;
        REP1(i, n-1)
        {
            REP(I, (1<<m))REP(J, (1<<(2*m)))
            {
                if(chk(i-1,(J<<m)|I))add(dp[i][((J<<m)|I)&((1<<(2*m))-1)], dp[i-1][J]);
            }
        }
        ll tt = 0;
        REP(I, (1<<2*m))if(chk(n-1,(I<<m)))
        {
            add(tt, dp[n-1][I]);
        }
        cout<<tt<<endl;
        
    }
}