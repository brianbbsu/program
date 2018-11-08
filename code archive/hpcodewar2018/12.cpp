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

int main()
{
    IOS();
    ll n,m;
    ii a,b;
    cin>>n>>m;
    cin>>a.X>>a.Y;
    ll n1,e1,n2,e2;
    ll f1,f2;
    cin>>e1>>n1>>f1>>b.X>>b.Y>>e2>>n2>>f2;
    ll st1 = 0,st2 = 1,ct1 = 0,ct2 = 0;
    ll ct = 0;
    while((f1 || f2) && a != b)
    {
        debug(a,b);
        ct ++;
        if(f1)
        {
            ct1++;
            if(st1 % 2 == 0)
            {
                a.X ++;
                if(a.X == n)a.X = 0;
                if(ct1 == e1)ct1 = 0,st1 ++;
            }
            else
            {
                a.Y ++;
                if(a.Y == m)a.Y = 0;
                if(ct1 == n1)ct1 = 0,st1 ++;
            }
            f1 --;
        }
        if(f2)
        {
            ct2++;
            if(st2 % 2 == 1)
            {
                b.X ++;
                if(b.X == n)b.X = 0;
                if(ct2 == e2)ct2 = 0,st2 ++;
            }
            else
            {
                b.Y ++;
                if(b.Y == m)b.Y = 0;
                if(ct2 == n2)ct2 = 0,st2 ++;
            }
            f2 --;
        }
        debug(a,b);
    }
    if(a == b)cout<<ct<<endl;
    else cout<<-1<<endl;
}
