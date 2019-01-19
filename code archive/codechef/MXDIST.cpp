//{
#include<bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<int,int> ii;
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
template<typename _a, typename T> ostream &operator << (ostream &_s,set<_a, T> &_c){return _OUTC(_s,ALL(_c));}
template<typename _a,typename _b> ostream &operator << (ostream &_s,map<_a,_b> &_c){return _OUTC(_s,ALL(_c));}
template<typename _t> void pary(_t _a,_t _b){_OUTC(cerr,_a,_b);cerr<<endl;}
#define IOS()
#else
#define debug(...)
#define pary(...)
#define endl '\n'
#endif // brian
//}

#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);

const ll MAXn=2e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll operator * (const ii &a, const ii &b){
    return (ll)a.X * (ll)b.Y - (ll)a.Y * (ll)b.X;
}
ii operator - (const ii &a, const ii &b){
    return ii(a.X - b.X, a.Y - b.Y);
}


vector<ii> conv(vector<ii> v, bool srt = false)
{
    if(SZ(v) <= 2)return v;
    vector<ii> up, down;
    up.pb(v[0]);
    up.pb(v[1]);
    for(int i = 2;i < SZ(v);i++)
    {
        while(SZ(up) >= 2 && (v[i] - up[SZ(up) - 2]) * (up.back() - up[SZ(up) - 2]) <= 0)up.pop_back();
        up.pb(v[i]);
    }
    down.pb(v[SZ(v) - 1]);
    down.pb(v[SZ(v) - 2]);
    for(int i = SZ(v) - 3;i >= 0;i--)
    {
        while(SZ(down) >= 2 && (v[i] - down[SZ(down) - 2]) * (down.back() - down[SZ(down) - 2]) <= 0)down.pop_back();
        down.pb(v[i]);
    }
    vector<ii> ret;
    if(srt)
    {
        ret.resize(SZ(up) + SZ(down) - 2);
        reverse(ALL(down));
        merge(ALL(up), next(down.begin()), prev(down.end()), ret.begin());
        return ret;
    }
    else
    {
        for(ii x:up)ret.pb(x);
        for(int i = 1;i < SZ(down) - 1;i ++)ret.pb(down[i]);
        return ret;
    }
} 


vector<ii> mg(vector<ii> &a, vector<ii> &b)
{
    if(!SZ(a) || !SZ(b))return (SZ(a)?a:b);
    vector<ii> v;
    v.resize(SZ(a) + SZ(b));
    merge(ALL(a), ALL(b), v.begin());
    return conv(v, 1);
}

ll dist(ii a,ii b)
{
    ii c = a - b;
    return (ll)c.X * (ll)c.X + (ll)c.Y * (ll)c.Y;
}


ll cal(vector<ii> c)
{
    if(SZ(c) < 1)return 0;
    c.pb(c[0]);
    ll l = 0, r = 1, mx = dist(c[0], c[1]);
    while(r != SZ(c) - 1)
    {
        if((c[l+1] - c[l]) * (c[r+1] - c[r]) <= 0)r++;
        else l++;
        ll x = dist(c[l], c[r]);
        if(x > mx)mx = x;
    }
    return mx;
}

struct node{
    ii d;
    node *p, *n;
    node(ii di, node *pi=0, node *ni=0):d(di), p(pi), n(ni){}
} *urt = new node({-1,-1}, 0, 0), *drt = new node({-1, -1}, 0, 0);

map<ii, node*> uc;
map<ii, node*, greater<ii> > dc;

template<typename T>
void ins(T &mp, node *rt, ii x)
{
    if(mp.count(x))return;
    node *nd;
    if(!SZ(mp))nd = new node(x, rt, 0);
    else
    {
        auto it = mp.lower_bound(x);
        if(it == mp.end())
        {
            it--;
            node *p = it->Y;
            nd = new node(x, p, 0);
        }
        else
        {
            node *n = it->Y;
            nd = new node(x, n->p, n);
        }
    }
    if(nd->p->p && nd->n)
    {
        node *p = nd->p, *n = nd->n;
        if((n->d - p->d) * (nd->d - p->d) <= 0)return;
    }
    while(nd->n && nd->n->n)
    {
        auto n = nd->n, nn = n->n;
        if((nn->d - nd->d) * (n->d - nd->d) <= 0)mp.erase(n->d), nd->n = nn;
        else break;
    }
    while(nd->p->p && nd->p->p->p)
    {
        auto p = nd->p, pp = p->p;
        if((nd->d - pp->d) * (p->d - pp->d) <= 0)mp.erase(p->d), nd->p = pp;
        else break;
    }
    nd->p->n = nd;
    if(nd->n)nd->n->p = nd;
    mp[x] = nd;
}

vector<ii> curc()
{
    vector<ii> ret;
    if(SZ(dc) == 1)ret.pb(drt->n->d);
    else if(SZ(dc) > 1)
    {
        vector<ii> up;
        vector<ii> down;
        for(node *it = urt->n;it;it = it->n)up.pb(it->d);
        for(node *it = drt->n->n;it->n;it = it->n)down.pb(it->d);
        reverse(ALL(down));
        ret.resize(SZ(up) + SZ(down));
        merge(ALL(up), ALL(down), ret.begin());
    }
    return ret;
}

ll ans[MAXn];
ii qr[MAXn];
vector<ii> dt[MAXn];
ii d[MAXn];

void dnq(vector<ll> q, ll l,ll r)
{
    if(l == r)
    {
        for(ll x:q)ans[x] = 0;
        return;
    }
    ll h = (l+r)/2;
    vector<ll> t;
    for(ll x:q)if(qr[x].X <= h && qr[x].Y > h)t.pb(x);
    vector<ii> p;
    for(ll x:t)p.pb(ii(qr[x].X, x));
    sort(ALL(p), greater<ii>());
    uc.clear();
    dc.clear();
    urt = new node({-1,-1}, 0, 0);
    drt = new node({-1, -1}, 0, 0);
    ll it = h;
    for(ii x:p)
    {
        while(it >= x.X)ins(uc, urt, d[it]), ins(dc, drt, d[it]), it--;
        dt[x.Y] = curc();
    }

    p.clear();
    for(ll x:t)p.pb(ii(qr[x].Y, x));
    sort(ALL(p));
    uc.clear();
    dc.clear();
    urt = new node({-1,-1}, 0, 0);
    drt = new node({-1, -1}, 0, 0);
    it = h+1;
    for(ii x:p)
    {
        while(it <= x.X)ins(uc, urt, d[it]), ins(dc, drt, d[it]), it++;
        vector<ii> tmp = curc();
        dt[x.Y] = mg(dt[x.Y],tmp);
        ans[x.Y] = cal(conv(dt[x.Y]));
        dt[x.Y].clear();
        dt[x.Y].shrink_to_fit();
    }
    t.clear();
    for(ll x:q)if(qr[x].Y <= h)t.pb(x);
    dnq(t, l, h);
    t.clear();
    for(ll x:q)if(qr[x].X > h)t.pb(x);
    dnq(t, h+1, r);
}


int main()
{
    IOS();
    ll n;
    cin>>n;
    REP1(i,n)cin>>d[i].X>>d[i].Y;
    ll q;
    cin>>q;
    REP1(i,q)cin>>qr[i].X>>qr[i].Y;
    vector<ll> tmp;
    REP1(i,q)tmp.pb(i);
    dnq(tmp, 1, n);
    REP1(i,q)cout<<ans[i]<<'\n';

}
