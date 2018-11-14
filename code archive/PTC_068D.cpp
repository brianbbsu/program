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


const ll MAXn=2e6+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll d[MAXn];
ll dg[MAXn],h[MAXn];
ll ct[MAXn],p[MAXn];

queue<ll> q;

int main()
{
    IOS();
    ll T;
    cin>>T;
    while(T--)
    {
        ll n;
        cin>>n;
        ll N = 2 * n - 1;
        REP(i,N)cin>>d[i];
        REP1(i,n)ct[i] = dg[i] = h[i] = 0;
        p[d[0]] = -1;
        REP(i,N)
        {
            ct[d[i]]++;
            if(i != N-1 && ct[d[i+1]]==0)
            {
                p[d[i+1]] = d[i];
                dg[d[i]]++;
            }
        }
        REP1(i,n)if(!dg[i])q.push(i);
        REP1(i,n)ct[i]=0;
        while(SZ(q))
        {
            ll t = q.front();
            q.pop();
            if(p[t] == -1)continue;
            h[p[t]] = max(h[p[t]],h[t] + 1);
            ct[p[t]]++;
            if(ct[p[t]] == dg[p[t]])q.push(p[t]);
        }
        ll tt = 0;
        REP1(i,n)tt += h[i];
        cout<<tt<<endl;
    }
}
