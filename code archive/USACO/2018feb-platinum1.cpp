//{
#include<bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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

string _taskname;
void _init()
{
  #ifndef brian
      freopen((_taskname+".in").c_str(), "r", stdin);
      freopen((_taskname+".out").c_str(),"w",stdout);
  #endif
}
void _end()
{
  #ifndef brian
      fclose( stdin);
      fclose(stdout);
  #endif
}

const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll N;

struct seg{
    ll s[8 * MAXn];
    void build(){
        for(int i = (N<<1) - 1;i > 0;i --)s[i] = INF;
    }
    void ins(ll x,ll k){
        for(x+=N, s[x] = min(s[x], k);x > 1;x >>= 1)s[x>>1] = min(s[x], s[x^1]);
    }
    ll query(ll l,ll r)
    {
        ll ret = INF;
        for(l += N, r += N;l < r;l>>=1,r>>=1)
        {
            if(l&1)ret = min(ret, s[l++]);
            if(r&1)ret = min(ret, s[--r]);
        }
        return ret;
    }
}lrt,rrt;

struct edge{
    ll s,t,c;
};
struct tg{
    ll a,b, id;
}; 
vector<edge> e;
vector<tg> qr;
vector<ll> uni;

ll pos(ll x)
{
    return lower_bound(ALL(uni), x) - uni.begin();
}

ll ans[MAXn];

int main()
{
    IOS();
    _taskname = "slingshot";
    _init();
    ll n,m;
    cin>>n>>m;
    REP(i,n)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        e.pb({a,b,c});
        uni.pb(a);
        uni.pb(b);
    }
    REP(i,m)
    {
        ll a,b;
        cin>>a>>b;
        qr.pb({a,b,i});
        ans[i] = abs(a - b);
        uni.pb(a);
        uni.pb(b);
    }
    sort(ALL(e),[](edge a,edge b){return a.s < b.s;});
    sort(ALL(qr),[](tg a, tg b){return a.a < b.a;});
    sort(ALL(uni));
    uni.resize(unique(ALL(uni)) - uni.begin());
    N = SZ(uni);
    lrt.build();
    rrt.build();
    ll eit = 0;
    for(tg &q:qr)
    {
        while(eit < SZ(e) && e[eit].s <= q.a)
        {
            lrt.ins(pos(e[eit].t),e[eit].c - e[eit].s - e[eit].t);
            rrt.ins(pos(e[eit].t),e[eit].c - e[eit].s + e[eit].t);
            eit++;
        }
        ans[q.id] = min(ans[q.id], lrt.query(0,pos(q.b)) + q.a + q.b);
        ans[q.id] = min(ans[q.id], rrt.query(pos(q.b),SZ(uni)) + q.a - q.b);
    }
    lrt.build();
    rrt.build();
    eit = SZ(e) - 1;
    for(int i = SZ(qr) - 1;i >= 0;i --)
    {
        tg &q = qr[i];
        while(eit >=0 && e[eit].s >= q.a)
        {
            lrt.ins(pos(e[eit].t),e[eit].c + e[eit].s - e[eit].t);
            rrt.ins(pos(e[eit].t),e[eit].c + e[eit].s + e[eit].t);
            eit--;
        }
        ans[q.id] = min(ans[q.id], lrt.query(0,pos(q.b)) - q.a + q.b);
        ans[q.id] = min(ans[q.id], rrt.query(pos(q.b),SZ(uni)) - q.a - q.b);
    }
    REP(i,m)cout<<ans[i]<<endl;
    cout.flush();
    _end();
}
