#include<bitset>
using namespace std;
#define REP(i,n) for(short i = 0;i < n;i ++)
#ifndef brian
#define int short
#include "lib1087.h"
#else
void Initialize(){}
void Take_Stone(int pile_no, int num, int *com_pile, int *com_num){}
#endif

bitset<3696> dt;

#define d(i,j,k) dt[i + j * 11 + 176 * k]

int32_t main()
{
    d(0,0,0) = 1;
    REP(i,11)REP(j,16)REP(k, 21)
    {
        if(!(i || j || k))continue;
        bool fg = 0;
        REP(l, i)if(!d(l,j,k))fg = 1;
        REP(l, j)if(!d(i,l,k))fg = 1;
        REP(l, k)if(!d(i,j,l))fg = 1;
        d(i,j,k) = fg;
    }
    short p[4] = {0, 10, 15, 20};
    Initialize();
    while(1)
    {
        int comp, comn, fg = 0;
        if(!fg)REP(i, p[1])if(!d(i,p[2],p[3]))
        {
            Take_Stone(1,p[1] - i, &comp, &comn);
            p[1] = i;
            fg = 1;
            break;
        }
        if(!fg)REP(i, p[2])if(!d(p[1],i,p[3]))
        {
            Take_Stone(2,p[2] - i, &comp, &comn);
            p[2] = i;
            fg = 1;
            break;
        }
        if(!fg)REP(i, p[3])if(!d(p[1],p[2],i))
        {
            Take_Stone(3,p[3] - i, &comp, &comn);
            p[3] = i;
            fg = 1;
            break;
        }
        p[comp] -= comn;
    }
}
