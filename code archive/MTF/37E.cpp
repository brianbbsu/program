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
const ll MOD=998244353;
const ll INF=ll(1e15);


ll pw(ll x,ll k)
{
    if(!k)return 1;
    ll a = pw(x, k>>1);
    a = a * a % MOD;
    if(k & 1)return a * x % MOD;
    else return a;
}

ll fac[2 * MAXn], inv[2 * MAXn];

ll h(ll a, ll b)
{
    if(a <= 0)return 0;
    a = a + b - 1;
    return fac[a] * inv[b] % MOD * inv[a - b] % MOD;
}

ll cal2(string s)
{
    ll tt = 1, ct = 0, tmpct = 0;
    for(int i = 1;i < SZ(s);i ++)
    {
        if(s[i] == 'L'){
            tmpct ++;
            continue;
        }
        ll tmp = (fac[tmpct + 1] - fac[tmpct] + MOD) % MOD * h(ct, tmpct + 1) % MOD;
        tmp += fac[tmpct] * h(ct+1, tmpct + 1) % MOD;
        tt = tt * tmp % MOD;
        ct += tmpct + 1;
        tmpct = 0;
    }
    return tt;
}

ll ct;
ll go(string s)
{
    ll tmpct = 0;
    for(char c:s)if(c != '.')tmpct ++;
    if(tmpct != SZ(s) - 1)return 0;
    if(s == ".")return 1;
    if(s[0] == '.')
    {
        reverse(ALL(s));
        for(char &c:s)
        {
            if(c == 'R')c = 'L';
            else if(c == 'L')c = 'R';
        }
    }
    if(s[0] == 'L')return 0;
    ll tmp2 = 0;
    while(SZ(s) > 1 && s[SZ(s) - 2] == 'R')tmp2 ++, tmpct --, s[SZ(s) - 2] = '.', s.pop_back();
    ll tt = fac[tmp2] * h(ct + 1, tmp2) % MOD;
    ct += tmp2;
    if(SZ(s) == 1)return tt;
    tt = tt * h(ct + 1, tmpct) % MOD;
    tt = tt * cal2(s) % MOD;
    ct += tmpct;
    return tt;
}

int main()
{
    IOS();
    fac[0] = 1;
    REP1(i, 2 * MAXn - 1)fac[i] = fac[i-1] * i % MOD;
    REP(i, 2 * MAXn)inv[i] = pw(fac[i], MOD-2);

    ll T;
    cin>>T;
    while(T--)
    {
        ll n, tt = 1;
        ct = 0;
        string s;
        cin>>n>>s;
        string tmp=".";
        for(int i = 0;i < (n<<1) + 1;i ++)
        {
            if(!(i&1)){
                if(s[i] == '#'){
                    tt = tt * go(tmp) % MOD;
                    tmp = "";
                }
            }
            else {
                tmp.pb(s[i]);
                if(s[i] == '.')tt = tt * go(tmp) % MOD, tmp = ".";
            }
        }
        tmp.pb('.');
        tt = tt * go(tmp) % MOD;
        cout<<tt<<endl;
    }
}
