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
const ll INF=ll(1e15);



int main()
{
    IOS();
    ll r,c;
    cin>>r>>c;
    int ct[2][r+1][c+1],d[r][c];
    REP(i,r)REP(j,c)cin>>d[i][j];
    FILL(ct,0);
    REP(i,r)REP1(j,c-1)if(d[i][j-1]&&d[i][j])ct[0][i+1][j+1]++;
    REP(j,c)REP1(i,r-1)if(d[i-1][j]&&d[i][j])ct[1][i+1][j+1]++;
    REP(t,2)REP1(i,r)REP1(j,c)ct[t][i][j]+=ct[t][i-1][j]+ct[t][i][j-1]-ct[t][i-1][j-1];

    ll q;
    cin>>q;
    REP(i,q)
    {
      ll r1,r2,c1,c2;
      cin>>r1>>c1>>r2>>c2;
      ll ans=ct[0][r2][c2]-ct[0][r2][c1]-ct[0][r1-1][c2]+ct[0][r1-1][c1];
      ans += ct[1][r2][c2]-ct[1][r2][c1-1]-ct[1][r1][c2]+ct[1][r1][c1-1];
      cout<<ans<<endl;
    }

}
