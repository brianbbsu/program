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


const ll MAXn=3.5e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

const ll sigma=26;

int ct[MAXn],f[MAXn],id[MAXn],it;//,v[MAXn];//,node[MAXn][sigma];
ii p[MAXn];
vector<int> bfs;
vector<ii> v[MAXn];

inline int node(int x,int c)
{
  for(auto k:v[x])if(k.X==c)return k.Y;
  return 0;
}

int main()
{
    IOS();
    ll T;
    cin>>T;
    REP1(kz,T)
    {
      it=1;
      string m;
      cin>>m;
      for(char &c:m)c=c-'a';
      ll n;
      cin>>n;
      REP(i,n)
      {
        string s;
        cin>>s;
        for(char &c:s)c=c-'a';
        int now=1;
        for(char c:s)
        {
          if(!node(now,c))
          {
            int t=++it;
            p[t]=ii(now,c);
            v[now].pb(ii(c,t));
            //v[now]|=(1<<c);
            //node[now][c]=t;
          }
          now=node(now,c);
        }
        id[i]=now;
      }
      queue<int> q;
      while(SZ(q))q.pop();
      q.push(1);
      while(SZ(q))
      {
        int tmp=q.front();q.pop();
        bfs.pb(tmp);
        /*int t=v[tmp];
        while(t)
        {
          int J=t&-t;
          t-=J;
          q.push(node[tmp][__lg(J)]);
        }*/
        for(auto &k:v[tmp])q.push(k.Y);
      }
      f[1]=-1;
      REP1(i,SZ(bfs)-1)
      {
        int now=f[p[bfs[i]].X],c=p[bfs[i]].Y;
        while(1)
        {
          if(now==-1)
          {
            f[bfs[i]]=1;
            break;
          }
          int k=node(now,c);
          if(k)
          {
            f[bfs[i]]=k;
            break;
          }
          now=f[now];
        }
      }
      int now=1;
      for(char c:m)
      {
        while(now!=-1&&!node(now,c))now=f[now];
        if(now==-1)now=1;
        else now=node(now,c);
        ct[now]++;
        //debug(c,now);
      }
      for(int i=SZ(bfs)-1;i>0;i--)
      {
        ct[f[bfs[i]]]+=ct[bfs[i]];
      }
      REP1(i,it)debug(i,p[i],f[i],ct[i]);
      REP(i,n)cout<<ct[id[i]]<<endl;
      REP1(i,it)
      {
        ct[i]=0;
        //REP(k,26)node[i][k]=0;
        /*
        while(v[i])
        {
          int J=v[i]&-v[i];
          v[i]-=J;
          node[i][__lg(J)]=0;
        }*/
        v[i].clear();
        v[i].shrink_to_fit();
      }
      bfs.clear();
    }
}
