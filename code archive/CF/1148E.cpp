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


const ll MAXn=3e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

struct tg{
    int a, b, c;
};


int s[MAXn], t[MAXn], d[MAXn], dt[MAXn], p[MAXn];

set<ii> pos, neg;

void put(int x)
{
    if(d[x] < 0)neg.insert(ii(s[x], x));
    else if(d[x] > 0)pos.insert(ii(s[x], x));
}

int main()
{
    IOS();
    int n;
    cin>>n;
    REP1(i,n)cin>>s[i], dt[i] = i;
    REP1(i,n)cin>>t[i];
    sort(dt + 1, dt + 1 + n, [](int a,int b){return s[a] < s[b];});
    sort(t + 1, t + 1 + n);
    REP1(i,n)d[dt[i]] = t[i] - s[dt[i]];
    pary(d + 1, d + 1 + n);
    ll tt = 0;
    REP1(i,n)
    {
        tt += d[dt[i]];
        if(tt < 0){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    if(tt != 0)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    vector<tg> v;

    REP1(i,n)put(i);
    
    while(SZ(neg))
    {
        ii x = *pos.begin();
        pos.erase(pos.begin());
        ii y = *neg.upper_bound(ii(x.X + 1, -1));
        neg.erase(neg.upper_bound(ii(x.X + 1, -1)));
        ll t = min(abs(d[x.Y]), abs(d[y.Y]));
        v.pb({x.Y, y.Y, t});
        d[x.Y] -= t;
        d[y.Y] += t;
        put(x.Y);
        put(y.Y);
    }
    cout<<"YES"<<endl;
    cout<<SZ(v)<<endl;
    for(auto &p:v)cout<<p.a<<" "<<p.b<<" "<<p.c<<endl;

}
