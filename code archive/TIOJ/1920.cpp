#include<cstdio>
#define REP(i,n) for(int i=0;i<n;i++)

const int MAXn=1e6+5;

namespace trie{
  const int M=300005;
  int nit=0,mn[M],pt[2][M],rt=0;
  inline void ins(int &id,const int lv,const int x,const int p)
  {
    if(!id)id=++nit;
    mn[id]=p;
    if(lv!=-1)ins(pt[(x&(1<<lv))>0][id],lv-1,x,p);
  }
  inline int qr(int id,int now,const int lv,const int x,const int p)
  {
    if(lv==-1)return now;
    int t=!((x&(1<<lv))>0);
    if(pt[t][id]&&mn[pt[t][id]]<p)return qr(pt[t][id],now|(t<<lv),lv-1,x,p);
    else return qr(pt[!t][id],now|((!t)<<lv),lv-1,x,p);
  }
}

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

int d[10005],qrl[MAXn],qrr[MAXn],qrv[MAXn],dt[MAXn],ct[10005],ans[MAXn];

int main(){

    int n,q;
    input(n);input(q);
    REP(i,n)input(d[i]);
    REP(i,q)input(qrl[i]),input(qrr[i]),input(qrv[i]),ct[qrl[i]]++;
    for(int i=n-2;i>=0;i--)d[i]=(d[i]^d[i+1]),ct[i]+=ct[i+1];
    REP(i,q)dt[--ct[qrl[i]]]=i,qrv[i]^=d[qrr[i]];

    int it=n;
    REP(i,q){
      int t=dt[i];
      while(it>qrl[t]){
        it--;trie::ins(trie::rt,29,d[it],it);
      }
      ans[t]=(trie::qr(trie::rt,0,29,qrv[t],qrr[t])^qrv[t]);
    }
    REP(i,q)printf("%d\n",ans[i]);
}
