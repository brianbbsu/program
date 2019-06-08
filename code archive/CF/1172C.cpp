//{
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lf;
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
const ll MOD=998244353;
const ll INF=ll(1e15);

ll pw(ll x,ll k)
{
    if(!k)return 1;
    ll a = pw(x, k / 2);
    a = a * a % MOD;
    if(k & 1)return a * x % MOD;
    else return a;
}

ii operator + (ii a, ii b){return ii((a.X * b.Y + b.X * a.Y), a.Y * b.Y);}
ii operator - (ii a, ii b){return ii(((a.X * b.Y - b.X * a.Y)), a.Y * b.Y);}
ii operator * (ii a, ii b){return ii((a.X * b.X), a.Y * b.Y);}
ii operator / (ii a, ii b){return ii((a.X * b.Y), a.Y * b.X);}


ll tp[MAXn], v[MAXn];
ii w[MAXn];
lf wf[MAXn];

int main()
{
    IOS();
    ll n, m;
    cin>>n>>m;
    REP1(i,n)cin>>tp[i];
    REP1(i,n)cin>>w[i].X, w[i].Y = 1, v[i] = 1, wf[i] = w[i].X;

    if(n == 1)
    {
        if(tp[1] == 1)cout<<w[1].X + m<<endl;
        else cout<<max(0LL, w[1].X - m)<<endl;
        return 0;
    }

    while(m--)
    {
        ii tt = ii(0, 1);
        lf ttf = 0;
        REP1(i,n)if(v[i])tt = tt + w[i], ttf = ttf + wf[i];
        debug(tt);
        REP1(i,n)if(v[i])
        {
            if(tp[i] == 1)wf[i] += wf[i] / ttf, w[i] = w[i] + w[i] / tt;
            else
            {
                wf[i] -= wf[i] / ttf;
                if(wf[i] < -1e-12)wf[i] = 0, v[i] = 0, w[i] = ii(0, 1);
                else w[i] = w[i] - w[i] / tt;
            }
        }
        REP1(i,n)debug(w[i], wf[i]);
    }
    REP1(i,n)cout<<w[i].X * pw(w[i].Y, MOD - 2) % MOD<<endl;
}
