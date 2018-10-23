//{
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(ll i=0;i<n;i++)
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
#else
#define debug(...)
#define pary(...)
#define endl '\n'
#endif // brian
//}

const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);


struct node
{
    ll d,dp,sz;
    node *l,*r;
    node(ll di=0,node *li=0,node *ri=0):d(di),dp(1),l(li),r(ri),sz(1){}
};
inline int deep(node *a){return (a?a->dp:0);}
node *mg(node *a,node *b)
{
    if(!a||!b)return (a?a:b);
    if(a->d<b->d)swap(a,b);
    a->sz+=b->sz;
    a->r=mg(a->r,b);
    if(deep(a->l)<deep(a->r))swap(a->l,a->r);
    a->dp=deep(a->r)+1;
    return a;
}


node *h[MAXn];
ll tt[MAXn];
vector<ll> v[MAXn];
ll d[MAXn];
ll ld[MAXn];
ll n,m;
ll ans=0;

void dfs(ll now)
{
    h[now]=new node(d[now]);
    tt[now]+=d[now];
    for(ll k:v[now])
    {
        dfs(k);
        tt[now]+=tt[k];
        h[now]=mg(h[k],h[now]);
    }
    while(tt[now]>m)
    {
        tt[now]-=h[now]->d;
        node *a=h[now]->l,*b=h[now]->r;
        h[now]=mg(a,b);
    }
    ans=max(ans,ld[now]*(h[now]?h[now]->sz:0));
}
int main()
{
    cin>>n>>m;
    REP(i,n)
    {
        ll a;
        cin>>a>>d[i]>>ld[i];
        a--;
        if(a>=0)v[a].pb(i);
    }
    dfs(0);
    cout<<ans<<endl;
}
