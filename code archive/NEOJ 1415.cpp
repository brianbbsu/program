#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(ll i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)

#ifdef brian
#define IOS()
#else
#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#endif // brian

const ll MAXn=1e6+5;

struct node{
  ll d;
  node *pre,*nxt;
  node(ll di=-1,node *prei=0,node *nxti=0):d(di),pre(prei),nxt(nxti){}
};

node lst[MAXn],ed[MAXn];
node *d[MAXn];
int main()
{
    IOS();
    ll n,m;
    cin>>n>>m;
    REP1(i,n)d[i]=new node(i,lst+i,ed+i),lst[i].nxt=d[i],ed[i].pre=d[i];
    REP(i,m)
    {
      ll t,a,b;
      cin>>t>>a>>b;
      if(t==0)
      {
        d[a]->pre->nxt=d[a]->nxt;
        d[a]->nxt->pre=d[a]->pre;
        d[a]->pre=d[b];
        d[a]->nxt=d[b]->nxt;
        d[b]->nxt->pre=d[a];
        d[b]->nxt=d[a];
      }
      else
      {
        if(lst[a].nxt->d!=-1)
        {
          lst[a].nxt->pre=ed[b].pre;
          ed[b].pre->nxt=lst[a].nxt;
          ed[b].pre=ed[a].pre;
          ed[a].pre->nxt=ed+b;
          lst[a].nxt=ed+a;
          ed[a].pre=lst+a;
        }
      }
    }
    REP1(i,n)
    {
      cout<<"#"<<i<<":";
      node *it=lst[i].nxt;
      while(it->d!=-1){cout<<" "<<it->d;it=it->nxt;}
      cout<<endl;
    }
}
