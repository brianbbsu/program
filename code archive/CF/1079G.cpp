//{
#include<bits/stdc++.h>
using namespace std;
typedef int ll;
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
const ll INF=ll(1e9);

struct node{
    ll l,r;
    node *lc,*rc;
    ll dtl,dtr;
    void pull(){
        dtl = min(lc->dtl,rc->dtl);
        dtr = max(lc->dtr,rc->dtr);
    }
    void insl(ll x,ll k)
    {
        if(l == r-1)dtl = min(dtl,k);
        else
        {
            if(x < (l+r)/2)lc->insl(x,k);
            else rc->insl(x,k);
            pull();
        }
    }
    void insr(ll x,ll k)
    {
        if(l == r-1)dtr = max(dtr,k);
        else
        {
            if(x < (l+r)/2)lc->insr(x,k);
            else rc->insr(x,k);
            pull();
        }
    }
    ll qrl(ll li,ll ri)
    {
        if(li >= r || ri <= l)return INF;
        else if(li <= l && ri >= r)return dtl;
        else return min(lc->qrl(li,ri),rc->qrl(li,ri));
    }
    ll qrr(ll li,ll ri)
    {
        if(li >= r || ri <= l)return -1;
        else if(li <= l && ri >= r)return dtr;
        else return max(lc->qrr(li,ri),rc->qrr(li,ri));
    }
    void clr()
    {
        dtl = INF,dtr = -1;
        if(l == r-1)return;
        if(lc->dtl != INF || lc->dtr != -1)lc->clr();
        if(rc->dtl != INF || rc->dtr != -1)rc->clr();
    }
};

node *build(ll l,ll r)
{
    if(l == r-1)return new node{l,r,0,0,INF,-1};
    else return new node{l,r,build(l,(l+r)/2),build((l+r)/2,r),INF,-1};
}

ll d[MAXn];
ll l[MAXn][MAXlg],r[MAXn][MAXlg],nl[MAXn],nr[MAXn],ct[MAXn];
node *rt;

int main()
{
    IOS();
    ll n,nn;
    cin>>n;
    nn = 2 * n;
    if(n == 1)
    {
        cout<<0<<endl;
        return 0;
    }
    rt = build(0,nn);
    REP(i,n)cin>>d[i];
    REP(i,n)d[n + i] = d[i];
    REP(i,nn)l[i][0] = max(0,i - d[i]),r[i][0] = min(nn-1,i + d[i]);
    for(int i = 0; i < nn;i ++)nl[i] = nr[i] = i,ct[i] = 0;
    REP1(i,MAXlg-1)
    {
        //rt->clr();
        REP(j,nn)
        {
            rt->insl(j,l[j][i-1]),rt->insr(j,r[j][i-1]);
        }
        REP(j,nn)
        {
            l[j][i] = rt->qrl(l[j][i-1],r[j][i-1]+1);
            r[j][i] = rt->qrr(l[j][i-1],r[j][i-1]+1);
        }
    }
    for(int i = MAXlg-1;i > 0;i--)
    {
        rt->clr();
        REP(j,nn)
        {
            rt->insl(j,l[j][i-1]),rt->insr(j,r[j][i-1]);
        }
        for(int j = 0; j < nn;j ++)
        {
            ll tmpl = rt->qrl(nl[j],nr[j]+1);
            ll tmpr = rt->qrr(nl[j],nr[j]+1);
            if(tmpr - tmpl + 1 < n)
            {
                nl[j] = tmpl, nr[j] = tmpr;
                ct[j] += (1<<(i-1));
            }
        }
    }
    for(int j = 0; j < n;j ++)cout<<min(ct[j],ct[j+n])+1<<" ";
    
}
