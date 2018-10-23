//{
#include<cstdio>
using namespace std;
typedef int ll;



int main()
{
  ll a,b,c,d,e,f;
  scanf("%d:%d:%d",&a,&b,&c);
  scanf("%d:%d:%d",&d,&e,&f);
  a=(60*a+b)*60+c;
  d=(60*d+e)*60+f;
  d-=a;
  if(d<=0)d+=86400;
  c=d%60;
  a=d/3600;
  b=(d-3600*a)/60;
  printf("%02d:%02d:%02d\n",a,b,c);

}
