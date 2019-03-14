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


const ll MAXn=1e6+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll dp[MAXn], ct[MAXn], tt[MAXn];
vector<ll> uni;
vector<ii> d;

void add(ll &a,ll b)
{
    a += b;
    if(a >= MOD)a -= MOD;
    else if(a < 0)a += MOD;
}

int main()
{
    IOS();
    ll T;
    cin>>T;
    while(T--)
    {
        ll m, n;
        cin>>m>>n;
        uni.clear();
        d.clear();
        REP(i,n)
        {
            ll l, r;
            cin>>l>>r;
            uni.pb(l);
            uni.pb(r);
            d.pb({l,r});
        }
        sort(ALL(uni));
        uni.resize(unique(ALL(uni)) - uni.begin());
        for(auto &p:d)p.X = lower_bound(ALL(uni), p.X) - uni.begin();
        for(auto &p:d)p.Y = lower_bound(ALL(uni), p.Y) - uni.begin();
        sort(ALL(d), [](ii a, ii b){return a.Y < b.Y;});
        
        ll mx = -1, it = 0, it2 = 0;
        REP(i, SZ(uni) + 1)dp[i] = 0, ct[i] = 0;
        REP1(i,n)tt[i] = 0;
        REP(i, SZ(uni) - 1){
            while(it != SZ(d) && d[it].Y <= i)mx = max(mx, d[it].X), it++;
            while(it2 != SZ(uni) - 1 && it2 < mx)add(tt[dp[it2]], -ct[it2]), it2++;
            if(mx == -1)dp[i] = 1, ct[i] = uni[i+1] - uni[i], add(tt[1], ct[i]);
            else dp[i] = dp[mx] + 1, ct[i] = (uni[i+1] - uni[i]) * tt[dp[mx]] % MOD, add(tt[dp[i]], ct[i]);
        }
        
        while(it != SZ(d))mx = max(mx, d[it].X), it++;
        
        ll ans = 0;
        for(int i = mx;i < SZ(uni) - 1;i++)if(dp[i] == dp[mx])add(ans, ct[i]);

        REP(i, SZ(uni) - 2)assert(dp[i] <= dp[i+1]);

        cout<<dp[mx]<<" "<<ans<<endl;
        debug(uni);
        pary(dp, dp + SZ(uni));
    }
}
