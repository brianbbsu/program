//{
#include<bits/stdc++.h>
using namespace std;
typedef int ll;
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


const ll MAXn=1e3*2e3+5,MAXc=62,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

int node[MAXn][MAXc],f[MAXn],ct[MAXn],id[1005],it=1;
ii p[MAXn];
vector<ii> v[MAXn];
vector<ll> bfs;

char uni(char c)
{
  if(islower(c))return c-'a';
  else if(isupper(c))return c-'A'+26;
  else return c-'0'+52;
}


int main()
{
    IOS();
    debug(MAXn);
    string M;
    ll n;
    cin>>M>>n;
    transform(ALL(M),M.begin(),uni);
    p[1]=ii(-1,0);
    f[1]=1;
    REP(i,n)
    {
        string s;
        cin>>s;
        transform(ALL(s),s.begin(),uni);
        ll now=1;
        for(auto c:s)
        {
          if(node[now][c])now=node[now][c];
          else
          {
            ll t=++it;
            p[t]=ii(now,c);
            v[now].pb(ii(t,c));
            node[now][c]=t;
            now=t;
            v[t].reserve(32);
          }
        }
        id[i]=now;
    }
    queue<ll> q;
    q.push(1);
    while(SZ(q))
    {
      ll t=q.front();
      q.pop();
      bfs.pb(t);
      for(auto tmp:v[t])q.push(tmp.X);
    }
    debug(bfs);
    for(ll t:bfs)
    {
      if(t==1)continue;
      char c=p[t].Y;
      ll now=p[t].X;
      while(1)
      {
        if(now==1){
          f[t]=1;
          break;
        }
        if(node[f[now]][c]){
          f[t]=node[f[now]][c];
          break;
        }
        now=f[now];
      }
    }
    ll now=1;
    for(char c:M)
    {
      while(1)
      {
        if(!node[now][c])
        {
          if(now==1)break;
          else now=f[now];
        }
        else
        {
          now=node[now][c];
          ct[now]++;
          break;
        }
      }
    }
    for(int i=SZ(bfs)-1;i>0;i--)
    {
      ct[f[bfs[i]]]+=ct[bfs[i]];
    }
    pary(id,id+n);
    REP1(i,it)debug(i,v[i],p[i],f[i],ct[i]);
    REP(i,n)cout<<(ct[id[i]]?"Y":"N")<<endl;

}
