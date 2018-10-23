//#include "bigint.h"
#ifndef BIGINT
#define BIGINT
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <iomanip>
class bigint{
typedef unsigned long long ll;

private:
  const ll base=100000000,ln=8;
  std::vector<ll> d;
public:
  bigint(){};
  bigint(ll di);
  bigint(std::string di);
  ~bigint();
  int size()const{
    return (int)d.size();
  }
  void shrink()
  {
    while(d.size()&&!d.back())d.pop_back();
  }
  void resize(int sz)
  {
    d.resize(sz,0);
  }
  bigint &operator = (const bigint &_d)
  {
    d=_d.d;
    return (*this);
  }
  friend std::ostream &operator << (std::ostream&,const bigint&);
  friend std::istream &operator >> (std::istream&,const bigint&);
  ll &operator [](size_t t)
  {
    if(d.size()<=t)d.resize(t+1,0);
    return d[t];
  }
  bigint operator + (const bigint &b)const;
  bigint operator * (const bigint &b)const;
  bool operator < (const bigint &b)const;
  ll get(size_t t)const
  {
    if(d.size()<=t)return 0;
    else return d[t];
  }
};

bigint::bigint(ll di)
{
  while(di>0)
  {
    d.push_back(di%base);
    di/=base;
  }
}

bigint::bigint(std::string di)
{
  std::reverse(di.begin(),di.end());
  ll tmp=0,bs=1;
  for(char c:di)
  {
    tmp=tmp+bs*(c-'0');
    bs*=10;
    if(bs>=base)
    {
      d.push_back(tmp);
      tmp=0;bs=1;
    }
  }
  if(tmp)d.push_back(tmp);
  this->shrink();
}

bigint::~bigint()
{
  d.clear();
  d.shrink_to_fit();
}

std::ostream &operator << (std::ostream &_ss,const bigint &d)
{
  if(!d.size())
  {
    _ss<<"0";
    return _ss;
  }
  _ss<<d.d.back();
  for(int i=d.size()-2;i>=0;i--)_ss<<std::setw(d.ln)<<std::setfill('0')<<d.d[i];
  return _ss;
}

std::istream &operator >> (std::istream &_ss,bigint &d)
{
  std::string s;
  _ss>>s;
  d=bigint(s);
  return _ss;
}

bigint bigint::operator + (const bigint &b)const{
  const bigint &a=(*this);
  bigint rt;
  int t=std::max(a.size(),b.size());
  rt.resize(t+1);
  for(int i=0;i<t;i++)rt[i]=a.get(i)+b.get(i);
  for(int i=0;i<t;i++)if(rt.get(i)>=base)rt[i+1]+=rt[i]/base,rt[i]%=base;
  rt.shrink();
  return rt;
}
bigint bigint::operator * (const bigint &b)const{
  const bigint &a=(*this);
  bigint rt;
  int t=a.size()+b.size();
  rt.resize(t+1);
  for(int i=0;i<a.size();i++)
    for(int j=0;j<b.size();j++)rt[i+j]+=a.get(i)*b.get(j);
  for(int i=0;i<t;i++)if(rt.get(i)>=base)rt[i+1]+=rt[i]/base,rt[i]%=base;
  rt.shrink();
  return rt;
}

bool bigint::operator  < (const bigint &b)const{
  return this->size()>b.size();
}

#endif


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0;i<n;i++)


const ll MAXn=2e4+5,MAXlg=__lg(MAXn)+2;

ll d[2][MAXn];

priority_queue<bigint> pq;

int main()
{
    ll n;
    cin>>n;
    REP(i,2)REP(j,n)cin>>d[i][j];
    sort(d[0],d[0]+n);
    sort(d[1],d[1]+n,greater<ll>());

    REP(i,n)pq.push(bigint(d[0][i]+d[1][i]));

    while(1)
    {
      bigint a=pq.top();
      pq.pop();
      bigint b=pq.top();
      pq.pop();
      if(pq.empty()){
        cout<<a*b<<endl;
        return 0;
      }
      else pq.push(a*b);
    }
}
