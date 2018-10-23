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


const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

queue<ll> q;

ll cal(vector<vector<int> > &d,ll n,ll m,ll k,bool t)
{
  while(SZ(q))q.pop();
  ll rt=0;
  REP(i,n)
  {
    while(SZ(q)&&q.front()<=i-k)q.pop();
    if(i+k<=n&&((SZ(q)%2)^d[i][0])!=t)q.push(i),rt++;
    if(SZ(q)%2==1)REP(j,m)d[i][j]=!d[i][j];
  }
  while(SZ(q))q.pop();
  REP(j,m)
  {
    while(SZ(q)&&q.front()<=j-k)q.pop();
    if(j+k<=m&&!((SZ(q)%2)^d[0][j]))q.push(j),rt++;
    if(SZ(q)%2==1)REP(i,n)d[i][j]=!d[i][j];
  }
  REP(i,n)REP(j,m)if(!d[i][j])return INF;
  return rt;
}

vector<vector<int> > d,dbk;
ll n,m,k;

int main()
{
    IOS();
    ll T;
    cin>>T;
    while(T--&&cin>>n>>m>>k)
    {
      d.resize(n,vector<int>(m));
      dbk.resize(n,vector<int>(m));
      REP(i,n)
      {
        string s;
        cin>>s;
        REP(j,m)d[i][j]=(s[j]=='+'),dbk[i][j]=d[i][j];

      }
      ll a=min(cal(d,n,m,k,1),cal(dbk,n,m,k,0));
      if(a==INF)cout<<"QAQ"<<endl;
      else cout<<a<<endl;

    }

}
