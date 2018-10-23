#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(ll i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)

const ll MAXn=1e6+5;
#include "lib1820.h"

int d[MAXn];

int main()
{
    REP1(i,MAXn-1){
      if(i%2==1)d[i]=i;
      else d[i]=d[i/2];
    }
    ll p = 4;
    while(p<MAXn){
      d[p]=p/2;
      p*=4;
    }
    ll n = initial();
    if(n%2==1||d[n]==1)n-=first(false);
    else first(true);
    while(1){
      ll t = play_with_loli(d[n]);
      n-=d[n]+t;
    }
}
