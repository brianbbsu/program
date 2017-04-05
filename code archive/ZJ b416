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
const ll INF=ll(1e13);

struct node
{
    ll l,r;
    node *lc,*rc;
    ll d;
    node(ll li=0,ll ri=0,node *lci=0,node *rci=0):l(li),r(ri),lc(lci),rc(rci),d(0){}
    void ins(ll k)
    {
        if(l==r-1)d++;
        else
        {
            if(k>=(l+r)/2)
            {
                rc=new node(rc->l,r,rc->lc,rc->rc);
                rc->ins(k);
            }
            else
            {
                lc=new node(l,lc->r,lc->lc,lc->rc);
                lc->ins(k);
            }
            d=lc->d+rc->d;
        }
    }
    ll qr(ll li,ll ri)
    {
        if(li>=r||ri<=l)return 0;
        else if(li<=l&&ri>=r)return d;
        else return lc->qr(li,ri)+rc->qr(li,ri);
    }
};

ll n,m;
ii d[MAXn];
node *rt[MAXn];

node *build(ll l,ll r)
{
    if(l==r-1)return new node(l,r);
    else return new node(l,r,build(l,(l+r)/2),build((l+r)/2,r));
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    REP(i,n)cin>>d[i].X,d[i].Y=i;
    rt[0]=build(0,n);
    sort(d,d+n);
    pary(d,d+n);
    REP(i,n)
    {
        rt[i+1]=new node(0,n,rt[i]->lc,rt[i]->rc);
        rt[i+1]->ins(d[i].Y);
    }
    REP(i,n)debug(i,rt[i]->d);
    REP(i,m)
    {
        ll a,b,l,r;
        cin>>l>>r>>a>>b;
        a=lower_bound(d,d+n,ii(a,-1))-d;
        b=upper_bound(d,d+n,ii(b,INF))-d;
        debug(a,b);
        cout<<rt[b]->qr(l-1,r)-rt[a]->qr(l-1,r)<<endl;
    }


}

