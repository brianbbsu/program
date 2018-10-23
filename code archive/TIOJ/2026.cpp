#include<cstdio>
using namespace std;
typedef int ll;
#define REP(i,n) for(ll i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)

const ll MAXn=(1<<20)+1;

inline char readchar()
{
    static const size_t bufsize = 65536;
    static char buf[bufsize];
    static char *p = buf, *end = buf;
    if (p == end) end = buf + fread_unlocked(buf, 1, bufsize, stdin), p = buf;
    return *p++;
}

template <class T> void input(T& a)
{
    static char p;
    while ((p = readchar()) < '0') ;
    a = p ^ '0';
    while ((p = readchar()) >= '0') a *= 10, a += p ^ '0';
}


ll bit[MAXn];
inline void ins(ll x)
{
  while(x<MAXn)
  {
    bit[x]++;
    x+=x&-x;
  }
}
inline ll qr(ll x)
{
  ll p=0,l=(1<<19);
  while(l)
  {
    if(bit[p+l]<=x)x-=bit[p+l],p+=l;
    l>>=1;
  }
  return p+1;
}

int main()
{
    ll q,x,tt=0;
    input(q);
    while(q--)
    {
      input(x);
      if(x&1)
      {
        input(x);
        tt++;
        ins(x);
      }
      else printf("%d\n",qr(tt>>1));
    }

}
