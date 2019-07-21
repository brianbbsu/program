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

vector<ii> d[MAXn], v;
vector<ll> dt;

int main()
{
    IOS();
    ll kz = 0;
    ll n;
    while(cin>>n)
    {
        kz ++;
        cout<<"Case "<<kz<<": ";
        REP1(i, n)d[i].clear();
        dt.clear();
        REP1(i, n)
        {
            d[i].pb(ii(-1, 1));
            ll k;
            cin>>k;
            REP(j, k)
            {
                ll t;
                cin>>t;
                if(t == d[i].back().X)d[i].back().Y ++;
                else d[i].pb(ii(t, 1));
                dt.pb(t);
            }
        }
        sort(ALL(dt));
        v.clear();
        for(ll t:dt){
            if(v.empty() || v.back().X != t)v.pb(ii(t, 1));
            else v.back().Y ++;
        }
        ll ct = 0;
        while(SZ(v))
        {
            vector<ll> tmp;
            REP1(i, n)if(d[i].back().X == v.back().X)tmp.pb(i);
            sort(ALL(tmp), [](int a,int b){return d[a][SZ(d[a]) - 2].X < d[b][SZ(d[b]) - 2].X;});
            for(ll t:tmp)
            {
                ct ++;
                while(1)
                {
                    if(d[t].back().Y == 0)d[t].pop_back();
                    if(SZ(v) && v.back().Y == 0)v.pop_back();
                    if(!SZ(v))break;
                    if(d[t].back().X != v.back().X)break;
                    d[t].back().Y --, v.back().Y --;
                }
            }
        }
        cout<<(ct - n) * 2 + n - 1<<endl;
    }
}
