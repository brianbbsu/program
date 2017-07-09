#include <iostream>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <cstring>
#include <queue>
#include <cassert>
#include <algorithm>
using namespace std;

typedef long double ld;
const int MAX_N = 1e6 + 6;
const int MAX_M = 1e6 + 6;
const ld eps = 1e-9;

vector<int> edg[MAX_N];
vector<int> rev_edg[MAX_N];
vector<int> scc_edg[MAX_N];
bool visit[MAX_N];
int get_stamp[MAX_N];
int cnt[MAX_N];

int n,m;

bool is_1(ld d) {
    if (fabs(1.0-d) <= eps) return true;
    return false;
}

int stamp=0;
int in_scc[MAX_N];
int scc_sz[MAX_N];
int scc_val[MAX_N];
int deg[MAX_N];
bool kirino[MAX_N];
ld dp[MAX_N];

void dfs1(int id) {
    visit[id]=1;
    for (int i:rev_edg[id]) {
        if (!visit[i]) dfs1(i);
    }
    get_stamp[++stamp] = id;
}

void dfs2(int id,int scc) {
    visit[id]=1;
    for (int i:edg[id]) {
        if (!visit[i]) dfs2(i,scc);
    }
    in_scc[id]=scc;
}

void dfs3(int id) {
    visit[id]=1;
    if (in_scc[n] == id) {
        kirino[id]=1;
        return;
    }
    for (int i:scc_edg[id]) {
        if (!visit[i]) dfs3(i);
        kirino[id] |= kirino[i];
    }
}

void build_scc() {
    stamp=0;
    for (int i=1;n>=i;i++) {
        if (!visit[i]) dfs1(i);
    }
    //cout<<"hello";
    for(int i=0;n>=i;i++) visit[i]=0;
    int scc=0;
    for (int i=n;i>=1;i--) {
            //cout<<"haha = "<<get_stamp[i]<<endl;
        if (!visit[ get_stamp[i] ]) dfs2(get_stamp[i],++scc);
    }
    //cout<<"scc = "<<scc<<endl;
    for(int i=0;n>=i;i++) visit[i]=0;
    for(int i=0;n>=i;i++) deg[i]=0;
    for (int i=1;n>=i;i++) {
            //cout<<"in_scc = "<<in_scc[i]<<endl;
        scc_sz[in_scc[i] ]++;
        scc_val[in_scc[i] ] = i;
        for (int j:edg[i]) {
            if (in_scc[i] != in_scc[j]) {
                scc_edg[ in_scc[i] ].push_back( in_scc[j] );
            }
        }
    }
    for (int i=0;n>=i;i++) kirino[i]=0;
    dfs3(in_scc[1]);
    for (int i=1;scc>=i;i++) {
        sort(scc_edg[i].begin(),scc_edg[i].end());
        scc_edg[i].resize(unique(scc_edg[i].begin(),scc_edg[i].end()) - scc_edg[i].begin());
        for (int j:scc_edg[i]) if (kirino[i] && kirino[j])deg[j]++;
    }
    for (int i=0;n>=i;i++) visit[i]=0;
}

int main () {
    //freopen("i2.in","r",stdin);
    //freopen("i2.out","w",stdout);
    int T;
    scanf("%d",&T);
    while (T--) {
        scanf("%d %d",&n,&m);
        for (int i=1;m>=i;i++) {
            int a,b;
            scanf("%d %d",&a,&b);
            edg[a].push_back(b);
            rev_edg[b].push_back(a);
            if (a==b) cnt[a]++;
        }
        //cout<<"hellll";
        build_scc();
        //cout<<"hello";
        if (in_scc[1] == in_scc[n] || !kirino[ in_scc[1] ]) {
            //if (in_scc[1] == in_scc[n]) printf("reason 1");
            //else printf("reason 2");
            puts("0\n");
        }
        else {
            vector<int> ans;
            queue<int> que;
            que.push(in_scc[1]);
            for (int i=0;n>=i;i++) dp[i]=0;
            dp[in_scc[1] ]=1;
            bool get_n=false;
            while (!que.empty()) {
                int t=que.front();
                assert(kirino[t] == 1);
                get_n |= t==in_scc[n];
                que.pop();
                //cout<<"dp = "<<dp[t]<<" , t = "<<t<<endl;
                if (scc_sz[t]==1 && is_1(dp[t]) && cnt[scc_val[t] ] == 0) ans.push_back(scc_val[t]);
                int cnt=0;
                for (int i:scc_edg[t]) {
                    if (kirino[i]) cnt++;
                }
                for (int i:scc_edg[t]) {
                    if (kirino[i]) {
                        dp[i] += dp[t]/ld(cnt);
                        deg[i]--;
                        if (deg[i]==0) que.push(i);
                    }
                }
            }
            assert(get_n);
            assert(is_1(dp[in_scc[n] ]));
            printf("%d\n",(int)ans.size());
            bool check=false;
            for (int i:ans) {
                if (check) printf(" ");
                printf("%d",i);
                check=true;
            }
            puts("");
        }
        //after print answer
        for (int i=0;n>=i;i++) {
            edg[i].clear();
            rev_edg[i].clear();
            scc_edg[i].clear();
            scc_sz[i]=0;
            cnt[i]=0;
        }
    }
}
