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
template<typename _a> ostream &operator << (ostream &_s,multiset<_a> &_c){return _OUTC(_s,ALL(_c));}
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

void qt()
{
    cout<<"syntax error"<<endl;
    exit(0);
}

struct tg{
    ll x, a, b;
};

ii a[MAXn], b[MAXn];
ll dta[MAXn], dtb[MAXn], ans[MAXn];
ll n;

int main()
{
    IOS();
    cin>>n;
    REP1(i,n)cin>>a[i].X>>a[i].Y, dta[i] = i;
    REP1(i,n)cin>>b[i].X>>b[i].Y, dtb[i] = i;
    sort(dta + 1, dta + n + 1, [](int x,int y){return a[x] > a[y];});
    sort(dtb + 1, dtb + n + 1, [](int x,int y){return b[x] > b[y];});
    set<ii> pst;
    ll it = 1;
    REP1(i, n)
    {
        ll t = dta[i];
        while(it <= n && b[dtb[it]].X >= a[t].X)
        {
            ll y = b[dtb[it]].Y;
            pst.insert(ii(y, dtb[it]));
            it++;
        }
        auto sit = pst.lower_bound(ii(a[t].Y, -1));
        if(sit == pst.end())qt();
        ans[t] = sit->Y;
        pst.erase(sit);
    }
    vector<tg> h, v;
    REP1(i, n)
    {
        ll t = ans[i];
        v.pb({a[i].X, a[i].Y, b[t].Y});
        v.pb({b[t].X, a[i].Y, b[t].Y});
        h.pb({a[i].X, b[t].Y, 1});
        h.pb({a[i].X, a[i].Y, 1});
        h.pb({b[t].X + 1, b[t].Y, -1});
        h.pb({b[t].X + 1, a[i].Y, -1});
        
    }
    sort(ALL(v), [](auto &x, auto &y){return x.x < y.x;});
    sort(ALL(h), [](auto &x, auto &y){return x.x < y.x;});
    multiset<ll> st;
    pary(ans + 1, ans + 1 + n);
    it = 0;
    for(auto &p:v)
    {
        while(it < SZ(h) && h[it].x <= p.x)
        {
            if(h[it].b == 1)st.insert(h[it].a);
            else st.erase(st.lower_bound(h[it].a));
            it ++;
        }
        debug(st, p.a, p.b);
        st.erase(st.lower_bound(p.a));
        st.erase(st.lower_bound(p.b));
        if(st.lower_bound(p.a) != st.upper_bound(p.b))qt();
        st.insert(p.a);st.insert(p.b);
    }
    REP1(i,n)cout<<ans[i]<<endl;
}
