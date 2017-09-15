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


const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

struct node{
  node *lc,*rc;
  ll d;
  node(ll di,node *lci,node *rci):lc(lci),rc(rci),d(di){}
};

ll mystoi(string a)
{
  stringstream ss(a);
  ll rt;
  ss>>rt;
  return rt;
}
node *build(string s)
{
  if(!SZ(s))return NULL;
  if(s[0]=='(')return build(s.substr(1,SZ(s)-2));
  ll i=0;
  while(s[i]!='(')i++;
  ll t=i,ct=1;
  while(ct)
  {
    t++;
    if(s[t]=='(')ct++;
    else if(s[t]==')')ct--;
  }
  return new node(mystoi(s.substr(0,i)),build(s.substr(i,t-i+1)),build(s.substr(t+1)));
}

node *rt;
ll ans=0;


void dfs(node *now,ll s=0)
{
  if(!now)return;
  s+=now->d;
  ans=max(ans,s);
  dfs(now->lc,s);
  dfs(now->rc,s);
}

int main()
{
    IOS();
    ll T;
    cin>>T;
    ll kz=0;
    while(T--)
    {
      kz++;
      string s="(";
      ans=0;
      char c;
      while(cin>>c&&c!='(');
      ll ct=1;
      while(ct)
      {
        cin>>c;
        if(!isdigit(c)&&c!='('&&c!=')')continue;
        if(c=='(')ct++;
        else if(c==')')ct--;
        s+=" ";
        s[SZ(s)-1]=c;
      }
      rt=build(s);
      dfs(rt);
      map<int,string> mp;
      mp[1]="一";
      mp[2]="二";
      mp[3]="三";
      mp[4]="四";
      mp[5]="五";
      mp[6]="六";
      mp[7]="七";
      mp[8]="八";
      mp[9]="九";
      mp[10]="十";

      cout<<"第"<<mp[kz]<<"棵二元樹最長路徑長度："<<ans<<endl;
    }
}
