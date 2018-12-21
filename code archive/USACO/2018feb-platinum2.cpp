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

string _taskname;
void _init()
{
  #ifndef brian
      freopen((_taskname+".in").c_str(), "r", stdin);
      freopen((_taskname+".out").c_str(),"w",stdout);
  #endif
}
void _end()
{
  #ifndef brian
      fclose( stdin);
      fclose(stdout);
  #endif
}

const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);


vector<ll> v[MAXn];
ll st[MAXn][MAXlg], nit, vis[MAXn], h[MAXn][2], far[MAXn], dph[MAXn], g[MAXn], gp[MAXn];

ll fd(ll x){return g[x] = (g[x] == x?x:fd(g[x]));}
void mg(ll a,ll b)
{
    a = fd(a), b = fd(b);
    g[a] = b;
    gp[b] = min(gp[b], gp[a]);
}


void dfs1(ll now,ll f)
{
    h[now][0] = h[now][1] = 0;
    vis[now] = 1;
    for(ll k:v[now])if(k != f)
    {
        dfs1(k, now);
        if(h[k][0] + 1 >= h[now][0])h[now][1] = h[now][0], h[now][0] = h[k][0] + 1;
        else if(h[k][0] + 1 >= h[now][1])h[now][1] = h[k][0] + 1;
    }
}
void dfs2(ll now,ll f, ll tp)
{
    far[now] = max(tp, h[now][0]);
    for(ll k:v[now])if(k != f)
    {
        if(h[k][0] + 1 == h[now][0])dfs2(k, now, max(tp, h[now][1]) + 1);
        else dfs2(k, now, max(tp, h[now][0]) + 1);
    }
}


ll lca(ll a,ll b)
{
    if(dph[a] < dph[b])swap(a,b);
    for(int j = MAXlg-1;j >= 0;j --)if(dph[st[a][j]] >= dph[b])a = st[a][j];
    if(a == b)return a;
    for(int j = MAXlg-1;j >= 0;j --)if(st[a][j] != st[b][j])a = st[a][j], b = st[b][j];
    return st[a][0];
}

vector<ll> dt;
const ll K = 170;

int main()
{
    //IOS();
    _taskname = "newbarn";
    _init();
    REP1(i,MAXn-1)g[i] = i, gp[i] = i;
    ll q;
    cin>>q;
    while(q--)
    {
        char c;
        ll p;
        cin>>c>>p;
        if(c == 'Q')
        {
            //dfs1(gp[fd(p)], -1);
            //dfs2(gp[fd(p)], -1, 0);
            ll ret = far[p];
            for(ll x:dt)if(fd(x) == fd(p))
            {
                ll t = lca(x, p);
                debug(x,p,t, ret);
                ret = max(ret, dph[x] + dph[p] - 2 * dph[t]);
            }
            cout<<ret<<endl;
        }
        else 
        {
            if(p != -1)
            {
                v[p].pb(++nit);
                gp[nit] = p;
                mg(nit, p);
                dph[nit] = dph[p] + 1;
                far[nit] = far[p] + 1;
                st[nit][0] = p;
                REP1(j,MAXlg-1)st[nit][j] = st[st[nit][j-1]][j-1];
            }
            else
            {
                dph[++nit] = 0;
                REP(j,MAXlg)st[nit][j] = nit;
            }
            dt.pb(nit);
            if(SZ(dt) > K)
            {
                REP1(i,nit)vis[i] = 0;
                REP1(i,nit)if(!vis[i])
                {
                    dfs1(gp[fd(i)], -1);
                    dfs2(gp[fd(i)], -1, 0);
                }
                dt.clear();
                pary(far+1,far+1+nit);
            }
            debug(dt);
        }
    }
    _end();
}
