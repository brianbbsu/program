//{
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(ll i=0;i<n;i++)
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
template<typename _a,typename _b> ostream &operator << (ostream &_s,pair<_a,_b> &_p){return _s<<"("<<_p.X<<","<<_p.Y<<")";}
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
#else
#define debug(...)
//#define endl '\n'
#endif // brian
//}

const ll MAXn=17;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll n;
ll dp[(1<<MAXn)][2][MAXn*MAXn];
bool t[MAXn];
ll r[MAXn],b[MAXn];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    ll cr=0,cb=0;
    REP(i,n)
    {
        char ch;
        cin>>ch>>r[i]>>b[i];
        t[i]=(ch=='B');
        if(r[i]>n){cr+=r[i]-n;r[i]=n;}
        if(b[i]>n){cb+=b[i]-n;b[i]=n;}
    }
    REP(i,(1<<n))REP(j,2)REP(k,n*n+1)dp[i][j][k]=INF;
    ll base=n+max(cr,cb);
    if(cr>cb)dp[0][1][cr-cb]=0;
    else dp[0][0][cr-cb]=0;
    for(int I=1;I<(1<<n);I++)
    {
        cr=cb=0;
        for(int i=0,J=1;i<n;i++,J<<=1)if(I&J)(t[i]?cb++:cr++);
        for(int i=0,J=1;i<n;i++,J<<=1)
        {
            if((I&J)==0)continue;

        }
    }
}
