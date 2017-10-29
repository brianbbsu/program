#include <cstdio>
#include <cstring>
#include <cstdlib>

const int MAXn=1e5+5;
int bkt[MAXn];
#define isLMS(T) (t[(T)]&&!t[(T)-1])

void sais(int *s,int *sa,int n,int sigma,int *t,int *p,int *s1)
{
  int pit=0,*ct,prv=-1,nit=-1;
  ct=(int *)malloc(sizeof(int)*(sigma+1));
  memset(ct,0,sizeof(int)*(sigma+1));

  t[n-1]=1;
  for(int i=n-2;i>=0;i--)t[i]=(s[i]<s[i+1]?1:(s[i]==s[i+1]?t[i+1]:0));
  for(int i=1;i<=n-1;i++)if(isLMS(i))p[pit++]=i;
  for(int i=0;i<n;i++)ct[s[i]+1]++;
  for(int i=1;i<=sigma;i++)ct[i]+=ct[i-1];

  memset(sa,-1,sizeof(int)*n);
  memcpy(bkt,ct+1,sizeof(int)*sigma);
  for(int i=0;i<pit;i++)sa[--bkt[s[p[i]]]]=p[i];
  memcpy(bkt,ct,sizeof(int)*sigma);
  for(int i=0;i<n;i++)if(sa[i]>0&&!t[sa[i]-1])sa[bkt[s[sa[i]-1]]++]=sa[i]-1;
  memcpy(bkt,ct+1,sizeof(int)*sigma);
  for(int i=n-1;i>=0;i--)if(sa[i]>0&&t[sa[i]-1])sa[--bkt[s[sa[i]-1]]]=sa[i]-1;

  for(int i=0;i<n;i++)
  {
    if(sa[i]==0||!isLMS(sa[i]))continue;
    bool diff=0;
    for(int d=0;;d++)
      if(prv==-1||s[sa[i]+d]!=s[prv+d]||t[sa[i]+d]!=t[prv+d]){diff=1;break;}
      else if(d&&(isLMS(sa[i]+d)||isLMS(prv+d)))break;
    prv=sa[i];
    if(diff)s1[sa[i]]=++nit;
    else s1[sa[i]]=nit;
  }
  nit++;
  for(int i=0;i<pit;i++)s1[i]=s1[p[i]];

  int *sa1=s1+n-pit;
  if(nit<pit)sais(s1,sa1,pit,nit,sa+n-pit,p+n-pit,sa);
  else for(int i=0;i<pit;i++)sa1[s1[i]]=i;

  memset(sa,-1,sizeof(int)*n);
  memcpy(bkt,ct+1,sizeof(int)*sigma);
  for(int i=pit-1;i>=0;i--)sa[--bkt[s[p[sa1[i]]]]]=p[sa1[i]];
  memcpy(bkt,ct,sizeof(int)*sigma);
  for(int i=0;i<n;i++)if(sa[i]>0&&!t[sa[i]-1])sa[bkt[s[sa[i]-1]]++]=sa[i]-1;
  memcpy(bkt,ct+1,sizeof(int)*sigma);
  for(int i=n-1;i>=0;i--)if(sa[i]>0&&t[sa[i]-1])sa[--bkt[s[sa[i]-1]]]=sa[i]-1;
  free(ct);
}
int s[MAXn],sa[MAXn],t[MAXn],p[MAXn],s1[MAXn];
int main()
{
    char tmps[MAXn];
    fgets(tmps,MAXn,stdin);
    int n=strlen(tmps);
    for(int i=0;i<n;i++)s[i]=tmps[i];
    sais(s,sa,n,128,t,p,s1);
    for(int i=1;i<n;i++)printf("%d\n",sa[i]);
}
