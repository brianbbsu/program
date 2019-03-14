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


const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll K;
vector<ll> v[MAXn];

ll d[MAXn];

ll cal(ll i, ll j)
{
    return d[j] / (j - i + 1);
}

int main()
{
    IOS();
    ll T;
    cin>>T;
    while(T--)
    {
        ll n, m;
        cin>>n>>m;
        K = sqrt(100000 + 0.5) * 2;
        REP1(i, n)cin>>d[i];
        REP1(i, n)v[i].clear();
        ll mn = n+1, tt = 0;
        for(int i = n;i > 0;i --)
        {
            ll tmp = 0;
            for(int j = 0;j <= K && i + j <= n;j++){
                tmp += cal(i, i+j);
            }
            //cout<<tmp + tt<<'\n';
            if(tmp + tt <= m)mn = i;
            if(i + K <= n)
            {
                ll p = cal(i, i + K); 
                tt += p;
                if(p != 0)
                {
                    ll t = d[i+K] / p;
                    if(i + K - t + 1 > 0)v[i + K - t + 1].pb(i + K);
                }
            }
            for(ll x:v[i]){
                ll p = cal(i, x);
                tt -= p;
                if(p != 1)
                {
                    //p = cal(i-1, x);
                    p--;
                    tt += p;
                    if(p != 0){
                        ll t = d[x] / p;
                        if(x - t + 1 > 0)v[x - t + 1].pb(x);
                    }
                }
            }
        }
        cout<<mn<<endl;
    }
}
