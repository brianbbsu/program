//{
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<string>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<sstream>
#include<cmath>

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


const ll MAXn=1e3+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

vector<vector<char> > ans;

vector<char> v[MAXn];

bool vis[MAXn],fin[MAXn];

vector<char> his;

void dfs(char now)
{
  his.pb(now);
  vis[now]=1;
  REP(i,SZ(v[now]))
  {
    if(fin[v[now][i]])continue;
    if(vis[v[now][i]])
    {
      char t=v[now][i];
      ll it=0;
      vector<char> tmp;
      while(his[it]!=t)it++;
      while(it<SZ(his))
      {
        tmp.pb(his[it]);
        it++;
      }
      rotate(tmp.begin(),min_element(ALL(tmp)),tmp.end());
      ans.pb(tmp);
    }
    else dfs(v[now][i]);
  }
  his.pop_back();
  vis[now]=0;
}
vector<char> al;
int main()
{
    IOS();


    char a,b;
    while(cin>>a>>b)
    {
      v[a].pb(b);
      al.pb(a);al.pb(b);
    }
    sort(ALL(al));
    al.resize(unique(ALL(al))-al.begin());
    REP(i,SZ(al))
    {
      dfs(al[i]);
      fin[al[i]]=1;
    }

    sort(ALL(ans));
    if(!SZ(ans))cout<<"不存在迴圈"<<endl;
    else
    {
      cout<<"存在迴圈"<<endl;
      ans.resize(unique(ALL(ans))-ans.begin());
      REP(i,SZ(ans))
      {
        REP(j,SZ(ans[i]))cout<<(j?" ":"")<<ans[i][j];
        cout<<endl;
      }
    }
}
