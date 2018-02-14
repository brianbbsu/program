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
template<typename _a> ostream &operator << (ostream &_s,const vector<_a> &_c){return _OUTC(_s,ALL(_c));}
template<typename _a> ostream &operator << (ostream &_s,set<_a> &_c){return _OUTC(_s,ALL(_c));}
template<typename _a,typename _b> ostream &operator << (ostream &_s,const map<_a,_b> &_c){return _OUTC(_s,ALL(_c));}
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
const ll INF=ll(1e15);

string s;

vector<ii> bk[MAXn],fr[MAXn];
vector<ll> dt;
ll M=20;

void frdfs(ll lv,ii ct0,ii ct1,ll dif,bool ed=0)
{
  if(lv==1)
  {
    debug(ct0,ct1);
    fr[ct0.Y+ct1.Y].pb(ii(ct0.X+ct1.X,dif+('1'!=s[0])));
    return ;
  }
  frdfs(lv-1,ii(ct0.X+ct1.X,ct0.Y+ct1.Y),ct1,dif+('0'!=s[lv-1]));
  if(!ed)frdfs(lv-1,ct0,ii(ct0.X+ct1.X,ct0.Y+ct1.Y),dif+('1'!=s[lv-1]));
}
void bkdfs(ll lv,ll ct0,ll ct1,ll dif,bool ed=0)
{
  if(lv==0)
  {
    bk[ct1].pb(ii(ct0,dif));
    return ;
  }
  bkdfs(lv-1,ct0+ct1,ct1,dif+('0'!=s[SZ(s)-M+lv-1]));
  if(!ed)bkdfs(lv-1,ct0,ct1+ct0,dif+('1'!=s[SZ(s)-M+lv-1]));
}

int main()
{
    IOS();


    ll T;
    cin>>T;
    while(T--)
    {
      cin>>s;
      ll c,n;
      cin>>c;c++;
      n=SZ(s);
      if(n<=M)
      {
        REP(i,MAXn)fr[i].clear();
        frdfs(n,ii(1,0),ii(0,1),0,1);
        if(SZ(fr[c]))
        {
          ll mn=INF;
          for(ii tmp:fr[c])mn=min(mn,tmp.Y);
          cout<<"YES"<<endl;
          cout<<mn<<endl;
        }
        else cout<<"NO"<<endl;
      }
      else
      {
        REP(i,MAXn)fr[i].clear();
        frdfs(n-M,ii(1,0),ii(0,1),0);
        REP(i,MAXn)bk[i].clear();
        bkdfs(M,0,1,0,1);
        dt.clear();
        REP(i,MAXn)if(SZ(bk[i]))dt.pb(i);
        ll mn = INF;
        REP(i,MAXn)if(SZ(fr[i]))for(ll k:dt)if(i*k<=c)
        {
          ll t = c-i*k;
          for(ii &tmp:fr[i])
          {
            if(tmp.X==0)
            {
              if(t==0)for(ii &tmp2:bk[k])mn=min(mn,tmp.Y+tmp2.Y);
            }
            else if(t%tmp.X==0)
            {
              ll tx = t/tmp.X;
              for(ii &tmp2:bk[k])if(tmp2.X==tx)mn=min(mn,tmp.Y+tmp2.Y);
            }
          }
        }
        else break;

        if(mn!=INF)
        {
          cout<<"YES"<<endl;
          cout<<mn<<endl;
        }
        else cout<<"NO"<<endl;
      }
    }

}
