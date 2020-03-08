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

struct tg{ // first add then flip
    ll fg, a0, a1;
};

struct val{
    ll c0, c1, s;
};

void add(tg &a, tg b){
    if(a.fg)swap(b.a0, b.a1);
    a.a0 += b.a0;
    a.a1 += b.a1;
    a.fg ^= b.fg;
}

val mg(val a, val b){
    return {a.c0 + b.c0, a.c1 + b.c1, a.s + b.s};
}

val apply(val v, tg d){
    v.s += v.c0 * d.a0 + v.c1 * d.a1;
    if(d.fg)swap(v.c0, v.c1);
    return v;
}

struct node{
    int l, r;
    node *lc, *rc;
    tg d;  
    val v;
    node(ll li,ll ri, node *lci = 0, node *rci = 0):l(li), r(ri), lc(lci), rc(rci), d({0, 0, 0}), v({r - l, 0, 0}){}
    void pull(){
        if(l == r - 1)v = {1, 0, 0};
        else v = mg(lc->v, rc->v);
        v = apply(v, d);
    }
    void push(){
        if(d.fg || d.a0 || d.a1){
            add(lc->d, d);
            add(rc->d, d);
            lc->pull();
            rc->pull();
            d = {0, 0, 0};
            pull();
        }
    }
    void flip(int li, int ri){
        if(li >= r || ri <= l)return;
        else if(li <= l && ri >= r)
           d.fg ^= 1;
        else{
            push();
            lc->flip(li, ri);
            rc->flip(li, ri);
        }
        pull();
    }
    void ins(int li, int ri, ll ki){
        if(li >= r || ri <= l)return;
        else if(li <= l && ri >= r)
            if(d.fg)d.a0 += ki;
            else d.a1 += ki;
        else{
            push();
            lc->ins(li, ri, ki);
            rc->ins(li, ri, ki);
        }
        pull();
    }
    val qr(int li, int ri){
        if(li >= r || ri <= l)return {0, 0, 0};
        else if(li <= l && ri >= r)return v;
        else{
            push();
            return apply(mg(lc->qr(li, ri), rc->qr(li, ri)), d);
        }
    }
    void dfs(){
        debug(l, r, d.a0, d.a1, d.fg, v.c0, v.c1, v.s);
        if(l != r - 1)lc->dfs(), rc->dfs();
    }
};

node* build(int l, int r){
    if(l == r - 1)return new node(l, r);
    else return new node(l, r, build(l, (l + r) / 2), build((l + r) / 2, r));
}

int n, m;
node *rt;

int main()
{
    IOS();
    ll n, m;
    cin >> n >> m;
    rt = build(1, n + 1);
    rt->flip(1, n + 1);
    for(int i = 1;i <= n;i ++){
        ll t;
        cin >> t;
        rt->ins(i, i + 1, t);
    }
    for(int i = 1;i <= n;i ++){
        ll t;
        cin >> t;
        if(t == 0)
            rt->flip(i, i + 1);
    }
    for(int i = 1;i <= m;i ++){
        //rt->dfs();
        ll tp, l, r;
        cin >> tp >> l >> r;
        if(tp == 1)rt->flip(l, r + 1);
        else if(tp == 2){
            ll t;
            cin >> t;
            rt->ins(l, r + 1, t);
        }
        else cout << rt->qr(l, r + 1).s << endl;
    }
}
