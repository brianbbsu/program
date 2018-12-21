#include<cstdio>
const int MAXn=2e5+5;

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


namespace seg{
    const int N = (1<<20);
    const int lg = 20;
    int t[N<<1], s[N<<1];
    void calc(int x,int k){
        s[x] = (t[x]?k:s[x<<1] + s[x<<1|1]);
    }
    void apply(int x,int v,int k)
    {
        t[x] += v;
        if(x & N)s[x] = (t[x] > 0);
        else calc(x,k);
    }
    void build(int x){
        int k = 2;
        for(;x > 1;k <<= 1)x>>=1,calc(x,k);
    }
    void ins(int l, int r, int tp){
        l += N, r += N;
        int l0 = l, r0 = r, k =1;
        for(; l < r;l >>= 1, r >>= 1, k <<= 1){
            if(l&1)apply(l++, tp, k);
            if(r&1)apply(--r, tp, k);
        }
        build(l0);
        build(r0-1);
    }
}

int dt[MAXn];
struct tg{int l,r,x,tp;}qr[MAXn];

int ct[1000005];

int main()
{
    int n;
    input(n);
    for(int i = 0;i < n;++i)
    {
        int L,R,D,U;
        input(L);input(R);
        input(D);input(U);
        qr[i<<1] = tg({D,U,L,1});
        qr[i<<1|1] = tg({D,U,R,-1});
    }
    int mx = 0;
    for(int i = 0;i < (n<<1);++i)ct[qr[i].x]++, mx = (qr[i].x > mx?qr[i].x:mx);
    for(int i = 1;i <= mx;++i)ct[i] += ct[i-1];
    for(int i = 0;i < (n<<1);++i)dt[--ct[qr[i].x]] = i;
    long long tt = 0;
    for(int i = 0;i < (n<<1);++i)
    {
        seg::ins(qr[dt[i]].l,qr[dt[i]].r,qr[dt[i]].tp);
        if(i + 1 != (n<<1) && qr[dt[i]].x != qr[dt[i+1]].x){
            long long x = seg::s[1], y = (qr[dt[i+1]].x - qr[dt[i]].x);
            tt += x * y;
        }
    }
    printf("%lld\n", tt);
}
