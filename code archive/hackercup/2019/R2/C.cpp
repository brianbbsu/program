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


const ll MAXn=3e2+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e6);

ll d[MAXn][MAXn];

ll dp[MAXn][2][MAXn]; // for stack i, starting with j, with k lost, minimum context switch

ll ch(ll st, ll ct, ll now)
{
    return (st ^ ((ct - 1) & 1)) != now;
}

int main()
{
    IOS();
    ll T;
    cin>>T;
    ll kz = 0;
    while(T--)
    {
        kz ++;
        cout<<"Case #"<<kz<<":";
        ll n, m, q;
        cin>>m>>n>>q;
        REP1(i, m)
        {
            string s;
            cin>>s;
            REP1(j, n)d[j][i] = (s[j - 1] == 'B');
        }
        REP1(i, n)d[i][0] = -1;
        REP1(i, n)
        {
            vector<ii> v;
            REP1(j, m)if(d[i][j] == d[i][j - 1])v.back().Y ++;else v.pb(ii(d[i][j], 1));
            for(int j = 0;j <= m;j ++)dp[i][0][j] = dp[i][1][j] = 1;
            dp[i][0][0] = dp[i][1][0] = 1;
            ll ts = 0;
            for(auto &p:v)
            {
                REP(s, 2)
                {
                    for(int j = m;j >= 0;j --)
                    {
                        if(j < p.Y)dp[i][s][j] = dp[i][s][j] + ch(s, dp[i][s][j], p.X);
                        else dp[i][s][j] = min(dp[i][s][j] + ch(s, dp[i][s][j], p.X), dp[i][s][j - p.Y]);
                    }
                }
                ts += p.Y;
            }
        }
        while(q--)
        {
            ll L;
            cin>>L; // maximum lost
            // ask for minimum context switch
            ll l = 0, r = n * m;
            while(l != r - 1)
            {
                ll h = (l + r) / 2;
                ll mn = INF;
                REP(s, 2)
                {
                    ll tt = 0;
                    REP1(i, n)
                    {
                        ll t = lower_bound(dp[i][s], dp[i][s] + 1 + m, h, greater<ll>()) - dp[i][s];
                        tt += t;
                    }
                    mn = min(mn, tt);
                }
                if(mn <= L)r = h;
                else l = h;
            }
            cout<<" "<<r;
        }
        cout<<endl;
    }
}
