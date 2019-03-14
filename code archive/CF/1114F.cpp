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


const ll MAXn=4e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);


struct node{
    int l, r;
    node *lc, *rc;
    ll tt, tg;
    node(int li, int ri, node *lci = 0, node *rci = 0):l(li), r(ri), lc(lci), rc(rci), tt(0), tg(0){};
    void pull()
    {
        if(l != r-1)tt = lc->tt + rc->tt + (r - l) * tg;
        else tt = tg;
    }
    ll cal(int li,int ri)
    {
        return ((min(r, ri) - max(l, li)) * tg);
    }
    ll qr(int li, int ri)
    {
        if(li >= r || ri <= l)return 0;
        else if(li <= l && ri >= r)return tt;
        else return lc->qr(li, ri) + rc->qr(li, ri) + cal(li, ri);
    }
    void ins(int li,int ri,ll x)
    {
        if(li >= r || ri <= l)return;
        else if(li <= l && ri >= r)tg += x, pull();
        else lc->ins(li, ri, x), rc->ins(li, ri, x), pull();
    }
    void clr()
    {
        tt = 0, tg = 0;
        if(l != r-1)lc->clr(), rc->clr();
    }
};

node * build(int l,int r)
{
    if(l == r-1)return new node(l, r);
    else return new node(l, r, build(l, (l+r)/2), build((l+r)/2, r));
}


ll mypow(ll a,ll b){
	ll res=1LL;
	while(b){
		if(b&1) res=res*a%MOD;
		a=a*a%MOD;
		
		b>>=1;
	}
	return res;
}

vector<ll> p;
node *rt;
ll ans[MAXn], d[MAXn];
vector<pair<ii, ll>> qr;

ll fac(ll x,ll k)
{
    ll ct = 0;
    while(x % k == 0)ct++, x /= k;
    return ct;
}

int main()
{
    IOS();
    for(int i = 2;i <= 300;i ++)
    {
        bool fg = 1;
        for(int j = 2;j * j <= i;j++)if(i % j == 0)fg = 0;
        if(fg)p.pb(i);
    }
    ll n, q;
    cin>>n>>q;
    rt = build(1, n+1);
    REP1(i,n)cin>>d[i];
    REP(i,q)ans[i] = 1;
    REP(i,q)
    {
        string s;
        cin>>s;
        if(s[0] == 'M')
        {
            ll l, r, x;
            cin>>l>>r>>x;
            qr.pb({{l, r}, x});
        }
        else
        {
            ll l, r;
            cin>>l>>r;
            qr.pb({{l, r}, -1});
        }
    }
    for(ll t:p)
    {
        rt->clr();
        REP1(i,n){
            ll c = fac(d[i], t);
            if(c)rt->ins(i, i+1, c);
        }
        REP(i, q)
        {
            if(qr[i].Y == -1)
            {
                ll c = rt->qr(qr[i].X.X, qr[i].X.Y+1);
                if(!c)continue;
                ans[i] = ans[i] * mypow(t, c-1) % MOD;
                ans[i] = ans[i] * (t - 1) % MOD;
            }
            else
            {
                ll c = fac(qr[i].Y, t);
                if(c)rt->ins(qr[i].X.X, qr[i].X.Y+1, c);
            }
        }
    }
    REP(i,q)if(qr[i].Y == -1)cout<<ans[i]<<endl;
}
