//{
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef int ll;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define SZ(_a) (int)_a.size()
#define ALL(_a) _a.begin(),_a.end()
#define pb push_back

const ll MAXn=3e3+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

int x[MAXn], y[MAXn], dtx[MAXn], dty[MAXn];

int mx = 0;
vector<int> v;
int n, l, w;

void cal()
{
    int it = 0;
    REP(i, SZ(v))
    {
        while(it < SZ(v) && v[it] - v[i] <= l)it++;
        mx = max(mx, it - i);
    }
}

int main()
{
    scanf("%d %d %d", &n, &l, &w);
    REP(i,n)scanf("%d %d", x + i, y + i), dtx[i] = i, dty[i] = i;
    sort(dtx, dtx + n, [](int a,int b){return x[a] < x[b];});
    sort(dty, dty + n, [](int a,int b){return y[a] < y[b];});
    int it = 0;
    REP(i, n)
    {
        while(it < n && x[dtx[it]] - x[dtx[i]] <= w)it++;
        if(!i || x[dtx[i]] != x[dtx[i-1]])
        {
            v.clear();
            //for(int j = i;j < it;j ++)v.pb(y[dtx[j]]);
            //sort(ALL(v));
            REP(j,n)if(x[dty[j]] >= x[dtx[i]] && x[dty[j]] <= x[dtx[it-1]])v.pb(y[dty[j]]);
            cal();
        }
    }
    printf("%d\n", mx);
}
