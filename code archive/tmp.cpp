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
const ll INF=ll(1e15);

struct optg{ll tp,x;};//0~3 op
struct chtg{ll tp;string a,b;};//0:S 1: ap 2:ch 3:sr 4:sl 5:mirror 6:del

unordered_map<ll,ll> mp;
unordered_map<ll,ii> p;

queue<ll> q;

vector<optg> op;
vector<chtg> ch;

ll doop(ll n,optg &tmp)
{
  ll t=tmp.tp,x=tmp.x;
  if(t==0)n+=x;
  else if(t==1)n-=x;
  else if(t==2)n*=x;
  else if(t==3&&n%x==0)n/=x;
  return n;
}
ll doch(ll n,chtg &tmp)
{
  ll t=tmp.tp;
  string s=to_string(n);
  if(t==0)
  {
    ll tt=0;
    for(char c:s)if(c!='-')tt+=c-'0';
    if(n<0)tt*=-1;
    return tt;
  }
  else if(t==1)
  {
    s+=tmp.a;
    return stoll(s);
  }
  else if(t==2)
  {
    string g="";
    REP(i,SZ(s))if(s.substr(i,SZ(tmp.a))==tmp.a)g+=tmp.b,i+=SZ(tmp.a)-1;else g.pb(s[i]);
    return stoll(g);
  }
  else if(t==3)
  {
    rotate(s.begin(),s.begin()+SZ(s)-1,s.end());
    return stoll(s);
  }
  else if(t==4)
  {
    rotate(s.begin(),s.begin()+1,s.end());
    return stoll(s);
  }
  else if(t==5)
  {
    string g=s;
    reverse(ALL(g));
    s+=g;
    return stoll(s);
  }
  else if(t==6)
  {
    if(SZ(s)>1)s.pop_back();
    return stoll(s);
  }
}
void prtop(ll i)
{
  ll t=op[i].tp;
  if(t==0)cout<<"+ "<<op[i].x<<endl;
  else if(t==1)cout<<"- "<<op[i].x<<endl;
  else if(t==2)cout<<"* "<<op[i].x<<endl;
  else if(t==3)cout<<"/ "<<op[i].x<<endl;
}
void prtch(ll i)
{
  ll t=ch[i].tp;
  if(t==0)cout<<"sum"<<endl;
  else if(t==1)cout<<"append "<<ch[i].a<<endl;
  else if(t==2)cout<<"replace "<<ch[i].a<<" "<<ch[i].b<<endl;
  else if(t==3)cout<<"shiftR"<<endl;
  else if(t==4)cout<<"shiftL"<<endl;
  else if(t==5)cout<<"mirror"<<endl;
  else if(t==6)cout<<"delete"<<endl;
}
void read()
{
  string s;
  while(cin>>s)
  {
    vector<string> ops={"+","-","*","/"};
    bool ok=0;
    REP(i,SZ(ops))if(s==ops[i])
    {
      ll x;cin>>x;
      op.pb({i,x});
      ok=1;break;
    }
    if(ok)continue;
    ok=1;
    if(s=="sum")ch.pb({0,"",""});
    else if(s=="shiftR")ch.pb({3,"",""});
    else if(s=="shiftL")ch.pb({4,"",""});
    else if(s=="mirror")ch.pb({5,"",""});
    else if(s=="delete")ch.pb({6,"",""});
    else if(s=="replace")
    {
      string a,b;
      cin>>a>>b;
      ch.pb({2,a,b});
    }
    else if(s=="append")
    {
      string a;
      cin>>a;
      ch.pb({1,a,""});
    }
    else ok=0;
    if(!ok)assert("ERROR");
  }
}
int main()
{
    IOS();
    int s,t;
    cin>>s>>t;
    read();
    mp[s]=0;
    p[s]=ii(-1,-1);
    q.push(s);
    bool ok=0;
    while(!ok)
    {
      ll n=q.front();q.pop();
      //debug(n);
      ll dis=mp[n];
      REP(i,SZ(op)){
        auto &tmp=op[i];
        ll rt=doop(n,tmp);
        if(rt>=10000000)continue;
        if(!mp.count(rt))
        {
          mp[rt]=dis+1;
          p[rt]=ii(i,n);
          if(rt==t){
            ok=1;
            break;
          }
          else q.push(rt);
        }
      }
      REP(i,SZ(ch)){
        auto &tmp=ch[i];
        ll rt=doch(n,tmp);
        if(rt>=10000000)continue;
        if(!mp.count(rt))
        {
          mp[rt]=dis+1;
          p[rt]=ii(i+SZ(op),n);
          if(rt==t){
            ok=1;
            break;
          }
          else q.push(rt);
        }
      }
    }

    vector<ll> his;
    ll now=t;
    while(p[now].X!=-1)
    {
      his.pb(p[now].X);
      now=p[now].Y;
    }
    reverse(ALL(his));
    debug(SZ(his));
    for(ll tmp:his)
    {
      if(tmp<SZ(op))prtop(tmp);
      else prtch(tmp-SZ(op));
    }
}
