#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define FILL(i,n) memset(i,n,sizeof i)
#define X first
#define Y second
#define SZ(x) ((ll)(x).size())
#define pb push_back
#define endl '\n'


const ll MAXn=6e5+5,MAXlg=20;
const ll INF=ll(1e18);

const ll C=8;

unordered_map<ll,ll> mp;

ll ct=0,bs=0;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	ll n,q;
	string s;
	cin>>n>>q>>s;
	REP(i,SZ(s))
	{
		ll tt=0;
		REP1(j,min(C,SZ(s)-i))
		{
			
			tt=(tt*27)+s[i+j-1]-'a'+1;
			//cout<<i<<" "<<j<<" "<<tt<<endl;
			if(++mp[tt]==1)ct++;
		}
	}
	//cout<<"  "<<ct<<endl;
	for(int i=C+1;i<=SZ(s);i++)bs+=(SZ(s)-i+1);
	REP(T,q)
	{
		ll x;
		char c;
		cin>>x>>c;
		x--;
		for(int i=max(0LL,x-C+1);i<=x;i++)
		{
			ll tt=0;
			for(int j=i;j<x;j++)tt=(tt*27)+s[j]-'a'+1;
			for(int j=x;j-i+1<=C&&j<SZ(s);j++)
			{
				tt=(tt*27)+s[j]-'a'+1;
				//cout<<i<<" "<<j<<" "<<tt<<endl;
				if(--mp[tt]==0)ct--;
			}
		}
		s[x]=c;
		for(int i=max(0LL,x-C+1);i<=x;i++)
		{
			ll tt=0;
			for(int j=i;j<x;j++)tt=(tt*27)+s[j]-'a'+1;
			for(int j=x;j-i+1<=C&&j<SZ(s);j++)
			{
				tt=(tt*27)+s[j]-'a'+1;
				//cout<<i<<" "<<j<<" "<<tt<<endl;
				if(++mp[tt]==1)ct++;
			}
		}
		cout<<ct+bs<<endl;
	}
}