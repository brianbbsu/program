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

vector<ll> v[MAXn];
ll px[MAXn], py[MAXn], vy[MAXn];
ll dp[MAXn][2];


bool dfs(ll x)
{
    for(ll y:v[x])
    {
        if(!vy[y])
        {
            vy[y] = 1;
            if(py[y] == -1 || dfs(py[y]))
            {
                py[y] = x;
                px[x] = y;
                return 1;
            }
        }
    }
    return 0;
}

void trdfs(ll now,ll f)
{
    dp[now][0] = dp[now][1] = 0;
    ll tt = 0;
    for(ll k:v[now])if(k != f)
    {
        trdfs(k, now);
        tt += max(dp[k][0], dp[k][1]);
    }
    dp[now][0] = tt;
    for(ll k:v[now])if(k != f)dp[now][1] = max(dp[now][1], tt - max(dp[k][0], dp[k][1]) + dp[k][0] + 1);
}

int main()
{
    IOS();
    ll T;
    cin>>T;
    while(T--)
    {
        ll n,m,k;
        cin>>n>>m>>k;
        if(n > 1500)
        {
            REP1(i,n+m)v[i].clear();
            REP1(i,k)
            {
                ll a,b;
                cin>>a>>b;
                b += n;
                v[a].pb(b);
                v[b].pb(a);
            }
            trdfs(1,-1);
            cout<<max(dp[1][0], dp[1][1])<<endl;
        }
        else
        {

            REP1(i,n)v[i].clear();
            REP1(i,k)
            {
                ll a,b;
                cin>>a>>b;
                v[a].pb(b);
            }
            REP1(i,n)px[i] = -1;
            REP1(i,m)py[i] = -1;
            ll ct = 0;
            REP1(i,n)for(ll y:v[i])if(py[y] == -1)
            {
                px[i] = y;
                py[y] = i;
                ct ++;
                break;
            }
            REP1(i,n)if(px[i] == -1)
            {
                REP1(j,m)vy[j] = 0;
                if(dfs(i))ct++;
            }
            cout<<ct<<endl;
        }
    }
}
