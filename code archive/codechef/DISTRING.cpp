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


const ll MAXn=5e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD1=1000000093,MOD2 = 1000000097,bs = 1000000033;
const ll INF=ll(1e15);

vector<vector<ll> > d;
vector<ii> hs[MAXn];

ii sub(ii a,ii b)
{
  ii rt = ii(a.X - b.X,a.Y - b.Y);
  if(rt.X < 0)rt.X += MOD1;
  if(rt.Y < 0)rt.Y += MOD2;
  return rt;
}

const ll TH = 150;

int main()
{
    IOS();
    ll n,m;
    cin>>n>>m;
    //assert(5 * m <= n);
    d.resize(n+1,vector<ll>(m+1));
    REP1(i,n)REP1(j,m)cin>>d[i][j];
    REP1(i,n)hs[i].resize(m+1);
    REP1(i,n)
    {
      hs[i][0] = ii(0,0);
      ll tmp1 = 1,tmp2 = 1;
      REP1(j,m)
      {
        hs[i][j].X = (tmp1 * d[i][j] + hs[i][j-1].X)%MOD1;
        hs[i][j].Y = (tmp2 * d[i][j] + hs[i][j-1].Y)%MOD2;
        tmp1 = tmp1 * bs % MOD1;
        tmp2 = tmp2 * bs % MOD2;
      }
    }
    ll tt = 0;
    if(m <= TH)
    {
      for(int i = 1;i<=m;i++)for(int j = i;j<=m;j++)
      {
        unordered_map<ll,ll> mp;
        REP1(k,n)
        {
          ii tmp = sub(hs[k][j],hs[k][i-1]);
          ll p = tmp.X * MOD2 + tmp.Y;
          auto it = mp.insert({p,k});
          if(it.Y)tt += k * (n - k + 1);
          else
          {
            ll x = it.X->Y;
            tt += (k - x) * (n - k + 1);
            it.X->Y = k;
          }
          debug(i,j,k,*(it.X),it.Y,tt);
        }
      }
    }
    else{
      for(int i = 1;i<=n;i++)
      {
        vector<ll> lst;
        lst.resize(m+1,0);

        tt += m * (m+1) / 2 * (n - i + 1);
        debug(i,tt);
        for(int j = i - 1;j > 0;j--)
        {
          ll it = 0;
          REP1(k,m)
          {
            if(k > it)
            {
              it ++;
              while(it <= m && d[j][it] == d[i][it])it++;
            }
            lst[k] = max(lst[k],it);
            tt += (m + 1 - lst[k]) * (n - i + 1);
            debug(i,j,k,it,tt);
          }
        }
      }
      //assert(0);
    }
    cout<<tt<<endl;

}
