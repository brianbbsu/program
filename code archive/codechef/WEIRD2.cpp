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


const ll MAXn=1e6+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll ct[MAXn],pt[MAXn],d[MAXn];
vector<ll> dt,dt2;
vector<ll> chang;

ll bit[MAXn];
void ins(ll x)
{
    while(x < MAXn)
    {
        if(!bit[x])chang.pb(x);
        bit[x]++;
        x += x & -x;
    }
}
ll qr(ll x)
{
    ll rt = 0;
    while(x)
    {
        rt += bit[x];
        x -= x & -x;
    }
    return rt;
}

int main()
{
    IOS();
    ll T;
    cin>>T;
    while(T--)
    {
        ll n;
        cin>>n;
        REP(i,n)cin>>d[i];
        REP(i,n)ct[d[i]]++;
        dt.clear();
        dt2.clear();
        chang.clear();
        REP(i,n)if(!pt[d[i]])dt.pb(d[i]),dt2.pb(d[i]),pt[d[i]] = 1;
        sort(ALL(dt),[](int a,int b){return ct[a] > ct[b];});
        sort(ALL(dt2),greater<ll>());
        ll it = 0,tt=0;
        for(ll x:dt2)
        {
            while(it < SZ(dt) && ct[dt[it]] >= x)
            {
                ins(dt[it]);
                it++;
            }
            tt += qr(ct[x]);
        }
        /*ll tt = 0;
        for(ll tmp:dt)
        {
            tt += qr(ct[tmp]);
            ins(tmp);
        }
        tt *= 2;
        for(ll tmp:dt)if(ct[tmp] >= tmp)tt ++;*/
        for(ll tmp:dt)pt[tmp] = ct[tmp] = 0;
        for(ll tmp:chang)bit[tmp] = 0;
        cout<<tt<<endl;
    }
}
