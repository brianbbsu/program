//{
#include<bits/stdc++.h>
using namespace std;
typedef int ll;
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

ll l[MAXn], r[MAXn], dp[MAXn], u[MAXn], inq[MAXn];

set<ii> stl[MAXn], str[MAXn];
queue<ll> q;

ll ans[MAXn];

void rm(ll x)
{
    debug(x);
    stl[dp[x]].erase(ii(l[x], x)), str[dp[x]].erase(ii(r[x], x));
    u[x] = 1;
    if(!inq[dp[x]])inq[dp[x]] = 1, q.push(dp[x]);
}

int main()
{
    IOS();
    ll n;
    cin>>n;
    REP1(i, n)cin>>l[i]>>r[i];

    ll ml = 0;

    {
        vector<ll> dtl, dtr;
        REP1(i,n)dtl.pb(i), dtr.pb(i);
        sort(ALL(dtl), [](int a,int b){return l[a] < l[b];});
        sort(ALL(dtr), [](int a,int b){return r[a] < r[b];});
        ll it = 0;
        for(ll t:dtl)
        {
            while(it < SZ(dtr) && r[dtr[it]] < l[t])ml = max(ml, dp[dtr[it++]]);
            dp[t] = ml + 1;
        }
        while(it < SZ(dtr))ml = max(ml, dp[dtr[it++]]);
    }

    REP1(i,n)stl[dp[i]].insert(ii(l[i], i)), str[dp[i]].insert(ii(r[i], i));

    REP1(i, ml)q.push(i), inq[i] = 1;

    REP1(i, n)
    {
        while(SZ(q))
        {
            ll t = q.front();
            q.pop();inq[t] = 0;
            debug(t, str[t-1], stl[t]);
            if(t != 1)while(SZ(str[t-1]) && str[t-1].rbegin()->X >= stl[t].rbegin()->X)rm(str[t-1].rbegin()->Y);
            if(t != ml)while(SZ(stl[t+1]) && stl[t+1].begin()->X <= str[t].begin()->X)rm(stl[t+1].begin()->Y);
        }
        if(!u[i])
        {
            debug(dp[i], i);
            ans[dp[i]] = i;
            auto it = stl[dp[i]].begin();
            while(it != stl[dp[i]].end())
            {
                auto nxt = next(it);
                if(it->Y != i)rm(it->Y);
                it = nxt;
            }
        }
    }
    
    cout<<ml<<endl;
    sort(ans + 1, ans + 1 + ml);
    REP1(i,ml)cout<<ans[i]<<" \n"[i == ml];

}
