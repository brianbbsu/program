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


const ll MAXn=90+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

struct EnergySource{
  set<vector<ll> > st;
  queue<vector<ll> > q;
  vector<long long> countDifferentSources(int number){
    ll ct = 1,prodsum = number;
    q.push({number});
    st.insert({number});
    while(SZ(q))
    {
      auto now = q.front();q.pop();
      REP(i,SZ(now))if(i==0||now[i]!=now[i-1])for(int j = 2;j<=now[i];j++)if(now[i] % j == 0)
      {
        vector<ll> tmp;
        REP(k,SZ(now))if(k!=i)tmp.pb(now[k]);
        REP(k,j)tmp.pb(now[i]/j);
        sort(ALL(tmp));
        if(!st.count(tmp))
        {
          st.insert(tmp);
          q.push(tmp);
          ll prod = 1;
          for(ll k:tmp)prod *= k;
          ct++;
          prodsum += prod;
        }
      }
    }
    return vector<ll>({ct,prodsum});
  }

};

#ifdef brian
int main(){
  EnergySource e;
  debug(e.countDifferentSources(13));
  for(auto v: e.st)debug(v);

}

#endif
