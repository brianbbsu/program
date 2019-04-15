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
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#endif // brian
//}


const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);



template<typename T>
T exgcd(T a,T b,T &x,T &y){//a*x+b*y=(return)
	if(b){
		T tmd=exgcd(b,a%b,y,x);
		y-=a/b*x;
		return tmd;
	}
	x=1,y=0;
	return a;
}

ll cal(vector<ll> v, vector<ll> d)
{
    ll tt = 0;
    REP(i, SZ(v))
    {
       ll m = 1;
       REP(j, SZ(v))if(j != i)m *= v[j];
       ll x, y;
       exgcd(m, v[i], x, y);
       ll p = x;
       p = (p % v[i] + v[i]) % v[i];
       //debug(p, m, v[i]);
       tt += p * m * d[i];
    }
    ll M = 1;
    REP(i, SZ(v))M *= v[i];
    return tt % M;
}

int main()
{
    IOS();
    vector<ll> v = {18 ,17 ,13 ,11 ,7 ,5};
    /*REP1(i, 1000000)
    {
        vector<ll> ret;
        for(ll x:v)ret.pb(i % x);
        if(cal(v, ret) != i)
        {
            debug(i, v, ret);
            return 0;
        }
    }*/
    
    ll T, n, m;
    cin>>T>>n>>m;
    while(T--)
    {
        vector<ll> ret;
        for(ll x:v)
        {
            REP1(i,18)cout<<x<<" ";
            cout<<endl;
            ll tt = 0;
            cin>>tt;
            if(tt == -1)return 0;
            REP1(i, 17)
            {
                ll t;
                cin>>t;
                tt = (tt + t) % x;
            }
            ret.pb(tt);
        }
        debug(v, ret, cal(v, ret));
        cout<<cal(v, ret)<<endl;
        ll t;
        cin>>t;
        if(t == -1)return 0;
    }
}
