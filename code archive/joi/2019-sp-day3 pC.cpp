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


const ll MAXn=3e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

struct qrtg{
    ll i, s, st, e, et;
};


ll l[2][MAXn], r[2][MAXn], ans[MAXn];
ii dp[2][MAXn][2];
ll n, q;

const ll K = 700;

//vector<qrtg> qr[2];
set<ii> u[2][K + 5], d[2][K + 5];


void let(ll p, ll s,ll t)
{
    t--;
    l[0][p] = s - p;
    r[0][p] = t - p;
    p = n - p;
    l[1][p] = s - p;
    r[1][p] = t - p;
}

ii cal(ll fg,ll it, ll x)
{
    ll ut = prev(u[fg][it].lower_bound({x, -1}))->Y;
    ll dt = d[fg][it].lower_bound({x, INF})->Y;
    if(min(ut, dt) == n)return {0, x};
    if(ut <= dt)return {dp[fg][ut][1].X + x - r[fg][ut], dp[fg][ut][1].Y};
    else return dp[fg][dt][0];
}

void build(ll fg, ll it)
{
    
}

int main()
{
    IOS();
    cin>>n>>q;
    REP1(i,n-1)
    {
        ll s, t;
        cin>>s>>t;
        let(i, s, t);
    }
    
    for(int i = 0;i < q;i++)
    {
        ll tp, s, st, e, et;
        cin>>tp>>s>>st>>e>>et;
        if(s < e)qr[0].pb({i, s, st, e, et});
        else qr[1].pb({i, n - s + 1, st, n - e + 1, et});
    }
    for(int fg = 0;fg <= 1;fg ++)
    {
        u.clear();d.clear();
        u.insert({-INF, n});d.insert({INF, n});
        sort(ALL(qr[fg]), [](auto &a, auto &b){return a.s > b.s;});
        for(auto &p:qr[fg])p.st -= p.s, p.et -= p.e;
        int it = 0;
        for(int i = n-1;i >= 1; i--)
        {
            dp[fg][i][0] = cal(fg, l[fg][i]);
            dp[fg][i][1] = cal(fg, r[fg][i]);
            u.erase(u.lower_bound({r[fg][i], -1}), u.end());
            d.erase(d.begin(), d.lower_bound({l[fg][i], INF}));
            u.insert({r[fg][i], i});d.insert({l[fg][i], i});
            while(it != SZ(qr[fg]) && qr[fg][it].s == i){
                ii t = cal(fg, qr[fg][it].st);
                if(t.Y > qr[fg][it].et)t.X += t.Y - qr[fg][it].et;
                ans[qr[fg][it].i] = t.X;
                it++;
            }
        }

    }
    REP(i, q)cout<<ans[i]<<endl;

}
