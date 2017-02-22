#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define FILL(i,n) memset(i,n,sizeof(i));
#define SZ(A) ((int)A.size())
#define ALL(A) A.begin(),A.end()
#define X first
#define Y second
#define pb push_back
#ifdef brian
#define  debug(...) do{\
    fprintf(stderr,"%s - %d : (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0)
template<typename t> void _do(t &&_x){cerr<<_x<<endl;}
template<typename t,typename ...T> void _do(t &&_x,T &&...tail){cerr<<_x<<", ";_do(tail...);}
#else
#define debug(...)
#define endl '\n'
#endif // brian

const ll INF=ll(1e15);
const ll MAXn=1e6+5,MAXlg=20;
const ll MOD = 1000000007;

struct node
{
    ll d,p,sz;
    node *l,*r;
    bool tg;
    node(ll di):d(di),p(rand()),sz(1),l(0),r(0),tg(0){}
};
void tg(node *a){if(a)a->tg=!a->tg;}
ll sz(node *a){return (a?a->sz:0);}
void pull(node *a){if(a)a->sz=sz(a->l)+sz(a->r)+1;}
vector<ll> dt;
void dfs(node *a)
{
    if(a->tg)rot(a);
    if(a->l)dfs(a->l);
    dt.pb(a->d);
    if(a->r)dfs(a->r);
}
void rot(node *a)
{
    tg(a);
    tg(a->l);
    tg(a->r);
    swap(a->l,a->r);
}
node *Merge(node *a,node *b)
{
    if(!a)return b;
    if(!b)return a;
    if(a->p>b->p)
    {
        if(a->tg)rot(a);
        a->r=Merge(a->r,b);
        pull(a);
        return a;
    }
    if(b->tg)rot(b);
    b->l=Merge(a,b->l);
    pull(b);
    return b;
}
void Split(node *a,node *&b,node *&c,ll k)
{
    if(!a)b=c=0;
    else
    {
        if(a->tg)rot(a);
        if(sz(a->l)>=k)
        {
            c=a;
            Split(a->l,b,c->l,k);
            pull(c);
        }
        else
        {
            b=a;
            Split(a->r,b->r,c,k-sz(a->l)-1);
            pull(b);
        }
    }
}
ll n,m;
node *rt=NULL;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    srand(time(NULL));
    cin>>n>>m;
    REP(i,n)
    {
        rt=Merge(rt,new node(i+1));
    }
    REP(i,m)
    {
        ll l,r;
        cin>>l>>r;
        l--;r--;
        node *a=0,*b=0,*c=0,*tmp=0;
        Split(rt,a,tmp,l);
        Split(tmp,b,c,r-l+1);
        tg(b);
        tmp=Merge(a,b);
        rt=Merge(tmp,c);
    }
    dfs(rt);
    REP(i,n)cout<<(i?" ":"")<<dt[i];
    cout<<endl;
}
