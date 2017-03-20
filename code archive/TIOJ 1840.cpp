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

const ll MAXn=5e4+5,MAXlg=__lg(10*MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);


struct chtag{
    ll t,p,x,type;
    chtag(ll ti,ll pi,ll xi,ll tpi):t(ti),p(pi),x(xi),type(tpi){}
};
struct qrtag{
    ll t,l,r,k;
    qrtag(ll ti,ll li,ll ri,ll ki):t(ti),l(li),r(ri),k(ki){}
};


ll aryd[2][MAXn];
vector<chtag> ch[MAXlg];
vector<qrtag> qr[MAXlg],tmpqr;
stack<chtag> st;
ll n,q;
ll it=-1;
ll ans[MAXn];
vector<ll> uni;

//bit
ll bit[MAXn*10];
void ins(ll x,ll k){
    while(x<=SZ(uni))bit[x]+=k,x+=x&-x;
}
ll precnt(ll x){
    ll r=0;while(x>0)r+=bit[x],x-=x&-x;return r;
}

void DC(ll now,ll l,ll r)
{
    if(l==r-1)
    {
        for(auto &k:qr[now])ans[k.t]=uni[r-1];
        return;
    }
    tmpqr.clear();
    ll chit=0;
    for(ll &k:qr[now])
    {
        while(chit<SZ(ch[now])&&ch[now][chit].t<k.t){

        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    debug(MAXlg);
    ll T;
    cin>>T;
    while(T--&&cin>>n>>q)
    {
        it=-1;
        REP(i,MAXlg)ch[i].clear(),qr[i].clear();
        uni.clear();
        FILL(bit,0);

        REP(i,n)cin>>aryd[0][i],uni.pb(aryd[0][i]);
        copy_n(aryd[0],n,aryd[1]);

        //input
        REP(i,q)
        {
            ll t;
            cin>>t;
            if(t==1)
            {
                ll l,r,k;
                cin>>l>>r>>k;
                l--;r--;
                it++;
                qr[0].pb(qrtag(it,l,r,k));
            }
            else if(t==2)
            {
                ll x,k;
                cin>>x>>k;
                x--;
                ch[0].pb(chtag(it,x,k,1));
                ch[0].pb(chtag(it,x,aryd[0][x],-1));
                aryd[0][x]=k;
                uni.pb(k);
            }
            else
            {
                it++;
                ans[it]=7122;
            }
        }
        sort(ALL(uni));
        uni.resize(unique(ALL(uni))-uni.begin());
        REP(i,n)
        {
            ll x=lower_bound(ALL(uni),aryd[1][i])-uni.begin()+1;
            ins(x,1);
        }
        for(auto &k:ch[0])k.x=lower_bound(ALL(uni),k.x)-uni.begin()+1;
        it(0,-1,SZ(uni)-1);
        REP(i,it+1)cout<<ans[i]<<endl;
    }

}
