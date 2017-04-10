#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define RI(a) scanf("%d",&a)
#define RII(a,b) scanf("%d%d",&a,&b)
#define RIII(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define ALL(a) a.begin(),a.end()
#define F first
#define S second
#define REP(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#ifdef leowang
#define debug(...) do{\
	fprintf(stderr,"%s - %d : (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
	_DO(__VA_ARGS__);\
}while(0)
template<typename I> void _DO(I&&x){cerr<<x<<endl;}
template<typename I,typename...T> void _DO(I&&x,T&&...tail){cerr<<x<<", ";_DO(tail...);}
#else
#define debug(...)
#endif
//}}}
const ll maxn=100005;
const ll maxlg=__lg(maxn)+2;
const ll INF64=8000000000000000000LL;
const int INF=2000000000;

int main()
{
	//freopen("ans1.txt","w",stdout);
	int t;
	RI(t);
	for(int I=1;I<=t;I++){
		string s;
		cin>>s;
		int k;
		RI(k);
		printf("Case #%d: ",I);

		int n=s.length();
		int cnt=0;
		bool a[1005];
		REP(i,n) a[i]=s[i]=='+'?1:0;
		for(int i=0;i<n;i++){
			if(i==n-k+1) break;
			if(!a[i]){
				cnt++;
				for(int j=i;j<i+k;j++) a[j]=!a[j];
			}
		}
		bool flag=0;
		for(int i=n-k+1;i<n;i++) if(!a[i]){
			puts("IMPOSSIBLE");flag=1;break;
		}
		if(!flag) printf("%d\n",cnt);
	}
	//fclose(stdout);
	return 0;
}
