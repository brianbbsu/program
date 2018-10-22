#include <iostream>
#include <map>
using namespace std;

map<string,int> c,p;


int main(){
  double tt = 0.0;
  while(1)
  {
    string s;
    cin>>s;
    if(s == "0000000000")break;
    int pi,ci;
    cin>>pi>>ci;
    c[s] += ci;
    p[s] = pi;
  }
  for(map<string,int>::iterator it = c.begin();it != c.end();it++)
  {
    int ci = it->second;
    int pi = p[it->first];
    if(it->first[0] == 'A')tt += pi * ci;
    else if(it->first[0] == 'X')tt += (ci / 2 + ci % 2) * pi;
    else tt += (ci / 2 + ci % 2) * pi + (ci / 2) * (pi / 2.0);
    
  }
  cout<<tt<<endl;
}
