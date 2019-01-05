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
const ll INF=ll(1e9);


struct seg{ll l,r,w;};
vector<seg> d;

ll far[MAXn],mn[MAXn];
ii dq[MAXn];

int main()
{
    IOS();
    ll T;
    cin>>T;
    while(T--)
    {
      ll n,tt=0,itl=0,itr=0;
      d.clear();
      cin>>n;
      REP(i,n)
      {
        ll l,r,w;
        cin>>l>>r>>w;
        if(l==r)tt+=w;
        else d.pb({l,r,w});
      }
      if(!SZ(d))
      {
        cout<<tt<<endl;
        continue;
      }
      sort(ALL(d),[](seg &a,seg &b){return a.r<b.r;});
      REP(i,MAXn)far[i]=INF;
      REP(i,SZ(d))far[d[i].l]=min(far[d[i].l],d[i].r-1);
      for(int i=MAXn-2;i>=0;i--)far[i]=min(far[i],far[i+1]);
      dq[itr++]=ii(far[0],0);
      ll it=0;
      REP(i,MAXn)
      {
        //while(itr-itl&&dq[itl].X<i)itl++;
        while(it<SZ(d)&&d[it].r==i)
        {
          ll l=-1,r=itr-itl;
          while(l!=r-1)
          {
            ll h=(l+r)/2;
            if(dq[itl+h].X>=d[it].l)r=h;
            else l=h;
          }
          pary(dq+itl,dq+itr);
          debug(r);
          ii tmp=ii(far[d[it].r],dq[itl+r].Y+d[it].w);
          while(itr-itl&&dq[itr-1].Y >= tmp.Y)itr--;
          dq[itr++] = tmp;
          it++;
        }
        //mn[i]=dq[itl].Y;
        //if(i<=10)debug(i,mn[i]);
      }
      while(itr-itl&&dq[itl].X!=INF)itl++;
      assert(itr-itl);
      cout<<dq[itl].Y<<endl;

    }
}
