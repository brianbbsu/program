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


const ll MAXn=5e1+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

struct HalfGraph{
    ll iter[MAXn], dg[MAXn];
    vector<ii> e;
    vector <string> compute(vector <string> a){
        ll n = SZ(a);
        REP(i,n)
        {
            dg[i] = 0;
            REP(j, n)if(a[i][j]=='1')dg[i]++;
            if(dg[i] % 2)return vector<string>();
        }
        REP(i,n)iter[i] = 0;
        e.clear();
        REP(i,n)if(iter[i] != n)
        {
            vector<ii> tmp;
            ll now = i;
            while(!(now == i && iter[i] == n))
            {
                if(a[now][iter[now]] == '0'){
                    iter[now]++;
                    continue;
                }
                a[now][iter[now]] = '0';
                a[iter[now]][now] = '0';
                tmp.pb({now, iter[now]});
                now = iter[now];
            }
            if(SZ(tmp))
            {
                bool fg = 0;
                for(auto it = e.begin();it != e.end();it++)
                {
                    if(it->X == now)
                    {
                        fg = 1;
                        e.insert(it, ALL(tmp));
                        break;
                    }
                }
                if(!fg)e.insert(e.end(), ALL(tmp));
            }
        }
        debug(e);
        REP(i,n)REP(j,n)a[i][j] = '0';
        for(int i = 0;i < SZ(e);i += 2)a[e[i].X][e[i].Y] = a[e[i].Y][e[i].X] = '1';
        REP(i,n)
        {
            ll ct = 0;
            REP(j, n)if(a[i][j]=='1')ct++;
            if(ct * 2 != dg[i])return vector<string>();
        }
        return a;
    }
};

#ifdef brian
int main()
{
    IOS();
    HalfGraph sol;
    debug(sol.compute({"01111",
 "10111",
 "11011",
 "11101",
 "11110"}));
}
#endif
