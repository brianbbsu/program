#include<cstdio>

#define swap(a,b) a ^= b ^= a ^= b;

int main()
{
    int a,b;
    int tt = 0;
    while(scanf("%d %d", &a, &b) == 2)
    {
        tt = 0;
        if(a > b)swap(a,b);
        while(a)
        {
            tt += b / a;
            b %= a;
            swap(a,b);
        }
        printf("%d\n", tt);
    }
}
