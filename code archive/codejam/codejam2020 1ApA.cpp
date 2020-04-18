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

string s[55];
int l[55], r[55];

int main()
{
    IOS();
    ll T;
    cin >> T;
    for(int kz = 1;kz <= T;kz ++){
        cout << "Case #" << kz << ": ";
        int n;
        cin >> n;
        for(int i = 1;i <= n;i ++)
            cin >> s[i], l[i] = 0, r[i] = SZ(s[i]) - 1;
        string a = "", b = "", c  = "";
        int fg = 1;
        for(int i = 1;i <= n;i ++){
            while(s[i][l[i]] != '*')l[i]++;
            while(s[i][r[i]] != '*')r[i]--;
            if(s[i].substr(0, min(l[i], (int)SZ(a))) != a.substr(0, min(l[i], (int)SZ(a))))
                fg = 0;
            else if(l[i] > (int)SZ(a))
                a = s[i].substr(0, l[i]);
            if(s[i].substr(SZ(s[i]) - min(SZ(s[i]) - r[i] - 1, SZ(b))) != b.substr(SZ(b) - min(SZ(s[i]) - r[i] - 1, SZ(b))))
                fg = 0;
            else if(SZ(s[i]) - r[i] - 1 > SZ(b))
                b = s[i].substr(r[i] + 1);
            for(int t = l[i] + 1;t < r[i];t++)
                if(s[i][t] != '*')c.pb(s[i][t]);
        }
        if(!fg)cout << "*\n";
        else cout << a + c + b << "\n";
    }
}
