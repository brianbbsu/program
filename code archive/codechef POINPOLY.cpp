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

vector<ii> tp,dw;
set<ii> st;

inline bool crs(ii a,ii b){ //True if a cross b > 0
  return (a.X*b.Y-a.Y*b.X)>0;
}

ll n,g;
bool chk(ii p)
{
  REP(i,SZ(tp)-1)if(!crs(ii(tp[i+1].X-tp[i].X,tp[i+1].Y-tp[i].Y),ii(p.X-tp[i].X,p.Y-tp[i].Y)))return 0;
  REP(i,SZ(dw)-1)if(!crs(ii(dw[i+1].X-dw[i].X,dw[i+1].Y-dw[i].Y),ii(p.X-dw[i].X,p.Y-dw[i].Y)))return 0;
  if(g&&!st.count(p))
  {
    st.insert(p);
    g--;
    return 1;
  }
  return 0;
}

int main()
{
    IOS();
    ll T,tmpT;
    cin>>T;tmpT=T;
    while(T--)
    {
      tp.clear();dw.clear();
      cin>>n;
      g=n/10;
      REP(i,n)
      {
        ll a,b;
        cin>>a>>b;
        tp.pb(ii(a,b));
      }
      ll mnid=min_element(ALL(tp))-tp.begin();
      ll mxid=max_element(ALL(tp))-tp.begin();
      dw=tp;
      rotate(tp.begin(),tp.begin()+mxid,tp.end());
      rotate(dw.begin(),dw.begin()+mnid,dw.end());
      if(mnid<mxid)tp.resize(n-(mxid-mnid-1)),dw.resize(mxid-mnid+1);
      else dw.resize(n-(mnid-mxid-1)),tp.resize(mnid-mxid+1);
      debug(tp,dw);
      st.clear();
      if(!g)continue;
      bool fg=(tmpT<=100&&n<=100);
      for(int i=1;i<SZ(dw)&&g;i++)
      {
        if(fg)
        {
          ll x=dw[i].X,y=dw[i].Y;
          chk(ii(x,y+1));
          chk(ii(x+1,y+1));
          chk(ii(x-1,y+1));
          chk(ii(x-1,y));
          chk(ii(x+1,y));
          continue;
        }
        ii tmp=ii(dw[i].X,dw[i].Y+1);
        if(tmp.X==tp[0].X||tmp.X==tp.back().X)continue;
        ll t=lower_bound(ALL(tp),tmp,greater<ii>())-tp.begin();
        if(t==0)continue;
        t--;
        //assert(tmp.X<=tp[t].X&&tmp.X>=tp[t+1].X);
        if(crs(ii(tp[t+1].X-tp[t].X,tp[t+1].Y-tp[t].Y),ii(tmp.X-tp[t].X,tmp.Y-tp[t].Y))&&!st.count(tmp))st.insert(tmp),g--;
      }
      for(int i=1;i<SZ(tp)&&g;i++)
      {
        if(fg)
        {
          ll x=dw[i].X,y=dw[i].Y;
          chk(ii(x,y-1));
          chk(ii(x+1,y-1));
          chk(ii(x-1,y-1));
          chk(ii(x-1,y));
          chk(ii(x+1,y));
          continue;
        }
        ii tmp=ii(tp[i].X,tp[i].Y-1);
        if(tmp.X==tp[0].X||tmp.X==tp.back().X)continue;
        ll t=lower_bound(ALL(dw),tmp)-dw.begin();
        if(t==0)continue;
        t--;
        //assert(tmp.X>=dw[t].X&&tmp.X<=dw[t+1].X);
        if(crs(ii(dw[t+1].X-dw[t].X,dw[t+1].Y-dw[t].Y),ii(tmp.X-dw[t].X,tmp.Y-dw[t].Y))&&!st.count(tmp))st.insert(tmp),g--;
      }
      debug(fg);
      if(g)
      {
        cout<<-1<<endl;
        continue;
      }
      for(ii tmp:st)cout<<tmp.X<<" "<<tmp.Y<<endl;
    }
}
