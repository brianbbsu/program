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


const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

set<ii> st;

ll C = 10000000000LL, MC = 1000000000000LL;

void ins(ll p)
{
    auto it = st.lower_bound(ii(p + 1, -1));
    it--;
    ll l = it->X, r = it->Y;
    st.erase(it);
    if(p - l >= C)st.insert(ii(l, p - 1));
    if(r - (p + C - 1) >= C)st.insert(ii(p + C, r));
}

int main()
{
    IOS();
    ll T, W;
    cin>>T>>W;
    ll fl = 0;
    while(T--)
    {
        st.clear();
        st.insert(ii(1, MC));
        ll flfg = 0;
        while(1)
        {
            ll p;
            cin>>p;
            if(p <= -2)break;
            else if(p == -1)return 0;
            ins(p);
            ll tt = 0;
            vector<ii> v;
            for(ii t:st)v.pb(t);
            sort(ALL(v), [](ii a,ii b){return 
                ii((a.Y - a.X + 1) / C, -(a.Y - a.X + 1) % C) > ii((b.Y - b.X + 1) / C, -(b.Y - b.X + 1) % C);
            });
            for(ii t:v)tt += (t.Y - t.X + 1) / C;
            if(tt&1)
            {
                ll l = v.front().X;
                p = l;
                cout<<p<<endl;
                ins(p);
            }
            else
            {
                ll fg = 0;
                for(ii t:v)
                {
                    ll l = t.Y - t.X + 1, x = l / C;
                    if(x >= 2 && l % C != C - 1)
                    {
                        fg = 1;
                        p = t.X + (l % C + C) / 2;
                        cout<<p<<endl;
                        ins(p);
                        break;
                    }
                }
                if(!fg)
                {
                    ll l = v.front().X, r = v.front().Y;
                    ll x = (r - l + 1) / C;
                    p = l + (x / 2) * C;
                    cout<<p<<endl;
                    ins(p);
                    flfg=1;
                }
            }
        }
        if(flfg)fl++;
    }
    debug(fl);
}
