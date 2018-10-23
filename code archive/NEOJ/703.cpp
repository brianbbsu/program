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


const ll MAXn=3e3+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll cnt[MAXn][30],clrcnt[MAXn];
bool u[MAXn];

queue<ii> q;

vector<ii> a;

ll fd(ll x)
{
  REP(i,26)if(cnt[x][i])return i;
}

int main()
{
    IOS();
    ll n,m;
    cin>>n>>m;
    REP(i,n)
    {
      string s;
      cin>>s;
      REP(j,m)
      {
        cnt[i][s[j]-'a']++;
        if(cnt[i][s[j]-'a']==1)clrcnt[i]++;
        cnt[n+j][s[j]-'a']++;
        if(cnt[n+j][s[j]-'a']==1)clrcnt[n+j]++;
      }
    }

    REP(i,n)if(clrcnt[i]==1)q.push(ii(i,fd(i))),u[i]=1;
    REP(i,m)if(clrcnt[i+n]==1)q.push(ii(i+n,fd(i+n))),u[i+n]=1;

    while(SZ(q))
    {
      ii tmp = q.front();q.pop();
      if(tmp.X < n)
      {
        REP(i,m)if(!u[i+n])
        {
          cnt[i+n][tmp.Y]--;
          if(cnt[i+n][tmp.Y]==0)clrcnt[i+n]--;
          if(clrcnt[i+n]==1)q.push(ii(i+n,fd(i+n))),u[i+n]=1;
        }
      }
      else
      {
        REP(i,n)if(!u[i])
        {
          cnt[i][tmp.Y]--;
          if(cnt[i][tmp.Y]==0)clrcnt[i]--;
          if(clrcnt[i]==1)q.push(ii(i,fd(i))),u[i]=1;
        }
      }
      a.pb(tmp);
    }
    reverse(ALL(a));
    for(ii tmp:a)
    {
      if(tmp.X < n)
      {
          cout<<"row "<<tmp.X+1<<" "<<char(tmp.Y+'a')<<endl;
      }
      else
      {
        cout<<"column "<<tmp.X-n+1<<" "<<char(tmp.Y+'a')<<endl;
      }
    }
}
