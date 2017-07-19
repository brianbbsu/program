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

ll d[MAXn][6];
bool tp[MAXn];

vector<lf> ans,pt;
ll bst=INF;
vector<lf> tmp;
ll n=0,mx=0,mn=INF;

bool cal(ll t)
{

    ll ct[2][2];
    FILL(ct,0);

    REP(i,n)
    {
      lf tt=0;
      REP(j,5)tt+=tmp[j]*lf(d[i][j]-d[t][j]);
      if(tt<=0)ct[tp[i]][0]++;
      else ct[tp[i]][1]++;
    }
    ll a=min(ct[0][0]+ct[1][1],ct[0][1]+ct[1][0]);
    if(a<=bst)
    {
      bst=a;
      ans=tmp;
      pt.clear();
      REP(i,5)pt.pb(d[t][i]);
      return 1;
    }
    return 0;
}

int main()
{
    IOS();

    

    srand(time(0));

    while(cin>>d[n][0])
    {
      REP1(i,4)cin>>d[n][i];
      cin>>tp[n];
      REP(i,5)mx=max(mx,d[n][i]),mn=min(mn,d[n][i]);
      n++;
    }
    debug(n,mx,mn);

    const ll MAXc=210;
    lf dlt=100;

    ans.pb(1);
    REP(i,4)ans.pb(lf(rand()%(2*100*MAXc)-100*MAXc)/100.0);

    REP(T,MAXn/10)
    {
      tmp=ans;
      ll t=rand()%4+1;
      dlt=rand()%100+1;
      if(rand()%2)tmp[t]+=dlt;
      else tmp[t]-=dlt;
      //REP(i,4)tmp.pb(lf(rand()%(2*100*MAXc)-100*MAXc)/100.0);
      bool b=0;
      REP(i,n)b|=cal(i);
      //if(b)dlt=max(dlt-5,5.0);
    }
    debug(bst,ans,pt,dlt);
}
