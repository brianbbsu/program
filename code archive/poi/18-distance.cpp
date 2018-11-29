//{
#include<bits/stdc++.h>
using namespace std;
typedef int ll;
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


const ll MAXn=1e6+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e9);

ii dt[MAXn][2];
vector<ll> pm;
ll lspm[MAXn];

vector<ii> pmfac[MAXn], u;
vector<ii> fac[MAXn];
ll d[MAXn], dis[MAXn];


int main()
{
    IOS();
    REP(i,MAXn)dt[i][0] = dt[i][1] = ii(INF,-1);
    for(int i = 2;i < MAXn;i ++)
    {
        if(!lspm[i])lspm[i] = i, pm.pb(i);
        for(int j = 0;pm[j] * i < MAXn;j++)
        {
            lspm[pm[j] * i] = pm[j];
            if(i % pm[j] == 0)break;
        } 
    }
    FILL(dis,-1);
    ll n;
    cin>>n;
    REP(i,n)cin>>d[i];
    REP(i,n)
    {
        ll x = d[i];
        while(x != 1)
        {
            ll t = lspm[x];
            pmfac[i].pb({t,0});
            while(lspm[x] == t)x /= t,pmfac[i].back().Y++;
        }
    }
    REP(i,n)
    {
        fac[i].pb({1,0});
        for(ii p:pmfac[i])fac[i].back().Y += p.Y;
        for(ii p:pmfac[i])
        {
            ll s = SZ(fac[i]), tmp = 1;
            REP1(j,p.Y)
            {
                tmp *= p.X;
                REP(k,s)fac[i].pb(ii(fac[i][k].X * tmp, fac[i][k].Y - j));
            }
        }
    }
    REP(i,n)debug(d[i],pmfac[i],fac[i]);
    REP(i,n)for(auto p:fac[i])
    {
        if(dt[p.X][0] >= ii(p.Y,i))dt[p.X][1] = dt[p.X][0], dt[p.X][0] = ii(p.Y,i);
        else if(dt[p.X][1] > ii(p.Y,i))dt[p.X][1] = ii(p.Y,i);
    }
    REP(i,n)
    {
        ii mn = ii(INF,i);
        for(auto p:fac[i])
        {
            if(dt[p.X][0] == ii(p.Y,i))mn = min(mn,ii(p.Y+dt[p.X][1].X,dt[p.X][1].Y));
            else mn = min(mn,ii(p.Y+dt[p.X][0].X,dt[p.X][0].Y));
        }
        cout<<mn.Y+1<<endl;
    }
}
