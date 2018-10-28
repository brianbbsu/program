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


const ll MAXn=50+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll pw(ll x,ll k)
{
    if(!k)return 1;
    ll a = pw(x,k/2);
    a = a * a % MOD;
    if(k & 1)return a * x % MOD;
    else return a;
}

ll tt;
ll d[MAXn],ct[MAXn];
ll n;
ll iv[MAXn],fac[MAXn];

void add(ll &a,ll b)
{
    a += b;
    if(a >= MOD)a -= MOD;
}

void f(ll h,ll mx,ll it)
{
    debug(h,mx,it);
    if(it == n && h > 0)return;
    if(it < n && h == 0)return;
    if(h == 0)
    {
        pary(d,d+n);
        ll tmp = 0;
        REP(i,n)REP(j,i)add(tmp,__gcd(d[i],d[j]));
        ll ivp = 1,cnt = 0;
        REP1(i,50)
        {
            cnt += ct[i];
            ivp = ivp * iv[ct[i]] % MOD;
        }
        add(tt,tmp * fac[cnt] % MOD * ivp % MOD);
        return;
    }
    REP1(i,mx)
    {
        d[it] = i;
        ct[i]++;
        f(h-i,min(i,h-i),it+1);
        ct[i] --;
    }
}

int main()
{
    IOS();
    ll T;
    cin>>T;
    fac[0] = 1;
    REP1(i,50)fac[i] = fac[i-1] * i % MOD;
    REP(i,51)iv[i] = pw(fac[i],MOD-2);
    while(T--)
    {
        ll s;
        cin>>n>>s;
        ll it = 0;
        REP(i,n)
        {
            ll x;
            cin>>x;
            if(x != -1)d[it] = x,it++,s-=x;
        }
        tt = 0;
        if(s < 0)
        {
            cout<<0<<endl;
            continue;
        }
        f(s,s,it);
        cout<<tt<<endl;
    }
}
