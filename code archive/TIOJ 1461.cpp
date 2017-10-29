#include<cstdio>

char s[10000005],*it;

int main()
{
    //IOS();
    int n,m;
    while(scanf("%d %d\n",&n,&m)&&n)
    {
      it=s;
      while(n--)
      {
        fgets(it,103,stdin);
        while((*it)>='A')it++;
      }
      int t;
      while(m--)
      {
        scanf("%d",&t);
        putchar(s[t-1]);
      }
      puts("");
    }
}
