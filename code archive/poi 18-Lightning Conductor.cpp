//{
#include<bits/stdc++.h>
using namespace std;
typedef int ll;
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
const ll MOD=1000000007;
const ll INF=ll(2e9);

#define sq(x) ((x)*(x))

ll n,d[MAXn],p[2][MAXn],itl=0,itr=0;
ii dt[MAXn],dq[MAXn];

void cal(ll *f)
{
  itl=itr=0;
  REP(i,n)
  {
    if(itr-itl)
    {
      while(1)
      {
        ll t = dq[itr-1].X;
        ll l=i-1,r=n;
        while(l!=r-1)
        {
          ll h=(l+r)/2;
          if(dt[h-i].X+d[i]>dt[h-t].X+d[t])r=h;
          else if(dt[h-i].X+d[i]==dt[h-t].X+d[t]&&dt[h-i].Y<=dt[h-t].Y)r=h;
          else l=h;
        }
        if(r<=dq[itr-1].Y)itr--;
        else{
          dq[itr++]=ii(i,r);
          break;
        }
      }
    }
    else dq[itr++]=ii(i,-INF);
    while(itr-itl>1&&i>=dq[itl+1].Y)itl++;
    f[i]=dt[i-dq[itl].X].X+d[dq[itl].X]-d[i];
  }
}

int main()
{
    IOS();
    dt[0]=ii(0,0);
    REP1(i,MAXn-1)
    {
      if(dt[i-1].Y)dt[i]=ii(dt[i-1].X,dt[i-1].Y-1);
      else dt[i]=ii(dt[i-1].X+1,sq(dt[i-1].X+1)-sq(dt[i-1].X)-1);
    }
    cin>>n;
    REP(i,n)cin>>d[i];
    cal(p[0]);
    reverse(d,d+n);
    cal(p[1]);
    REP(i,n)cout<<max(p[0][i],p[1][n-i-1])<<endl;
}
