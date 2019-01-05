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


const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e9);

const ll M = 1002;
int dp[10005][2005];
deque<ii> dq[2][MAXn];


int main()
{
    IOS();
    string s,t;
    ll L,k;
    cin>>s>>t>>L>>k;
    REP(i,10005)REP(j,2005)dp[i][j] = INF;
    dp[0][M] = 0;
    ll T = L * k;
    if(abs(SZ(s) - SZ(t)) > T)
    {
        cout<<"Impossible"<<endl;
        return 0;
    }
    REP(i,SZ(s)+1)
    {
        for(int j = -T;j <= T;j ++)
        {
            if(i + j < 0 || i + j > SZ(t))continue;
            if(i == 0 && i + j == 0)dp[0][M] = 0;
            else if(i == 0)dp[i][j + M] = (i + j - 1) / L + 1;
            else if(i + j == 0)dp[i][j + M] = (i - 1) / L + 1;
            else
            {
                if(s[i-1] == t[i+j-1])dp[i][j + M] = dp[i-1][j + M];
                while(SZ(dq[0][i]) && dq[0][i].front().Y < j - L)dq[0][i].pop_front();
                if(SZ(dq[0][i]))dp[i][j+M] = min(dp[i][j+M], dq[0][i].front().X + 1);
                while(SZ(dq[1][i + j]) && dq[1][i + j].front().Y < i - L)dq[1][i + j].pop_front();
                if(SZ(dq[1][i + j]))dp[i][j+M] = min(dp[i][j+M], dq[1][i + j].front().X + 1);
            }
            while(SZ(dq[0][i]) && dq[0][i].back().X >= dp[i][j + M])dq[0][i].pop_back();
            dq[0][i].push_back({dp[i][j + M], j});
            while(SZ(dq[1][i + j]) && dq[1][i + j].back().X >= dp[i][j + M])dq[1][i + j].pop_back();
            dq[1][i + j].push_back({dp[i][j + M], i});
            debug(i, i + j, dp[i][j + M]);
        }
    }
    if(dp[SZ(s)][SZ(t) - SZ(s) + M] > k)cout<<"Impossible"<<endl;
    else cout<<dp[SZ(s)][SZ(t) - SZ(s) + M]<<endl;
}