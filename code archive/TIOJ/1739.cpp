//{
#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(ll i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define FILL(i,n) memset(i,n,sizeof i)
#define X first
#define Y second
#define SZ(_a) (int)_a.size()
#define ALL(_a) _a.begin(),_a.end()
#define pb push_back
#ifdef brian
#define debug(...) do{\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0)
template<typename T>void _do(T &&_x){cerr<<_x<<endl;}
template<typename T,typename ...S> void _do(T &&_x,S &&..._t){cerr<<_x<<" ,";_do(_t...);}
template<typename _a,typename _b> ostream& operator << (ostream &_s,const pair<_a,_b> &_p){return _s<<"("<<_p.X<<","<<_p.Y<<")";}
template<typename It> ostream& _OUTC(ostream &_s,It _ita,It _itb)
{
    _s<<"{";
    for(It _it=_ita;_it!=_itb;_it++)
    {
        _s<<(_it==_ita?"":",")<<*_it;
    }
    _s<<"}";
    return _s;
}
template<typename _a> ostream &operator << (ostream &_s,vector<_a> &_c){return _OUTC(_s,ALL(_c));}
template<typename _a> ostream &operator << (ostream &_s,set<_a> &_c){return _OUTC(_s,ALL(_c));}
template<typename _a,typename _b> ostream &operator << (ostream &_s,map<_a,_b> &_c){return _OUTC(_s,ALL(_c));}
template<typename _t> void pary(_t _a,_t _b){_OUTC(cerr,_a,_b);cerr<<endl;}
#define IOS()
#else
#define debug(...)
#define pary(...)
#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#endif // brian
//}


#ifdef brian
int getNumQuestions(){
    ll q;
    cin>>q;
    return q;
}
void getQuestion(int &A, int &B)
{
    cin>>A>>B;
}
void answer(int ans)
{
    printf("Answer: %d\n", ans);
}
#else
#include "lib1739.h"
#endif


const ll MAXn=3e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

vector<ii> _v[2 * MAXn];
int vid[MAXn][MAXlg], vit = 0;

inline vector<ii> &v(int i,int j)
{
    if(vid[i][j] == 0)return _v[vid[i][j] = ++vit];
    else return _v[vid[i][j]];
}

ll mp(int i, int j, int x)
{
    ll t = lower_bound(ALL(v(i,j)), ii(x, -1)) - v(i,j).begin();
    if(t == SZ(v(i,j)) || v(i,j)[t].X != x)return x;
    else return v(i,j)[t].Y;
}



int d[MAXn], u[MAXn];

int main()
{
    debug(MAXn * MAXlg);
    int n, m;
    scanf("%d%d", &n, &m);
    REP1(i, m)scanf("%d", d + i);
    
    REP(i, m)
    {
        v(i, 0).pb(ii(d[i+1], d[i+1] + 1));
        v(i, 0).pb(ii(d[i+1] + 1, d[i+1]));
    }
    for(int j = 1;(1<<j) <= m;j++)
    {
        for(int i = 0;i + (1<<j) <= m;i += (1<<j))
        {
            ll t = i + (1<<(j-1));
            for(auto &p:v(i, j-1))
            {
                v(i,j).pb(ii(p.X, mp(t, j-1, p.Y)));
                u[p.X] = 1;
            }
            for(auto &p:v(t, j-1))if(!u[p.X])v(i,j).pb(p);
            for(auto &p:v(i,j))u[p.X] = 0;
            sort(ALL(v(i,j)));
        }
    }

    /*ll q = getNumQuestions();
    while(q--)
    {
        int a, b;
        getQuestion(a, b);
        int now = 0;
        for(int j = MAXlg - 1;j >= 0;j --)if(b&(1<<j))
        {
            a = mp(now, j, a);
            now += (1<<j);
        }
        answer(a);
    }*/
}