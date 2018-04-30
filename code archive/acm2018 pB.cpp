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


const ll MAXn=1e6+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

unordered_map<string,int> mp;
string dt[MAXn];

vector<ii> d;

ll g[2*MAXn];
ll fd(ll x){return g[x] = (g[x] == x?x:fd(g[x]));}
void mg(ll a,ll b){g[fd(a)] = fd(b);}

ll f[MAXn],b[MAXn],a[2*MAXn];

int main()
{
    IOS();
    REP(i,2*MAXn)g[i]=i;
    string s;
    while(cin>>s)
    {
      ll fg=0;
      if(s.back() == ',')fg=1,s.pop_back();
      else if(s.back() == '.')fg = 2,s.pop_back();
      auto it = mp.find(s);
      ll t;
      if(it == mp.end())
      {
        t = SZ(mp);
        dt[t] = s;
        mp[s] = t;
      }
      else t = it->Y;
      if(SZ(d)&&d.back().Y!=2)mg(2*d.back().X+1,2*t);
      if(SZ(d)&&d.back().Y==1)f[t] = 1;
      if(fg==1)b[t] = 1;
      d.pb(ii(t,fg));
    }
    REP(i,SZ(mp))
    {
      if(f[i])a[fd(2*i)]=1;
      if(b[i])a[fd(2*i+1)]=1;
    }
    REP(i,SZ(d))
    {
      cout<<dt[d[i].X];
      if(d[i].Y==2)cout<<'.';
      else if(a[fd(2*d[i].X+1)])cout<<',';
      if(i!=SZ(d)-1)cout<<" ";
    }
    cout<<endl;
}
