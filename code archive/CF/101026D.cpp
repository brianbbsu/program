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

struct node{
    ll l, r;
    node *lc, *rc;
    ll tt;
    node(ll li,ll ri, node *lci = 0, node *rci = 0):l(li), r(ri), lc(lci), rc(rci), tt(0){}
    node(node *ni):l(ni->l), r(ni->r), lc(ni->lc), rc(ni->rc), tt(ni->tt){}
    void pull()
    {
        if(l == r-1)return;
        else tt = lc->tt + rc->tt;
    }
    void ins(ll x,ll k)
    {
        if(l == r-1)tt += k;
        else
        {
            if(x < (l + r) / 2)
            {
                lc = new node(lc);
                lc->ins(x, k);
            }
            else
            {
                rc = new node(rc);
                rc->ins(x, k);
            }
            pull();
        }
    }
    ll qr(ll li,ll ri)
    {
        if(li >= r || ri <= l)return 0;
        else if(li <= l && ri >= r)return tt;
        else return lc->qr(li, ri) + rc->qr(li, ri);
    }
};

node *build(ll l,ll r)
{
    if(l == r-1)return new node(l, r);
    else return new node(l, r, build(l, (l + r) / 2), build((l + r) / 2, r));
}

node *rt[MAXn];
vector<ii> dt;

int main()
{
    IOS();
    ll n, m;
    cin>>n>>m;
    rt[0] = build(1, n + 1);
    REP1(i, n)
    {
        ll x;
        cin>>x;
        dt.pb({x, i});
    }
    sort(ALL(dt));
    REP(i, n)
    {
        rt[i + 1] = new node(rt[i]);
        rt[i + 1]->ins(dt[i].Y, dt[i].X);
    }
    while(m--)
    {
        ll l, r;
        cin>>l>>r;
        ll now = 0;
        while(1)
        {
            ll tmp = rt[lower_bound(ALL(dt), ii(now + 1, INF)) - dt.begin()]->qr(l, r + 1);
            if(tmp == now)break;
            else now = tmp;
        }
        cout<<now + 1<<endl;
    }
}
