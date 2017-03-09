//{
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(ll i=0;i<n;i++)
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
template<typename _t>
struct ary
{
    _t _a,_b;
    ary(_t _ai,_t _bi):_a(_ai),_b(_bi){}
};
#else
#define debug(...)
//#define endl '\n'
#endif // brian
//}

const ll MAXn=2e5+5,MAXlg=__lg(10*MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

#ifndef brian
#include "lib1956.h"
#endif
ii d[MAXn];
int solve(int l,int u,int w[],int n,int result[])
{
    REP(i,n)d[i].X=w[i],d[i].Y=i;
    sort(d,d+n);
    ll s=0;
    ll itl=0,itr=0;
    s=0;
    while((s<l||s>u))
    {
        if(s<l)
        {
            if(itr<n)s+=d[itr++].X;
            else return 0;
        }
        else s-=d[itl++].X;
        debug(s);
    }
    ll t=0;
    for(;itl!=itr;itl++)result[t++]=d[itl].Y;
    return t;
}

#ifdef brian


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int l,u,n;
    cin>>l>>u>>n;
    int d[n];
    int r[n];
    REP(i,n)cin>>d[i];
    ll k=solve(l,u,d,n,r);
    debug(k);
    _OUTC(cout,r,r+k);
    cout<<endl;
}
#endif // brian
