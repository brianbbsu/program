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


const ll MAXn=3e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);


ii d[MAXn];

set<pair<ii,ll> > st;
ll v[MAXn];
vector<ii> op[MAXn];
ll n,k;

void pre()
{
  REP1(i,n)
  {
    while(1)
    {
      auto it = st.lower_bound({{d[i].Y,d[i].Y},-1});
      if(it == st.begin())break;
      it = prev(it);
      if(it -> X.Y <= d[i].X)break;
      else if(it -> X.X >= d[i].X && it -> X.Y >= d[i].Y){
        ii tmp = {d[i].Y,it->X.Y};
        op[i].pb(ii(it->Y,-(d[i].Y - it->X.X)));
        if(tmp.X != tmp.Y)st.insert({tmp,it->Y});
      }else if(it -> X.X <= d[i].X && it -> X.Y <= d[i].Y){
        ii tmp = {it->X.X,d[i].X};
        op[i].pb(ii(it->Y,-(it->X.Y - d[i].X)));
        if(tmp.X != tmp.Y)st.insert({tmp,it->Y});
      }else if(it -> X.X <= d[i].X && it -> X.Y >= d[i].Y){
        ii tmp1 = {d[i].Y,it->X.Y};
        ii tmp2 = {it->X.X,d[i].X};
        op[i].pb(ii(it->Y,-(d[i].Y - d[i].X)));
        if(tmp1.X != tmp1.Y)st.insert({tmp1,it->Y});
        if(tmp2.X != tmp2.Y)st.insert({tmp2,it->Y});
      }else {
        op[i].pb(ii(it->Y,-(it->X.Y - it->X.X)));
      }
      st.erase(it);
    }
    op[i].pb(ii(i,d[i].Y - d[i].X));
    st.insert({d[i],i});
  }
}


int main()
{
    IOS();
    cin>>n>>k;
    REP1(i,n)cin>>d[i].X>>d[i].Y;
    pre();
    ll l = 0,r = 0;
    REP1(i,n)r = max(r,d[i].Y);
    r+=1;
    while(l != r-1)
    {
      ll h = (l+r)/2;
      ll it = 0,tt = 0,now = 0,sum = 0,ctsum = 0;
      REP(i,n+1)v[i]=0;
      REP1(i,n)
      {
        for(ii tmp:op[i])
        {
          if(tmp.X >= it)now += tmp.Y,v[tmp.X]+=tmp.Y;
          tt += min(it,tmp.X) * tmp.Y;
        }
        while(it != n)
        {
          now -= v[it];
          v[it] = 0;
          if(now >= h)tt += now,it ++;
          else break;
        }
        sum += tt;
        ctsum += it;
      }
      if(ctsum < k)r = h;
      else l = h;
    }
    ll it = 0,tt = 0,now = 0,sum = 0,ctsum = 0;
    REP(i,n+1)v[i]=0;
    REP1(i,n)
    {
      for(ii tmp:op[i])
      {
        if(tmp.X >= it)now += tmp.Y,v[tmp.X]+=tmp.Y;
        tt += min(it,tmp.X) * tmp.Y;
      }
      while(it != n)
      {
        now -= v[it];
        v[it] = 0;
        if(now >= l)tt += now,it ++;
        else break;
      }
      sum += tt;
      ctsum += it;
    }
    cout<< sum - (ctsum - k) * l <<endl;

}
