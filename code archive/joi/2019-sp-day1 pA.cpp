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

namespace bit{
    ll bit[2 * MAXn], ct = 0;
    void ins(ll x,ll k)
    {
        ct += k;
        while(x < (MAXn<<1))bit[x] += k, x += x & -x;
    }
    int qr(ll x) // >= x
    {
        x --;
        ll ret = 0;
        while(x)ret += bit[x], x -= x & -x;
        return ct - ret;
    }
};

struct tg{
    ll a, b, c, i;
};

struct dt{
    ll a, b, c;
};

ll ans[MAXn];

void cal(vector<tg> &qr, vector<dt> &d)
{
    sort(ALL(d), [](dt &a, dt &b){return a.c > b.c;});
    sort(ALL(qr), [](tg &a, tg &b){return a.c > b.c;});
    ll it = 0;
    for(auto &q: qr)
    {
        while(it < SZ(d) && d[it].c >= q.c)bit::ins(d[it].b, 1), it++;
        ans[q.i] += bit::qr(q.b);
    }
    while(it != 0)it--, bit::ins(d[it].b, -1);
}

void dnq(int l, int r, vector<tg> &qr, vector<dt> &d)
{
    if(l == r-1){
        cal(qr, d);
        return;
    }
    ll h = (l + r) / 2;
    vector<tg> qrl, qrr;
    vector<dt> dl, dr;
    for(auto &t:qr)if(t.a < h)qrl.pb(t); else qrr.pb(t); 
    for(auto &t:d)if(t.a < h)dl.pb(t); else dr.pb(t); 
    cal(qrl, dr);
    dnq(l, h, qrl, dl);
    dnq(h, r, qrr, dr);
}

vector<ll> uni;

int main()
{
    IOS();
    ll n, q;
    cin>>n>>q;
    vector<dt> d;
    REP(i,n){
        ll a, b;
        cin>>a>>b;
        d.pb({a, b, a + b});
        uni.pb(a);
        uni.pb(b);
    }
    sort(ALL(uni));
    uni.resize(unique(ALL(uni)) - uni.begin());
    REP(i,n)d[i].a = lower_bound(ALL(uni), d[i].a) - uni.begin() + 1, d[i].b = lower_bound(ALL(uni), d[i].b) - uni.begin() + 1;

    vector<tg> qr;
    REP(i,q)
    {
        ll a, b, c;
        cin>>a>>b>>c;
        a = lower_bound(ALL(uni), a) - uni.begin() + 1;
        b = lower_bound(ALL(uni), b) - uni.begin() + 1;
        qr.pb({a, b, c, i});
    }
    dnq(1, SZ(uni) + 2, qr, d);
    REP(i,q)cout<<ans[i]<<endl;
}
