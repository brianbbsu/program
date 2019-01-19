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


const ll MAXn=2e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);


const ll K = 100;

namespace bit{
    ll bit[MAXn], N;
    void init(int n)
    {
        N = n;
        REP(i,N+1)bit[i] = 0;
    }
    void ins(ll x,ll k)
    {
        while(x <= N)bit[x] += k, x += x & -x;
    }
    ll qr(ll x)
    {
        ll ret = 0;
        while(x)ret += bit[x], x -= x & -x;
        return ret;
    }
};

struct tg{
    ll x, l, r, tp, id;
};

ll ans[MAXn], ct[MAXn];
vector<ii> v, vp, qr;
vector<tg> dt;


void cal_large(){
    ll it = 0;
    for(ii q:qr)
    {
        while(it < SZ(vp) && vp[it].X < q.X)it++;
        while(it < SZ(vp) && vp[it].X <= q.Y)ct[vp[it].Y]++,it++;
    }
}

void cal_small()
{
    ll it = 0;
    for(auto &q:dt)
    {
        while(it < SZ(v) && v[it].X <= q.x)bit::ins(v[it].Y, 1), it++;
        ans[q.id] += q.tp * (bit::qr(q.r) - bit::qr(q.l-1));
    }
}

int main()
{
    IOS();
    ll T;
    cin>>T;
    while(T--)
    {
        ll n,m;
        cin>>n>>m;
        v.clear();
        vp.clear();
        dt.clear();
        REP(i,m)
        {
            ll a,b;
            cin>>a>>b;
            if(a > b)swap(a,b);
            v.pb({a,b});
        }
        REP(i,m)vp.pb({v[i].X, i}), vp.pb({v[i].Y, i});
        sort(ALL(vp));
        sort(ALL(v));
        ll q;
        cin>>q;
        REP(i,q)ans[i] = 0;
        REP(tc, q)
        {
            ll k;
            cin>>k;
            qr.clear();
            REP(i,k)
            {
                ll a, b;
                cin>>a>>b;
                qr.pb({a,b});
            }
            sort(ALL(qr));
            if(k > K)
            {
                REP(i,m)ct[i] = 0;
                cal_large();
                REP(i,m)if(ct[i] == 2)ans[tc]++;
            }
            else
            {
                for(int i = 0;i < k;i ++)for(int j = 0;j <= i;j ++)
                {
                    dt.pb({qr[j].X-1, qr[i].X, qr[i].Y, -1, tc});
                    dt.pb({qr[j].Y, qr[i].X, qr[i].Y, 1, tc});
                }
            }
        }
        sort(ALL(dt), [](auto &a, auto &b){return a.x < b.x;});
        bit::init(n);
        cal_small();
        REP(i,q)cout<<(ans[i]?"NO":"YES")<<endl;
    }
}
