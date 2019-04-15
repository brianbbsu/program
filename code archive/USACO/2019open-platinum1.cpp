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

#ifndef brian
#include "grader.h"
#else
namespace test{
    int N;
}
int getN(){
    return test::N;
}
int getQ();
void setFarmLocation(int ID, int X, int Y){
    debug(ID, X, Y);
}
void addBox(int X1, int Y1, int X2, int Y2){
    debug(X1, Y1, X2, Y2);
}

#endif

vector<ll> v[MAXn];
ll n, tin=1, tout=1, in[MAXn], out[MAXn], dph[MAXn], p[MAXn][MAXlg];

void addRoad(int a, int b){
	v[a].pb(b);
    v[b].pb(a);
}

void dfs(ll now,ll f)
{
    p[now][0] = f;
    in[now] = tin ++;
    for(ll k:v[now])if(k != f){
        dph[k] = dph[now] + 1;
        dfs(k, now);
    }
    out[now] = tout ++;
}

void buildFarms(){
	n = getN();
    dfs(0, 0);
    REP(i,n)setFarmLocation(i, in[i], out[i]);
    REP1(j, MAXlg - 1)REP(i,n)p[i][j] = p[p[i][j-1]][j-1];
}

ll lca(ll a, ll b)
{
    if(dph[a] < dph[b])swap(a, b);
    for(int j = MAXlg - 1;j >= 0;j --)if(dph[p[a][j]] >= dph[b])a = p[a][j];
    if(a == b)return a;
    for(int j = MAXlg - 1;j >= 0;j --)if(p[a][j] != p[b][j])a = p[a][j], b = p[b][j];
    return p[a][0];
}

ll la(ll x,ll k)
{
    for(int j = MAXlg - 1;j >= 0;j --)if((1<<j) <= k)k -= (1<<j), x = p[x][j];
    return x;
}

void notifyFJ(int a, int b){
	if(dph[a] < dph[b])swap(a, b);
    // dph[a] >= dph[b]
    ll c = lca(a, b);
    if(c == b){// a chain
        addBox(in[b], out[a], in[a], out[b]);
    }
    else{
        ll d = la(a, dph[a] - dph[c] - 1);
        // a -> d, b -> c
        addBox(in[d], out[a], in[a], out[d]);
        addBox(in[c], out[b], in[b], out[c]);
    }
}

#ifdef brian
int main()
{
    cin>>test::N;
    REP(i, test::N - 1){
        ll a, b;
        cin>>a>>b;
        addRoad(a, b);
    }
    buildFarms();
    ll a, b;
    while(cin>>a>>b){
        notifyFJ(a, b);
    }
}
#endif
