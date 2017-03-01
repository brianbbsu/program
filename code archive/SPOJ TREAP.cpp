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
template<typename _a,typename _b>
ostream& operator <<(ostream &_s,const pair<_a,_b> &_p){return _s<<"("<<_p.X<<","<<_p.Y<<")";}
#else
#define debug(...)
#define endl '\n'
#endif // brian

const ll INF=ll(1e15);
const ll MAXn=1e5+5,MAXlg=20;
const ll MOD = 1000000007;

struct node
{
    ll d,mxd,mnd,mx,mn,sz,pri;
    node *l,*r;
    node(ll di)
    {
        d=mx=mn=di;
        mxd=-1;
        mnd=INF;
        sz=1;
        pri=rand();
        l=r=0;
    }
};
ll sz(node *a){return (a?a->sz:0);}
void pull(node *a)
{
    a->sz=sz(a->l)+sz(a->r)+1;
    if(!(a->l||a->r))
    {
        a->mxd=-1;
        a->mnd=INF;
        a->mx=a->mn=a->d;
    }
    else if(!(a->r))
    {
        a->mn=a->l->mn;
        a->mx=a->d;
        a->mxd=a->mx-a->mn;
        a->mnd=min(a->l->mnd,a->d-a->l->mx);
    }
    else if(!(a->l))
    {
        a->mn=a->d;
        a->mx=a->r->mx;
        a->mxd=a->mx-a->mn;
        a->mnd=min(a->r->mnd,a->r->mn-a->d);
    }
    else
    {
        a->mn=a->l->mn;
        a->mx=a->r->mx;
        a->mxd=a->mx-a->mn;
        a->mnd=min({a->l->mnd,a->r->mnd,a->d-a->l->mx,a->r->mn-a->d});
    }
}
node *Merge(node *a,node *b)
{
    if(!a)return b;
    if(!b)return a;
    if(a->pri>b->pri)
    {
        a->r=Merge(a->r,b);
        pull(a);
        return a;
    }
    b->l=Merge(a,b->l);
    pull(b);
    return b;
}
void Split_w_key(ll k,node *a,node *&b,node *&c)//>=k
{
    if(!a)b=c=0;
    else if(a->d>=k)
    {
        c=a;
        Split_w_key(k,a->l,b,c->l);
        pull(c);
    }
    else
    {
        b=a;
        Split_w_key(k,a->r,b->r,c);
        pull(b);
    }
}
void Split_w_index(ll k,node *a,node *&b,node *&c)//>=k
{
    if(!a)b=c=0;
    else if(sz(a->l)>=k)//>=k
    {
        c=a;
        Split_w_index(k,a->l,b,c->l);
        pull(c);
    }
    else //<k
    {
        b=a;
        Split_w_index(k-sz(a->l)-1,a->r,b->r,c);
        pull(b);
    }
}
set<ll> st;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    srand(time(NULL));
    ll n;
    cin>>n;
    node *rt=0;
    REP(i,n)
    {
        char ch;
        cin>>ch;
        if(ch=='I')
        {
            ll k;
            cin>>k;
            if(!st.count(k))
            {
                node *a,*b;
                Split_w_key(k,rt,a,b);
                a=Merge(a,new node(k));
                rt=Merge(a,b);
                st.insert(k);
            }
        }
        else if(ch=='D')
        {
            ll k;
            cin>>k;
            if(st.count(k))
            {
                node *a,*b,*c,*tmp;
                Split_w_key(k,rt,a,tmp);
                Split_w_key(k+1,tmp,b,c);
                rt=Merge(a,c);
                st.erase(k);
            }
        }
        else if(ch=='N')
        {
            ll l,r;
            cin>>l>>r;
            node *a,*b,*c,*tmp;
            Split_w_index(l,rt,a,tmp);
            Split_w_index(r-l+1,tmp,b,c);
            cout<<(b->mnd==INF?-1:b->mnd)<<endl;
            tmp=Merge(b,c);
            rt=Merge(a,tmp);
        }
        else
        {
            ll l,r;
            cin>>l>>r;
            node *a,*b,*c,*tmp;
            Split_w_index(l,rt,a,tmp);
            Split_w_index(r-l+1,tmp,b,c);
            cout<<b->mxd<<endl;
            tmp=Merge(b,c);
            rt=Merge(a,tmp);
        }
    }
}
