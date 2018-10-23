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


const ll MAXn=3e3+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e13);

void maxfy(ll &a,const ll b){a=max(a,b);}

ll n,k;
ll d[MAXn];
ll dp[MAXn],dpl[MAXn];
ll mx;
ll a[MAXn],b[MAXn];
deque<ll> qs[MAXlg],tmpq;
vector<ii> qr;
ll cal(ll id,ll x){return a[id]*x+b[id];}
void it(ll l,ll r,ll lv)
{
    // init
    deque<ll> &q=qs[lv];
    q.clear();

    if(l==r-1)// edge case
    {

        a[l]=-2*d[l];
        b[l]=mx+d[l]*d[l];
        q.pb(l);
        maxfy(mx,dpl[l]);
        debug(l,mx);
        debug(SZ(qs[lv]));
        return;
    }

    ll h=(l+r)/2;
    it(l,h,lv+1);
    q.swap(qs[lv+1]);

    qr.resize(0);
    for(int i=h;i<r;i++)qr.pb(ii(d[i],i));
    sort(ALL(qr));
    ll t=0;
    pary(ALL(q));
    REP(i,SZ(qr))
    {
        while(t<SZ(q)-1&&cal(q[t+1],qr[i].X)>=cal(q[t],qr[i].X))t++;
        debug(qr[i].Y,q[t]);
        maxfy(dp[qr[i].Y],cal(q[t],qr[i].X)+d[qr[i].Y]*d[qr[i].Y]);
    }

    it(h,r,lv+1);
    q.swap(tmpq);
    q.clear();
    ll ita=0,itb=0;
    deque<ll> &qa=tmpq,&qb=qs[lv+1];
    while(ita<SZ(qa)||itb<SZ(qb))
    {
        ll id;
        if(ita==SZ(qa))id=qb[itb++];
        else if(itb==SZ(qb))id=qa[ita++];
        else if(a[qa[ita]]<=a[qb[itb]])id=qa[ita++];
        else id=qb[itb++];
        if(SZ(q)&&a[q.back()]==a[id])
        {
            if(b[id]>=b[q.back()])q.pop_back();
            else continue;
        }
        while(SZ(q)>1&& (b[q[q.size()-2]]-b[id]) * (a[q.back()]-a[q[q.size()-2]]) <=
                        (b[q[q.size()-2]]-b[q.back()]) * (a[id]-a[q[q.size()-2]]))q.pop_back();
        debug(1);
        q.pb(id);
    }
    debug(SZ(qs[lv]));

}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k;
    REP(i,n)cin>>d[i];
    FILL(dp,0);
    REP(i,k)
    {
        swap(dp,dpl);
        REP(j,n)dp[j]=-INF;
        if(i==0)mx=0;
        else mx=-INF;

        it(0,n,0);
        debug(i);
        pary(dp,dp+n);
        pary(a,a+n);
        pary(b,b+n);
    }
    ll ans=0;
    REP(i,n)maxfy(ans,dp[i]);
    cout<<ans<<endl;
}
