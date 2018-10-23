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
template<typename _t> void pary(_t _a,_t _b){_OUTC(cerr,_a,_b);cerr<<endl;}
#else
#define debug(...)
#define pary(...)
#define endl '\n'
#endif // brian
//}


const ll MAXn=1e6+5,MAXlg=__lg(MAXn)+2,MAXsq=ll(sqrt(MAXn))+5;
const ll MOD=1000000007;
const ll INF=ll(1e13);

ii qr[MAXn];
bool cmp(ll a,ll b){return qr[a].Y<qr[b].Y;}

ll n,m;
vector<ll> q[MAXsq];
ii ans[MAXn];
ll d[MAXn];
ll cnt[MAXn],num[MAXn];
ll k,t;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    k=sqrt(n);
    t=(n-1)/k+1;
    debug(k,t);
    REP(i,n)cin>>d[i];
    REP(i,m)
    {
        cin>>qr[i].X>>qr[i].Y;
        qr[i].X--;
        qr[i].Y--;
        q[qr[i].X/k].pb(i);
    }
    REP(i,t)sort(ALL(q[i]),cmp);
    REP(i,t)
    {
        if(SZ(q[i])==0)continue;
        ll l=qr[q[i][0]].X;
        ll r=l-1;
        FILL(cnt,0);
        FILL(num,0);
        ll it=0;
        debug(q[i]);
        for(ll id:q[i])
        {
            while(r<qr[id].Y)
            {
                num[cnt[d[++r]]]--;
                cnt[d[r]]++;
                num[cnt[d[r]]]++;
                if(cnt[d[r]]>it)it++;
            }
            if(qr[id].X<=l)
            {
                while(l>qr[id].X)
                {
                    num[cnt[d[--l]]]--;
                    cnt[d[l]]++;
                    num[cnt[d[l]]]++;
                    if(cnt[d[l]]>it)it++;
                }
            }
            else
            {
                while(l<qr[id].X)
                {
                    num[cnt[d[l]]]--;
                    if(cnt[d[l]]==it&&num[cnt[d[l]]]==0)it--;
                    cnt[d[l]]--;
                    num[cnt[d[l++]]]++;

                }
            }
            ans[id]=ii(it,num[it]);
            debug(id);
        }
    }
    REP(i,m)cout<<ans[i].X<<" "<<ans[i].Y<<endl;
}
