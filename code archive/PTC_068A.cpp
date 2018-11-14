//{
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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


const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);


const int MAX_N = 81;
typedef bitset<MAX_N> bst;
bool adj[MAX_N][MAX_N];
bst N[MAX_N];
int p[MAX_N];

int n;
int ans=0;
bst empty_bst;

void BronKerbosch2(bst R,bst P,bst X) {
    if (P==empty_bst && X==empty_bst) {
        ans = max(ans,(int)R.count());
        return;
    }
    bst tmp=P|X;
    int u;
    if ((R|P|X).count()<=ans) return;
    for (int uu=0;n>uu;uu++) {
        u=p[uu];
        if (tmp[u]==1) break;
    }
    bst now2=P&~N[u];
    for (int vv=0;n>vv;vv++) {
        int v=p[vv];
        if (now2[v] == 1) {
            R[v]=true;
            BronKerbosch2(R,P&N[v],X&N[v]);
            R[v]=false;
            P[v]=false;
            X[v]=true;
        }
    }
}

int main()
{
    IOS();
    srand(71227122);
    ll T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        ll d[100];
        REP(i,n)cin>>d[i];
        FILL(adj,0);
        REP(i,MAX_N)N[i].reset();
        ans = 0;
        REP(i,n)REP(j,i)if(__builtin_popcount((d[i]^d[j])) > 4)adj[i][j] = adj[j][i] = 1;
        for (int i=0;n>i;i++) {
            for (int j=0;n>j;j++) {
                N[i][j] = adj[i][j];
            }
        }
        bst R,P,X;
        P.flip();
        for (int i=0;n>i;i++) p[i]=i;
        random_shuffle(p,p+n);
        BronKerbosch2(R,P,X);     
        cout<<ans<<endl;
    }
}
