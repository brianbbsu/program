#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
#define REP(i,n) for(ll i=0;i<n;i++)
#define FILL(i,n) memset(i,n,sizeof i)
#define X first
#define Y second
#define pb push_back

const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;

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
void ins(ll x)
{
  while(x < MAXn)bit[x]++,x+=x&-x;
}
int qr(ll x)
{
  ll ret = 0;
  while(x > 0)ret += bit[x],x-=x&-x;
  return ret;
}

vector<ll> stk;

ll a[MAXn],b[MAXn],c[MAXn];
ii d[MAXn];

int main()
{
    ll n;
    while(1)
    {
      input(n);
      if(n==0)break;
      stk.clear();
      REP(i,n)
      {
        input(a[i]);
        input(b[i]);
        input(c[i]);
        d[i] = ii(b[i],i);
      }
      sort(d,d+n);
      FILL(bit,0);
      ll it = 0,tt = 0;
      REP(i,n)
      {
        while(it < d[i].X)stk.pb(++it);
        ll t = d[i].Y;
        ll tmp = qr(b[t]) - qr(a[t]);
        while(tmp < c[t])
        {
          ll x = stk.back();
          stk.pop_back();
          ins(x);
          tt++;
          tmp++;
        }
      }
      printf("%d\n",tt);
    }
}
