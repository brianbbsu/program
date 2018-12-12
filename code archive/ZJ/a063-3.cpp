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

struct node{
    node *lc, *rc;
    ll sz, pri, id, tg;
    node(ll idi): lc(0), rc(0), sz(1), pri(rand()), id(idi), tg(0){}
};

ll gsz(node *a){return (a?a->sz:0);}

void pull(node *a){a->sz = gsz(a->lc) + gsz(a->rc) + 1;}
void push(node *a){
    if(a->tg)
    {
        swap(a->lc, a->rc);
        a->tg = 0;
        if(a->lc)a->lc->tg ^= 1;
        if(a->rc)a->rc->tg ^= 1;
    }
}

node* mg(node *a, node *b)
{
    if(!a || !b)return (a?a:b);
    if(a->pri > b->pri)
    {
        push(a);
        a->rc = mg(a->rc, b);
        pull(a);
        return a;
    }
    push(b);
    b->lc = mg(a, b->lc);
    pull(b);
    return b;
}

void splt(node *a, node *&b, node *&c, ll k) // sz = k, else
{
    if(!a)b = c = 0;
    else
    {
        push(a);
        if(gsz(a->lc) < k)
        {
            b = a;
            splt(a -> rc, b -> rc, c, k - 1 - gsz(a -> lc));
            pull(b);
        }
        else
        {
            c = a;
            splt(a -> lc, b , c -> lc, k);
            pull(c);
        }
    }
}

void dfs(node *a)
{
    if(!a)return;
    push(a);
    dfs(a->lc);
    cout<<a->id<<" ";
    dfs(a->rc);
}

node * rt = 0;

int main()
{
    IOS();
    ll n,q;
    cin>>n>>q;
    REP1(i, n)rt = mg(rt, new node(i));
    while(q--)
    {
        ll l, r;
        cin>>l>>r;
        node *a, *b, *c;
        splt(rt, a, b, l - 1);
        splt(b, b, c, r - l + 1);
        debug(gsz(a), gsz(b), gsz(c));
        b->tg ^= 1;
        b = mg(b,c);
        rt = mg(a, b);
    }
    dfs(rt);
}
