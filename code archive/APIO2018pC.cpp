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


const ll MAXn=4e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);


vector<ll> v[MAXn],v2[MAXn];
ll n,m,vis[MAXn],dph[MAXn],lp[MAXn],sz[MAXn],subsz[MAXn],p[MAXn],git=0,pct=0;
vector<ll> stk;
vector<ll> his;
void predfs(ll now,ll pi)
{
  his.pb(now);
  pct++;
  stk.pb(now);vis[now] = 1;
  lp[now] = dph[now];
  sz[now] = 1;
  for(ll k:v[now])
  {
    if(!vis[k]){
      dph[k] = dph[now] + 1;
      predfs(k,now);
      debug(k,dph[k],lp[k]);
      lp[now] = min(lp[now],lp[k]);
      if(lp[k]>dph[now])
      {
        v2[now].pb(k);
        v2[k].pb(now);
        stk.pop_back();
      }
      else if(lp[k]==dph[now])
      {
        v2[now].pb(git);
        v2[git].pb(now);
        while(1)
        {
          ll tmp = stk.back();stk.pop_back();
          if(SZ(v2[tmp]))v2[git].pb(tmp),v2[tmp].pb(git);
          else sz[git]++;
          if(tmp==k)break;
        }
        git++;
      }
    }
    else if(k!=pi)lp[now] = min(lp[now],dph[k]);
  }


}

void szdfs(ll now,ll pi)
{
  subsz[now] = sz[now];p[now] = pi;
  for(ll k:v2[now])if(k!=pi)
  {
    szdfs(k,now);
    subsz[now] += subsz[k];
  }
}

int main()
{
    IOS();
    cin>>n>>m;
    git = n;
    REP(i,m)
    {
      ll a,b;
      cin>>a>>b;
      a--;b--;
      v[a].pb(b);
      v[b].pb(a);
    }
    ll tt=0,lt=n;
    REP(T,n)if(!vis[T]){
        stk.clear();his.clear();
        pct=0;
        dph[T] = 0;
        predfs(T,-1);
        szdfs(T,-1);

        for(int i=lt;i<git;i++)
        {
          debug(i,v2[i],sz[i]);
          ll tmp = (pct-sz[i])*(pct-sz[i]);
          for(ll k:v2[i])if(k!=p[i])tmp-=subsz[k]*subsz[k];
          if(p[i]!=-1)tmp-=(pct-subsz[i])*(pct-subsz[i]);
          tmp*=sz[i];
          tmp += 2*sz[i]*(pct-sz[i])*(sz[i]-1);
          tmp += sz[i]*(sz[i]-1)*(sz[i]-2);
          tt += tmp;
          debug(i,tmp);
        }
        for(ll i:his)if(SZ(v2[i]))
        {
          debug(i,v2[i],subsz[i],sz[i]);
          ll tmp=0,s=0;
          for(ll k:v2[i])if(k>=n)s+=sz[k];
          tmp += (pct-s-1) * (pct-s-1);
          for(ll k:v2[i])if(k!=p[i])
          {
            if(k>=n)tmp-=(subsz[k]-sz[k])*(subsz[k]-sz[k]);
            else tmp-=subsz[k]*subsz[k];
          }
          if(p[i]!=-1)
          {
            if(p[i]>=n)tmp-=(pct-subsz[i]-sz[p[i]])*(pct-subsz[i]-sz[p[i]]);
            else tmp-=(pct-subsz[i])*(pct-subsz[i]);
          }
          tmp += (pct-s-1)*s*2;
          tmp += s * (s-1);
          tt += tmp;
          debug(i,tmp);
          v2[i].clear();
        }
        lt=git;
    }

    cout<<tt<<endl;
}
