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
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#endif // brian
//}

#define endl '\n' 

const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

int eval(string s, int x)
{
    if(SZ(s) == 1)
    {
        if(s == "0")return 0;
        else if(s == "1")return 1;
        else if(s == "x")return x;
        else return !x;
    }
    s = s.substr(1, SZ(s) - 2);
    ll t = 0, it = 0;
    do{
        if(s[it] == '(')t ++;
        else if(s[it] == ')')t --;
        it ++;
    }while(t != 0);
    ll a = eval(s.substr(0, it), x);
    ll b = eval(s.substr(it + 1), x);
    if(s[it] == '|')return a | b;
    else if(s[it] == '&')return a & b;
    else return a ^ b;
}

int main()
{
    IOS();
    ll T, kz = 0;
    cin>>T;
    while(T--)
    {
        kz ++;
        cout<<"Case #"<<kz<<": ";
        string s;
        cin>>s;
        if(eval(s, 0) != eval(s, 1))cout<<1<<endl;
        else cout<<0<<endl;
    }
}
