//{
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<string>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<sstream>
#include<cmath>
#include<queue>
#include<stack>

using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(ll i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define FILL(i,n) memset(i,n,sizeof i)
#define MEM(i,n) memset(i,n,sizeof i)
#define X first
#define Y second
#define SZ(_a) (int)_a.size()
#define ALL(_a) _a.begin(),_a.end()
#define pb push_back
#define eb emplace_back
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

#define MAXN MAXn

const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll mat[6][6] = {
    {-2,1,-2,3,2,1},
    {-5,-2,5,2,5,-4},
    {-5,-5,0,5,-1,-1},
    {-3,-2,-5,0,1,2},
    {5,-3,-2,-1,-3,1},
    {-5,-4,-5,2,4,-1}
};

const ll N = 6;

set<ii> st[MAXn];

int main()
{
    IOS();
    ll n,m;
    cin>>n>>m;
    st[0].insert(ii(n,m));
    queue<pair<ll,ii> > q;
    q.push({0,{n,m}});
    while(SZ(q))
    {
        ll ite = q.front().X;
        ll tp = q.front().Y.X;
        ll p = q.front().Y.Y;
        q.pop();
        ite ++;

        REP(i,N)
        {
            ll np = p + mat[tp][i];
            if(ite % 2 == 0)
            {
                np -= abs(np % 10) + ite;
            }
            if(np < 0)np += ite * ite % 30;
            if(np < 0)continue;
            else if(np == 0)
            {
                cout<<ite<<endl;
                return 0;
            }
            else if(!st[ite].count(ii(i,np)))
            {
                st[ite].insert(ii(i,np));
                q.push({ite,{i,np}});
            }
        }
    }
}
