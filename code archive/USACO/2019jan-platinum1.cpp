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

string _taskname;
void _init()
{
  #ifndef brian
      freopen((_taskname+".in").c_str(), "r", stdin);
      freopen((_taskname+".out").c_str(),"w",stdout);
  #endif
}
void _end()
{
  #ifndef brian
      fclose( stdin);
      fclose(stdout);
  #endif
}

const ll MAXn=3e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e9);

namespace seg{
    ll N, d[4 * MAXn];
    void build(ll n)
    {
        N = n;
        for(int i = 1;i < 2 * N;i++)d[i] = INF;
    }
    void ins(ll x,ll k)
    {
        for(d[x += N] = k;x > 1;x>>=1)d[x>>1] = min(d[x], d[x^1]);
    }
    ll qr(ll l,ll r)
    {
        ll ret = INF;
        for(l += N, r += N;l < r;l >>= 1, r >>= 1)
        {
            if(l&1)ret = min(ret, d[l++]);
            if(r&1)ret = min(ret, d[--r]);
        }
        return ret;
    }
};


ll d[MAXn];
map<ll, deque<ii>> dq;
ll n, k;

void ins(deque<ii> &q, ii p)
{
    while(SZ(q) && q.back().Y >= p.Y)q.pop_back();
    q.pb(p);
}

int main()
{
    //IOS();
    _taskname = "redistricting";
    _init();
    
    cin>>n>>k;
    string s;
    cin>>s;
    REP1(i,n)d[i] = (s[i-1] == 'H'?1:-1);
    REP1(i,n)d[i] = d[i-1] + d[i];
    seg::build(2 * n + 1);
    ins(dq[0+n], ii(0, 0));
    seg::ins(0+n, 0);
    ll lst = 0;
    REP1(i, n)
    {
        ll t = i - k - 1;
        if(t >= 0 && dq[d[t]+n].front().X == t)
        {
            dq[d[t]+n].pop_front();
            if(SZ(dq[d[t]+n]))seg::ins(d[t]+n, dq[d[t]+n].front().Y);
            else seg::ins(d[t]+n, INF);
        }
        ll tmp;
        tmp = min(seg::qr(0, d[i] + n), seg::qr(d[i] + n, 2 * n + 1) + 1);
        ins(dq[d[i] + n], ii(i, tmp));
        seg::ins(d[i] + n, dq[d[i] + n].front().Y);
        lst = tmp;
    }
    cout<<lst<<endl;
    _end();
}
