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


const ll MAXn=60+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

int n,m,a;
ll c[MAXn][MAXn];
ll d[MAXn][MAXn];
ll s[MAXn][10][10],p[MAXn][10][10],cls[10][10];
ll tmpans[MAXn][10][10];
vector<ii> q;
ll mn=INF;

void cal()
{
  int ans=0;
  REP1(i,n)
  {
    REP(x,6)
    {
      int f=-1,e=-1;
      REP(y,7)
      {
        if(s[i][x][y])
        {
          if(f==-1)f=y;
          e=y;
        }
      }
      if(f!=-1)ans+=(3+e-f)*(3+e-f);
    }
  }
  REP1(i,m)
  {
    REP(x,6)
    {
      int f=-1,e=-1;
      REP(y,7)
      {
        if(p[i][x][y])
        {
          if(f==-1)f=y;
          e=y;
        }
      }
      if(f!=-1)ans+=(3+e-f)*(3+e-f);
    }
  }
  if(ans<mn)
  {
    mn=ans;
    REP1(i,n)REP(x,6)REP(y,7)tmpans[i][x][y]=s[i][x][y];
  }
}
int main()
{
    IOS();
    srand(time(NULL));
    cin>>n>>m>>a;
    REP1(i,n)REP1(j,m)
    {
      cin>>c[i][j];
      REP(k,c[i][j])q.pb(ii(i,j));
    }
    REP(T,100000)
    {
      FILL(s,0);FILL(p,0);FILL(cls,0);

      for(ii &tmp:q)
      {
        while(1)
        {
          int t=rand()%42;
          int x=t/7,y=t%7;
          if(!s[tmp.X][x][y]&&!p[tmp.Y][x][y]&&cls[x][y]<a)
          {
            s[tmp.X][x][y]=tmp.Y;
            p[tmp.Y][x][y]=tmp.X;
            cls[x][y]++;
            break;
          }
        }
      }
      cal();
    }
    FILL(s,0);FILL(p,0);FILL(cls,0);
    multiset<ii> st;
    for(ii &tmp:q)st.insert(tmp);

    REP(x,6)
    {
      REP(y,7)
      {
        REP(t,a)
        {
          for(auto it=st.begin();it!=st.end();it++)
          {
            ii tmp=*it;
            if(!s[tmp.X][x][y]&&!p[tmp.Y][x][y])
            {
              s[tmp.X][x][y]=tmp.Y;
              p[tmp.Y][x][y]=tmp.X;
              st.erase(it);
              break;
            }
          }
        }
      }
    }
    if(!SZ(st))cal();

    FILL(s,0);FILL(p,0);FILL(cls,0);
    st.clear();
    for(ii &tmp:q)st.insert(ii(tmp.Y,tmp.X));

    REP(x,6)
    {
      REP(y,7)
      {
        REP(t,a)
        {
          for(auto it=st.begin();it!=st.end();it++)
          {
            ii tmp=*it;
            if(!s[tmp.Y][x][y]&&!p[tmp.X][x][y])
            {
              s[tmp.Y][x][y]=tmp.X;
              p[tmp.X][x][y]=tmp.Y;
              st.erase(it);
              break;
            }
          }
        }
      }
    }
    if(!SZ(st))cal();

    cout<<mn<<endl;
    REP1(i,n)
    {
      cout<<endl;
      REP(y,7)
      {
        REP(x,6)cout<<(x==0?"":" ")<<tmpans[i][x][y];
        cout<<endl;
      }
    }
}
