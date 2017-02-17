#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define FILL(i,n) memset(i,n,sizeof(i));
#define SZ(A) ((int)A.size())
#define ALL(A) A.begin(),A.end()
#define X first
#define Y second
#define pb push_back
#ifdef brian
#define  debug(...) do{\
    fprintf(stderr,"%s - %d : (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0)
template<typename t> void _do(t &&_x){cerr<<_x<<endl;}
template<typename t,typename ...T> void _do(t &&_x,T &&...tail){cerr<<_x<<", ";_do(tail...);}
#else
#define debug(...)
#endif // brian

const ll INF=ll(1e15);
const ll MAXn=1e6+5,MAXlg=20;
const ll MOD = 1000000007;
ll n;
bool b[MAXn];
vector<ll> pm;
ii two(ll k)
{
    for(auto it=upper_bound(ALL(pm),k/2)-1;;it--)
    {
        if(binary_search(ALL(pm),k-*it))return ii(*it,k-*it);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    for(int i=2;i<MAXn;i++)
    {
        if(!b[i])pm.pb(i);
        for(int j=0;j<SZ(pm)&&pm[j]*i<MAXn;j++)
        {
            b[pm[j]*i]=1;
            if(i%pm[j]==0)break;
        }
    }
    debug(SZ(pm));
    while(cin>>n&&n)
    {
        if(binary_search(ALL(pm),n))cout<<1<<" "<<n<<endl;
        else if(n%2==0)
        {
            ii ans=two(n);
            cout<<2<<" "<<ans.X<<" "<<ans.Y<<endl;
        }
        else if(binary_search(ALL(pm),n-2))cout<<2<<" "<<2<<" "<<n-2<<endl;
        else
        {
            ll ans[3],mx=0;
            for(auto it=upper_bound(ALL(pm),n/6)-1;*it<=n/3;it++)
            {
                ii tmp=two(n-*it);
                if((*it)*tmp.X*tmp.Y>mx)
                {
                    ans[0]=*it;
                    ans[1]=tmp.X;
                    ans[2]=tmp.Y;
                    mx=(*it)*tmp.X*tmp.Y;
                }
            }
            sort(ans,ans+3);
            cout<<3<<" "<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<endl;
        }
    }
}
