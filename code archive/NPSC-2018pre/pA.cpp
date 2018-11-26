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

struct edge{
    ll a,b,c;
};

vector<edge> e,ea,eb;
ll g[MAXn];
vector<ll> dt,ua,ub;
ll tta,ttb;

ll fd(ll a){return g[a] = (g[a] == a?a:fd(g[a]));}
void mg(ll a,ll b){
    a = fd(a),b = fd(b);
    g[a] = b;
}

int main()
{
    IOS();
    ll n,m,k;
    cin>>n>>m>>k;
//-----------------
    e.clear();
    dt.clear();
    REP1(i,n)g[i] = i;
    REP(i,m)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        e.pb({a,b,c});
        dt.pb(i);
    }
    ea = e;
    sort(ALL(dt),[&](int a,int b){return e[a].c < e[b].c;});
    for(ll t:dt)
    {
        edge &tmp = e[t];
        if(fd(tmp.a) != fd(tmp.b))
        {
            mg(tmp.a,tmp.b);
            tta += tmp.c;
            ua.pb(t+1);
        }
    }

//------------------------

    e.clear();
    dt.clear();
    REP1(i,n)g[i] = i;
    REP(i,m)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        e.pb({a,b,c});
        dt.pb(i);
    }
    eb = e;
    sort(ALL(dt),[&](int a,int b){return e[a].c < e[b].c;});
    for(ll t:dt)
    {
        edge &tmp = e[t];
        if(fd(tmp.a) != fd(tmp.b))
        {
            mg(tmp.a,tmp.b);
            ttb += tmp.c;
            ub.pb(t+1);
        }
    }
//----------------
    debug(ua,ub,tta,ttb);
    if(abs(tta - ttb) == k)
    {
        cout<<0<<endl;
        return 0;
    }
    if(m == 0 && k != 0)
    {
        cout<<"YP can’t build a treap."<<endl;
        return 0;
    }
    cout<<1<<endl;
    if(tta >= ttb)
    {
        if(tta - ttb < k)
        {
            cout<<"P "<<ub[0]<<" "<<eb[ub[0] - 1].c - (k - (tta - ttb))<<endl;
        }
        else
        {
            cout<<"Y "<<ua[0]<<" "<<ea[ua[0] - 1].c - ((tta - ttb)-k)<<endl;
        }
    }
    else
    {
        if(ttb - tta > k)
        {
            cout<<"P "<<ub[0]<<" "<<eb[ub[0] - 1].c - ((ttb - tta) - k)<<endl;
        }
        else
        {
            cout<<"Y "<<ua[0]<<" "<<ea[ua[0] - 1].c - (k - (ttb - tta))<<endl;
        }
    }
}
