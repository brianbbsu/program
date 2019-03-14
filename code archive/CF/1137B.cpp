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


const ll MAXn=5e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll z[MAXn];

void calz(string s)
{
    z[0] = 0;
    ll l = 0;
    REP1(i, SZ(s) - 1)
    {
        if(l + z[l] > i)z[i] = min(l + z[l] - i, z[i - l]);
        for(;i + z[i] < SZ(s) && s[i + z[i]] == s[z[i]];z[i]++);
    }
}

ll sct[2], tct[2], nct[2];

void fin()
{
    while(sct[0])
    {
        cout<<0;
        sct[0]--;
    }
    while(sct[1])
    {
        cout<<1;
        sct[1]--;
    }
    cout<<endl;
    exit(0);
}

int main()
{
    IOS();
    string s, t;
    cin>>s>>t;
    calz(t);
    ll it = -1;
    REP(i,SZ(t))if(i + z[i] == SZ(t)){it = i;break;}
    if(it == -1)it = SZ(t);
    REP(i, SZ(s))sct[s[i] - '0']++;
    REP(i, SZ(t))tct[t[i] - '0']++;
    REP(i,2)nct[i] = tct[i];
    for(int i = it;i < SZ(t);i++)nct[t[i] - '0']--;
    if(sct[0] < tct[0] || sct[1] < tct[1])fin();
    cout<<t;
    sct[0] -= tct[0];
    sct[1] -= tct[1];
    while(sct[0] >= nct[0] && sct[1] >= nct[1])
    {
        cout<<t.substr(SZ(t) - it);
        sct[0] -= nct[0];
        sct[1] -= nct[1];
    }
    fin();
}
