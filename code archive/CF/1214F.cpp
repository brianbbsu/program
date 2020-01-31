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


const ll MAXn=2e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e18);

struct tg{
    ll x, a, b, tp;
};
ll dif[MAXn];
vector<tg> dt;
vector<ii> v, c;
ll L, n;

ll norm(ll x)
{
    while(x < 0)x += n;
    while(x >= n)x -= n;
    return x;
}

ll cal(ll a,ll b)// ca, vb
{
    return min(abs(c[a].X - v[b].X), L - abs(c[a].X - v[b].X));
}

ll ans[MAXn];

int main()
{
    IOS();
    cin>>L>>n;
    ll hL = (L - 1) / 2 + 1;
    REP1(i, n)
    {
        ll t;
        cin>>t;
        t --;
        v.pb({t, i});
    }
    REP1(i, n)
    {
        ll t;
        cin>>t;
        t --;
        v.pb({t, i});
    }
    sort(ALL(v));
    sort(ALL(c));
    REP(i, n)
    {
        ll x = c[i].X;
        ll nx = lower_bound(ALL(v), ii(x, -1)) - v.begin();
        ll op = lower_bound(ALL(v), ii((x + hL) % L, -1)) - v.begin();
        if(i >= nx && i < op) // more less more
        {
            // i to op - 1
            dt.pb({0, i, i, 1});
            dt.pb({norm(op - i), i, norm(op - 1), -1});
            if(i != norm(op) && i != norm(op - 1))dif[1] ++, dif[norm(op - i)]--;

            // op to nx - 1
            dt.pb({norm(op - i), i, norm(op), 1});
            dt.pb({norm(nx - i), i, norm(nx - 1), -1});
            if(norm(op) != norm(nx) && norm(op) != norm(nx - 1))dif[norm(op - i + 1)] --, dif[norm(nx - i)]++;

            // nx to i - 1
            dt.pb({norm(nx - i), i, norm(nx), 1});
            if(norm(nx) != i && norm(nx) != norm(i - 1))dif[norm(nx - i + 1)] ++;
        }
        else // less more less
        {
            // i to nx - 1
            dt.pb({0, i, i, 1});
            dt.pb({norm(nx - i), i, norm(nx - 1), -1});
            if(i != norm(nx) && i != norm(nx - 1))dif[1] ++, dif[norm(nx - i)]--;

            // nx to op - 1
            dt.pb({norm(nx - i), i, norm(nx), 1});
            dt.pb({norm(op - i), i, norm(op - 1), -1});
            if(norm(nx) != norm(op) && norm(nx) != norm(op - 1))dif[norm(nx - i + 1)] --, dif[norm(op - i)]++;

            // op to i - 1
            dt.pb({norm(op - i), i, norm(op), 1});
            if(norm(op) != i && norm(op) != norm(i - 1))dif[norm(op - i + 1)] ++;
        }
    }
    sort(ALL(dt), [](auto &a, auto &b){return a.x < b.x;});
    ll mn = INF, tdif = 0, tt = 0, it = 0, bst = -1;
    REP(i, n)
    {
        tdif += dif[i];
        while(it < SZ(dt) && dt[it].x <= i)
        {
            tt += dt[it].tp * cal(dt[it].a, dt[it].b);
            it ++;
        }
        if(i > 0)tt += tdif * (v[i].X - v[i - 1].X);
        if(tt < mn)mn = tt, bst = i;
    }
    cout<<mn<<endl;
    REP(i, n)
    {
        ll t = (i + bst) % n;
        ans[v[t].Y] = c[i].Y;
    }
    REP1(i, n)cout<<ans[i]<<" \n"[i == n];

}
