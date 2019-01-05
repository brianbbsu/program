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


vector<ll> v[MAXn], bef[MAXn], aft[MAXn], his;
ll tg[MAXn],  vis[MAXn], dph[MAXn], ans[MAXn], ins[MAXn], dg[MAXn], ct[MAXn];

void dfs(ll now,ll f)
{
    his.pb(now);
    vis[now] = 1;
    ins[now] = 1;
    for(ll k:aft[now])if(vis[k])tg[now]++;
    for(ll k:bef[now])if(vis[k] && ins[k])tg[1]++, tg[his[dph[k] + 1]]--;
    for(ll k:bef[now])if(vis[k] && !ins[k])tg[k]++;
    for(ll k:v[now])if(k != f)
    {
        dph[k] = dph[now] + 1;
        dfs(k, now);
    }
    ins[now] = 0;
    his.pop_back();
}


void dfs2(ll now,ll f, ll s)
{
    s += tg[now];
    assert(s >= 0);
    if(!s)ans[now] = 1;
    else ans[now] = 0;
    for(ll k:v[now])if(k != f)dfs2(k,now, s);
}

int main()
{
    //IOS();
    _taskname = "gathering";
    _init();

    ll n,m;
    cin>>n>>m;
    REP(i,n-1)
    {
        ll a,b;
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    REP(i,m)
    {
        ll a,b;
        cin>>a>>b;
        bef[b].pb(a);
        aft[a].pb(b);
    }
    dph[1] = 0;
    dfs(1,-1);
    dfs2(1,-1, 0);
    ll ttct = 0;
    queue<ll> q;
    REP1(i,n)if(SZ(v[i]) == 1 && SZ(bef[i]) == 0)q.push(i);
    while(SZ(q))
    {
        ll t = q.front();q.pop();ttct++;
        for(ll k:v[t])
        {
            dg[k]++;
            if(SZ(bef[k]) == ct[k] && dg[k] == SZ(v[k]) - 1)q.push(k);
        }
        for(ll k:aft[t])
        {
            ct[k]++;
            if(SZ(bef[k]) == ct[k] && dg[k] == SZ(v[k]) - 1)q.push(k);
        }
    }
    if(ttct != n)REP1(i,n)ans[i] = 0;
    REP1(i,n)cout<<ans[i]<<endl;
    _end();
}
