//{
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
#define REP(i,n) for(ll i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define SZ(_a) (int)_a.size()
#define ALL(_a) _a.begin(),_a.end()
#define pb push_back
#ifdef brian
#define IOS()
#else
#define debug(...)
#define pary(...)
#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#endif // brian
//}


const ll MAXn=1e6+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

bool u[MAXn];
vector<ll> st,dt;

int main()
{
    IOS();
    srand(time(NULL));
    ll T;
    cin>>T;
    while(T--)
    {
      ll x,n;
      cin>>x>>n;
      ll tt=n*(n+1)/2-x;
      if(tt%2!=0||(x==1&&n==2)){
        cout<<"impossible"<<endl;
        continue;
      }
      else if(n==1){
        cout<<2<<endl;
        continue;
      }

      dt.clear();
      REP1(i,n)if(i!=x)dt.pb(i);

      tt/=2;
      bool ok=0;
      REP(_,10)
      {
        random_shuffle(ALL(dt));
        st.clear();
        ll tmp=tt;
        for(ll k:dt)
        {
          if(tmp<=n&&!u[tmp]&&tmp!=x)
          {
            st.pb(tmp);u[tmp]=1;tmp=0;
            break;
          }
          if(tmp>=k)
          {
            st.pb(k);u[k]=1;
            tmp-=k;
          }
        }
        if(tmp==0)
        {
          ok=1;
          break;
        }
        for(ll k:st)u[k]=0;
      }
      if(!ok){
        cout<<"impossible"<<endl;
        continue;
      }
      REP1(i,n)
      {
        if(i==x)cout<<"2";
        else if(u[i])cout<<"1";
        else cout<<"0";
      }
      cout<<endl;
      for(ll k:st)u[k]=0;
    }
}
