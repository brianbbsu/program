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

priority_queue<ii, vector<ii>, greater<ii> > pq;
vector<ll> v[MAXn];
ll ans[MAXn], dg[MAXn];

int main()
{
    IOS();
    ll n, m;
    cin>>n>>m;
    FILL(ans, -1);
    REP(i,m)
    {
        ll a, b;
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
        dg[a]++;
        dg[b]++;
    }
    REP1(i,n)pq.push(ii(dg[i], i));
    while(SZ(pq))
    {
        ll t = pq.top().Y;
        pq.pop();
        if(ans[t] != -1)continue;
        ll fg = 0;
        for(ll x:v[t])if(ans[x] == -1 || ans[x] != t)
        {
            ans[t] = x;
            dg[x]--;
            if(ans[x] == -1)pq.push({dg[x], x});
            fg = 1;
            break;
        }
        if(!fg){
            cout<<"NIE"<<endl;
            return 0;
        }
    }
    cout<<"TAK"<<endl;
    REP1(i,n)cout<<ans[i]<<endl;
}
