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

ll x[MAXn], y[MAXn];

#define OK {cout<<"yes"<<endl;continue;}


int main()
{
    IOS();
    ll T;
    cin>>T;
    while(T--)
    {
        ll n,m;
        cin>>n>>m;
        REP(i,n)cin>>x[i]>>y[i];
        ll ct = 0;
        REP(i,n)if(x[i] == 0 || x[i] == m-1)ct++;
        if(ct >= 2)OK
        ct = 0;
        REP(i,n)if(y[i] == 0 || y[i] == m-1)ct++;
        if(ct >= 2)OK
        ct = 0;
        REP(i,n)if((x[i] == 0 || x[i] == m-1) && (y[i] == 0 || y[i] == m-1))ct++;
        if(ct >= 1)OK
        if(n >= 4)OK
        bool fg = 0;
        REP(i,n)
        {
            if(x[i] == 0 || x[i] == m-1)
            {
                ll cta = 0, ctb = 0;
                REP(j,n)if(j != i)
                {
                    if(y[j] <= y[i])cta++;
                    if(y[j] >= y[i])ctb++;
                }
                if(cta >= 2 || ctb >= 2)fg = 1;
            }
            if(y[i] == 0 || y[i] == m-1)
            {
                ll cta = 0, ctb = 0;
                REP(j,n)if(j != i)
                {
                    if(x[j] <= x[i])cta++;
                    if(x[j] >= x[i])ctb++;
                }
                if(cta >= 2 || ctb >= 2)fg = 1;
            }
        }
        if(n >= 3)REP(i,n)REP(j,i)if(x[i] == 0 || x[i] == m-1 || y[i] == 0 || y[i] == m-1)if(x[j] == 0 || x[j] == m-1 || y[j] == 0 || y[j] == m-1)fg=1;
        if(fg)OK;
        cout<<"no"<<endl;
    }
}
