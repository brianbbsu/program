#define REP(i,n) for(int i=0;i<n;i++)
#include "lib2056.h"

int main()
{
    int T = Testcase();
    while(T--)
    {
      int n = Init();
      REP(i,n)
      {
        int now = i;
        while(1)
        {
          int t = Query(now);
          if(t==i)break;
          else now = t;
        }
        Answer(now);
      }
    }

}
