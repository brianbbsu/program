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

class ModularQuadrant{
public:
    ll cnt(int tp, int p)
    {
        return p / 3 + (p % 3 >= tp);
    }
    ll cal(int x,int y)
    {
        if(x < 0 || y < 0)return 0;
        ll tt = 0, t = min(x,y);
        REP(i,3)
        {
            ll l = cnt(i,t);
            tt += i * (2 * (i+1) + (l - 1) * 3) * l/ 2;
            tt += i * (2 * i + (l - 1) * 3) * l/ 2;
        }
        if(x > y)
        {
            REP(i,3)
            {
                ll l = cnt(i, x) - cnt(i, t);
                tt += l * (y + 1) * i;
            }
        }
        else if(y > x)
        {
            REP(i,3)
            {
                ll l = cnt(i, y) - cnt(i, t);
                tt += l * (x + 1) * i;
            }
        }
        return tt;
    }
    long long sum(int r1, int r2, int c1, int c2){
        return cal(r2,c2) - cal(r2,c1-1) - cal(r1-1,c2) + cal(r1-1,c1-1);
    }
};

#ifdef brian
int main()
{
    IOS();

}
#endif
