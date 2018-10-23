//{
#define REP(i,n) for(int i=0;i<n;i++)
//}

const int MAXn=1e6+5;

int ans[MAXn];

void solve(int n,int m,int dx=0,int dy=0,bool init=1)
{
  if(n==0)return;
  int tmp=n/2;
  int mx=0,id=-1;
  int tp;
  REP(i,m)
  {
    tp=GetVal(dx+tmp+1,dy+i+1);
    if(tp>mx)mx=tp,id=i;
  }
  ans[dx+tmp]=id+dy;

  solve(tmp,id,dx,dy,0);
  solve(n-tmp-1,m-id-1,dx+tmp+1,dy+id+1,0);
  if(init)
  {
    REP(i,n)Report(ans[i]+1);
  }
}
