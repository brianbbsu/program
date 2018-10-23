//{
#include<cstdio>

typedef int ll;

#define REP(i,n) for(ll i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)



const ll MAXn=1e4+5;


ll ct[MAXn],d[MAXn],g[MAXn];


int main()
{
    ll n,k;
    scanf("%d %d",&n,&k);
    REP(i,n)scanf("%d",d+i);
    REP(i,n)scanf("%d",g+i);
    ll now=0,tt=0;
    REP(i,n)
    {
      if(i>=k)now-=ct[i-k];
      if(now<0)now+=9;
      if(i+k<=n)
      {
        ct[i]=(g[i]-now-d[i]);
        if(ct[i]<0){ct[i]+=9;
        if(ct[i]<0)ct[i]+=9;}
        now+=ct[i];
        if(now>8)now-=9;
      }
      d[i]=d[i]+now;
      if(d[i]>9)d[i]-=9;
      if(d[i]!=g[i])
      {
        puts("0");
        return 0;
      }
      tt+=ct[i];
    }
    printf("%d\n",tt);

}
