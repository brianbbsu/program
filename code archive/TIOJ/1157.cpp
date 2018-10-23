//{
#include<algorithm>
#include<cstdio>
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
//}


const ll MAXn=5e1+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

struct fac{
  ll a,b; // a/b
  //fac():a(0),b(1){}
  fac uni()
  {
    if(b<0)a=-a,b=-b;
    if(a==0)b=1;
    else
    {
      ll t=__gcd(abs(a),b);
      a/=t;b/=t;
    }
    return *this;
  }
  fac operator *(fac &t)
  {
    fac rt={t.a*a,t.b*b};
    return rt.uni();
  }
  fac operator /(fac &t)
  {
    fac rt={t.b*a,t.a*b};
    return rt.uni();
  }
  fac operator -(fac t)
  {
    fac rt={a*t.b-b*t.a,t.b*b};
    return rt.uni();
  }
};

fac d[MAXn][MAXn];

int main()
{
    //IOS();
    ll n;
    scanf("%lld",&n);
    REP(i,n)
    {
      REP(j,n+1)
      {
        scanf("%lld",&d[i][j].a);
        d[i][j].b=1;
      }
    }
    //REP(j,n)REP(k,n+1)debug(j,k,d[j][k]);
    REP(i,n)
    {
      if(d[i][i].a==0)
      {
        for(int j=i+1;j<n;j++)if(d[j][i].a!=0)
        {
          for(int k=i;k<=n;k++)swap(d[i][k],d[j][k]);
          break;
        }
        if(d[i][i].a==0)continue;
      }
      for(int k=n;k>=i;k--)d[i][k]=d[i][k]/d[i][i];
      REP(j,n)
      {
        if(d[j][i].a==0||i==j)continue;
        for(int k=n;k>=i;k--)d[j][k]=d[j][k]-d[i][k]*d[j][i];
      }
    }
    bool multi=0,no=0;
    REP(i,n)if(d[i][i].a==0)
    {
      if(d[i][n].a==0)multi=1;
      else no=1;
    }
    if(no)puts("0");
    else if(multi)puts("N");
    else
    {
      puts("1");
      REP(i,n)
      {
        printf("x%lld = ",i+1);
        fac tmp=d[i][n]/d[i][i];
        if(tmp.a%tmp.b==0)printf("%lld\n",tmp.a/tmp.b);
        else printf("%lld/%lld\n",tmp.a,tmp.b);
      }
    }
}
