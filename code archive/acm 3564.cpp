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


const ll MAXn=2e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

struct tg{
  ll m,s,n,t;
  tg(ll mi=0,ll si=0,ll ni=0,ll ti=0):m(mi),s(si),n(ni),t(ti){};
};
const bool operator < (const tg &a,const tg &b)
{
  if(a.m+a.n<b.m+b.n)return 1;
  else if(a.s<b.s)return 1;
  else return 0;
}
const bool operator == (const tg &a,const tg &b)
{
  return a.m==b.m&&a.n==b.n&&a.s==b.s&&a.t==b.t;
}
ostream &operator << (ostream &_ss,const tg &a){return _ss<<a.m<<" "<<a.s<<" "<<a.n<<" "<<a.t;}

ll md[10][MAXn];
tg ans,d;
ii dt[MAXn],dt2[MAXn];

void mkd(ll n)
{
  vector<ii> tmp;
  while(n>0)
  {
    ll t=n%10;
    if(!SZ(tmp)||tmp.back().X!=t)tmp.pb(ii(t,1));
    else tmp.back().Y++;
    n/=10;
  }
  if(SZ(tmp)==2)
  {
    d=tg(tmp[1].Y,tmp[1].X,tmp[0].Y,tmp[0].X);
  }
  else d=tg(INF,0,INF,0);
}

int main()
{
    IOS();

    ll n;
    while(cin>>n&&n)
    {
      FILL(md,-1);
      ans=tg(INF,0,INF,0);
      mkd(n);
      ll g=max({min(n,100LL),n/10,2LL});
      debug(g);
      REP1(i,9)
      {
        ll t=0;
        for(int j=1;j<=g;j++)
        {
          t=(t*10+i)%n;
          md[i][j]=t;
        }
      }

      REP1(i,9)
      {
        for(int j=0;j<=n;j++)dt[j]=ii(-1,0),dt2[j]=ii(INF,0);
        for(int j=1;j<=g;j++)
        {
          if(dt[md[i][j]].X!=-1)
          {
            tg tmp=tg(j-dt[md[i][j]].X,i,dt[md[i][j]].X,i-dt[md[i][j]].Y);
            if(!(tmp==d))
            {
              ans=min(ans,tmp);
              break;
            }
          }
          if(dt2[n-md[i][j]].X!=INF)
          {
            tg tmp=tg(j-dt2[n-md[i][j]].X,i,dt2[n-md[i][j]].X,i+dt2[n-md[i][j]].Y);
            if(!(tmp==d))
            {
              ans=min(ans,tmp);
              break;
            }
          }
          REP1(k,i)dt[md[k][j]]=max(dt[md[k][j]],ii(j,k));
          REP1(k,9-i)dt2[md[k][j]]=min(dt2[md[k][j]],ii(j,k));
        }
        //debug(i,ans);
      }

      cout<<n<<": "<<ans<<endl;

    }
}
