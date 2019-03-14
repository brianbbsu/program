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
template<typename _a, typename _cmp> ostream &operator << (ostream &_s,set<_a, _cmp> &_c){return _OUTC(_s,ALL(_c));}
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


const ll MAXn=1e4+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e17);


struct seg{
    ll a, b, l, r;
};


#ifdef brian
ostream& operator << (ostream &_s, const seg s){return _s<<"{"<<s.a<<"x + "<<s.b<<", ["<<s.l<<","<<s.r<<"]}";}
#endif

inline ll cal(seg s, ll x)
{
    return s.a * x + s.b;
}

#define INS 0
#define FIN 1

bool fg;
struct cmp{
    bool operator () (const seg a, const seg b) const {
        if(fg == INS)return a.a > b.a;
        else return a.r < b.l;
    }
};
set<seg, cmp> st;

void ins(seg s)
{
    fg = INS;
    auto it = st.lower_bound(s);
    if(it != st.end() && cal(*it, it->l) <= cal(s, it->l))return;
    while(it != st.end())
    {
        if(it->a == s.a && it->b <= s.b)return;
        else if(it->a == s.a)it = st.erase(it);
        else if(cal(*it, it->r) >= cal(s, it->r))it = st.erase(it);
        else{
            s.r = (s.b - it->b) / (it->a - s.a);
            seg tmp = *it;
            tmp.l = s.r + 1;
            st.erase(it);
            it = st.insert(tmp).X;
            break;
        }
    }
    while(it != st.begin()){
        auto pit = prev(it);
        if(cal(*pit, pit->l) >= cal(s, pit->l))st.erase(pit);
        else{
            s.l = (s.b - pit->b) / (pit->a - s.a)+1;
            seg tmp = *pit;
            tmp.r = s.l - 1;
            st.erase(pit);
            st.insert(tmp);
            break;
        }
    }
    st.insert(s);
}

ll qr(ll x)
{
    debug(SZ(st), st);
    fg = FIN;
    auto it = st.lower_bound(seg({0,0,x,x}));
    assert(it != st.end());
    return cal(*it, x);
}

ll d[MAXn];

ll dp[105][MAXn];

int main()
{
    IOS();
    ll n, k;
    cin>>n>>k;
    REP1(i, n)cin>>d[i];
    dp[0][0] = 0;

    REP1(t, k)
    {
        st.clear();
        for(int i = t;i <= n;i ++)
        {
            if(!(t == 1 && i > 1))ins(seg({-2 * d[i], d[i] * d[i] + dp[t-1][i-1], 0, 100000000}));
            dp[t][i] = qr(d[i]) + d[i] * d[i];
        }
    }
    REP1(i,k)for(int j = i;j <= n;j ++)debug(i, j, dp[i][j]);
    cout<<dp[k][n]<<endl;
}
