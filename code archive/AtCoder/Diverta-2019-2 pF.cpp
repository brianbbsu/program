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

ll d[15];

ll a[15][15];
ll n = 5;

bool check()
{
    REP1(i,n)REP1(j,n)
    {
        if(i == j && a[i][j] != 0)return 0;
        else if(i != j && a[i][j] != a[j][i])return 0;
    }
    set<ll> st;
    vector<ll> dt;
    REP1(i, n)dt.pb(i);
    do{
        if(dt[0] > dt.back())break;
        ll tt = 0;
        REP(i, n - 1)tt += a[dt[i]][dt[i + 1]];
        if(tt > 100000000000LL)return 0;
        if(st.count(tt))return 0;
        st.insert(tt);
    }while(next_permutation(ALL(dt)));
    return 1;
}

int main()
{
    IOS();

    d[1] = 1;d[2] = 2;
    set<ll> st;
    st.insert(1);
    for(int i = 3;i <= 10;i ++)d[i] = d[i-1] + d[i-2];
    /*{
        for(int j = 1;;j ++)
        {
            bool fg = 0;
            for(int k = 1;k < i;k ++)if(st.count(d[k] + j) || d[k] == j)fg = 1;
            if(!fg)
            {
                d[i] = j;
                break;
            }
        }
        for(int j = 1;j < i;j ++)st.insert(d[i] + d[j]);
    }*/
    pary(d + 1, d + 1 + 10);

    st.clear();
    REP1(i, n)REP1(j, i - 1)
    {
        assert(!st.count(d[i] + d[j]));
        st.insert(d[i] + d[j]);
    }

    /*ll tt = 1;
    for(int i = 1;i <= 9;i ++)
    {
        tt = tt * (d[i] + d[i-1] + 2);
    }
    debug(tt);
    return 0;*/

    ll pt = 1;

    REP1(i, n)
    {
        REP1(j, n)if(i == j)a[i][j] = 0;
        else if(i > j)a[i][j] = a[j][i];
        else
        {
            a[i][j] = pt * d[j - i];
        }
        pt = pt * (d[n - i] + d[n - i - 1] + 1);
        debug(pt);
    }
    REP1(i, n)REP1(j, n)if(i != j)a[i][j] += 0;
    debug(check());
    REP1(i, n)REP1(j,n)cout<<a[i][j]<<" \n"[j == n];
}
