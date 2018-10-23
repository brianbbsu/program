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

string _taskname;
void _init()
{
  #ifndef brian
      freopen((_taskname+".in").c_str(), "r", stdin);
      freopen((_taskname+".out").c_str(),"w",stdout);
  #endif
}
void _end()
{
  #ifndef brian
      fclose( stdin);
      fclose(stdout);
  #endif
}

map<ll,ll> ct,d;
set<ii> st;
ll qrx[MAXn],qrid[MAXn],qrdlt[MAXn],qr[MAXn];

int main()
{
  _taskname = "measurement";
  _init();

  ll n,g;
  cin>>n>>g;
  REP(i,n)cin>>qrx[i]>>qrid[i]>>qrdlt[i],st.insert(ii(g,qrid[i])),qr[i]=i,d[qrid[i]]=g;
  sort(qr,qr+n,[](int a,int b){return qrx[a]<qrx[b];});

  st.insert(ii(g,INF));
  ct[g]=SZ(st);

  ll tt=0;
  REP(i,n)
  {
    ll id=qrid[qr[i]],dlt=qrdlt[qr[i]],orgmx=st.rbegin()->X,orgct=ct[orgmx],orgmxid=st.rbegin()->Y;
    ct[d[id]]--;
    st.erase(ii(d[id],id));
    d[id]+=dlt;
    ct[d[id]]++;
    st.insert(ii(d[id],id));
    ll newmx=st.rbegin()->X,newct=ct[newmx],newmxid=st.rbegin()->Y;
    if(orgct==1&&newct==1&&orgmxid==newmxid)continue;
    if(orgmx!=newmx||orgct!=newct)tt++;
  }
  cout<<tt<<endl;

  _end();
}
