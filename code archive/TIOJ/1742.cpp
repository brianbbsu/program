//{
#include<cstdio>
#include<algorithm>
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef int ll;
#define REP(i,n) for(ll i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)

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

const ll MAXn=1500+5;
const ll INF=1000000000;

ll d[MAXn][MAXn], dt[MAXn][MAXn];

ll LD[MAXn][MAXn];
ll LU[MAXn][MAXn];
ll RD[MAXn][MAXn];
ll RU[MAXn][MAXn];

int main()
{
    ll n, m, k;
    input(n);input(m);input(k);
    REP1(i,n)REP1(j,m)input(d[i][j]), d[i][j] = d[i][j] + d[i-1][j] + d[i][j-1] - d[i-1][j-1];
    REP(i, n+2)REP(j, m+2)dt[i][j] = LD[i][j] = LU[i][j] = RD[i][j] = RU[i][j] = -INF;

    for(int i = k;i <= n;i ++)for(int j = k;j <= m;j++)dt[i][j] = d[i][j] - d[i-k][j] - d[i][j-k] + d[i-k][j-k];

    for(int i = k;i <= n;i ++)for(int j = k;j <= m;j ++)LD[i][j] = max({dt[i][j], LD[i-1][j], LD[i][j-1]});
    for(int i = k;i <= n;i ++)for(int j = m - k + 1;j > 0;j --)LU[i][j] = max({dt[i][j + k - 1], LU[i-1][j], LU[i][j+1]});
    for(int i = n - k + 1;i > 0;i --)for(int j = m - k + 1;j > 0;j --)RU[i][j] = max({dt[i + k - 1][j + k - 1], RU[i+1][j], RU[i][j+1]});
    for(int i = n - k + 1;i > 0;i --)for(int j = k;j <= m;j ++)RD[i][j] = max({dt[i + k - 1][j], RD[i+1][j], RD[i][j-1]});

    ll a = 0;

    for(int i = k;i <= n;i ++)for(int j = k;j <= m;j ++)
    {
        ll p = LD[i - k][m] + max({RD[i - k + 1][j - k], RD[i + 1][m], RU[i - k + 1][j + 1]});
        ll q = RD[i + 1][m] + max(LD[i][j - k], LU[i][j + 1]);
        ll r = LD[n][j - k] + max({LU[i - k][j - k + 1], LU[n][j + 1], RU[i + 1][j - k + 1]});
        ll s = LU[n][j + 1] + max(LD[i - k][j], RD[i + 1][j]);
        a = max(a, max({p, q, r, s}) + dt[i][j]);
    }

    printf("%d\n", a);
}