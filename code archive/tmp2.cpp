#include <iostream>
#include <string>
#include <sstream>


using namespace std;

int getNum(string &inp,int pos){
	if(pos>inp.length())return 0;
	int len = inp.length();
	stringstream ss;
	ss<<inp[len-pos];
	int out;
	ss>>out;
	return out;
}
string addBigNum(string &a,string &b){
	int add=0;
	int digi=1;
	string c="";
	while(digi<=a.length()||digi<=b.length()||add>0){
		int ad = getNum(a,digi);
		int bd = getNum(b,digi);
		int sum = ad + bd + add;


		stringstream ss;
		ss<<sum%10;
		string tmpString;
		ss>>tmpString;

		c = tmpString + c;

		add = sum/10;

		digi++;
	}
	return c;
}
string timeBigNum(string a,string b){
	string op;
	op = "0";
	for(int i=1;i<=b.length();i++){
		int bSub = getNum(b,i);
		string total = "";

		int digi=1;
		int add=0;
		while(digi<=a.length()||add>0){
			int aSub = getNum(a,digi);
			int cal = aSub * bSub + add;
			add = cal/10;

			string tmpStr;

			stringstream ss;
			ss<<cal%10;
			ss>>tmpStr;

			total= tmpStr+total;


			digi++;
		}

		for(int j=1;j<i;j++){
			total+= "0";
		}

		op= addBigNum(op,total);
	}
	return op;
}
int main(){
	int x;
	cin>>x;

	string out="1";
	for(int i=2;i<=x;i++){
		stringstream ss;
		ss<<i;
		string tempStr;
		ss>>tempStr;
		out = timeBigNum(out,tempStr);
	}

	cout<<out<<endl;



	//cout<<addBigNum(a,b)<<endl;
}
