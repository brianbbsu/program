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
const ll INF=ll(1e15);

ll d[MAXn][MAXn], u[MAXn][MAXn], ans[MAXn][MAXn], h[MAXn];

int main()
{
    IOS();
    ll T;
    cin >> T;
    for(int kz = 1;kz <= T;kz ++){
        int n, m;
        cin >> n >> m;
        for(int i = 1;i <= n;i ++){
            string s;
            cin >> s;
            for(int j = 1;j <= m;j ++)
                d[i][j] = (s[j - 1] == '1');
        }
        debug(456);
        ll l = -1, r = n + m;
        while(l < r - 1){
            memset(u, 0, sizeof(u));
            memset(ans, 0, sizeof(ans));
            ll t = (l + r) / 2;
            debug(l, r, t);
            memset(h, -1, sizeof(h));
            for(int i = 1;i <= n;i ++){
                for(int j = 1;j <= m;j ++)
                    h[j]--;
                {
                    ll th = -1;
                    for(int j = 1;j <= m;j ++){
                        th--;
                        if(d[i][j])th = t;
                        h[j] = max(h[j], th);
                    }
                }
                {
                    ll th = -1;
                    for(int j = m;j >= 1;j --){
                        th--;
                        if(d[i][j])th = t;
                        h[j] = max(h[j], th);
                    }
                }
                for(int j = 1;j <= m;j ++)  
                    if(h[j] >= 0)
                        u[i][j] = 1;
            }
            memset(h, -1, sizeof(h));
            for(int i = n;i >= 1;i --){
                for(int j = 1;j <= m;j ++)
                    h[j]--;
                {
                    ll th = -1;
                    for(int j = 1;j <= m;j ++){
                        th--;
                        if(d[i][j])th = t;
                        h[j] = max(h[j], th);
                    }
                }
                {
                    ll th = -1;
                    for(int j = m;j >= 1;j --){
                        th--;
                        if(d[i][j])th = t;
                        h[j] = max(h[j], th);
                    }
                }
                for(int j = 1;j <= m;j ++)
                    if(h[j] >= 0)
                        u[i][j] = 1;
            }
            ll bck = 0;
            for(int i = 1;i <= n;i ++)
                for(int j = 1;j <= n;j ++)
                    bck += !u[i][j];
            for(int j = 1;j <= m;j ++)
                h[j] = INF;
            for(int i = 1;i <= n;i ++){
                for(int j = 1;j <= m;j ++)
                    h[j]--;
                {
                    ll th = INF;
                    for(int j = 1;j <= m;j ++){
                        th--;
                        if(!u[i][j])th = min(th, t);
                        h[j] = min(h[j], th);
                    }
                }
                {
                    ll th = INF;
                    for(int j = m;j >= 1;j --){
                        th--;
                        if(!u[i][j])th = min(th, t);
                        h[j] = min(h[j], th);
                    }
                }
                for(int j = 1;j <= m;j ++)
                    if(h[j] < 0)
                        ans[i][j] = 1;
            }
            for(int j = 1;j <= m;j ++)
                h[j] = INF;
            for(int i = n;i >= 1;i --){
                for(int j = 1;j <= m;j ++)
                    h[j]--;
                {
                    ll th = INF;
                    for(int j = 1;j <= m;j ++){
                        th--;
                        if(!u[i][j])th = min(th, t);
                        h[j] = min(h[j], th);
                    }
                }
                {
                    ll th = INF;
                    for(int j = m;j >= 1;j --){
                        th--;
                        if(!u[i][j])th = min(th, t);
                        h[j] = min(h[j], th);
                    }
                }
                for(int j = 1;j <= m;j ++)
                    if(h[j] < 0)
                        ans[i][j] = 1;
            }
            ll fg = 0;
            for(int i = 1;i <= n;i ++)
                for(int j = 1;j <= m;j++)
                    if(!ans[i][j])
                        fg = 1;
            if(fg) r = t;
            else l = t;
        }
        cout << "Case #" << kz << ": " << r << endl;
    }



}
