//{
#include<bits/stdc++.h>
#include "lib2000.h"
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
typedef pos_type pt;
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
const lf EPS=1e-6;

ostream& operator << (ostream &_s,const pos_type &_p){return _s<<"("<<_p.x<<","<<_p.y<<")";}



const double pi = 3.14159265359;
lf cal_ang(pos_type &a,pos_type &b)
{
  lf ang;
  pos_type dlt={b.x-a.x,b.y-a.y};
  /*
  if(fabs(dlt.x*dlt.y)<=EPS)
  {
    if(dlt.x>EPS)ang=0;
    else if(dlt.x<-EPS)ang=pi;
    else ang=pi/2;
  }
  else ang=atan(dlt.y/dlt.x);
  if(dlt.y<-EPS)ang+=pi;
  return ang;*/
  lf lth=sqrt(dlt.x*dlt.x+dlt.y*dlt.y);
  if(lth<1e-9)return 0;
  else if(dlt.y>=0)return acos(dlt.x/lth);
  else return 2*pi-acos(dlt.x/lth);
}
void init()
{
  srand(time(0));
  /*while(1)
  {
    pos_type a,b;
    cin>>a.x>>a.y>>b.x>>b.y;
    debug(a,b,cal_ang(a,b));
  }*/
}

ll ct=0;

lf sqdis(pt &a,pt &b)
{
  return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

bool in_rg(pos_type &a,pos_type &b)
{
  const ll mxrg=5;
  return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)<=mxrg*mxrg;
}

pos_type lt={49.0,25.0};

lf ang;

pos_type play()
{

  ct++;
  if(ct==1)return {50.0,25.0};
  //lf rat=250.0,r=15.0;
  auto now=get_pos();
  auto balls=get_ball();

  if(now.x<0.02)lt.x=-0.01;
  if(now.y<0.02)lt.y=-0.01;
  if(now.x>99.98)lt.x=100.01;
  if(now.y>49.98)lt.y=50.01;

  ang=cal_ang(lt,now);

  //if(sqdis(lt,now)<=0.2*0.2)ang+=pi;


  debug(ang,lt,now);
  lt=now;

  vector<pos_type> dt;

  dt.pb({now.x+cos(ang)*0.5,now.y+sin(ang)*0.5});

  for(lf tmp=-0.3;tmp-EPS<0.3;tmp+=0.1)
  {
    dt.pb({now.x+cos(ang+tmp)*0.8,now.y+sin(ang+tmp)*0.8});
  }
  for(auto &tmp:dt)
  {
    if(tmp.x<0)tmp.x=0;
    if(tmp.x>100)tmp.x=100;
    if(tmp.y<0)tmp.y=0;
    if(tmp.y>50)tmp.y=50;
  }
  debug(cal_ang(now,dt[1]));
  debug(dt);

  //now={now.x+cos(ang)*0.8,now.y+sin(ang)*0.8};

  lf bst=INF;
  pt dd;

  for(auto &tmp:dt)
  {
    lf tt=0,r=3;
    for(auto &b:balls)if(sqdis(tmp,b)<=r*r)
    {
      lf tmpdis=sqrt(sqdis(tmp,b));
      tt+=(r-tmpdis)*(r-tmpdis);
    }
    if(tt<bst)bst=tt,dd=tmp;
  }

  now=dd;

  return now;
  //return (pos_type){50.0+r*sin(2.0*pi*ct/rat),25.0+r*cos(2.0*pi*ct/rat)};
  //return (pos_type){rand()%10000/100.0,rand()%5000/100.0};

}
