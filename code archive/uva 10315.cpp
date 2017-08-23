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

struct val{
  vector<ll> d;
  ll tp;
}p[2];

vector<ll> d[2];

map<char,int> mp;

void cal(vector<ll> dt,val &v,bool sc)
{
  bool strt=1;
  REP1(i,4)if(dt[i]!=dt[i-1]+1)strt=0;
  if(strt||sc)
  {
    v.d=dt;
    sort(ALL(v.d),greater<ll>());
    if(sc&&strt)v.tp=8;
    else if(sc) v.tp=5;
    else v.tp=4;
  }
  do{
    if(dt[0]==dt[1]&&dt[1]==dt[2]&&dt[2]==dt[3])//7
    {
      if(v.tp>=7)continue;
      v.tp=7;
      v.d=dt;
    }
    else if(dt[0]==dt[1]&&dt[1]==dt[2]&&dt[3]==dt[4])//6
    {
      if(v.tp>=6)continue;
      v.tp=6;
      v.d=dt;
    }
    else if(dt[0]==dt[1]&&dt[1]==dt[2])//3
    {
      if(v.tp>=3)continue;
      v.tp=3;
      v.d=dt;
    }
    else if(dt[0]==dt[1]&&dt[2]==dt[3])//2
    {
      if(v.tp>=2)continue;
      v.tp=2;
      v.d=dt;
      sort(v.d.begin(),v.d.begin()+4,greater<ll>());
    }
    else if(dt[0]==dt[1])//1
    {
      if(v.tp>=1)continue;
      v.tp=1;
      v.d=dt;
      sort(v.d.begin()+2,v.d.begin()+5,greater<ll>());
    }
  }while(next_permutation(ALL(dt)));
}

void cmp()
{
  REP(i,5)
  {
    if(p[0].d[i]>p[1].d[i])cout<<"Black wins."<<endl;
    else if(p[0].d[i]<p[1].d[i])cout<<"White wins."<<endl;
    else continue;
    return;
  }
  cout<<"Tie."<<endl;
}

int main()
{
    IOS();
    REP1(i,8)mp[i+1+'0']=i+1;
    mp['T']=10;mp['J']=11;mp['Q']=12;
    mp['K']=13;mp['A']=14;

    string s;
    while(getline(cin,s))
    {
      stringstream ss(s);
      d[0].resize(5);
      d[1].resize(5);
      bool sc[2]={1,1};
      char clr[2];
      REP(i,2)REP(j,5)
      {
        string tmp;
        ss>>tmp;
        debug(tmp);
        d[i][j]=mp[tmp[0]];
        if(!j)clr[i]=tmp[1];
        else if(tmp[1]!=clr[i])sc[i]=0;
      }
      REP(i,2)sort(ALL(d[i]),greater<ll>());
      REP(i,2)p[i].tp=0,p[i].d=d[i];
      REP(i,2)reverse(ALL(d[i]));
      REP(i,2)cal(d[i],p[i],sc[i]);
      if(p[0].tp>p[1].tp)cout<<"Black wins."<<endl;
      else if(p[0].tp<p[1].tp)cout<<"White wins."<<endl;
      else cmp();
      debug(p[0].tp,p[0].d,p[1].tp,p[1].d);
    }
}
