#include <cstdio>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int now=0;
    for(int i=2;i<=n;i++)
    {
      if(now==0)now=i-1;
      //now=(now-1+i)%i;
      now--;
      if(now<0)now+=i;
    }
    printf("%d\n",(-now+n)%n+1);
}
