//{
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<int,int> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
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

int z[MAXn];

void calz(string s){
    ll n = SZ(s);
    z[0] = 0;
    int far = 0;
    REP1(i, n-1){
        z[i] = 0;
        if(far + z[far] - 1 >= i)z[i] = min(z[i - far], far + z[far] - i);
        for(;i + z[i] < n && s[i + z[i]] == s[z[i]];z[i]++);
    }
}

string s, d[15];
vector<ii> dt[15];
int nxt[15][MAXn], prv[15][MAXn], ct[MAXn];
ll n, m, ans;

void cal(int msk){
    vector<ll> v;
    FILL(ct, 0);
    REP(i,m)if(msk&(1<<i))v.pb(i);
    do{
        ll now = 0;
        for(int i = 0;i < SZ(v) && now != -1;i++)now = nxt[v[i]][now+1];
        if(now == -1)continue;
        else ct[now]++;
    }while(next_permutation(ALL(v)));
    REP1(i,n)ct[i] += ct[i-1];
    v.clear();
    REP(i,m)if(!(msk&(1<<i)))v.pb(i);
    do{
        ll now = n+1;
        for(int i = 0;i < SZ(v) && now != -1;i++)now = prv[v[i]][now-1];
        if(now == -1)continue;
        else ans += ct[now-1];
    }while(next_permutation(ALL(v)));
}


int main()
{
    IOS();
    cin>>n>>m;
    cin>>s;
    REP(i,m)cin>>d[i];
    REP(i,m)
    {
        calz(d[i] + s);
        REP(j,n)if(z[SZ(d[i]) + j] >= SZ(d[i]))dt[i].pb(ii(j + 1, j + SZ(d[i])));
    }
    FILL(nxt, -1);
    FILL(prv, -1);
    REP(i,m)for(ii p:dt[i])nxt[i][p.X] = p.Y, prv[i][p.Y] = p.X;
    REP(i,m)for(int j = n-1;j > 0;j--)if(nxt[i][j] == -1)nxt[i][j] = nxt[i][j+1];
    REP(i,m)for(int j = 2;j <= n;j++)if(prv[i][j] == -1)prv[i][j] = prv[i][j-1];
    ll g = min(7LL, m);
    REP(I, (1<<m)){
        ll c = 0;
        REP(i,m)if((1<<i) & I)c++;
        if(c == g)cal(I);
    }
    cout<<ans<<endl;
}
