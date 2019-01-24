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
const ll INF=ll(1e17);

vector<ii> v[MAXn];
ll dis[MAXn];
priority_queue<ii, vector<ii>, greater<ii> > pq;


int main()
{
    IOS();
    ll n,m,s;
    cin>>n>>m>>s;
    REP1(i,m)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        v[a].pb({b,c});
        v[b].pb({a,c});
    }
    REP1(i,n)dis[i] = INF;
    dis[s] = 0;
    pq.push({0, s});
    while(SZ(pq))
    {
        while(SZ(pq) && dis[pq.top().Y] != pq.top().X)pq.pop();
        if(!SZ(pq))break;
        ll t = pq.top().Y;
        pq.pop();
        debug(t);
        for(ii k:v[t])
        {
            if(dis[k.X] > dis[t] + k.Y)
            {
                pq.push({dis[t] + k.Y, k.X});
                dis[k.X] = dis[t] + k.Y;
            }
        }
    }
    ll l;
    cin>>l;
    ll tt = 0;
    REP1(i,n)
    {
        if(dis[i] == l)
        {
            tt++;
            continue;
        }
        if(dis[i] > l)continue;
        for(ii k:v[i])
        {
            ll dif = l - dis[i];
            if(k.Y <= dif)continue;
            if(dis[k.X] + k.Y - dif > l)tt++;
            else if(dis[k.X] + k.Y - dif == l && k.X > i)tt++;
        }
    }
    cout<<tt<<endl;
}
