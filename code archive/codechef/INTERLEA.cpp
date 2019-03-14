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

ll n;
string s[MAXn];
ll iter[MAXn];
queue<ll> q[20];

vector<ll> vshape(ll fg)
{
    ll tt = 0;
    REP(i,n)iter[i] = 0;
    vector<ll> ret;
    while(tt != SZ(s[0]) * n)
    {
        vector<pair<ll, ii>> v;
        REP(i,n)if(iter[i] != SZ(s[i]))
        {
            if(fg){
                v.pb({-s[i][iter[i]], {i+1, iter[i]}});
                iter[i]++;
                while(iter[i] != SZ(s[i]) && s[i][iter[i]] <= s[i][iter[i]-1]){
                    v.pb({-s[i][iter[i]], {i+1, iter[i]}});
                    iter[i]++;
                }
            }
            else{
                v.pb({s[i][iter[i]], {i+1, iter[i]}});
                iter[i]++;
                while(iter[i] != SZ(s[i]) && s[i][iter[i]] >= s[i][iter[i]-1]){
                    v.pb({s[i][iter[i]], {i+1, iter[i]}});
                    iter[i]++;
                }
            }
        }
        sort(ALL(v));
        tt += SZ(v);
        for(auto x:v)ret.pb(x.Y.X);
        fg = !fg;
    }
    return ret;
}

vector<ll> same()
{
    REP(i, 10)while(SZ(q[i]))q[i].pop();
    REP(i,n)q[s[i][0] - '0'].push(i);
    REP(i,n)iter[i] = 0;
    ll now = 0;
    vector<ll> v;
    while(1)
    {
        bool fg = 0;
        for(int i = 0;now + i <= 9 || now - i >= 0;i++)
        {
            if(now + i <= 9 && SZ(q[now + i]))
            {
                fg = 1;
                ll t = q[now + i].front();
                q[now + i].pop();
                iter[t]++;
                v.pb(t+1);
                if(iter[t] != SZ(s[t]))q[s[t][iter[t]] - '0'].push(t);
                now = now + i;
                break;
            }
            else if(now - i >= 0 && SZ(q[now - i]))
            {
                fg = 1;
                ll t = q[now - i].front();
                q[now - i].pop();
                iter[t]++;
                v.pb(t+1);
                if(iter[t] != SZ(s[t]))q[s[t][iter[t]] - '0'].push(t);
                now = now - i;
                break;
            }
        }
        if(!fg)break;
    }
    return v;
}

vector<ll> one()
{
    REP(i, 10)while(SZ(q[i]))q[i].pop();
    REP(i,n)q[s[i][0] - '0'].push(i);
    REP(i,n)iter[i] = 0;
    ll tt = 0;
    vector<ll> ret;
    while(tt != SZ(s[0]) * n)
    {
        bool fg = 0;
        REP(i,2)if(SZ(q[0]))
        {
            ll t = q[i].front();q[i].pop();
            iter[t]++;
            if(iter[t] != SZ(s[t]))q[s[t][iter[t]] - '0'].push(t);
            ret.pb(t+1);
            tt++;fg = 1;break;
        }
        if(!fg)
        {
            vector<ll> v;
            REP(i,n)if(iter[i] != SZ(s[i]))v.pb(i);
            sort(ALL(v), [](int a,int b){return s[a][iter[a]] < s[b][iter[b]];});
            for(int i = 0;i < SZ(v);i += 2){
                ll t = v[i];
                iter[t]++;
                if(iter[t] != SZ(s[t]))q[s[t][iter[t]] - '0'].push(t);
                ret.pb(t+1);
                tt++;
            }
            for(int i = SZ(v) - 1 - SZ(v)%2;i >= 0;i -= 2){
                ll t = v[i];
                iter[t]++;
                if(iter[t] != SZ(s[t]))q[s[t][iter[t]] - '0'].push(t);
                ret.pb(t+1);
                tt++;
            }
        }
    }
    return ret;
}

ll cal(vector<ll> v)
{
    ll tt = 0;
    REP(i,n)iter[i] = 0;
    ll lst = s[v[0]-1][iter[v[0]-1]++];
    REP1(i, SZ(v)-1)
    {
        ll t = s[v[i]-1][iter[v[i]-1]++];
        tt += (lst-t) * (lst-t);
        lst = t;
    }
    debug(tt);
    return tt;
}

vector<ll> bst;
ll mn;

void tr(vector<ll> v)
{
    assert(SZ(v) == SZ(s[0]) * n);
    if(!SZ(bst))bst = v, mn = cal(v);
    else{
        ll tmp = cal(v);
        if(tmp < mn)mn = tmp, bst = v;
    }
}

int main()
{
    IOS();
    cin>>n;
    REP(i,n)cin>>s[i];
    tr(vshape(1));
    tr(vshape(0));
    tr(same());
    tr(one());
    //for(ll k:bst)cout<<k<<" ";
    //cout<<endl;
    debug(mn);
    cout<<mn<<endl;
}
