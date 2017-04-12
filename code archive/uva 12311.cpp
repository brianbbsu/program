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


const ll MAXn=3e4+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll n;
ii d[MAXn];
inline ll sq(ll a){return a*a;}
inline ll dis(ll a,ll b){return sq(d[a].X-d[b].X)*sq(d[a].Y-d[b].Y);}
ii operator - (ii &a,ii &b){return ii(a.X-b.X,a.Y-b.Y);}
inline ll cross(ii a,ii b){return a.X*b.Y-a.Y*b.X;}
int main()
{
    IOS();
    while(cin>>n&&n)
    {
      REP(i,n)cin>>d[i].X>>d[i].Y;
      d[n]=d[0];
      ll it=1;
      REP(i,n)
      {
        ll ans=it;
        while(cross(d[i+1]-d[i],d[it+1]-d[it])>0)
        {
          debug(i,it);
          it++;
          if(it==n)it=0;
          if(dis(i,ans)<dis(i,it))ans=it;
        }
        cout<<ans+1<<endl;
      }
    }
}
