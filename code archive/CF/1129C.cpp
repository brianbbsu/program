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

ll bs, M;
map<ll, ll> mp, tmp;

bool isval(string t)
{
    debug(t);
    return t != "0011" && t != "0101" && t != "1110" && t != "1111";
}

ll suf[MAXn];

int main()
{
    IOS();
    // init
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    vector<ll> pms = {1100000000081LL, 1100000000041LL, 1100000000003LL};
    M = pms[rng() % SZ(pms)];
    bs = rng() % 10000 + 200;
    mp[0] = 1;
    string s = "";
    ll m;
    cin>>m;
    ll ans = 0;
    REP(i, m)
    {
        string c;
        cin>>c;
        s += c;
        ll tt = 0;
        tmp.clear();
        suf[i] = s[i];
        for(int j = i-1;j >= 0;j --)suf[j] = (suf[i] * bs + s[j]) % M;
        for(int l = 1;l <= 4 && l <= i+1;l++)if(isval(s.substr(i - l + 1, l)))
        {
            ll h = 0;
            for(int j = i-l+1;j >= 0;j --)
            {
                auto it = mp.find(h);
                if(it != mp.end()){
                    debug(l, h);
                    auto p = tmp.insert(ii(suf[j], it->Y));
                    if(!p.Y)p.X->Y = (p.X->Y + it->Y) % MOD;
                    debug(p.X->Y);
                }
                if(j != 0)h = (h * bs + s[j-1]) % M;
            }
        }
        debug(tmp);
        for(auto dt:tmp){
            auto p = mp.insert(dt);
            if(p.Y)ans = (ans + dt.Y) % MOD;
        }
        cout<<ans<<endl;
        debug(mp);
    }
}
