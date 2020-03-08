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


const ll MAXn=3e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

vector<ll> uni;

struct node{
    int l, r;
    node *lc, *rc;
    ll ct, s;
    node(int li, int ri, node *lci = 0, node *rci = 0):l(li), r(ri), lc(lci), rc(rci), ct(0), s(0){}
    node(node *ni):l(ni->l), r(ni->r), lc(ni->lc), rc(ni->rc), ct(ni->ct), s(ni->s){}
    void pull(){
        ct = lc->ct + rc->ct;
        s = lc->s + rc->s;
    }
    void ins(ll x){
        if(l == r - 1)ct ++, s += uni[l];
        else{
            if(x < (l + r) / 2)lc = new node(lc), lc->ins(x);
            else rc = new node(rc), rc->ins(x);
            pull();
        }
    }
};

node *build(ll l, ll r){
    if(l == r - 1)return new node(l, r);
    else return new node(l, r, build(l, (l + r) / 2), build((l + r) / 2, r));
}

node *rt[MAXn];

ll d[MAXn];

int main()
{
    IOS();
    ll n, q;
    cin >> n >> q;
    for(int i = 1;i <= n;i ++)
        cin >> d[i], uni.pb(d[i]);
    sort(ALL(uni));
    uni.resize(unique(ALL(uni)) - uni.begin());
    for(int i = 1;i <= n;i ++)
        d[i] = lower_bound(ALL(uni), d[i]) - uni.begin();
    rt[0] = build(0, SZ(uni) + 1);
    for(int i = 1;i <= n;i ++)
    {
        rt[i] = new node(rt[i - 1]);
        rt[i]->ins(d[i]);
    }
    while(q--)
    {
        ll l, r, k;
        cin >> l >> r >> k;
        node *nl = rt[l - 1], *nr = rt[r];
        ll mx = -1;
        while(nl->l != nl->r - 1){
            if(nr->rc->ct - nl->rc->ct)
                nl = nl->rc, nr = nr->rc;
            else
                nl = nl->lc, nr = nr->lc;
        }
        mx = nl->l;
        nl = rt[l - 1], nr = rt[r];
        ll cct = 0, cs = 0;
        while(nl->l != nl->r - 1){
            ll ct = nr->lc->ct - nl->lc->ct;
            ll s = nr->lc->s - nl->lc->s;
            if((nl->rc->l > mx) || (cct + ct) * uni[nl->rc->l] - (s + cs) > k)
                nl = nl->lc, nr = nr->lc;
            else
                nl = nl->rc, nr = nr->rc, cct += ct, cs += s;
            debug(cct, cs, nl, nr, nl->l, nr->l, nl->r, nr->r);
        }
        ll ct = nr->ct - nl->ct;
        ll s = nr->s - nl->s;
        cct += ct, cs += s;
        ll t = nl->l;
        t = uni[t], mx = uni[mx];
        k -= cct * t - cs;
        assert(k >= 0);
        if(t != mx)
            t += k / cct;
        else if(k % cct)t --;
        cout << mx - t << endl;    
    }
}
