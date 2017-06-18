#include <iostream>
#include <stdio.h>
#include <map>
#include <cstring>
#include <queue>
using namespace std;

int adj[123][123];
int deg[123];
int mx[123];

int main () {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >>s;
        map<string,int> mp;
        mp["initial"] = 1;
        mp["terminal"] = 2;
        int id=3;
        memset(adj,-1,sizeof(adj));
        memset(deg,0,sizeof(deg));
        while (1) {
            string a,b;
            int c;
            cin >> a;
            if (a=="end") break;
            cin >> b >>c;
            int aa=mp[a];
            if (!aa) mp[a] = (id++);
            int bb=mp[b];
            if (!bb) mp[b] = (id++);
            aa=mp[a];
            bb=mp[b];
            adj[aa][bb] = c;
            deg[bb]++;
        }
        int n=id-1;
        memset(mx,0,sizeof(mx));
        queue<int> que;
        for (int i=1;n>=i;i++) {
            if (deg[i] ==0)que.push(i);
        }
        while (!que.empty()) {
            int t=que.front();
            que.pop();
            for (int i=1;n>=i;i++) {
                if (adj[t][i] != -1) {
                    mx[i] = max(mx[i],mx[t] + adj[t][i]);
                    deg[i]--;
                    if (deg[i] == 0) que.push(i);
                }
            }
        }
        cout<<mx[2]<<endl;
    }
}
