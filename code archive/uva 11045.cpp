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

struct Dinic {
	static const int MAX_N = 1e3 + 6;
	struct Edge {
		int to,cap,rev;
	};
	Edge make_edge(int _to,int _cap,int _rev) {
		Edge ret;
		ret.to=_to;
		ret.cap=_cap;
		ret.rev=_rev;
		return ret;
	}
	vector<Edge> edg[MAX_N];
	void add_edge(int from,int to,int cap) {
		edg[from].push_back(make_edge(to,cap,SZ(edg[to])));
		edg[to].push_back(make_edge(from,0,SZ(edg[from])-1));
	}
	int n,s,t;
	void init(int _n,int _s,int _t) {
		n=_n;
		s=_s;
		t=_t;
		for (int i=0;n>=i;i++) {
			edg[i].clear();
		}
	}
	int level[MAX_N],iter[MAX_N];
	void bfs() {
		memset(level,-1,sizeof(level));
		level[s]=0;
		queue<int> que;
		que.push(s);
		while (!que.empty()) {
			int t=que.front();
			que.pop();
			for (int i=0;SZ(edg[t])>i;i++) {
				Edge e=edg[t][i];
				if (e.cap > 0 && level[e.to] == -1) {
					level[e.to] = level[t] + 1;
					que.push(e.to);
				}
			}
		}
	}
	int dfs(int id,int flow) {
		if (id==t) return flow;
		for (int &i=iter[id];SZ(edg[id])>i;i++) {
			Edge &e=edg[id][i];
			if (e.cap>0 && level[e.to] == level[id] + 1) {
				int ret=dfs(e.to,min(flow,e.cap));
				if (ret>0) {
					e.cap -= ret;
					edg[e.to][e.rev].cap += ret;
					return ret;
				}
			}
		}
		return 0;
	}
	static const int INF = 1e9 + 7;
	int flow() {
		int ret=0;
		while (true) {
			bfs();
			if (level[t] == -1) break;
			memset(iter,0,sizeof(iter));
			int tmp=0;
			while ((tmp=dfs(s,INF)) > 0) {
				ret += tmp;
			}
		}
		return ret;
	}
} sagiri;

map<string,ll> mp;

int main()
{
  mp["XXL"]=1;
  mp["XL"]=2;
  mp["L"]=3;
  mp["M"]=4;
  mp["S"]=5;
  mp["XS"]=6;
  ll T;
  cin>>T;
  while(T--)
  {
    ll n,m;
    cin>>n>>m;
    sagiri.init(m+10,0,6+m+1);

    REP1(i,6)sagiri.add_edge(0, i, n/6);
    REP1(i,m)
    {
      string a,b;
      cin>>a>>b;
      sagiri.add_edge(mp[a], 6+i, 1);
      sagiri.add_edge(mp[b], 6+i, 1);
      sagiri.add_edge(6+i, 6+m+1, 1);
    }
    if(sagiri.flow()==m)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }

}
