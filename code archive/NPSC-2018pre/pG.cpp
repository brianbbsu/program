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
    ll l,r;
    node *lc,*rc;
    ll tt;
    node(ll li,ll ri):l(li),r(ri),lc(0),rc(0),tt(0){}
    void pull()
    {
        tt = 0;
        if(lc)tt += lc->tt;
        if(rc)tt += rc->tt;
    }
    void ins(ll x,ll k)
    {
        if(l == r-1)tt += k;
        else
        {
            if(x < (l+r)/2)
            {
                if(!lc)lc = new node(l,(l+r)/2);
                lc -> ins(x,k);
            }
            else
            {
                if(!rc)rc = new node((l+r)/2,r);
                rc->ins(x,k);
            }
            pull();
        }
    }
    ll qr(ll li,ll ri)
    {
        if(li >= r || ri <= l)return 0;
        else if(li <= l && ri >= r)return tt;
        else
        {
            ll ret = 0;
            if(lc)ret += lc->qr(li,ri);
            if(rc)ret += rc->qr(li,ri);
            return ret;
        }
    }
};

map<ll,node*> mpr,mpc; 

ll C = 1000000000000000000LL,lst = 0;

ll get()
{
    ll x;
    cin>>x;
    return (x + lst + 2 * C + 1) % (2 * C + 1) - C;
}

int main()
{
    IOS();
    ll n;
    cin>>n;
    while(n--)
    {
        ll tp;
        cin>>tp;
        if(tp == 1)
        {
            debug(lst);
            ll x1 = get();
            ll y1 = get();
            ll x2 = get();
            ll y2 = get();
            ll w;
            cin>>w;
            debug(x1,y1,x2,y2,w);
            if(x1 == x2)
            {
                node * rt = 0;
                if(!mpr.count(x1))rt = mpr[x1] = new node(-C-5,C+5);
                else rt = mpr[x1];
                rt->ins(y1,w);
                rt->ins(y2+1,-w);
            }
            else
            {
                node * rt = 0;
                if(!mpc.count(y1))rt = mpc[y1] = new node(-C-5,C+5);
                else rt = mpc[y1];
                rt->ins(x1,w);
                rt->ins(x2+1,-w);
            }
        }
        else
        {
            ll x = get();
            ll y = get();
            debug(x,y);
            ll tt = 0;
            if(mpr.count(x))tt += mpr[x]->qr(-C-5,y+1);
            if(mpc.count(y))tt += mpc[y]->qr(-C-5,x+1);
            cout<<tt<<endl;
            lst = tt;
        }
    }
}
