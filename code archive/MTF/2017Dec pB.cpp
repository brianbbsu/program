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

vector<vector<int> > dt;
map<ll,ll> mp;

ll cal(vector<int> &a)
{
  ll k=1,rt=0;
  for(int i=0;i<8;i++)rt+=k*a[i],k*=10;
  return rt;
}
ll d[20];
int main()
{
    IOS();

    vector<int> pm;
    REP(i,8)pm.pb(i);
    do{
        dt.pb(pm);
    }while(next_permutation(ALL(pm)));
    sort(ALL(dt));
    mp[cal(pm)]=1;

    for(auto &now:dt)
    {
      bool b=1;
      if(mp[cal(now)]>1)b=0;
      REP(i,7)
      {
        if(now[i]<now[i+1])
        {
          vector<int> tmp=now;
          swap(tmp[i],tmp[i+1]);
          ll t=cal(tmp);
          if(b)mp[t]++;
          else mp[t]=INF;
        }
      }
    }

    ll T;
    cin>>T;
    while(T--)
    {
      ll n;
      cin>>n;
      vector<int> tmp;
      REP(i,n){
        ll t;
        cin>>t;
        tmp.pb(t-1);
      }
      for(int i=n;i<8;i++)tmp.pb(i);
      ll t=cal(tmp);
      if(mp[t]==1)cout<<"Y"<<endl;
      else cout<<"N"<<endl;
    }
}
