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


const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

vector<int> cmd;
char mem[MAXn];



int main()
{
    IOS();
    string s,S="><+-.,[]";
    //          01234567
    vector<ll> stk;
    while(getline(cin,s)&&s!="@")
    {
      for(char c:s)REP(i,SZ(S))if(c==S[i])
      {
        if(i==6)stk.pb(SZ(cmd)),cmd.pb(-1);
        else if(i==7)
        {
          cmd[stk.back()]=-SZ(cmd)-1;
          cmd.pb(-stk.back()-1);
          stk.pop_back();
        }
        else cmd.pb(i);
        break;
      }
    }
    ll T;
    cin>>T;
    getline(cin,s);
    debug(cmd);
    while(T--)
    {
      getline(cin,s);
      s.pb('\n');
      FILL(mem,0);
      ll cmdit=0;
      ll memit=0;
      ll sit=0;
      while(cmdit<SZ(cmd))
      {
        ll t=cmd[cmdit];
        if(t==0)memit++;
        else if(t==1)memit--;
        else if(t==2)mem[memit]++;
        else if(t==3)mem[memit]--;
        else if(t==4)cout<<mem[memit];
        else if(t==5)mem[memit]=(sit>=0&&sit<SZ(s)?s[sit++]:-1);
        else
        {
          ll gt=-(t+1);
          if(gt<cmdit&&mem[memit]!=0)cmdit=gt;
          else if(gt>cmdit&&mem[memit]==0)cmdit=gt;
        }
        cmdit++;
      }
    }
}
