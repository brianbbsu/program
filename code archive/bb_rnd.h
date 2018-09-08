#ifndef BB_RND
#define BB_RND
#include <cassert>
#include <random>
#include <vector>
#include <algorithm>
#include <limits>
#include <string>
using namespace std;
struct bb_rnd{
  random_device rdseed;
  mt19937 rd_engine;
  bb_rnd(){
    rd_engine=mt19937(rdseed());
  }
  inline int operator () (int l,int r,int w=0)//[l,r),range = int_min~int_max, w > 0 max, w < 0 min
  {
    assert(l<r);
    if(w < 0)
    {
      w = -w;
      int ret = r-1;
      for(int i=0;i<w;i++)ret = min(ret, (*this)(l,r));
      return ret;
    }
    else if(w > 0)
    {
      int ret = l;
      for(int i=0;i<w;i++)ret = max(ret, (*this)(l,r));
      return ret;
    }
    uniform_int_distribution<int> rnd_dist(l,r-1);
    return rnd_dist(rd_engine);
  }
  template<typename T>
  inline typename iterator_traits<T>::value_type pick(T _s,T _t)
  {
    assert(_t-_s > 0);
    return *(_s+(*this)(0,_t-_s));
  }
  inline char pick(const string charset){
    return (*this).pick(charset.begin(),charset.end());
  }
  template<typename T>
  inline T pick(const vector<T> _t){
    return (*this).pick(_t.begin(),_t.end());
  }
  template<typename T>
  void bb_shuffle(T a,T b){
    random_shuffle(a,b,[&](int i){return (*this)(0,i);});
  }
}rnd;
#endif
