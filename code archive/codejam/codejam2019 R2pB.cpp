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
//#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#endif // brian
//}


const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

set<ll> st[30];
ll ct[30];

int main()
{
    IOS();
    srand(chrono::system_clock::now().time_since_epoch().count());
    ll T;
    cin>>T;
    ll sp[] = {10, 30, 60, 70, 80, 85, 97};
    ll kz = 0;
    while(T--)
    {
        kz ++;
        ll d;
        vector<ll> v;
        while(cin>>d)
        {
            if(d <= sp[0])
            {
                cout<<1<<" "<<0<<endl;
                ll n, _;
                cin>>n;
                REP(i,n)cin>>_;
            }
            else if(d <= sp[1])
            {
                ll t = d - sp[0];
                cout<<t<<" "<<0<<endl;
                ll x;st[t].clear();
                cin>>ct[t];
                REP(i,ct[t])cin>>x, st[t].insert(x);
                if(d == sp[1])
                {
                    v.clear();
                    REP1(i, 20)v.pb(i);
                    sort(ALL(v), [](int a,int b){return ct[a] > ct[b];});
                }
            }
            else if(d <= sp[2])
            {
                ll t = v[(d - sp[1] - 1) / 3], x;
                for(x = 1;st[t].count(x);x++);
                st[t].insert(x);
                cout<<t<<" "<<x<<endl;
                if(d == sp[2])
                {
                    reverse(ALL(v));
                    v.resize(10);
                    reverse(ALL(v));
                }
            }
            else if(d <= sp[3])
            {
                ll t = v[(d - sp[2] - 1)];
                cout<<t<<" "<<0<<endl;
                ll x;st[t].clear();
                cin>>ct[t];
                REP(i,ct[t])cin>>x, st[t].insert(x);
                if(d == sp[3])sort(ALL(v), [](int a,int b){return ct[a] > ct[b];});
            }
            else if(d <= sp[4])
            {
                ll t = v[(d - sp[3] - 1) / 2], x;
                for(x = 1;st[t].count(x);x++);
                st[t].insert(x);
                cout<<t<<" "<<x<<endl;
                if(d == sp[4])
                {
                    reverse(ALL(v));
                    v.resize(5);
                    reverse(ALL(v));
                    //debug(kz, v);
                }
            }
            else if(d <= sp[5])
            {
                ll t = v[(d - sp[4] - 1)];
                cout<<t<<" "<<0<<endl;
                ll x;st[t].clear();
                cin>>ct[t];
                REP(i,ct[t])cin>>x, st[t].insert(x);
                if(d == sp[5])sort(ALL(v), [](int a,int b){return ct[a] > ct[b];});
            }
            else if(d <= sp[6])
            {
                ll t = v[(d - sp[5] - 1) / 3], x;
                for(x = 1;st[t].count(x);x++);
                st[t].insert(x);
                cout<<t<<" "<<x<<endl;
                if(d == sp[6])
                {
                    reverse(ALL(v));
                    v.resize(1);
                }
            }
            else if(d == 100)
            {
                cout<<v[0]<<" "<<100<<endl;
                break;
            }
            else{
                cout<<1<<" "<<0<<endl;
                ll n, _;
                cin>>n;
                REP(i,n)cin>>_;
            }
        }
    }
}
