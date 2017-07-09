#include <bits/stdc++.h>
using namespace std;
//debug
#ifdef grief
#define debug(...) do{\
	fprintf(stderr , "%s - %d : (%s) = " , __PRETTY_FUNCTION__ , __LINE__ , #__VA_ARGS__ );\
	_DO(__VA_ARGS__);\
}while(0)
template<typename I> void _DO(I&&x){
	cerr<<x<<endl;
}
template<typename I,typename...T> void _DO(I&&x,T&&...tail){
	cerr<<x<<" , ";
	_DO(tail...);
}
#else
#define debug(...)
#endif
//type
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef priority_queue<pll,vector<pll>,greater<pll> > heap;
//macro
#define SZ(x) ((ll)(x).size())
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define mkp make_pair
#define pb push_back
#define IOS do{ios_base::sync_with_stdio(0); cin.tie(0);}while(0)
const ll INF=4e18;
const ll MAX=1e5+5;
const ll MOD=1e9+7;
//}}}
int r,c;
char f;
int box[130][130];
int s=2;
bool make(){
	if(f=='B') s=3;
	for(int x=s;x<=r+c-2;x+=2){
		bool done=0;
		int bes=-1;
		pii ap;
		for(int i=r;i>0;i--){
			int j=x-i;
			if(j<=0||j>c||box[i][j]==14)	continue;
			if(i+1<=r&&j+1<=c&& abs( (i-j)-(r-c) )>bes  ){
				bes=abs( (i-j)-(r-c) );
				ap={i,j};
				done=1;
//				break;
			}
		}
		if(!done)	return 0;
		box[ap.F][ap.S]=13;
		box[ap.F+1][ap.S+1]=14;
//		debug(ap.F,ap.S);
	}
	return 1;
}
int main(){
	//IOS;
//	freopen("b1.in","r",stdin);
//	freopen("B.out","w",stdout);
	int t;	cin>>t;
	while(t--){
		s=2;
		memset(box,0,sizeof box);
		cin>>r>>c;
		bool fuck=0;
		if(r>c){
			fuck=1;
			swap(r,c);
		}
		cin>>f;
//		if(r==1){
//			if(f=='W'&&c>2){
//				cout<<"impossible\n";
//				continue;
//			}
//			if(f=='B'&&c>3){
//				cout<<"impossible\n";
//				continue;
//			}
//		}
		if(!make()){
			cout<<"impossible\n";
			continue;
		}
		for(int x=s;x<=r+c;x+=2){

			for(int i=r;i>0;i--){
				int j=x-i;
				if(j<=0||j>c)	continue;
				if(box[i][j]==14){
					if(fuck)	cout<<j<< ' '<<i<< '\n';
					else		cout<<i<< ' '<<j<< '\n';
					break;
				}
			}
			for(int i=r;i>0;i--){
				int j=x-i;
				if(j<=0||j>c)	continue;
				if(box[i][j]==0){
					if(fuck)	cout<<j<< ' '<<i<< '\n';
					else		cout<<i<< ' '<<j<< '\n';
				}
			}
			for(int i=r;i>0;i--){
				int j=x-i;
				if(j<=0||j>c)	continue;
				if(box[i][j]==13){
					if(fuck)
						cout<<j<< ' '<<i<< '\n';
					else
						cout<<i<< ' '<<j<< '\n';
					break;
				}
			}
		}
	}
	return 0;
}
