//{
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<string>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<sstream>
#include<cmath>
#include<queue>
#include<stack>

using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(ll i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define FILL(i,n) memset(i,n,sizeof i)
#define MEM(i,n) memset(i,n,sizeof i)
#define X first
#define Y second
#define SZ(_a) (int)_a.size()
#define ALL(_a) _a.begin(),_a.end()
#define pb push_back
#define eb emplace_back
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

#define MAXN MAXn

const ll MAXn=5e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e18);

ll dis[MAXn],p[MAXn];

vector<ii> v[MAXn];
priority_queue<ii,vector<ii>, greater<ii> > pq;

int main()
{
    IOS();
    ll n,m,a,b,c;
    cin>>n>>m>>a>>b>>c;
    REP(i,m)
    {
        ll x,y,aa,bb,cc;
        cin>>x>>y>>aa>>bb>>cc;
        ll tmp = aa * a + bb * b + cc * c;
        v[x].pb(ii(y,tmp));
        v[y].pb(ii(x,tmp));
    }
    REP1(i,n)dis[i] = INF;
    dis[1] = 0;
    pq.push(ii(0,1));
    while(SZ(pq))
    {
        ll x = pq.top().Y,y = pq.top().X;
        pq.pop();
        if(dis[x] != y)continue;
        for(ii tmp:v[x])
        {
            if(dis[tmp.X] > dis[x] + tmp.Y)
            {
                p[tmp.X] = x;
                dis[tmp.X] = dis[x] + tmp.Y;
                pq.push({dis[tmp.X],tmp.X});
            }
        }
    }
    vector<ll> stk;
    ll now = n;
    while(now != 1)
    {
        stk.pb(now);
        now = p[now];
    }
    stk.pb(1);
    while(SZ(stk))
    {
        cout<<stk.back()<<" ";
        stk.pop_back();
    }
}
