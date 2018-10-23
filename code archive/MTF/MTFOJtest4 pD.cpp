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


const ll MAXn=1e18+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);


vector<ll> dt[2][3];
ll tmp=0;

void g2(ll a,ll b,ll c)
{
  cout<<2<<endl;
  cout<<(a^tmp^c)<<" "<<(b^c)<<endl;
}
void g3(ll a,ll b,ll c,ll d)
{
  cout<<3<<endl;
  cout<<(a^tmp^b^c)<<" "<<(a^b^d)<<" "<<(a^c^d)<<endl;
}

int main()
{
    IOS();

    ll a,b;
    cin>>a>>b;
    ll n=a^b;
    if(n%3==0)
    {
      cout<<1<<endl<<n<<endl;
      return 0;
    }

    for(ll i=0,I=1;i<60;i++,I<<=1)
    {
      dt[(n&I)>0][I%3].pb(i);
    }
    REP(i,2)REP1(j,2)debug(i,j,dt[i][j]);

    REP1(i,2)while(SZ(dt[1][i])>=3)
    {
      REP(j,3)
      {
        tmp|=(1LL<<dt[1][i].back());
        dt[1][i].pop_back();
      }
    }
    REP(i,2)REP1(j,2)for(ll &k:dt[i][j])k=(1LL<<k);
    debug(tmp);
    n^=tmp;
    ll x=SZ(dt[1][1]),y=SZ(dt[1][2]);
    vector<ll> &A=dt[1][1],&B=dt[1][2];
    if(x==0)
    {
      if(y==1)
      {
        g3(n,dt[0][2][0],dt[0][2][1],dt[0][2][2]);
      }
      else//y==2
      {
        g2(B[0],B[1],1);
      }
    }
    else if(x==1)
    {
      if(y==0)
      {
        g3(n,dt[0][1][0],dt[0][1][1],dt[0][1][2]);

      }
      else//y==2
      {
        g3(n,dt[0][1][0]&dt[0][1][1],dt[0][1][2]&dt[0][1][3],dt[0][1][4]&dt[0][1][5]);
      }
    }
    else
    {
        if(y==0)
        {
          g2(A[0],A[1],2);
        }
        else //y==1
        {
          g2(A[0]&A[1],B[0],dt[0][1][0]);
        }
    }


}
