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

namespace bit{
    const ll N = (1<<20);
    ll bit[N], s[N];
    void ins(ll x,ll k)
    {
        ll t = x;
        x++;
        while(x < N)bit[x] += k, s[x] += t * k, x += x & -x;
    }
    ii qr(ll x)
    {
        ll ret = 0, rets = 0;
        x++;
        while(x)ret += bit[x], rets += s[x], x -= x & -x;
        return ii(ret, rets);
    }
    ll f(ll x)
    {
        ll l = 0, len = (N>>1);
        while(len)
        {
            if(bit[l + len] < x)x -= bit[l + len], l += len;
            len >>= 1;
        }
        return l;
    }
};

ll d[MAXn];

int main()
{
    IOS();
    ll n, k;
    cin>>n>>k;
    REP1(i,n)cin>>d[i];
    ll mn = INF, mni = -1, mnt = -1;
    REP1(i,n)
    {
        bit::ins(d[i], 1);
        if(i > k)bit::ins(d[i - k], -1);
        if(i >= k)
        {
            ll t = bit::f((k+1)/2);
            ii a = bit::qr(t), b = bit::qr(bit::N-5);
            ll tt = a.X * t - a.Y + (b.Y - a.Y) - (b.X - a.X) * t;
            debug(i, tt);
            if(tt < mn)
            {
                mn = tt;
                mni = i - k + 1;
                mnt = t;
            }
        }
    }
    cout<<mn<<endl;
    REP(i, k)d[mni + i] = mnt;
    REP1(i,n)cout<<d[i]<<endl;
}
