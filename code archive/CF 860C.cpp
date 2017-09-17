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

string its[2*MAXn];


vector<string> d[2];

set<string> st[2],tst[2],tmpst;

vector<string> dt[2][2];//to 0 or to 1 / inside another?

void mv(string a,string b)
{
  cout<<"move"<<" "<<a<<" "<<b<<endl;
}



int main()
{
    IOS();
    REP1(i,2*MAXn-1)
    {
      stringstream ss("");
      ss<<i;
      ss>>its[i];
    }
    ll n;
    cin>>n;
    REP(i,n)
    {
      string s;
      cin>>s;
      ll t;
      cin>>t;
      d[!t].pb(s);
    }
    REP1(i,SZ(d[0]))st[0].insert(its[i]),tst[0].insert(its[i]);
    REP1(i,SZ(d[1]))st[1].insert(its[i+SZ(d[0])]),tst[1].insert(its[i+SZ(d[0])]);

    REP(k,2)
    {
      REP(i,SZ(d[k]))
      {
        if(st[k].count(d[k][i]))
        {
          st[k].erase(d[k][i]);
          continue;
        }
        if(tst[!k].count(d[k][i]))dt[k][1].pb(d[k][i]);
        else dt[k][0].pb(d[k][i]);
      }
    }

    REP(i,2)REP(j,2)debug(i,j,SZ(dt[i][j]),dt[i][j]);
    debug(st[0],st[1]);

    ll cc=min(SZ(dt[0][1]),SZ(dt[1][1]));

    cout<<SZ(st[0])+SZ(st[1])+(cc?1:0)<<endl;

    if(cc)
    {
      for(int i=n+1;i<=2*n+3;i++)tmpst.insert(its[i]);
      for(string &s:d[0])tmpst.erase(s);
      for(string &s:d[1])tmpst.erase(s);
      mv(dt[0][1][0],*tmpst.begin());
      REP(i,cc-1)
      {
        mv(dt[1][1][i],dt[0][1][i]);
        mv(dt[0][1][i+1],dt[1][1][i]);
      }
      mv(dt[1][1][cc-1],dt[0][1][cc-1]);
      mv(*tmpst.begin(),dt[1][1][cc-1]);
      REP(i,cc)st[0].erase(dt[1][1][i]),st[1].erase(dt[0][1][i]);
    }
    REP(k,2)for(int i=cc;i<SZ(dt[k][1]);i++)
    {
      mv(dt[k][1][i],*st[k].begin());
      st[k].erase(*st[k].begin());
    }
    REP(k,2)for(int i=0;i<SZ(dt[k][0]);i++)
    {
      mv(dt[k][0][i],*st[k].begin());
      st[k].erase(*st[k].begin());
    }
    debug(st[0],st[1]);
}
