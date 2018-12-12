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

vector<ll> v[MAXn];
ll dis[MAXn], sdis[MAXn], ans[MAXn], dt[MAXn];
ll n,m;

void bfs(ll s)
{
    REP1(i,n)dis[i] = INF;
    dis[s] = 0;
    queue<ll> q;
    q.push(s);
    while(SZ(q))
    {
        ll t = q.front();
        q.pop();
        for(ll k:v[t])if(dis[k] > dis[t] + 1)
        {
            dis[k] = dis[t] + 1;
            q.push(k);
        }
    }
}

int main()
{
    IOS();
    ll s,a,b;
    cin>>n>>m>>s>>a>>b;
    REP(i,m)
    {
        ll x,y;
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    bfs(s);
    REP1(i,n)ans[i] = min(dis[i] * a, dis[i] / 2 * b + (dis[i] & 1) * a);
    priority_queue<ii,vector<ii>, greater<ii> > pq;
    REP1(i,n)pq.push({ans[i], i});
    while(SZ(pq))
    {
        ll t = pq.top().Y, tmpa = pq.top().X;
        pq.pop();
        if(ans[t] != tmpa)continue;
        bfs(t);
        REP1(j,n)if(dis[j] == 2 && ans[j] > ans[t] + b)ans[j] = ans[t] + b, pq.push({ans[j], j});
    }
    REP1(i,n)cout<<ans[i]<<endl;
}
